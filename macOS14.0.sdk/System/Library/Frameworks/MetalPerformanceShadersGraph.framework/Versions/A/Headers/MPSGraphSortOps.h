//
//  MPSGraphSortOps.h
//  MPSGraph
//
//  Created by Matteo Franciolini on 6/30/22.
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#ifndef MPSGraphSortOps_h
#define MPSGraphSortOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphSortOps)

/// Sort the elements of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension over which you sort the tensor
///   - descending: if true, reverse the sort direction
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) sortWithTensor:(MPSGraphTensor *) tensor
                              axis:(NSInteger) axis
                        descending:(BOOL) descending
                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( sort(_:axis:descending:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Sort the elements of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension over which you sort the tensor
///   - descending: if true, reverse the sort direction
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) sortWithTensor:(MPSGraphTensor *) tensor
                        axisTensor:(MPSGraphTensor *) axisTensor
                        descending:(BOOL) descending
                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( sort(_:axisTensor:descending:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Sort the elements of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension over which you sort the tensor
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) sortWithTensor:(MPSGraphTensor *) tensor
                              axis:(NSInteger) axis
                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( sort(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Sort the elements of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension over which you sort the tensor
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) sortWithTensor:(MPSGraphTensor *) tensor
                        axisTensor:(MPSGraphTensor *) axisTensor
                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( sort(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the indices that sort the elements of an input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension over which you sort the tensor
///   - descending: if true, reverse the sort direction
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object with 32-bit integer data type
-(MPSGraphTensor *) argSortWithTensor:(MPSGraphTensor *) tensor
                                 axis:(NSInteger) axis
                           descending:(BOOL) descending
                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( argSort(_:axis:descending:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Compute the indices that sort the elements of an input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension over which you sort the tensor
///   - descending: if true, reverse the sort direction
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object with 32-bit integer data type
-(MPSGraphTensor *) argSortWithTensor:(MPSGraphTensor *) tensor
                           axisTensor:(MPSGraphTensor *) axisTensor
                           descending:(BOOL) descending
                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( argSort(_:axisTensor:descending:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Compute the indices that sort the elements of an input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension over which you sort the tensor
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object with 32-bit integer data type
-(MPSGraphTensor *) argSortWithTensor:(MPSGraphTensor *) tensor
                                 axis:(NSInteger) axis
                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( argSort(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Compute the indices that sort the elements of an input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension over which you sort the tensor
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object with 32-bit integer data type
-(MPSGraphTensor *) argSortWithTensor:(MPSGraphTensor *) tensor
                           axisTensor:(MPSGraphTensor *) axisTensor
                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( argSort(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphArgSortOps_h */
