//
//  MPSGraphCumulativeOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 06/12/22.
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#ifndef MPSGraphScanOps_h
#define MPSGraphScanOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphCumulativeOps)

/// Compute the cumulative sum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to zero
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeSumWithTensor:(MPSGraphTensor *) tensor
                                       axis:(NSInteger) axis
                                  exclusive:(BOOL) exclusive
                                    reverse:(BOOL) reverse
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeSum(_:axis:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative sum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to zero
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeSumWithTensor:(MPSGraphTensor *) tensor
                                 axisTensor:(MPSGraphTensor *) axisTensor
                                  exclusive:(BOOL) exclusive
                                    reverse:(BOOL) reverse
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeSum(_:axisTensor:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative sum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeSumWithTensor:(MPSGraphTensor *) tensor
                                       axis:(NSInteger) axis
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeSum(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative sum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeSumWithTensor:(MPSGraphTensor *) tensor
                                 axisTensor:(MPSGraphTensor *) axisTensor
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeSum(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative product of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to one
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeProductWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeProduct(_:axis:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative product of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to one
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeProductWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeProduct(_:axisTensor:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative product of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeProductWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeProduct(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative product of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to one
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeProductWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeProduct(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative minimum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to the largest value of the tensor data type
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMinimumWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMinimum(_:axis:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative minimum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to the largest value of the tensor data type
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMinimumWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMinimum(_:axisTensor:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative minimum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMinimumWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMinimum(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative minimum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to the largest value of the tensor data type
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMinimumWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMinimum(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative maximum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to the lowest value of the tensor data type
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMaximumWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMaximum(_:axis:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative maximum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - exclusive: if true, perform the exclusive cumulative operation, and the first element will be equal to the lowest value of the tensor data type
///   - reverse: if true, reverse the direction of the cumulative operation along the specified axis
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMaximumWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                      exclusive:(BOOL) exclusive
                                        reverse:(BOOL) reverse
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMaximum(_:axisTensor:exclusive:reverse:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative maximum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axis: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMaximumWithTensor:(MPSGraphTensor *) tensor
                                           axis:(NSInteger) axis
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMaximum(_:axis:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Compute the cumulative maximum of the input tensor along a specified axis.
///
/// - Parameters:
///   - tensor: input tensor
///   - axisTensor: the tensor dimension where you compute the cumulative operation
///   - name: name for the operation
/// - Returns: a valid MPSGraphTensor object
-(MPSGraphTensor *) cumulativeMaximumWithTensor:(MPSGraphTensor *) tensor
                                     axisTensor:(MPSGraphTensor *) axisTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( cumulativeMaximum(_:axisTensor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphCumulativeOps_h */
