// Copyright © 2020 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(12.0), ios(15.0), tvos(16.0)) API_UNAVAILABLE(watchos)
@protocol ASAuthorizationPublicKeyCredentialDescriptor <NSObject, NSSecureCoding, NSCopying>

/*! @abstract An identifier that uniquely identifies a specific credential.
 */
@property (nonatomic, copy) NSData *credentialID;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
