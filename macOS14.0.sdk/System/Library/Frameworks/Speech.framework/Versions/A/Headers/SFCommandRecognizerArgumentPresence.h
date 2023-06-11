//
//  SFCommandRecognizerArgumentPresence.h
//  Speech
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <stdint.h>

NS_SWIFT_SENDABLE
typedef NS_ENUM(int8_t, SFCommandRecognizerArgumentPresence) {
    SFCommandRecognizerArgumentPresencePresentAndDelimited = 0,
    SFCommandRecognizerArgumentPresencePresentMaybeIncomplete = 1,
    SFCommandRecognizerArgumentPresenceMissingMaybeExpected = 2,
    SFCommandRecognizerArgumentPresenceMissing = 3
} API_AVAILABLE(macos(14), ios(17), macCatalyst(17));
