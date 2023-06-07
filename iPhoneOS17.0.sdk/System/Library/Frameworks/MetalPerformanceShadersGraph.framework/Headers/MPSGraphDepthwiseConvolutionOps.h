//
//  MPSGraphDepthwiseConvolutionOps.h
//  MPSGraph
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#ifndef MPSGraphDepthwiseConvolutionOps_h
#define MPSGraphDepthwiseConvolutionOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines a 2d depthwise convolution operation.
MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraphDepthwiseConvolution2DOpDescriptor : MPSGraphObject<NSCopying>

/// Defines stride for X (Width) dimension. Default value: 1.
@property (readwrite, nonatomic) NSUInteger strideInX;
/// Defines stride for Y (Height) dimension. Default value: 1.
@property (readwrite, nonatomic) NSUInteger strideInY;
/// Defines dilation rate for X (Width) dimension. Default value: 1.
@property (readwrite, nonatomic) NSUInteger dilationRateInX;
/// Defines dilation rate for Y (Height) dimension. Default value: 1.
@property (readwrite, nonatomic) NSUInteger dilationRateInY;


/// Defines explicit padding value for X (Width) dimension to add before the data. Default value: 0.
@property (readwrite, nonatomic) NSUInteger paddingLeft;
/// Defines explicit padding value for X (Width) dimension to add after the data. Default value: 0.
@property (readwrite, nonatomic) NSUInteger paddingRight;
/// Defines explicit padding value for Y (Height) dimension to add before the data. Default value: 0.
@property (readwrite, nonatomic) NSUInteger paddingTop;
/// Defines explicit padding value for Y (Height) dimension to add after the data. Default value: 0.
@property (readwrite, nonatomic) NSUInteger paddingBottom;

/// Defines what kind of padding to apply to operation.
/// Default value: ``MPSGraphPaddingStyleExplicit``.
@property (readwrite, nonatomic) MPSGraphPaddingStyle paddingStyle;
/// Defines the data layout of the input data (in forward pass). See: ``MPSGraphTensorNamedDataLayout``.
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout dataLayout;
/// Defines the data layout of the weights. See: ``MPSGraphTensorNamedDataLayout``.
/// NOTE: 'O' index is channel multiplier index
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout weightsLayout;

/// Creates a 2d depthwise convolution descriptor with given values.
///
/// - Parameters:
///   - strideInX: See ``strideInX`` property.
///   - strideInY: See ``strideInY`` property.
///   - dilationRateInX: See ``dilationRateInX`` property.
///   - dilationRateInY: See ``dilationRateInY`` property.
///   - paddingLeft: See ``paddingLeft`` property.
///   - paddingRight: See ``paddingRight`` property.
///   - paddingTop: See ``paddingTop`` property.
///   - paddingBottom: See ``paddingBottom`` property.
///   - paddingStyle: See ``paddingStyle`` property.
///   - dataLayout: See ``dataLayout`` property.
///   - weightsLayout: See ``weightsLayout`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithStrideInX:(NSUInteger) strideInX
                                       strideInY:(NSUInteger) strideInY
                                 dilationRateInX:(NSUInteger) dilationRateInX
                                 dilationRateInY:(NSUInteger) dilationRateInY
                                     paddingLeft:(NSUInteger) paddingLeft
                                    paddingRight:(NSUInteger) paddingRight
                                      paddingTop:(NSUInteger) paddingTop
                                   paddingBottom:(NSUInteger) paddingBottom
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// Creates a 2d depthwise convolution descriptor with given properties and default values.
///
/// - Parameters:
///   - dataLayout: See ``dataLayout`` property.
///   - weightsLayout: See ``weightsLayout`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithDataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                    weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// Sets the explicit padding values and sets ``paddingStyle`` to ``MPSGraphPaddingStyleExplicit``
///
/// - Parameters:
///   - paddingLeft: See ``paddingLeft`` property.
///   - paddingRight: See ``paddingRight`` property.
///   - paddingTop: See ``paddingTop`` property.
///   - paddingBottom: See ``paddingBottom`` property.
-(void) setExplicitPaddingWithPaddingLeft:(NSUInteger) paddingLeft
                             paddingRight:(NSUInteger) paddingRight
                               paddingTop:(NSUInteger) paddingTop
                            paddingBottom:(NSUInteger) paddingBottom;
