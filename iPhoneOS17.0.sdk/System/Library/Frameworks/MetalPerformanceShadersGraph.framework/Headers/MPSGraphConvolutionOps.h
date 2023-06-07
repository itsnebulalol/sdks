//
//  MPSGraphConvolutionOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 12/20/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphConvolutionOps_h
#define MPSGraphConvolutionOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

/// Descriptor for properties of convolution.
/// It is used to create 2D convolution operation.
MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraphConvolution2DOpDescriptor : MPSGraphObject<NSCopying>

/// stride in `x` or width dimension.
@property (readwrite, nonatomic) NSUInteger strideInX;
/// stride in `y` or height dimension.
@property (readwrite, nonatomic) NSUInteger strideInY;
/// dilation in `x` or width dimension.
@property (readwrite, nonatomic) NSUInteger dilationRateInX;
/// dilation in `y` or height dimension.
@property (readwrite, nonatomic) NSUInteger dilationRateInY;
/// padding in `x` or width dimension on left side.
@property (readwrite, nonatomic) NSUInteger paddingLeft;
/// padding in `x` or width dimension on right side.
@property (readwrite, nonatomic) NSUInteger paddingRight;
/// padding in `y` or height dimension at top.
@property (readwrite, nonatomic) NSUInteger paddingTop;
/// padding in `y` or height dimension at bottom.
@property (readwrite, nonatomic) NSUInteger paddingBottom;
/// padding style applied on source tensor. If paddingStyle is `MPSGraphPaddingStyleExplicit`, paddingLeft, laddingRight, paddingTop,
/// paddingBottom must to be specified. This is symbolic padding on input tensor. For all other padding styles,
/// paddings on left, right, top and bottom are computed internally and need not be specified.
@property (readwrite, nonatomic) MPSGraphPaddingStyle paddingStyle;
/// layout of source tensor. Convolution operation uses this to interpret data in source tensor i.e. order of named dimensions
/// e.g. `batch x channels x width x height` for `NCHW` layout
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout dataLayout;
/// layout of weights tensor. Convolution operation uses this to interpret data in weights tensor i.e. order of named dimensions
/// e.g. `outputChannels x inputChannels x kernelHeight x kernelWidth` for `OIHW`.
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout weightsLayout;
/// number of groups in convolution. Input and output feature channels are divided into groups and
/// input channels in a group are only connected to output channels in corresponding group.
/// Number of weights are `outputFeatureChannels x inputFeatureChannels/groups x kernelWidth x kernelHeight`
@property (readwrite, nonatomic) NSUInteger groups;

/// creates convolution descriptor with given values for parameters.
/// - Parameters:
///   - strideInX: See ``strideInX`` property.
///   - strideInY: See ``strideInY`` property.
///   - dilationRateInX: See ``dilationRateInX`` property.
///   - dilationRateInY: See ``dilationRateInY`` property.
///   - groups: See ``groups`` property.
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
                                          groups:(NSUInteger) groups
                                     paddingLeft:(NSUInteger) paddingLeft
                                    paddingRight:(NSUInteger) paddingRight
                                      paddingTop:(NSUInteger) paddingTop
                                   paddingBottom:(NSUInteger) paddingBottom
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// creates convolution descriptor with given values for parameters.
/// - Parameters:
///   - strideInX: See ``strideInX`` property.
///   - strideInY: See ``strideInY`` property.
///   - dilationRateInX: See ``dilationRateInX`` property.
///   - dilationRateInY: See ``dilationRateInY`` property.
///   - groups: See ``groups`` property.
///   - paddingStyle: See ``paddingStyle`` property.
///   - dataLayout: See ``dataLayout`` property.
///   - weightsLayout: See ``weightsLayout`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithStrideInX:(NSUInteger) strideInX
                                       strideInY:(NSUInteger) strideInY
                                 dilationRateInX:(NSUInteger) dilationRateInX
                                 dilationRateInY:(NSUInteger) dilationRateInY
                                          groups:(NSUInteger) groups
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// sets values of padding to given values.
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

/// Descriptor for properties of convolution.
/// It is used to create 3D convolution operation.
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
@interface MPSGraphConvolution3DOpDescriptor : MPSGraphObject<NSCopying>

