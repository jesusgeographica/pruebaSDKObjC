/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_VECTORTILELAYER_H_
#define _CARTO_VECTORTILELAYER_H_

#include "core/MapTile.h"
#include "core/MapBounds.h"
#include "components/CancelableTask.h"
#include "components/DirectorPtr.h"
#include "components/Task.h"
#include "layers/TileLayer.h"
#include "vectortiles/VectorTileDecoder.h"

#include <memory>
#include <map>

#include <stdext/timed_lru_cache.h>

namespace carto {
    class TileDrawData;
    class VectorTileEventListener;
        
    namespace VectorTileRenderOrder {
        /**
         * Vector tile rendering order.
         */
        enum VectorTileRenderOrder {
            /**
             * No rendering, elements are hidden.
             */
            VECTOR_TILE_RENDER_ORDER_HIDDEN = -1,
            /**
             * Elements are rendered together with the same layer elements.
             * Layers that are on top of the layers are rendered on top this layer.
             */
            VECTOR_TILE_RENDER_ORDER_LAYER = 0,
            /**
             * Elements are rendered on top of all normal layers.
             */
            VECTOR_TILE_RENDER_ORDER_LAST = 1
        };
    };
    
    /**
     * A tile layer where each tile is a bitmap. Should be used together with corresponding data source.
     */
    class VectorTileLayer : public TileLayer {
    public:
        /**
         * Constructs a VectorTileLayer object from a data source and tile decoder.
         * @param dataSource The data source from which this layer loads data.
         * @param decoder The tile decoder that decoder loaded tiles and applies styles.
         */
        VectorTileLayer(const std::shared_ptr<TileDataSource>& dataSource, const std::shared_ptr<VectorTileDecoder>& decoder);
        virtual ~VectorTileLayer();
    
        /**
         * Returns the tile decoder assigned to this layer.
         * @return The tile decoder assigned to this layer.
         */
        virtual std::shared_ptr<VectorTileDecoder> getTileDecoder() const;
        
        /**
         * Returns the tile cache capacity.
         * @return The tile cache capacity in bytes.
         */
        std::size_t getTileCacheCapacity() const;
        /**
         * Sets the vector tile cache capacity. Tile cache is the primary storage for vector data,
         * all tiles contained within the cache are stored as uncompressed vertex buffers and can immediately be
         * drawn to the screen. Setting the cache size too small may cause artifacts, such as disappearing tiles.
         * The more tiles are visible on the screen, the larger this cache should be. 
         * The default is 10MB, which should be enough for most use cases with preloading enabled. If preloading is
         * disabled, the cache size should be reduced by the user to conserve memory.
         * @param capacityInBytes The new tile bitmap cache capacity in bytes.
         */
        void setTileCacheCapacity(std::size_t capacityInBytes);
        
        /**
         * Returns the current display order of the labels.
         * @return The display order of the labels. Default is VECTOR_TILE_RENDER_ORDER_LAYER.
         */
        VectorTileRenderOrder::VectorTileRenderOrder getLabelRenderOrder() const;
        /**
         * Sets the current display order of the labels.
         * @param renderOrder The new display order of the labels.
         */
        void setLabelRenderOrder(VectorTileRenderOrder::VectorTileRenderOrder renderOrder);
    
        /**
         * Returns the current display order of the buildings.
         * @return The display order of the buildigns. Default is VECTOR_TILE_RENDER_ORDER_LAYER.
         */
        VectorTileRenderOrder::VectorTileRenderOrder getBuildingRenderOrder() const;
        /**
         * Sets the current display order of the buildings.
         * @param renderOrder The new display order of the labels.
         */
        void setBuildingRenderOrder(VectorTileRenderOrder::VectorTileRenderOrder renderOrder);
    
        /**
         * Returns the vector tile event listener.
         * @return The vector tile event listener.
         */
        std::shared_ptr<VectorTileEventListener> getVectorTileEventListener() const;
        /**
         * Sets the vector tile event listener.
         * @param eventListener The vector tile event listener.
         */
        void setVectorTileEventListener(const std::shared_ptr<VectorTileEventListener>& eventListener);
    
    protected:
        virtual bool tileExists(const MapTile& mapTile, bool preloadingCache) const;
        virtual bool tileValid(const MapTile& mapTile, bool preloadingCache) const;
        virtual void fetchTile(const MapTile& mapTile, bool preloadingTile, bool invalidated);
        virtual void clearTiles(bool preloadingTiles);
        virtual void tilesChanged(bool removeTiles);

        virtual long long getTileId(const MapTile& mapTile) const;
        virtual std::shared_ptr<VectorTileDecoder::TileMap> getTileMap(long long tileId) const;

        virtual void calculateDrawData(const MapTile& visTile, const MapTile& closestTile, bool preloadingTile);
        virtual void refreshDrawData(const std::shared_ptr<CullState>& cullState);
    
        virtual int getMinZoom() const;
        virtual int getMaxZoom() const;
        virtual std::vector<long long> getVisibleTileIds() const;
        
