//
//  MPSGraphActivationOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 12/13/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphActivationOps_h
#define MPSGraphActivationOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphActivationOps)

/// Computes a ReLU (rectified linear activation unit) function with an input tensor.
/// The operation is:  f(x) = max(x, 0).
/// 
/// - Parameters:
///   - tensor: An input tensor.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object.
-(MPSGraphTensor *) reLUWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Computes gradient of ReLU  (rectified linear activation unit) function using the incoming gradient.
/// 
/// - Parameters:
///   - gradient: The incoming gradient tensor.
///   - source: The input tensor from forward pass.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object.
-(MPSGraphTensor *) reLUGradientWithIncomingGradient:(MPSGraphTensor *) gradient
                                        sourceTensor:(MPSGraphTensor *) source
                                                name:(NSString * _Nullable) name;

/// Computes sigmoid operation on an input tensor. 
/// 
/// - Parameters:
///   - tensor: An input tensor.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object.
-(MPSGraphTensor *) sigmoidWithTensor:(MPSGraphTensor *) tensor
                                 name:(NSString * _Nullable) name;

/// Computes gradient of sigmoid function using the incoming gradient tensor.
/// 
/// - Parameters:
///   - gradient: The incoming gradient tensor.
///   - source: The input tensor.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor *) sigmoidGradientWithIncomingGradient:(MPSGraphTensor *) gradient
                                           sourceTensor:(MPSGraphTensor *) source
                                                   name:(NSString * _Nullable) name;

/// Computes a softmax function on an input tensor along a specified axis.
/// 
/// - Parameters:
///   - tensor: An input tensor.
///   - axis: An axis along which softmax is computed.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor *) softMaxWithTensor:(MPSGraphTensor *) tensor
                                 axis:(NSInteger) axis
                                 name:(NSString * _Nullable) name;

/// Computes the gradient of the softmax function along a specified axis using the incoming gradient tensor.
/// 
/// - Parameters:
///   - gradient: The incoming gradient tensor.
///   - source: The input tensor.
///   - axis: An axis along which softmax is computed.
///   - name: A name for the operation
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor *) softMaxGradientWithIncomingGradient:(MPSGraphTensor *) gradient
                                           sourceTensor:(MPSGraphTensor *) source
                                                   axis:(NSInteger) axis
                                                   name:(NSString * _Nullable) name;

/// Computes leaky ReLU (rectified linear unit activation) on an input tensor.
/// The operation is: f(x) = max(x, alpha).
/// 
/// - Parameters:
///   - tensor: An input tensor.
///   - alpha: A scalar value alpha used by all elements in the input tensor.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor*)leakyReLUWithTensor:(MPSGraphTensor* _Nonnull)tensor
                                alpha:(double) alpha
                                 name:(NSString* _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Computes leaky ReLU (rectified linear unit activation) on an input tensor. 
/// The operation is: f(x) = max(x, alpha).
/// This operation supports broadcasting with the alpha tensor.
/// 
/// - Parameters:
///   - tensor: An input tensor.
///   - alpha: An alpha tensor.
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor*)leakyReLUWithTensor:(MPSGraphTensor* _Nonnull) tensor
                          alphaTensor:(MPSGraphTensor* _Nonnull) alphaTensor
                                 name:(NSString* _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Computes gradient of leaky ReLU (rectified linear unit activation).
/// Supports broadcasting with alpha tensor.
/// 
/// - Parameters:
///   - gradient: The incoming gradient tensor.
///   - source: The input tensor in forward pass.
///   - alpha: An alpha tensor
///   - name: A name for the operation.
/// - Returns: A valid ``MPSGraphTensor`` object
-(MPSGraphTensor*)leakyReLUGradientWithIncomingGradient:(MPSGraphTensor *) gradient
                                           sourceTensor:(MPSGraphTensor* _Nonnull) source
                                            alphaTensor:(MPSGraphTensor* _Nonnull) alphaTensor
                                                   name:(NSString* _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphActivationOps_h */
