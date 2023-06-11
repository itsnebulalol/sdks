/*
 * NERelay.h
 *
 * Copyright (c) 2022 Apple Inc.
 * All rights reserved.
 */

#ifndef __NE_INDIRECT__
#error "Please import the NetworkExtension module instead of this file directly."
#endif


NS_ASSUME_NONNULL_BEGIN

/*!
 * @interface NERelay
 * @discussion The NERelay class declares the programmatic interface of an object that
 * 			manages the details of a relay's configuration, such as authentication and URL details.
 *
 * Instances of this class are thread safe.
 */
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0)) API_UNAVAILABLE(watchos)
@interface NERelay : NSObject <NSCopying,NSSecureCoding>

/*!
 * @property HTTP3RelayURL
 * @discussion The URL of the relay accessible over HTTP/3.
 */
@property (copy, nullable) NSURL *HTTP3RelayURL;

/*!
 * @property HTTP2RelayURL
 * @discussion The URL of the relay accessible over HTTP/2.
 */
@property (copy, nullable) NSURL *HTTP2RelayURL;

/*!
 * @property additionalHTTPHeaderFields
 * @discussion Additional HTTP header field names and values to be added to all relay requests.
 */
@property (copy) NSDictionary<NSString *, NSString *> *additionalHTTPHeaderFields;

/*!
 * @property rawPublicKeys
 * @discussion TLS 1.3 raw public keys to use to authenticate the relay servers.
 */
@property (copy, nullable) NSArray<NSData *> *rawPublicKeys;

/*!
 * @property identityData
 * @discussion The PKCS12 data for the relay client authentication. The value is a NSData in PKCS12 format.
 */
@property (copy, nullable) NSData *identityData;

/*!
 * @property identityDataPassword
 * @discussion The password to be used to decrypt the PKCS12 identity data.
 */
@property (copy, nullable) NSString *identityDataPassword;

@end

NS_ASSUME_NONNULL_END
