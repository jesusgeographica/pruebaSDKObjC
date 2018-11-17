/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_TILERENDERER_H_
#define _CARTO_TILERENDERER_H_

#include "graphics/Color.h"
#include "graphics/ViewState.h"

#include <memory>
#include <mutex>
#include <map>
#include <tuple>
#include <vector>

#include <cglib/ray.h>

#include <vt/TileId.h>
#include <vt/Tile.h>
#include <vt/Bitmap.h>

namespace carto {
    class Projection;
    class Shader;
    class ShaderManager;
    class TextureManager;
    class TileDrawData;
    class MapRenderer;
    class ViewState;
    namespace vt {
        class GLTileRenderer;
    }
    
    class TileRenderer : public std::enable_shared_from_this<TileRenderer> {
    public:
        TileRenderer(const std::weak_ptr<MapRenderer>& mapRenderer);
        virtual ~TileRenderer();
    
        void setInteractionMode(bool enabled);
        void setSubTileBlending(bool enabled);
        void setLabelOrder(int order);
        void setBuildingOrder(int order);
        void setBackgroundColor(const Color& color);
        void setBackgroundPattern(const std::shared_ptr<const vt::BitmapPattern>& pattern);

        void offsetLayerHorizontally(double offset);
    
        void onSurfaceCreated(const std::shared_ptr<ShaderManager>& shaderManager, const std::shared_ptr<TextureManager>& textureManager);
        bool onDrawFrame(float deltaSeconds, const ViewState& viewState);
        bool onDrawFrame3D(float deltaSeconds, const ViewState& viewState);
        void onSurfaceDestroyed();
    
        bool cullLabels(const ViewState& viewState);

        bool refreshTiles(const std::vector<std::shared_ptr<TileDrawData> >& drawDatas);

        void calculateRayIntersectedElements(const cglib::ray3<double>& ray, const ViewState& viewState, std::vector<std::tuple<vt::TileId, double, long long> >& results) const;
        void calculateRayIntersectedElements3D(const cglib::ray3<double>& ray, const ViewState& viewState, std::vector<std::tuple<vt::TileId, double, long long> >& results) const;
        void calculateRayIntersectedBitmaps(const cglib::ray3<double>& ray, const ViewState& viewState, std::vector<std::tuple<vt::TileId, double, vt::TileBitmap, cglib::vec2<float> > >& results) const;
    
    private:
        const static int CLICK_RADIUS = 4;

        std::weak_ptr<MapRenderer> _mapRenderer;
        std::shared_ptr<vt::GLTileRenderer> _glRenderer;
        std::shared_ptr<std::mutex> _glRendererMutex;
        bool _interactionMode;
        bool _subTileBlending;
        int _labelOrder;
        int _buildingOrder;
        Color _backgroundColor;
        std::shared_ptr<const vt::BitmapPattern> _backgroundPattern;
        double _horizontalLayerOffset;
        std::map<vt::TileId, std::shared_ptr<const vt::Tile> > _tiles;

        mutable std::mutex _mutex;
    };
    
}

#endif
