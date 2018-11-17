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
#import "NTProjection.h"

/**
 * A reverse geocoding request describing search location.
 */
__attribute__ ((visibility("default"))) @interface NTReverseGeocodingRequest : NSObject
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
 * Constructs a new ReverseGeocodingRequest object from a projection and location.<br>
 * @param projection The projection to use for the result and location data.<br>
 * @param location The location of the query.
 */
-(id)initWithProjection: (NTProjection*)projection location: (NTMapPos*)location;
/**
 * Returns the location of the query.<br>
 * @return The location of the query.
 */
-(NTMapPos*)getLocation;
/**
 * Returns the search radius (in meters).<br>
 * @return The search radius in meters.
 */
-(float)getSearchRadius;
/**
 * Sets the search radius (in meters).<br>
 * The default search radius is 100 meters.<br>
 * @param radius The new search radius in meters.
 */
-(void)setSearchRadius: (float)radius;
/**
 * Returns the projection of the query.<br>
 * @return The projection of the query.
 */
-(NTProjection*)getProjection;
/**
 * Creates a string representation of this request object, useful for logging.<br>
 * @return The string representation of this request object.
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


#ifdef __cplusplus
}
#endif

