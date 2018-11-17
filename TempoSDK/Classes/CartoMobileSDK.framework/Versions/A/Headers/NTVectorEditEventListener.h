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
 * The intended result of the drag operation.
 */
typedef NS_ENUM(NSInteger, NTVectorElementDragResult) {
/**
 * Dragging should be ignored. The input event will be passed on to other handlers.
 */
  NT_VECTOR_ELEMENT_DRAG_RESULT_IGNORE,
/**
 * Dragging should be ignored. The input event is not passed on to other handlers.
 */
  NT_VECTOR_ELEMENT_DRAG_RESULT_STOP,
/**
 * The underlying vector element (or vertex) should be modified.
 */
  NT_VECTOR_ELEMENT_DRAG_RESULT_MODIFY,
/**
 * The underlying vector element or vertex should be deleted.
 */
  NT_VECTOR_ELEMENT_DRAG_RESULT_DELETE
};

/**
 * Different types of styles for control points created for selected vector elements.
 */
typedef NS_ENUM(NSInteger, NTVectorElementDragPointStyle) {
/**
 * Normal control point. Corresponds to vertex.
 */
  NT_VECTOR_ELEMENT_DRAG_POINT_STYLE_NORMAL,
/**
 * Virtual control point (midpoint between actual vertices). Used for lines and polygons.
 */
  NT_VECTOR_ELEMENT_DRAG_POINT_STYLE_VIRTUAL,
/**
 * Selected control point.
 */
  NT_VECTOR_ELEMENT_DRAG_POINT_STYLE_SELECTED
};


#import "NTScreenPos.h"
#import "NTGeometry.h"
#import "NTVectorElement.h"
#import "NTPointStyle.h"
#import "NTVectorElementDragInfo.h"

/**
 * Listener interface for catching various events<br>
 * during map editing interactions. 
 */
__attribute__ ((visibility("default"))) @interface NTVectorEditEventListener : NSObject
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
+(NTVectorEditEventListener*)swigCreatePolymorphicInstance:(void*)cPtr swigOwnCObject:(BOOL)cMemoryOwn;

/**
 * Called when element is being selected. Can be used to disallow element selection.<br>
 * @param element The element being selected<br>
 * @return true if the element is selectable, false otherwise
 */
-(BOOL)onElementSelect: (NTVectorElement*)element;
/**
 * Called when element is being selected. Can be used to disallow element selection.<br>
 * @param element The element being selected<br>
 * @return true if the element is selectable, false otherwise
 */
-(BOOL)onElementSelectSwigExplicitNTVectorEditEventListener: (NTVectorElement*)element;
/**
 * Called when element is unselected.<br>
 * @param element The element which was unselected
 */
-(void)onElementDeselected: (NTVectorElement*)element;
/**
 * Called when element is unselected.<br>
 * @param element The element which was unselected
 */
-(void)onElementDeselectedSwigExplicitNTVectorEditEventListener: (NTVectorElement*)element;
/**
 * Called when element is being modified.<br>
 * It the responsibility of the implementation of this method to update actual vector element geometry.<br>
 * The geometry may be modified before updating the vector element, but topology of the element MUST not change!<br>
 * @param element The element that is being edited<br>
 * @param geometry The modified geometry for the element
 */
-(void)onElementModify: (NTVectorElement*)element geometry: (NTGeometry*)geometry;
/**
 * Called when element should be deleted.<br>
 * @param element The element that needs to be deleted
 */
-(void)onElementDelete: (NTVectorElement*)element;
/**
 * Called before element or vertex is dragged.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragStart: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called before element or vertex is dragged.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragStartSwigExplicitNTVectorEditEventListener: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called when element or vertex is being dragged to specific location.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragMove: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called when element or vertex is being dragged to specific location.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragMoveSwigExplicitNTVectorEditEventListener: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called when element or vertex dragging is finished.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragEnd: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called when element or vertex dragging is finished.<br>
 * @param dragInfo The information about the element or vertex.<br>
 * @return The intended result of dragging.
 */
-(enum NTVectorElementDragResult)onDragEndSwigExplicitNTVectorEditEventListener: (NTVectorElementDragInfo*)dragInfo;
/**
 * Called when drag point style is needed.<br>
 * @param element The vector element being dragged<br>
 * @param dragPointStyle Drag point style.<br>
 * @return The point style to use for the drag point.
 */
-(NTPointStyle*)onSelectDragPointStyle: (NTVectorElement*)element dragPointStyle: (enum NTVectorElementDragPointStyle)dragPointStyle;
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

