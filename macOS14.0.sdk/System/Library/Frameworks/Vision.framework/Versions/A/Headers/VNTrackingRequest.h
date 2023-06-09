//
//  VNTrackingRequest.h
//  Vision
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Vision/VNRequest.h>


NS_ASSUME_NONNULL_BEGIN


@class VNDetectedObjectObservation;


/*!
 @brief    Tracking level options to favor speed or location accuracy. The VNRequestTrackingLevelFast is the default option used by trackers.   
 */
typedef NS_ENUM(NSUInteger, VNRequestTrackingLevel)
{
    VNRequestTrackingLevelAccurate = 0,
    VNRequestTrackingLevelFast
};


/*!
	@abstract	A base class for all tracking requests.
	@discussion	Since this class is not meant to be directly instantiated, no initializers are available.
*/
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNTrackingRequest : VNImageBasedRequest

/*!
 @brief This class method returns a maximum number of allowed simultaneously executed trackers for [request revision x tracking level] combination
 
 @details The total number of simultaneously running trackes is limited due to performance concerns. There is a limit for each combination of
          [request revision x tracking level] and this method could be used to query that limit
                     
 @param revision The revision of a specific tracking request (an object of a subclass of VNTrackingRequest).
 @param trackingLevel Tracking level of a specific tracking request (an object of a subclass of VNTrackingRequest).
 @param error The address of a variable that will be populated with an error upon failure. If the caller does not need this information, NULL can be passed.
 
 @result Maximum number of trackers for a given combination [request revision x tracking level], or 0 if such combination doesn't exist
 */
- (NSUInteger)supportedNumberOfTrackersAndReturnError:(NSError **)error API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));

/*!
 @property property inputObservation
 @abstract The observation object that defines a region to track. Providing an observation not returned from a tracker (e.g. user-defined, or from a detector) begins a new tracker for the sequence. Providing an observation that was returned from a tracker continues the use of that tracker, to track the region to the next frame. In general, unless documented in the request's documentation, the rectangle must be defined in normalized coordinates (both dimensions normalized to [0,1] with the origin at the lower-left corner).
*/
@property (readwrite, nonatomic, strong) VNDetectedObjectObservation * inputObservation;

/*!
 @property property trackingLevel
 @abstract Tracking level allows tuning tracking algorithm to prefer speed (VNRequestTrackingLevelFast) vs. tracking object location accuracy (VNRequestTrackingLevelAccurate). This property has no effect on general purpose object tracker (VNTrackObjectRequest) revision 2 (VNTrackObjectRequestRevision2)
 */
@property (readwrite, nonatomic, assign) VNRequestTrackingLevel trackingLevel;

/*!
 @property property lastFrame
 @abstract This property allows marking the last frame for tracking using current tracker. If set to YES, the results for this frame will be processed and returned and the current tracker will be released to the pool of available trackers
 */
@property (readwrite, nonatomic, assign, getter=isLastFrame) BOOL lastFrame;

- (instancetype) init   NS_UNAVAILABLE;
- (instancetype) initWithCompletionHandler:(nullable VNRequestCompletionHandler)completionHandler   NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END
