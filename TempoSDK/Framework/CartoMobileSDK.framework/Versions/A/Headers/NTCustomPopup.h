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


#import "NTMapPos.h"
#import "NTScreenPos.h"
#import "NTBitmap.h"
#import "NTGeometry.h"
#import "NTPointGeometry.h"
#import "NTPopupStyle.h"
#import "NTClickType.h"
#import "NTPopupDrawInfo.h"
#import "NTPopupClickInfo.h"
#import "NTBillboard.h"
#import "NTCustomPopupHandler.h"

/**
 * A popup with user defined handler. The handler is responsible<br>
 * for drawing the bitmap for the popup and can also respond to<br>
 * touch event.
 */
__attribute__ ((visibility("default"))) @interface NTCustomPopup : NTPopup
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
+(NTCustomPopup*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Constructs a CustomPopup object with the specified style and attaches it to a billboard element.<br>
 * @param baseBillboard The billboard this popup will be attached to.<br>
 * @param style The style that defines what this popup looks like.<br>
 * @param popupHandler The handler to use for the popup.
 */
-(id)initWithBaseBillboard: (NTBillboard*)baseBillboard style: (NTPopupStyle*)style popupHandler: (NTCustomPopupHandler*)popupHandler;
/**
 * Constructs a CustomPopup object from a geometry object and a style.<br>
 * @param geometry The geometry object that defines the location of this popup.<br>
 * @param style The style that defines what this popup looks like.<br>
 * @param popupHandler The handler to use for the popup.
 */
-(id)initWithGeometry: (NTGeometry*)geometry style: (NTPopupStyle*)style popupHandler: (NTCustomPopupHandler*)popupHandler;
/**
 * Constructs a CustomPopup object from a map position and a style.<br>
 * @param pos The map position that defines the location of this popup.<br>
 * @param style The style that defines what this popup looks like.<br>
 * @param popupHandler The handler to use for the popup.
 */
-(id)initWithPos: (NTMapPos*)pos style: (NTPopupStyle*)style popupHandler: (NTCustomPopupHandler*)popupHandler;
/**
 * Returns the handler used for the popup.<br>
 * @return The popup handler responsible for drawing the popup and handling click events.
 */
-(NTCustomPopupHandler*)getPopupHandler;
/**
 * Handles the click event for this Popup.<br>
 * @param clickType The type of the click.<br>
 * @param clickPos The position of the click.<br>
 * @param elementClickPos The 2D position of the click on the popup.<br>
 * @return True if the click was handled. False otherwise.
 */
-(BOOL)processClick: (enum NTClickType)clickType clickPos: (NTMapPos*)clickPos elementClickPos: (NTScreenPos*)elementClickPos;
-(NTBitmap*)drawBitmap: (NTScreenPos*)anchorScreenPos screenWidth: (float)screenWidth screenHeight: (float)screenHeight dpToPX: (float)dpToPX;
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