/// stride in `x` or width dimension.
@property (readwrite, nonatomic) NSUInteger strideInX;
/// stride in `y` or height dimension.
@property (readwrite, nonatomic) NSUInteger strideInY;
/// stride in `z` or depth dimension.
@property (readwrite, nonatomic) NSUInteger strideInZ;
/// dilation in `x` or width dimension.
@property (readwrite, nonatomic) NSUInteger dilationRateInX;
/// dilation in `y` or height dimension.
@property (readwrite, nonatomic) NSUInteger dilationRateInY;
/// dilation in `z` or depth dimension.
@property (readwrite, nonatomic) NSUInteger dilationRateInZ;
/// padding in `x` or width dimension on left side.
@property (readwrite, nonatomic) NSUInteger paddingLeft;
/// padding in `x` or width dimension on right side.
@property (readwrite, nonatomic) NSUInteger paddingRight;
/// padding in `y` or height dimension at top.
@property (readwrite, nonatomic) NSUInteger paddingTop;
/// padding in `y` or height dimension at bottom.
@property (readwrite, nonatomic) NSUInteger paddingBottom;
/// padding in `z` or depth dimension in front.
@property (readwrite, nonatomic) NSUInteger paddingFront;
/// padding in `z` or depth dimension in back.
@property (readwrite, nonatomic) NSUInteger paddingBack;
/// padding style applied on source tensor. If paddingStyle is `MPSGraphPaddingStyleExplicit`, paddingLeft, laddingRight, paddingTop,
/// paddingBottom, paddingFront, paddingBack must to be specified. This is symbolic padding on input tensor. For all other padding styles,
/// paddings on left, right, top, bottom, front and back are computed internally and need not be specified.
@property (readwrite, nonatomic) MPSGraphPaddingStyle paddingStyle;
/// layout of source tensor. Convolution operation uses this to interpret data in source tensor i.e. order of named dimensions
/// e.g. `batch x channels x depth x width x height` for `NCDHW` layout
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout dataLayout;
/// layout of weights tensor. Convolution operation uses this to interpret data in weights tensor i.e. order of named dimensions
/// e.g. `outputChannels x inputChannels x kernelDepth x kernelHeight x kernelWidth` for `OIDHW`.
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout weightsLayout;
/// number of groups in convolution. Input and output feature channels are divided into groups and
/// input channels in a group are only connected to output channels in corresponding group.
/// Number of weights are `outputFeatureChannels x inputFeatureChannels/groups x kernelDepth x kernelWidth x kernelHeight`
@property (readwrite, nonatomic) NSUInteger groups;

/// creates convolution descriptor with given values for parameters.
/// - Parameters:
///   - strideInX: See ``strideInX`` property.
///   - strideInY: See ``strideInY`` property.
///   - strideInZ: See ``strideInZ`` property.
///   - dilationRateInX: See ``dilationRateInX`` property.
///   - dilationRateInY: See ``dilationRateInY`` property.
///   - dilationRateInZ: See ``dilationRateInZ`` property.
///   - groups: See ``groups`` property.
///   - paddingLeft: See ``paddingLeft`` property.
///   - paddingRight: See ``paddingRight`` property.
///   - paddingTop: See ``paddingTop`` property.
///   - paddingBottom: See ``paddingBottom`` property.
///   - paddingFront: See ``paddingFront`` property.
///   - paddingBack: See ``paddingBack`` property.
///   - paddingStyle: See ``paddingStyle`` property.
///   - dataLayout: See ``dataLayout`` property.
///   - weightsLayout: See ``weightsLayout`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithStrideInX:(NSUInteger) strideInX
                                       strideInY:(NSUInteger) strideInY
                                       strideInZ:(NSUInteger) strideInZ
                                 dilationRateInX:(NSUInteger) dilationRateInX
                                 dilationRateInY:(NSUInteger) dilationRateInY
                                 dilationRateInZ:(NSUInteger) dilationRateInZ
                                          groups:(NSUInteger) groups
                                     paddingLeft:(NSUInteger) paddingLeft
                                    paddingRight:(NSUInteger) paddingRight
                                      paddingTop:(NSUInteger) paddingTop
                                   paddingBottom:(NSUInteger) paddingBottom
                                    paddingFront:(NSUInteger) paddingFront
                                     paddingBack:(NSUInteger) paddingBack
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// creates convolution descriptor with given values for parameters.
/// - Parameters:
///   - strideInX: See ``strideInX`` property.
///   - strideInY: See ``strideInY`` property.
///   - strideInZ: See ``strideInZ`` property.
///   - dilationRateInX: See ``dilationRateInX`` property.
///   - dilationRateInY: See ``dilationRateInY`` property.
///   - dilationRateInZ: See ``dilationRateInZ`` property.
///   - groups: See ``groups`` property.
///   - paddingStyle: See ``paddingStyle`` property.
///   - dataLayout: See ``dataLayout`` property.
///   - weightsLayout: See ``weightsLayout`` property.
/// - Returns: The descriptor on autoreleasepool.
+(nullable instancetype) descriptorWithStrideInX:(NSUInteger) strideInX
                                       strideInY:(NSUInteger) strideInY
                                       strideInZ:(NSUInteger) strideInZ
                                 dilationRateInX:(NSUInteger) dilationRateInX
                                 dilationRateInY:(NSUInteger) dilationRateInY
                                 dilationRateInZ:(NSUInteger) dilationRateInZ
                                          groups:(NSUInteger) groups
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;

