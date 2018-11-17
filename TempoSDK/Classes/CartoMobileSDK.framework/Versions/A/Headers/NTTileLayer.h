/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#import <Foundation/Foundation.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * The policy to use when looking for tiles that are not available.
 */
typedef NS_ENUM(NSInteger, NTTileSubstitutionPolicy) {
/**
 * Consider all cached/loaded tiles.
 */
  NT_TILE_SUBSTITUTION_POLICY_ALL,
/**
 * Consider only tiles that are currently visible.<br>
 * This is recommended for low-latency data sources, like offline sources.
 */
  NT_TILE_SUBSTITUTION_POLICY_VISIBLE,
/**
 * Never substitute tiles.
 */
  NT_TILE_SUBSTITUTION_POLICY_NONE
};


#import "NTMapPos.h"
#import "NTMapTile.h"
#import "NTMapBounds.h"
#import "NTTileDataSource.h"
#import "NTTileLoadListener.h"
#import "NTUTFGridEventListener.h"
#import "NTLayer.h"

/**
 * An abstract base class for all tile layers.
 */
__attribute__ ((visibility("default"))) @interface NTTileLayer : NTLayer
/** @internal:nodoc: */
-(void*)getCptr;
/** @internal:nodoc: */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;

/**
 * Creates a polymorphic instance of the given native object. This is used internally by the SDK.
 * @param cPtr The native pointer of the instance.
 * @param cMemoryOwn The ownership flag.
 * @return The new instance.
 */
