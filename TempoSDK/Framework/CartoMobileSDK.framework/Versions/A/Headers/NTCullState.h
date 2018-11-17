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


#import "NTMapEnvelope.h"
#import "NTMapPos.h"
#import "NTFrustum.h"
#import "NTViewState.h"
#import "NTProjection.h"

/**
 * View specific state determined by the culling process. This includes <br>
 * convex envelope of the visible area, view frustum, tiles and camera state.
 */
__attribute__ ((visibility("default"))) @interface NTCullState : NSObject
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
 * Checks if this object is equal to the specified object.
 * @param object The reference object.
 * @return True when objects are equal, false otherwise.
 */
-(BOOL)isEqual:(id)object;

/**
 * Returns the hash value of this object.
 * @return The hash value of this object.
 */
-(NSUInteger)hash;

/**
 * Constructs a CullState object from an envelope and a viewstate.<br>
 * @param envelope The envelope.<br>
 * @param viewState The view state.
 */
-(id)initWithEnvelope: (NTMapEnvelope*)envelope viewState: (NTViewState*)viewState;
/**
 * Returns an envelope for the visible area in given projection coordinates.<br>
 * @param proj The projection for the envelope<br>
 * @return The envelope for the visible area in the coordinate system of the given projection.
 */
-(NTMapEnvelope*)getProjectionEnvelope: (NTProjection*)proj;
/**
 * Returns a view state.<br>
 * @return The view state.
 */
-(NTViewState*)getViewState;
/**
 * Returns the raw pointer to the object. This is used internally by the SDK.<br>
 * @return The internal pointer of the object.
 */
/** @internal:nodoc: */
-(long long)swigGetRawPtr;

-(void)dealloc;

@end


#ifdef __cplusplus
}
#endif
