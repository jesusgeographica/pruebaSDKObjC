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


#import "NTAnimationStyle.h"

/**
 * A builder for AnimationStyle instances.
 */
__attribute__ ((visibility("default"))) @interface NTAnimationStyleBuilder : NSObject
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
+(NTAnimationStyleBuilder*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Constructs an AnimationStyleBuilder object with all parameters set to defaults.
 */
-(id)init;
/**
 * Returns the relative speed of the animation.<br>
 * @return The relative speed of the animation (1.0 corresponds to the default speed).
 */
-(float)getRelativeSpeed;
/**
 * Sets the relative speed of the animation. The relative speed affects all phases of the animation.<br>
 * @param relativeSpeed The new relative speed of the animation.
 */
-(void)setRelativeSpeed: (float)relativeSpeed;
/**
 * Returns the phase-in duration of the animation.<br>
 * @return The phase-in duration of the animation in seconds. By default this is 0.5.
 */
-(float)getPhaseInDuration;
/**
 * Sets the phase-in duration of the animation.<br>
 * @param duration The new phase-in duration of the animation in seconds.
 */
-(void)setPhaseInDuration: (float)duration;
/**
 * Returns the phase-out duration of the animation.<br>
 * @return The phase-out duration of the animation in seconds. By default this is 0.0, which means instant effect.
 */
-(float)getPhaseOutDuration;
/**
 * Sets the phase-out duration of the animation.<br>
 * @param duration The new phase-out duration of the animation in seconds.
 */
-(void)setPhaseOutDuration: (float)duration;
/**
 * Returns the fade animation type.<br>
 * @return The type of the fade animation.
 */
-(enum NTAnimationType)getFadeAnimationType;
/**
 * Sets the fade animation type.<br>
 * @param animType The new type of the fade animation.
 */
-(void)setFadeAnimationType: (enum NTAnimationType)animType;
/**
 * Returns the size-related animation type.<br>
 * @return The type of the size-related animation.
 */
-(enum NTAnimationType)getSizeAnimationType;
/**
 * Sets the size-related animation type.<br>
 * @param animType The new type of the size-related animation.
 */
-(void)setSizeAnimationType: (enum NTAnimationType)animType;
/**
 * Builds a new instance of the AnimationStyle object using previously set parameters.<br>
 * @return A new AnimationStyle object.
 */
-(NTAnimationStyle*)buildStyle;
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

