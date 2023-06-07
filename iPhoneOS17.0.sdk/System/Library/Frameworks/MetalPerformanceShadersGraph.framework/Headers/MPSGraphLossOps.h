//
//  MPSGraphLossOps.h
//  MPSGraph
//
//  Created on 3/27/20.
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#ifndef MPSGraphLossOps_h
#define MPSGraphLossOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines the type of the reduction the graph applies in the loss operations.
typedef NS_ENUM(uint64_t, MPSGraphLossReductionType)
{
    /// No Reductions
    MPSGraphLossReductionTypeNone                                            MPS_ENUM_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0)) MPS_SWIFT_NAME(none) =   0L,
    /// No Reductions
    MPSGraphLossReductionTypeAxis                                            MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(axis) =   MPSGraphLossReductionTypeNone,
    /// Reduce sum down to a scalar.
    MPSGraphLossReductionTypeSum                                             MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                      =   1L,
    /// Reduce mean down to a scalar.
    MPSGraphLossReductionTypeMean                                            MPS_ENUM_AVAILABLE_STARTING(macos(12.0),  ios(15.0), tvos(15.0))                      =   2L,
};

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphLossOps)

/// Creates a softmax cross entropy loss operation and returns the result tensor.
/// This computes: `loss = reduction( - labels*ln( softmax(source) ))`,
/// where `sotfmax(source) = exp(source) / sum( exp(source) )`, where the sum is computed over ``axis``.
///
/// - Parameters:
///   - sourceTensor: The source tensor.
///   - labelsTensor: The labels tensor.
///   - axis: Axis over which the softmax reduction happens.
///   - reductionType: The type of reduction MPSGraph uses to reduce across all other axes.
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) softMaxCrossEntropyWithSourceTensor:(MPSGraphTensor *) sourceTensor
                                           labelsTensor:(MPSGraphTensor *) labelsTensor
                                                   axis:(NSInteger) axis
                                          reductionType:(MPSGraphLossReductionType) reductionType
                                                   name:(NSString * _Nullable) name
MPS_SWIFT_NAME( softMaxCrossEntropy(_:labels:axis:reuctionType:name:) );

/// Creates a softmax cross entropy loss operation and returns the result tensor.
///
/// - Parameters:
///   - gradientTensor: gradientTensor - Note: in most cases you want to pass in the initial gradient tensor, which is a constant tensor with value one.
///   - sourceTensor: The source tensor.
///   - labelsTensor: The labels tensor.
///   - axis: Axis over which loss reduction happens.
///   - reductionType: The type of reduction MPSGraph uses to reduce across all other axes.
///   - name: Name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) softMaxCrossEntropyGradientWithIncomingGradientTensor:(MPSGraphTensor *) gradientTensor
                                                             sourceTensor:(MPSGraphTensor *) sourceTensor
                                                             labelsTensor:(MPSGraphTensor *) labelsTensor
                                                                     axis:(NSInteger) axis
                                                            reductionType:(MPSGraphLossReductionType) reductionType
                                                                     name:(NSString * _Nullable) name
MPS_SWIFT_NAME( softMaxCrossEntropyGradient(_:source:labels:axis:reuctionType:name:) );

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphLossOps_h */
