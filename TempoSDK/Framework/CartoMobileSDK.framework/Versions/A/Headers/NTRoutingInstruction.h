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
 * Routing action type.
 */
typedef NS_ENUM(NSInteger, NTRoutingAction) {
/**
 * Head on, start the route.
 */
  NT_ROUTING_ACTION_HEAD_ON,
/**
 * Finish the route.
 */
  NT_ROUTING_ACTION_FINISH,
/**
 * Continue along the given street, do not turn.
 */
  NT_ROUTING_ACTION_NO_TURN,
/**
 * Go straight.
 */
  NT_ROUTING_ACTION_GO_STRAIGHT,
/**
 * Turn right.
 */
  NT_ROUTING_ACTION_TURN_RIGHT,
/**
 * Do an u-turn.
 */
  NT_ROUTING_ACTION_UTURN,
/**
 * Turn left.
 */
  NT_ROUTING_ACTION_TURN_LEFT,
/**
 * Reached given via point. If this is the final point, FINISH action is used instead.
 */
  NT_ROUTING_ACTION_REACH_VIA_LOCATION,
/**
 * Enter roundabout.
 */
  NT_ROUTING_ACTION_ENTER_ROUNDABOUT,
/**
 * Leave roundabout.
 */
  NT_ROUTING_ACTION_LEAVE_ROUNDABOUT,
/**
 * Continue along the roundabout.
 */
  NT_ROUTING_ACTION_STAY_ON_ROUNDABOUT,
/**
 * Start at the end of the street.
 */
  NT_ROUTING_ACTION_START_AT_END_OF_STREET,
/**
 * Enter street while moving against the allowed direction.
 */
  NT_ROUTING_ACTION_ENTER_AGAINST_ALLOWED_DIRECTION,
/**
 * Leave the street while moving aginst the allowed direction.
 */
  NT_ROUTING_ACTION_LEAVE_AGAINST_ALLOWED_DIRECTION
};


#import "NTMapPos.h"

/**
 * A class that defines a routing instruction at specified position in the path.
 */
__attribute__ ((visibility("default"))) @interface NTRoutingInstruction : NSObject
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
 * Constructs a new RoutingInstruction instance with all values set to default.
 */
-(id)init;
/**
 * Constructs a new RoutingInstruction instance given all instruction attributes.<br>
 * @param action Action to take.<br>
 * @param pointIndex Instruction starting point index in the point list.<br>
 * @param streetName Street name.<br>
 * @param turnAngle Turn angle in degrees.<br>
 * @param azimuth Azimuth in degrees.<br>
 * @param distance The distance to move along the given street in meters.<br>
 * @param time The approximate duration of the instruction in seconds.
 */
-(id)initWithAction: (enum NTRoutingAction)action pointIndex: (int)pointIndex streetName: (NSString*)streetName turnAngle: (float)turnAngle azimuth: (float)azimuth distance: (double)distance time: (double)time;
/**
 * Returns the action of the instruction.<br>
 * @return The action to take.
 */
-(enum NTRoutingAction)getAction;
/**
 * Returns the index of the first geometry point in external point array.<br>
 * @return The point index.
 */
-(int)getPointIndex;
/**
 * Returns the name of street.<br>
 * @return The name of the street.
 */
-(NSString*)getStreetName;
/**
 * Returns the turn angle of the action.<br>
 * @return The turn angle in degrees.
 */
-(float)getTurnAngle;
/**
 * Returns the azimuth of the initial position.<br>
 * @return The azimuth in degrees.
 */
-(float)getAzimuth;
/**
 * Returns the distance to move along the given street.<br>
 * @return The distance to move in meters.
 */
-(double)getDistance;
/**
 * Returns the time approximate duration of the instruction.<br>
 * @return The approximate duration of the instruction in seconds.
 */
-(double)getTime;
/**
 * Creates a string representation of this instruction, useful for logging.<br>
 * @return The string representation of this instruction.
 */
-(NSString*)description;
/**
 * Returns the raw pointer to the object. This is used internally by the SDK.<br>
 * @return The internal pointer of the object.
 */
/** @internal:nodoc: */
-(long long)swigGetRawPtr;

-(void)dealloc;

@end


#import "NTMapPos.h"

__attribute__ ((visibility("default"))) @interface NTRoutingInstructionVector : NSObject
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
-(id)init;
-(unsigned int)size;
-(unsigned int)capacity;
-(void)reserve: (unsigned int)n;
-(BOOL)isEmpty;
-(void)clear;
-(void)add: (NTRoutingInstruction*)x;
-(NTRoutingInstruction*)get: (int)i;
-(void)set: (int)i val: (NTRoutingInstruction*)val;
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

