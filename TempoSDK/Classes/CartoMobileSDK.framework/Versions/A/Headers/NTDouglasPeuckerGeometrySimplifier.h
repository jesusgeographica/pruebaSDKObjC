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


#import "NTGeometry.h"
#import "NTGeometrySimplifier.h"

/**
 * An implementation of Ramer-Douglas-Peucker algorithm for geometry simplification.<br>
 * Simplifier works on lines and polygons.<br>
 * Simplification is done in two passes - first pass uses fast Radial Distance vertex rejection,<br>
 * second pass uses Ramer-Douglas-Peuckerworst algorithm (with worst case quadratic complexity).
 */
__attribute__ ((visibility("default"))) @interface NTDouglasPeuckerGeometrySimplifier : NTGeometrySimplifier
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
+(NTDouglasPeuckerGeometrySimplifier*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Constructs a new simplifier, given tolerance.<br>
 * @param tolerance The maximum error for simplification. The tolerance value gives maximum error in pixels.
 */
-(id)initWithTolerance: (float)tolerance;
-(NTGeometry*)simplify: (NTGeometry*)geometry scale: (float)scale;
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

