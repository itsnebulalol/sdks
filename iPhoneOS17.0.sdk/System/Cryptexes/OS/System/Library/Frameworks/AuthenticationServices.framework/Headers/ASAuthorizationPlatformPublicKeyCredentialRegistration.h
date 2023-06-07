// Copyright © 2020 Apple Inc. All rights reserved.

#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialConstants.h>
#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialRegistration.h>
#import <AuthenticationServices/ASCOSEConstants.h>
#import <AuthenticationServices/ASFoundation.h>
#import <Foundation/Foundation.h>


NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(12.0), ios(15.0), tvos(16.0)) API_UNAVAILABLE(watchos)
@interface ASAuthorizationPlatformPublicKeyCredentialRegistration : NSObject <ASAuthorizationPublicKeyCredentialRegistration>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;


@property (nonatomic, readonly) ASAuthorizationPublicKeyCredentialAttachment attachment API_AVAILABLE(macos(13.5), ios(16.6)) API_UNAVAILABLE(tvos, watchos);

@end

NS_HEADER_AUDIT_END(nullability, sendability)
