//
//  AXSettings.h
//  Accessibility
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accessibility/AXFoundation.h>

NS_ASSUME_NONNULL_BEGIN

// Returns whether the system setting for displaying animations in an animated image is on or off.
AX_EXTERN BOOL AXAnimatedImagesEnabled(void) API_AVAILABLE(ios(17.0), macos(14.0), tvos(17.0), watchos(10.0));
AX_EXTERN NSNotificationName const AXAnimatedImagesEnabledDidChangeNotification API_AVAILABLE(ios(17.0), macos(14.0), tvos(17.0), watchos(10.0));

#if TARGET_OS_XR
// When true, indicates that the user prefers alternatives to camera anchored content
// Alternate anchors should be used for most camera anchored UI, such as world anchors
AX_EXTERN BOOL AXPrefersCameraAnchorAlternative(void) API_AVAILABLE(xros(1.0));
AX_EXTERN NSNotificationName const AXPrefersCameraAnchorAlternativeDidChangeNotification API_AVAILABLE(xros(1.0));
#endif

NS_ASSUME_NONNULL_END