@end


/// Defines a 3d depthwise convolution operation.
MPS_CLASS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))
@interface MPSGraphDepthwiseConvolution3DOpDescriptor : MPSGraphObject<NSCopying>

/// Defines strides for spatial dimensions. Must be three numbers, one for each spatial dimension, fastest running index last.
/// Default value: `@[ @1, @1, @1 ]`
@property (readwrite, nonatomic, copy) NSArray<NSNumber *> * _Nonnull   strides;

/// Defines dilation rates for spatial dimensions. Must be three numbers, one for each spatial dimension, fastest running index last.
/// Default value: `@[ @1, @1, @1 ]`
@property (readwrite, nonatomic, copy) NSArray<NSNumber *> * _Nonnull   dilationRates;

/// Defines padding values for spatial dimensions. Must be six numbers, two for each spatial dimension.
/// For example ``paddingValues[0]`` defines the explicit padding
/// amount before the first spatial dimension (slowest running index of spatial dimensions), 
/// ``paddingValues[1]`` defines the padding amount after the first spatial dimension etc.
/// Use only with ``paddingStyle = MPSGraphPaddingStyleExplicit``.
/// Default value: `@[ @0, @0, @0, @0, @0, @0 ]`
@property (readwrite, nonatomic, copy) NSArray<NSNumber *> * _Nonnull   paddingValues;

/// Defines what kind of padding to apply to operation. 
/// Default value: ``MPSGraphPaddingStyleExplicit``
@property (readwrite, nonatomic) MPSGraphPaddingStyle paddingStyle;

/// Defines which axis contains the channels in the input and the weights, within 
/// the 4d tile of the last dimensions. For example the value of `-1`
/// corresponds to `NDHWC`, `NHWC` layouts. This allows the placement
/// of the channel index anywhere within the last 4 dimensions of the tensor. In case your
/// weights are in a different layout it is recommended that you bring them to the same layout
/// as inputs using transposes or permutations. 
/// Default value: `-4`, corresponds to `NCDHW` and `CDHW` layouts.
@property (readwrite, nonatomic) NSInteger channelDimensionIndex;

/// Creates a 3d depthwise convolution descriptor with given values.
///
/// - Parameters:
///   - strides: See ``strides`` property.
///   - dilationRates: See ``dilationRates`` property.
///   - paddingValues: See ``paddingValues`` property.
///   - paddingStyle: See ``paddingStyle`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithStrides:(NSArray<NSNumber *> * _Nonnull) strides
                                 dilationRates:(NSArray<NSNumber *> * _Nonnull) dilationRates
                                 paddingValues:(NSArray<NSNumber *> * _Nonnull) paddingValues
                                  paddingStyle:(MPSGraphPaddingStyle) paddingStyle;

/// Creates a 3d depthwise convolution descriptor with default values.
///
/// - Parameters:
///   - paddingStyle: See ``paddingStyle`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithPaddingStyle:(MPSGraphPaddingStyle) paddingStyle;

@end

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphDepthwiseConvolutionOps)

/// Creates a 2d depthwise convolution operation and returns the result tensor.
///
/// - Parameters:
///   - source: 2d Image source as tensor - must be of rank=4. The layout is defined by ``descriptor.dataLayout``.
///   - weights: Weights tensor, must be rank=4. The layout is defined by ``descriptor.weightsLayout``.
///   - descriptor: Specifies strides, dilation rates, paddings and layouts.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution2DWithSourceTensor:(MPSGraphTensor *) source
                                             weightsTensor:(MPSGraphTensor *) weights
                                                descriptor:(MPSGraphDepthwiseConvolution2DOpDescriptor *) descriptor
                                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution2D(_:weights:descriptor:name:) );