        virtual void calculateRayIntersectedElements(const Projection& projection, const cglib::ray3<double>& ray,
            const ViewState& viewState, std::vector<RayIntersectedElement>& results) const;
        virtual bool processClick(ClickType::ClickType clickType, const RayIntersectedElement& intersectedElement, const ViewState& viewState) const;

        virtual void offsetLayerHorizontally(double offset);
        
        virtual void onSurfaceCreated(const std::shared_ptr<ShaderManager>& shaderManager, const std::shared_ptr<TextureManager>& textureManager);
        virtual bool onDrawFrame(float deltaSeconds, BillboardSorter& billboardSorter, StyleTextureCache& styleCache, const ViewState& viewState);
        virtual bool onDrawFrame3D(float deltaSeconds, BillboardSorter& billboardSorter, StyleTextureCache& styleCache, const ViewState& viewState);
        virtual void onSurfaceDestroyed();
        
        virtual std::shared_ptr<Bitmap> getBackgroundBitmap() const;
        virtual std::shared_ptr<Bitmap> getSkyBitmap() const;

        virtual void registerDataSourceListener();
        virtual void unregisterDataSourceListener();

        // Configuration parameters that can be tweaked in subclasses
        bool _useTileMapMode;
    
    private:    
        class TileDecoderListener : public VectorTileDecoder::OnChangeListener {
        public:
            explicit TileDecoderListener(const std::shared_ptr<VectorTileLayer>& layer);
            
            virtual void onDecoderChanged();
    
        private:
            std::weak_ptr<VectorTileLayer> _layer;
        };
    
        class FetchTask : public TileLayer::FetchTaskBase {
        public:
            FetchTask(const std::shared_ptr<VectorTileLayer>& layer, const MapTile& tile, bool preloadingTile);
            
        protected:
            virtual bool loadTile(const std::shared_ptr<TileLayer>& tileLayer);
        };
        
        class LabelCullTask : public CancelableTask {
        public:
            LabelCullTask(const std::shared_ptr<VectorTileLayer>& layer, const std::shared_ptr<TileRenderer>& tileRenderer, const ViewState& viewState);
            
            virtual void cancel();
            virtual void run();
    
        private:
            std::weak_ptr<VectorTileLayer> _layer;
            std::weak_ptr<TileRenderer> _tileRenderer;
            ViewState _viewState;
        };

        class TileInfo {
        public:
            TileInfo() : _tileBounds(), _tileData(), _tileMap() { }
            TileInfo(const MapBounds& tileBounds, const std::shared_ptr<BinaryData>& tileData, const std::shared_ptr<VectorTileDecoder::TileMap>& tileMap) : _tileBounds(tileBounds), _tileData(tileData), _tileMap(tileMap) { }

            const MapBounds& getTileBounds() const { return _tileBounds; }
            const std::shared_ptr<BinaryData>& getTileData() const { return _tileData; }
            const std::shared_ptr<VectorTileDecoder::TileMap>& getTileMap() const { return _tileMap; }

            std::size_t getSize() const;

        private:
            MapBounds _tileBounds;
            std::shared_ptr<BinaryData> _tileData;
            std::shared_ptr<VectorTileDecoder::TileMap> _tileMap;
        };

        static const int BACKGROUND_BLOCK_SIZE = 16;
        static const int BACKGROUND_BLOCK_COUNT = 16;
        static const int SKY_WIDTH = 512;
        static const int SKY_HEIGHT = 128;
        static const int SKY_GRADIENT_SIZE = 6;
        static const int SKY_GRADIENT_OFFSET = 1;
        static const int DEFAULT_CULL_DELAY = 200;
        static const int PRELOADING_PRIORITY_OFFSET = -2;
        static const int EXTRA_TILE_FOOTPRINT = 4096;
        static const int DEFAULT_VISIBLE_CACHE_SIZE = 512 * 1024 * 1024; // NOTE: the limit should never be reached in normal cases
        static const int DEFAULT_PRELOADING_CACHE_SIZE = 10 * 1024 * 1024;
        
        ThreadSafeDirectorPtr<VectorTileEventListener> _vectorTileEventListener;

        VectorTileRenderOrder::VectorTileRenderOrder _labelRenderOrder;
        VectorTileRenderOrder::VectorTileRenderOrder _buildingRenderOrder;
    
        const std::shared_ptr<VectorTileDecoder> _tileDecoder;
        std::shared_ptr<TileDecoderListener> _tileDecoderListener;

        mutable Color _backgroundColor;
        mutable std::shared_ptr<Bitmap> _backgroundBitmap;
        mutable Color _skyColor;
        mutable std::shared_ptr<Bitmap> _skyBitmap;

        std::shared_ptr<CancelableThreadPool> _labelCullThreadPool;

        std::vector<long long> _visibleTileIds;
        std::vector<std::shared_ptr<TileDrawData> > _tempDrawDatas;

        cache::timed_lru_cache<long long, TileInfo> _visibleCache;
        cache::timed_lru_cache<long long, TileInfo> _preloadingCache;
    };
    
}

#endif
