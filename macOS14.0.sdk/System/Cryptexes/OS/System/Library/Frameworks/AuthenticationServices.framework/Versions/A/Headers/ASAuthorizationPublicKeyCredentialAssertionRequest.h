// Copyright © 2020 Apple Inc. All rights reserved.

#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialConstants.h>
#import <Foundation/Foundation.h>

@protocol ASAuthorizationPublicKeyCredentialDescriptor;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(12.0), ios(15.0), tvos(16.0)) API_UNAVAILABLE(watchos)
@protocol ASAuthorizationPublicKeyCredentialAssertionRequest <NSObject, NSSecureCoding, NSCopying>

/*! @abstract The challenge to use when signing the request.
 */
@property (nonatomic, copy) NSData *challenge;

/*! @abstract The Relying Party identifier used to scope this request.
 */
@property (nonatomic, copy) NSString *relyingPartyIdentifier;

/*! @abstract A list of credentials to allow for this request. If this list is nonempty, only credentials matching the provided descriptors can be used to sign in.
 */
@property (nonatomic, copy) NSArray<id<ASAuthorizationPublicKeyCredentialDescriptor>> *allowedCredentials;

/*! @abstract A preference for whether the authenticator should attempt to verify that it is being used by its owner, such as through a PIN or biometrics.
 */
@property (nonatomic) ASAuthorizationPublicKeyCredentialUserVerificationPreference userVerificationPreference;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
