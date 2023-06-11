//
//  ASPasskeyCredentialRequest.h
//  AuthenticationServices Framework
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <AuthenticationServices/ASAuthorizationPublicKeyCredentialConstants.h>
#import <AuthenticationServices/ASCredentialRequest.h>
#import <AuthenticationServices/ASPasskeyCredentialIdentity.h>

NS_ASSUME_NONNULL_BEGIN

/*! @class This class encapsulates a password assertion request made to a credential provider extension.
 */
AS_EXTERN API_AVAILABLE(ios(17.0), macos(14.0)) API_UNAVAILABLE(tvos, watchos)
@interface ASPasskeyCredentialRequest : NSObject <ASCredentialRequest>

- (instancetype)init NS_UNAVAILABLE;

/*! @abstract Initializes an instance of ASPasskeyCredentialRequest.
 @param credentialIdentity credential identity to used for this request.
 @param clientDataHash the client data to be signed for this assertion request.
 @param userVerificationPreference user verification preference setting of this assertion request.
 */
- (instancetype)initWithCredentialIdentity:(ASPasskeyCredentialIdentity *)credentialIdentity clientDataHash:(NSData *)clientDataHash userVerificationPreference:(ASAuthorizationPublicKeyCredentialUserVerificationPreference)userVerificationPreference;

/*! @abstract Creates and initializes an instance of ASPasskeyCredentialRequest.
 @param credentialIdentity credential identity to used for this request. 
 @param clientDataHash the client data to be signed for this assertion request.
 @param userVerificationPreference user verification preference setting of this assertion request.
 */
+ (instancetype)requestWithCredentialIdentity:(ASPasskeyCredentialIdentity *)credentialIdentity clientDataHash:(NSData *)clientDataHash userVerificationPreference:(ASAuthorizationPublicKeyCredentialUserVerificationPreference)userVerificationPreference;

/*! @abstract Hash of client data for credential provider to sign as part of the assertion/registration operation.
 */
@property (nonatomic, readonly) NSData *clientDataHash;

/*! @abstract A preference for whether the authenticator should attempt to verify that
 it is being used by its owner, such as through a PIN or biometrics.
 */
@property (nonatomic) ASAuthorizationPublicKeyCredentialUserVerificationPreference userVerificationPreference;

@end

NS_ASSUME_NONNULL_END
