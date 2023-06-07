#if !__has_include(<PassKitCore/PKPayLaterUtilities.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKPayLaterUtilities.h
//    PassKit
//
//  Copyright © 2023 Apple, Inc. All rights reserved.
//

#ifndef __PKPAYLATERUTILITIES_H
#define __PKPAYLATERUTILITIES_H

#import <TargetConditionals.h>

#if TARGET_OS_IOS && !TARGET_OS_MACCATALYST

typedef NS_ENUM(NSUInteger, PKPayLaterDisplayStyle) {
    PKPayLaterDisplayStyleStandard = 0, /// The Standard Merchandising Widget
    PKPayLaterDisplayStyleBadge, /// Displays a simple Pay badge with the pay later info graphic
    PKPayLaterDisplayStyleCheckout, /// To be displayed inside of a toggleable checkout view
    PKPayLaterDisplayStylePrice, /// To be shown beneath a products price
} API_AVAILABLE(ios(17.0)) API_UNAVAILABLE(macos, watchos, tvos);

typedef NS_ENUM(NSUInteger, PKPayLaterAction) {
    PKPayLaterActionLearnMore = 0, /// Displays a simple info sheet on the learn more details of pay later
    PKPayLaterActionCalculator, /// The Standard Price breakdown calculator for pay later, that features an interactive calculator
} API_AVAILABLE(ios(17.0)) API_UNAVAILABLE(macos, watchos, tvos);

@interface PKPayLaterUtilities : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Checks if a Pay Later Merchandising information can be displayed for the given values
/// - Parameters:
///   - amount: The users bag price or item pricing
///   - locale: The localization data for the how the returned configuration will be
///   - completion: The block that is called when the eligibility result is calculated
+ (void)validateWithAmount:(NSDecimalNumber *)amount
                    locale:(NSLocale *)locale
                completion:(void(^)(BOOL eligible))completion NS_REFINED_FOR_SWIFT;

@end

#endif // TARGET_OS_IOS && !TARGET_OS_MACCATALYST

#endif // __PKPAYLATERVIEW_H

#else
#import <TargetConditionals.h>
#import <PassKitCore/PKPayLaterUtilities.h>
#endif