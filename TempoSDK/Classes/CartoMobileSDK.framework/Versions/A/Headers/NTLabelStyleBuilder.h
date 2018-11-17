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


#import "NTBillboardStyleBuilder.h"
#import "NTLabelStyle.h"

/**
 * A builder class for LabelStyle.
 */
__attribute__ ((visibility("default"))) @interface NTLabelStyleBuilder : NTBillboardStyleBuilder
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
+(NTLabelStyleBuilder*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Constructs a LabelStyleBuilder object with all parameters set to defaults.
 */
-(id)init;
/**
 * Returns the horizontal anchor point of the label.<br>
 * @return The horizontal anchor point of the label.
 */
-(float)getAnchorPointX;
/**
 * Sets the horizontal anchor point of the label.<br>
 * @param anchorPointX The new horizontal anchor point for the label. -1 means the left side,<br>
 *                     0 the center and 1 the right side of the label. The default is 0.
 */
-(void)setAnchorPointX: (float)anchorPointX;
/**
 * Returns the vertical anchor point of the label.<br>
 * @return The vertical anchor point of the label.
 */
-(float)getAnchorPointY;
/**
 * Sets the vertical anchor point of the label.<br>
 * @param anchorPointY The vertical anchor point for the label. -1 means the bottom,<br>
 *                     0 the center and 1 the top of the label. The default is -1.
 */
-(void)setAnchorPointY: (float)anchorPointY;
/**
 * Sets the anchor point for the label. Values will be clamped to [-1, 1] range.<br>
 * @param anchorPointX The new horizontal anchor point for the label. -1 means the left side,<br>
 *                     0 the center and 1 the right side of the label. The default is 0.<br>
 * @param anchorPointY The vertical anchor point for the label. -1 means the bottom,<br>
 *                     0 the center and 1 the top of the label. The default is -1.
 */
-(void)setAnchorPointX: (float)anchorPointX anchorPointY: (float)anchorPointY;
/**
 * Returns the state of the flippable flag.<br>
 * @return True if the label is flippable.
 */
-(BOOL)isFlippable;
/**
 * Sets the state of the flippable flag. If set to true and the orientation mode is set to<br>
 * GROUND the label is allowed to flip 180 degrees to try and face the camera better. This is<br>
 * useful for street names and some other texts. The default is true.<br>
 * @param flippable The new state of the flippable flag.
 */
-(void)setFlippable: (BOOL)flippable;
/**
 * Returns the orientation mode of the label.<br>
 * @return The orientation mode of the label.
 */
-(enum NTBillboardOrientation)getOrientationMode;
/**
 * Sets the orientation mode for the label. The default is BillboardOrientation::FACE_CAMERA_BILLBOARD.<br>
 * @param orientationMode The new orientation mode for the label.
 */
-(void)setOrientationMode: (enum NTBillboardOrientation)orientationMode;
/**
 * Returns the scaling mode of the label.<br>
 * @return The scaling mode of the label.
 */
-(enum NTBillboardScaling)getScalingMode;
/**
 * Sets the scaling mode for the label. The default is BillboardScaling::CONST_SCREEN_SIZE.<br>
 * @param scalingMode The new scaling mode for the label.
 */
-(void)setScalingMode: (enum NTBillboardScaling)scalingMode;
/**
 * Returns the relative rendering scale for the label. <br>
 * @return The relative rendering scale for the label.
 */
-(float)getRenderScale;
/**
 * Sets the relative rendering scale for the label. The default is 1.0. For sharper labels, this should be larger.<br>
 * @param renderScale The new rendering scale value.
 */
-(void)setRenderScale: (float)renderScale;
/**
 * Builds a new instance of the LabelStyle object using previously set parameters.<br>
 * @return A new LabelStyle object.
 */
-(NTLabelStyle*)buildStyle;
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