/** @internal:nodoc: */
+(NTTileLayer*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Returns the data source assigned to this layer.<br>
 * @return The tile data source assigned to this layer.
 */
-(NTTileDataSource*)getDataSource;
/**
 * Returns the tile data source of the associated UTF grid. By default this is null.<br>
 * @return The tile data source of the associated UTF grid.
 */
-(NTTileDataSource*)getUTFGridDataSource;
/**
 * Sets the tile data source of the associated UTF grid.<br>
 * @param dataSource The data source to use. Can be null if UTF grid is not used.
 */
-(void)setUTFGridDataSource: (NTTileDataSource*)dataSource;
/**
 * Returns the current frame number.<br>
 * @return The current frame number.
 */
-(int)getFrameNr;
/**
 * Sets the frame number, only used for animated tiles. <br>
 * Loading a new frame may take some time, previous frame is shown during loading.<br>
 * @param frameNr The frame number to display.
 */
-(void)setFrameNr: (int)frameNr;
/**
 * Returns the state of the preloading flag of this layer.<br>
 * @return True if preloading is enabled.
 */
-(BOOL)isPreloading;
/**
 * Sets the state of preloading for this layer. Preloading allows the downloading of tiles that are not<br>
 * currently visible on screen, but are adjacent to ones that are. This means that the user can pan the map without<br>
 * immediately noticing any missing tiles.<br>
 * <br>
 * Enabling this option might introduce a small performance hit on slower devices. It should also be noted that this<br>
 * will considerably increase network traffic if used with online maps. The default is false.<br>
 * @param preloading The new preloading state of the layer.
 */
-(void)setPreloading: (BOOL)preloading;
/**
 * Returns the state of the synchronized refresh flag.<br>
 * @return The state of the synchronized refresh flag.
 */
-(BOOL)isSynchronizedRefresh;
/**
 * Sets the state of the synchronized refresh flag. If disabled all tiles will appear on screen<br>
 * one by one as they finish loading. If enabled the map will wait for all the visible tiles to finish loading<br>
 * and then show them all on screen together. This is useful for animated tiles.<br>
 * @param synchronizedRefresh The new state of the synchronized refresh flag.
 */
-(void)setSynchronizedRefresh: (BOOL)synchronizedRefresh;
/**
 * Returns the current tile substitution policy.<br>
 * @return The current substitution policy. Default is TILE_SUBSTITUTION_POLICY_ALL.
 */
-(enum NTTileSubstitutionPolicy)getTileSubstitutionPolicy;
/**
 * Sets the current tile substitution policy.<br>
 * @param policy The new substitution policy. Default is TILE_SUBSTITUTION_POLICY_ALL.
 */
-(void)setTileSubstitutionPolicy: (enum NTTileSubstitutionPolicy)policy;
/**
 * Gets the current zoom level bias for this layer.<br>
 * @return The current zoom level bias for this layer.
 */
-(float)getZoomLevelBias;
/**
 * Sets the zoom level bias for this layer.<br>
 * Higher zoom level bias forces SDK to use more detailed tiles for given view compared to lower zoom bias.<br>
 * The default bias is 0.<br>
 * @param bias The new bias value, both positive and negative fractional values are supported.
 */
-(void)setZoomLevelBias: (float)bias;
/**
 * Gets the current maximum overzoom level for this layer.<br>
 * @return The current maximum overzoom level for this layer.
 */
-(int)getMaxOverzoomLevel;
/**
 * Sets the maximum overzoom level for this layer.<br>
 * If a tile for the given zoom level Z is not available, SDK will try to use tiles with zoom levels Z-1, ..., Z-MaxOverzoomLevel.<br>
 * The default is 6.<br>
 * @param overzoomLevel The new maximum overzoom value.
 */
-(void)setMaxOverzoomLevel: (int)overzoomLevel;
/**
 * Gets the current maximum underzoom level for this layer.<br>
 * @return The current maximum underzoom level for this layer.
 */
-(int)getMaxUnderzoomLevel;
/**
 * Sets the maximum underzoom level for this layer.<br>
 * If a tile for the given zoom level Z is not available, SDK will try to use tiles with zoom levels Z-1, ..., Z-MaxOverzoomLevel and then Z+1, ..., Z+MaxUnderzoomLevel.<br>
 * The default is 3.<br>
 * @param underzoomLevel The new maximum underzoom value.
 */
-(void)setMaxUnderzoomLevel: (int)underzoomLevel;
/**
 * Calculates the tile corresponding to given geographical coordinates and zoom level.<br>
 * Note: zoom level bias is NOT applied, only discrete zoom level is used.<br>
 * @param mapPos Coordinates of the point in data source projection coordinate system.<br>
 * @param zoom Zoom level to use for the tile.<br>
 * @return The corresponding map tile.
 */
-(NTMapTile*)calculateMapTile: (NTMapPos*)mapPos zoom: (int)zoom;
/**
 * Calculates the origin of given map tile.<br>
 * @param mapTile The map tile to use.<br>
 * @return The corresponding coordinates of the tile origin in data source projection coordinate system.
 */
-(NTMapPos*)calculateMapTileOrigin: (NTMapTile*)mapTile;
/**
 * Calculates the bounds of given map tile.<br>
 * @param mapTile The map tile to use.<br>
 * @return The corresponding bounds of the tile origin in data source projection coordinate system.
 */
-(NTMapBounds*)calculateMapTileBounds: (NTMapTile*)mapTile;
/**
 * Clears layer tile caches. This will release memory allocated to tiles.<br>
 * @param all True if all tiles should be released, otherwise only preloading (invisible) tiles are released.
 */
-(void)clearTileCaches: (BOOL)all;
/**
 * Returns the tile load listener.<br>
 * @return The tile load listener.
 */
-(NTTileLoadListener*)getTileLoadListener;
/**
 * Sets the tile load listener.<br>
 * @param tileLoadListener The tile load listener.
 */
-(void)setTileLoadListener: (NTTileLoadListener*)tileLoadListener;
/**
 * Returns the UTF grid event listener.<br>
 * @return The UTF grid event listener.
 */
-(NTUTFGridEventListener*)getUTFGridEventListener;
/**
 * Sets the UTF grid event listener.<br>
 * @param utfGridEventListener The UTF grid event listener.
 */
-(void)setUTFGridEventListener: (NTUTFGridEventListener*)utfGridEventListener;
-(BOOL)isUpdateInProgress;
/**
 * Returns the raw pointer to the object. This is used internally by the SDK.<br>
 * @return The internal pointer of the object.
 */
/** @internal:nodoc: */
-(long long)swigGetRawPtr;
/**
 * Returns the actual class name of this object. This is used internally by the SDK.<br>
 * @return The class name of this object.
 */
/** @internal:nodoc: */
-(NSString*)swigGetClassName;
/**
 * Returns the pointer to the connected director object. This is used internally by the SDK.<br>
 * @return The pointer to the connected director object or null if director is not connected.
 */
/** @internal:nodoc: */
-(void *)swigGetDirectorObject;

-(void)dealloc;

@end


#ifdef __cplusplus
}
#endif

