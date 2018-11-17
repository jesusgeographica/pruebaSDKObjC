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


#import "NTMapTile.h"
#import "NTMapBounds.h"
#import "NTStringMap.h"
#import "NTTileDataSource.h"
#import "NTTileData.h"
#import "NTPackageManager.h"

/**
 * A tile data source that loads tiles from package manager.
 */
__attribute__ ((visibility("default"))) @interface NTPackageManagerTileDataSource : NTTileDataSource
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
+(NTPackageManagerTileDataSource*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Constructs a PackageManagerTileDataSource object.<br>
 * @param packageManager The package manager that is used to retrieve requested tiles.
 */
-(id)initWithPackageManager: (NTPackageManager*)packageManager;
/**
 * Returns the package manager instance used by the data source.<br>
 * @return The package manager instance used by the data source.
 */
-(NTPackageManager*)getPackageManager;
-(NTTileData*)loadTile: (NTMapTile*)mapTile;
-(NTTileData*)loadTileSwigExplicitNTPackageManagerTileDataSource: (NTMapTile*)mapTile;
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

