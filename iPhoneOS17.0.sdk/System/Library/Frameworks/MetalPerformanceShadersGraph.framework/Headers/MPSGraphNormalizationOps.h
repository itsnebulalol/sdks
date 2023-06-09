//
//  MPSGraphNormalizationOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 2/7/20.
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#ifndef MPSGraphNormalizationOps_h
#define MPSGraphNormalizationOps_h

#import <MetalPerformanceShadersGraph/MetalPerformanceShadersGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphNormalizationOps)

/// Create a mean op and return the result tensor
///
/// - Parameters:
///   - axes: A list of axes over which to perform the reduction. The order of dimensions goes from the slowest moving at axis=0 to the fastest moving dimension.
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) meanOfTensor:(MPSGraphTensor *) tensor
                            axes:(NSArray<NSNumber *> *) axes
                            name:(NSString * _Nullable) name;

/// Create a variance op when you already have a precomputed mean and return the result tensor
///
/// - Parameters:
///   - axes: A list of axes over which to perform the reduction such that the order of dimensions goes from the slowest moving at axis=0 to the fastest moving dimension.
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) varianceOfTensor:(MPSGraphTensor *) tensor
                          meanTensor:(MPSGraphTensor *) meanTensor
                                axes:(NSArray<NSNumber *> *) axes
                                name:(NSString * _Nullable) name;

/// Create a variance op and return the result tensor
///
/// - Parameters:
///   - axes: A list of axes over which to perform the reduction. Tthe order of dimensions goes from the slowest moving at axis=0 to the fastest moving dimension.
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) varianceOfTensor:(MPSGraphTensor *) tensor
                                axes:(NSArray<NSNumber *> *) axes
                                name:(NSString * _Nullable) name;

/// Create a batch normalization op and return the result tensor
///
/// The mean and variance tensors should be outputs of meanWithTensor:axes:name and varianceWithTensor:meanTensor:axes:name. 
/// Use the axes parameter to achieve different types of normalizations. 
/// For example (assuming your data is in NxHxWxC format) 
/// Batch normalization: axes = [0, 1, 2] 
/// Instance normalization: axes = [1, 2] 
/// Shapes for gamma and beta must match the input data along at least one dimension and will be broadcast along the rest. 
/// For batch normalization, gamma and beta would typically be 1x1x1xC i.e. one value per channel.
///
/// - Parameters:
///   - tensor: input tensor
///   - mean: mean
///   - variance: variance
///   - gamma: Tensor used to scale the normalized result
///   - beta: Tensor used to bias the normalized result
///   - epsilon: A small value to add to the variance when normalizing the inputs.
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object. 
///
-(MPSGraphTensor *) normalizationWithTensor:(MPSGraphTensor *) tensor
                                 meanTensor:(MPSGraphTensor *) mean
                             varianceTensor:(MPSGraphTensor *) variance
                                gammaTensor:(MPSGraphTensor * _Nullable) gamma
                                 betaTensor:(MPSGraphTensor * _Nullable) beta
                                    epsilon:(float) epsilon
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( normalize(_:mean:variance:gamma:beta:epsilon:name:) );

/// Create a normalization gamma gradient op and return the result tensor
///
/// The mean and variance tensors should be outputs of ``meanWithTensor:axes:name`` and ``varianceWithTensor:meanTensor:axes:name``.
/// Use the axes parameter to achieve different types of normalizations.
/// For example (assuming your data is in `NxHxWxC` format)
/// Batch normalization: axes = [0, 1, 2]
/// Instance normalization: axes = [1, 2]
///
/// - Parameters:
///   - incomingGradientTensor: incoming original resultTensor gradient
///   - sourceTensor: original input source in forward direction
///   - meanTensor: mean tensor
///   - varianceTensor: variance
///   - axes: axes to which were normalized
///   - epsilon: A small value to add to the variance when normalizing the inputs.
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
///
-(MPSGraphTensor *) normalizationGammaGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradientTensor
                                                            sourceTensor:(MPSGraphTensor *) sourceTensor
                                                              meanTensor:(MPSGraphTensor *) meanTensor
                                                          varianceTensor:(MPSGraphTensor *) varianceTensor
                                                           reductionAxes:(NSArray<NSNumber *> *) axes
                                                                 epsilon:(float) epsilon
                                                                    name:(NSString * _Nullable) name;

/// Create a normalization beta gradient op and return the result tensor
///
/// The mean and variance tensors should be outputs of ``meanWithTensor:axes:name`` and ``varianceWithTensor:meanTensor:axes:name``.
/// Use the axes parameter to achieve different types of normalizations.
/// For example (assuming your data is in `NxHxWxC` format)
/// Batch normalization: axes = [0, 1, 2]
/// Instance normalization: axes = [1, 2]
///
/// - Parameters:
///   - incomingGradientTensor: incoming original resultTensor gradient
///   - sourceTensor: original input source in forward direction
///   - axes: axes to which were normalized
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
///
-(MPSGraphTensor *) normalizationBetaGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradientTensor
                                                           sourceTensor:(MPSGraphTensor *) sourceTensor
                                                          reductionAxes:(NSArray<NSNumber *> *) axes
                                                                   name:(NSString * _Nullable) name;
/// Create a normalization input gradient op and return the result tensor
///
/// The mean and variance tensors should be outputs of ``meanWithTensor:axes:name`` and ``varianceWithTensor:meanTensor:axes:name``.
/// Use the axes parameter to achieve different types of normalizations.
/// For example (assuming your data is in `NxHxWxC` format)
/// Batch normalization: axes = [0, 1, 2]
/// Instance normalization: axes = [1, 2]
///
/// - Parameters:
///   - incomingGradientTensor: incoming original resultTensor gradient
///   - sourceTensor: original input source in forward direction
///   - meanTensor: mean tensor
///   - varianceTensor: variance tensor
///   - gamma: gamma tensor
///   - gammaGradient: gammaGradient tensor
///   - betaGradient: betaGradient tensor
///   - axes: axes to which were normalized
///   - epsilon: A small value to add to the variance when normalizing the inputs.
///   - name: name for the placeholder operation
///
-(MPSGraphTensor *) normalizationGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradientTensor
                                                       sourceTensor:(MPSGraphTensor *) sourceTensor
                                                         meanTensor:(MPSGraphTensor *) meanTensor
                                                     varianceTensor:(MPSGraphTensor *) varianceTensor
                                                        gammaTensor:(MPSGraphTensor * _Nullable) gamma
                                                gammaGradientTensor:(MPSGraphTensor * _Nullable) gammaGradient
                                                 betaGradientTensor:(MPSGraphTensor * _Nullable) betaGradient
                                                      reductionAxes:(NSArray<NSNumber *> *) axes
                                                            epsilon:(float) epsilon
                                                               name:(NSString * _Nullable) name;

@end

NS_ASSUME_NONNULL_END


#endif /* MPSGraphNormalizationOps_h */