/// sets values of padding to given values.
/// - Parameters:
///   - paddingLeft: See ``paddingLeft`` property.
///   - paddingRight: See ``paddingRight`` property.
///   - paddingTop: See ``paddingTop`` property.
///   - paddingBottom: See ``paddingBottom`` property.
///   - paddingFront: See ``paddingFront`` property.
///   - paddingBottom: See ``paddingBottom`` property.
-(void) setExplicitPaddingWithPaddingLeft:(NSUInteger) paddingLeft
                             paddingRight:(NSUInteger) paddingRight
                               paddingTop:(NSUInteger) paddingTop
                            paddingBottom:(NSUInteger) paddingBottom
                             paddingFront:(NSUInteger) paddingFront
                              paddingBack:(NSUInteger) paddingBack;
@end

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphConvolutionOps)

/// Creates a 2d (forward) convolution operation and returns the result tensor.
///
/// - Parameters:
///   - source: source tensor - must be of rank 4. The layout is defined by ``descriptor.dataLayout``.
///   - weights: weights tensor, must be rank 4. The layout is defined by ``descriptor.weightsLayout``.
///   - descriptor: Specifies strides, dilation rates, paddings and layouts.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution2DWithSourceTensor:(MPSGraphTensor *) source
                                    weightsTensor:(MPSGraphTensor *) weights
                                       descriptor:(MPSGraphConvolution2DOpDescriptor *) descriptor
                                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( convolution2D(_:weights:descriptor:name:) );

/// Create convolution 2d gradient operation with respect to forward convolution source tensor.
/// If `S` is source tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution2DDataGradientWithIncomingGradientTensor returns tensor `dL/dS = dL/dR * dR/dS`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShape: Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution2DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                          weightsTensor:(MPSGraphTensor *) weights
                                                            outputShape:(MPSShape *) outputShape
                                           forwardConvolutionDescriptor:(MPSGraphConvolution2DOpDescriptor *) forwardConvolutionDescriptor
                                                                   name:(NSString * _Nullable) name
MPS_SWIFT_NAME( convolution2DDataGradient(_:weights:outputShape:forwardConvolutionDescriptor:name:) );

/// Create convolution 2d gradient operation with respect to forward convolution source tensor.
/// If `S` is source tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution2DDataGradientWithIncomingGradientTensor returns tensor `dL/dS = dL/dR * dR/dS`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShapeTensor: 4D Int32 or Int64 tensor. Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution2DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) gradient
                                                          weightsTensor:(MPSGraphTensor *) weights
                                                      outputShapeTensor:(MPSGraphTensor *) outputShapeTensor
                                           forwardConvolutionDescriptor:(MPSGraphConvolution2DOpDescriptor *) forwardConvolutionDescriptor
                                                                   name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))
MPS_SWIFT_NAME( convolution2DDataGradient(_:weights:outputShapeTensor:forwardConvolutionDescriptor:name:) );

/// Create convolution 2d gradient operation with respect to forward convolution weights tensor.
/// If `W` is weights tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution2DWeightsGradientWithIncomingGradientTensor returns tensor `dL/dW = dL/dR * dR/dW`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShape: Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution2DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                              sourceTensor:(MPSGraphTensor *) source
                                                               outputShape:(MPSShape *) outputShape
                                              forwardConvolutionDescriptor:(MPSGraphConvolution2DOpDescriptor *) forwardConvolutionDescriptor
                                                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( convolution2DWeightsGradient(_:source:outputShape:forwardConvolutionDescriptor:name:) );