/// Creates a 2d depthwise convolution gradient for data operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradient: 2d input gradient tensor - must be of rank=4. The layout is defined by ``descriptor.dataLayout``.
///   - weights: Weights tensor, must be rank=4. The layout is defined by ``descriptor.weightsLayout``.
///   - outputShape: Shape of the οutput tensor (and therefore input tensor of forward pass).
///   - descriptor: Specifies strides, dilation rates, paddings and layouts.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution2DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                                   weightsTensor:(MPSGraphTensor *) weights
                                                                     outputShape:(MPSShape *) outputShape
                                                                      descriptor:(MPSGraphDepthwiseConvolution2DOpDescriptor *) descriptor
                                                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution2DDataGradient(_:weights:outputShape:descriptor:name:) );

/// Creates a 2d depthwise convolution gradient for weights operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradient: 2d input gradient tensor - must be of rank=4. The layout is defined by ``descriptor.dataLayout``.
///   - source: 2d Image source as tensor - must be of rank=4. The layout is defined by ``descriptor.dataLayout``.
///   - outputShape: Shape of the οutput tensor (and therefore weight tensor of forward pass).
///   - descriptor: Specifies strides, dilation rates, paddings and layouts.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution2DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                                       sourceTensor:(MPSGraphTensor *) source
                                                                        outputShape:(MPSShape *) outputShape
                                                                         descriptor:(MPSGraphDepthwiseConvolution2DOpDescriptor *) descriptor
                                                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution2DWeightsGradient(_:source:outputShape:descriptor:name:));

#pragma mark - 3D Depthwise convolution

/// Creates a 3d depthwise convolution operation and returns the result tensor.
///
/// Works exactly like depthwise convolution2d, but in three dimensions. Supports different layouts with
/// the ``channelDimensionIndex`` property. If your weights need a different layout
/// add a permute operation on them before this operation.
///
/// - Parameters:
///   - source: 3d Image source as tensor - must be at least rank=4 (CDHW when channelDimensionIndex = -4).
///   - weights: Weights tensor, must be rank=4 - axes are interpreted as CDHW when channelDimensionIndex = -4 .
///   - descriptor: Specifies strides, dilation rates and paddings.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution3DWithSourceTensor:(MPSGraphTensor *) source
                                             weightsTensor:(MPSGraphTensor *) weights
                                                descriptor:(MPSGraphDepthwiseConvolution3DOpDescriptor* _Nonnull) descriptor
                                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution3D(_:weights:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a 3d depthwise convolution gradient for data operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradient: 3d input gradient tensor - must be at least rank=4 (CDHW).
///   - weights: Weights tenstor, must be rank=4 - axes are interpreted as CDHW.
///   - outputShape: Shape of the οutput tensor (and therefore input tensor of forward pass).
///   - descriptor: Specifies strides, dilation rates and paddings.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution3DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                                   weightsTensor:(MPSGraphTensor *) weights
                                                                     outputShape:(MPSShape * _Nullable) outputShape
                                                                      descriptor:(MPSGraphDepthwiseConvolution3DOpDescriptor* _Nonnull) descriptor
                                                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution3DDataGradient(_:weights:outputShape:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a 3d depthwise convolution gradient for weights operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradient: 3d input gradient tensor - must be at least rank=4 (NCDHW).
///   - source: Forward pass 3d Image source as tensor - must be at least rank=4 (NCDHW).
///   - outputShape: Shape of the οutput tensor (and therefore weight tensor of forward pass).
///   - descriptor: Specifies strides, dilation rates and paddings.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) depthwiseConvolution3DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                                       sourceTensor:(MPSGraphTensor *) source
                                                                        outputShape:(MPSShape *) outputShape
                                                                         descriptor:(MPSGraphDepthwiseConvolution3DOpDescriptor *) descriptor
                                                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( depthwiseConvolution3DWeightsGradient(_:source:outputShape:descriptor:name:));

@end

NS_ASSUME_NONNULL_END


#endif /* MPSGraphDepthwiseConvolutionOps_h */
