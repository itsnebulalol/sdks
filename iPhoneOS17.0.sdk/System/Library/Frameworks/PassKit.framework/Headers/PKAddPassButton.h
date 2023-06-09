#if !__has_include(<PassKitUI/PKAddPassButton.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKAddPassButton.h
//    PassKit
//
//  Copyright © 2015 Apple, Inc. All rights reserved.
//

#ifndef __PKADDPASSBUTTON_H
#define __PKADDPASSBUTTON_H

#import <TargetConditionals.h>

#if TARGET_OS_IOS

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PKAddPassButtonStyle) {
    PKAddPassButtonStyleBlack = 0,
    PKAddPassButtonStyleBlackOutline,
} API_AVAILABLE(ios(9.0));

// Use PKAddPassButton to show an "Add to Apple Wallet" button. Two types are available for barcode or payment passes.
// Refer to the Apple Pay developer documentation for more information on how to use this class
API_AVAILABLE(ios(9.0))
@interface PKAddPassButton : UIButton

+ (instancetype)addPassButtonWithStyle:(PKAddPassButtonStyle)addPassButtonStyle;

- (instancetype)initWithAddPassButtonStyle:(PKAddPassButtonStyle)style NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) PKAddPassButtonStyle addPassButtonStyle UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END

#endif
#endif

#else
#if !TARGET_OS_OSX 
#import <TargetConditionals.h>
#import <PassKitUI/PKAddPassButton.h>
#endif
#endif