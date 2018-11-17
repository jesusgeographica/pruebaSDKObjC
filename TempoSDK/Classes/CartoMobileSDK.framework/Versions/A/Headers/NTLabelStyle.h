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


#import "NTColor.h"
#import "NTBillboardStyle.h"

/**
 * A style for labels. Contains attributes for configuring how the label is drawn on the screen.
 */
__attribute__ ((visibility("default"))) @interface NTLabelStyle : NTBillboardStyle
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
+(NTLabelStyle*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Returns the horizontal anchor point of the label.<br>
 * @return The horizontal anchor point of the label.
 */
-(float)getAnchorPointX;
/**
 * Returns the vertical anchor point of the label.<br>
 * @return The vertical anchor point of the label.
 */
-(float)getAnchorPointY;
/**
 * Returns the state of the flippable flag.<br>
 * @return True if the label is flippable.
 */
-(BOOL)isFlippable;
/**
 * Returns the orientation mode of the label.<br>
 * @return The orientation mode of the label.
 */
-(enum NTBillboardOrientation)getOrientationMode;
/**
 * Returns the scaling mode of the label.<br>
 * @return The scaling mode of the label.
 */
-(enum NTBillboardScaling)getScalingMode;
/**
 * Returns the relative rendering scale of the label.<br>
 * @return The relative rendering scale of the label.
 */
-(float)getRenderScale;
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

