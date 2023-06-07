//
//  CLSActivityItem.h
//  ClassKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <ClassKit/CLSObject.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract      CLSActivityItem is used to gather information about the activity generated by a user.
 */

API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos)
@interface CLSActivityItem : CLSObject

/*!
 @abstract      Title of what this ActivityItem respresents.
 @discussion    This will be the title associated with the activity item in the generated progress report.
 */
@property (nonatomic, copy) NSString *title;

/*!
 @abstract      An identifier that is unique within its owning activity
 @discussion    The identifier can be used to look up existing activityItems in a given activity.
 */
@property (nonatomic, copy, readonly) NSString *identifier;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
