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


#import "NTRasterTileClickInfo.h"

/**
 * Listener for raster tile element events like clicks etc.
 */
__attribute__ ((visibility("default"))) @interface NTRasterTileEventListener : NSObject
{
  /** @internal:nodoc: */
  void *swigCPtr;
  /** @internal:nodoc: */
  BOOL swigCMemOwn;
}
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
+(NTRasterTileEventListener*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Listener method that gets called when a click is performed on a raster tile.<br>
 * This method will NOT be called from the main thread.<br>
 * @param clickInfo A container that provides information about the click.<br>
 * @return True if the click is handled and subsequent elements should not be handled. False if the next element should be called.
 */
-(BOOL)onRasterTileClicked: (NTRasterTileClickInfo*)clickInfo;
/**
 * Listener method that gets called when a click is performed on a raster tile.<br>
 * This method will NOT be called from the main thread.<br>
 * @param clickInfo A container that provides information about the click.<br>
 * @return True if the click is handled and subsequent elements should not be handled. False if the next element should be called.
 */
-(BOOL)onRasterTileClickedSwigExplicitNTRasterTileEventListener: (NTRasterTileClickInfo*)clickInfo;
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
-(id)init;

-(void)dealloc;

@end


#ifdef __cplusplus
}
#endif
