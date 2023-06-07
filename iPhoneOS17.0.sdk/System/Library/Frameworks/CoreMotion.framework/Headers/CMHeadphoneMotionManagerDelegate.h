/*
 *  CMHeadphoneMotionManagerDelegate.h
 *  CoreMotion
 *
 *  Copyright (c) 2020 Apple Inc. All rights reserved.
 *
 */

#import <Availability.h>
#import <Foundation/Foundation.h>
#import <CoreMotion/CMHeadphoneMotionManager.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  CMHeadphoneMotionManagerDelegate
 *
 *  Discussion:
 *    Delegate for CMHeadphoneMotionManager.
 */
#if defined(TARGET_OS_XR) && TARGET_OS_XR
COREMOTION_EXPORT API_AVAILABLE(macos(14.0), ios(14.0)) API_UNAVAILABLE(xros)
#else
COREMOTION_EXPORT API_AVAILABLE(macos(14.0), ios(14.0))
#endif // defined(TARGET_OS_XR) && TARGET_OS_XR
@protocol CMHeadphoneMotionManagerDelegate<NSObject>

@optional

/*
 *  headphoneMotionManagerDidConnect:
 *
 *  Discussion:
 *    Invoked when a headphone is connected. Execution of the delegate callback occurs on the operation queue used to
 *    deliver the device motion updates. The main thread is used if the queue was not specified.
 */
- (void)headphoneMotionManagerDidConnect:(CMHeadphoneMotionManager *)manager;

/*
 *  headphoneMotionManagerDidDisconnect:
 *
 *  Discussion:
 *    Invoked when a headphone is disconnected. Execution of the delegate callback occurs on the operation queue used to
 *    deliver the device motion updates. The main thread is used if the queue was not specified.
 */
- (void)headphoneMotionManagerDidDisconnect:(CMHeadphoneMotionManager *)manager;

@end

NS_ASSUME_NONNULL_END