/// Create convolution 2d gradient operation with respect to forward convolution weights tensor.
/// If `W` is weights tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution2DWeightsGradientWithIncomingGradientTensor returns tensor `dL/dW = dL/dR * dR/dW`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShapeTensor: 4D int32 or Int64 Tensor. Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution2DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) gradient
                                                              sourceTensor:(MPSGraphTensor *) source
                                                         outputShapeTensor:(MPSGraphTensor *) outputShapeTensor
                                              forwardConvolutionDescriptor:(MPSGraphConvolution2DOpDescriptor *) forwardConvolutionDescriptor
                                                                      name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))
MPS_SWIFT_NAME( convolution2DWeightsGradient(_:source:outputShapeTensor:forwardConvolutionDescriptor:name:) );


/// Creates a 3d (forward) convolution operation and returns the result tensor.
///
/// - Parameters:
///   - source: source tensor - must be of rank 5. The layout is defined by ``descriptor.dataLayout``.
///   - weights: weights tensor, must be rank 5. The layout is defined by ``descriptor.weightsLayout``.
///   - descriptor: Specifies strides, dilation rates, paddings and layouts.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution3DWithSourceTensor:(MPSGraphTensor *) source
                                    weightsTensor:(MPSGraphTensor *) weights
                                       descriptor:(MPSGraphConvolution3DOpDescriptor *) descriptor
                                             name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
MPS_SWIFT_NAME( convolution3D(_:weights:descriptor:name:) );

/// Create convolution 3d gradient operation with respect to forward convolution source tensor.
/// If `S` is source tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution3DDataGradientWithIncomingGradientTensor returns tensor `dL/dS = dL/dR * dR/dS`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShape: Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution3DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                          weightsTensor:(MPSGraphTensor *) weights
                                                            outputShape:(MPSShape *) outputShape
                                           forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor *) forwardConvolutionDescriptor
                                                                   name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
MPS_SWIFT_NAME( convolution3DDataGradient(_:weights:outputShape:forwardConvolutionDescriptor:name:) );

/// Create convolution 3d gradient operation with respect to forward convolution source tensor.
/// If `S` is source tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution3DDataGradientWithIncomingGradientTensor returns tensor `dL/dS = dL/dR * dR/dS`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShapeTensor: 4D Int32 or Int64 tensor. Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution3DDataGradientWithIncomingGradientTensor:(MPSGraphTensor *) gradient
                                                          weightsTensor:(MPSGraphTensor *) weights
                                                      outputShapeTensor:(MPSGraphTensor *) outputShapeTensor
                                           forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor *) forwardConvolutionDescriptor
                                                                   name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
MPS_SWIFT_NAME( convolution3DDataGradient(_:weights:outputShapeTensor:forwardConvolutionDescriptor:name:) );

/// Create convolution 3d gradient operation with respect to forward convolution weights tensor.
/// If `W` is weights tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution3DWeightsGradientWithIncomingGradientTensor returns tensor `dL/dW = dL/dR * dR/dW`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShape: Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution3DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradient
                                                              sourceTensor:(MPSGraphTensor *) source
                                                               outputShape:(MPSShape *) outputShape
                                              forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor *) forwardConvolutionDescriptor
                                                                      name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
MPS_SWIFT_NAME( convolution3DWeightsGradient(_:source:outputShape:forwardConvolutionDescriptor:name:) );

/// Create convolution 3d gradient operation with respect to forward convolution weights tensor.
/// If `W` is weights tensor to forward convoluiton, `R` is the result/returned tensor of forward convolution,
/// and `L` is the loss function, convolution3DWeightsGradientWithIncomingGradientTensor returns tensor `dL/dW = dL/dR * dR/dW`,
/// where `dL/dR` is the incomingGradient parameter.
///
/// - Parameters:
///   - incomingGradient: Incoming loss gradient tensor
///   - weights: Forward pass weights tensor
///   - outputShapeTensor: 4D int32 or Int64 Tensor. Shape of the forward pass source tensor
///   - forwardConvolutionDescriptor: Forward convolution 2d op ``descriptor``
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) convolution3DWeightsGradientWithIncomingGradientTensor:(MPSGraphTensor *) gradient
                                                              sourceTensor:(MPSGraphTensor *) source
                                                         outputShapeTensor:(MPSGraphTensor *) outputShapeTensor
                                              forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor *) forwardConvolutionDescriptor
                                                                      name:(NSString * _Nullable) name
MPS_CLASS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))
MPS_SWIFT_NAME( convolution3DWeightsGradient(_:source:outputShapeTensor:forwardConvolutionDescriptor:name:) );

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphConvolutionOps_h */
