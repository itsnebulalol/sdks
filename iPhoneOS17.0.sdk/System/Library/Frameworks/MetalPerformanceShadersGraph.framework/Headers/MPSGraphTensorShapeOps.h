//
//  MPSGraphTensorShapeOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 12/16/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphTensorShapeOps_h
#define MPSGraphTensorShapeOps_h


#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphTensorShapeOps)

/// Creates a reshape operation and returns the result tensor.
///
/// Reshapes the input tensor to the target shape.
/// The shape must be compatible with the input tensor shape, specifically the volume of the input tensor has to match the volume define by the shape.
/// The shape is allowed to contain dynamic dimensions (-1) when the result type can be inferred unambiguously.
///
/// - Parameters:
///   - tensor: Tensor to be reshaped.
///   - shape: The result tensor shape.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) reshapeTensor:(MPSGraphTensor *) tensor
                        withShape:(MPSShape *) shape
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( reshape(_:shape:name:) );

/// Creates a reshape operation and returns the result tensor.
///
/// Reshapes the input tensor to the target shape.
/// The shape tensor must be compatible with the input tensor shape, specifically the volume of the input tensor has to match the volume define by the shape tensor.
/// The shape tensor is allowed to contain dynamic dimensions (-1) when the result type can be inferred unambiguously.
///
/// - Parameters:
///   - tensor: Tensor to be reshaped.
///   - shapeTensor: 1D Int32 or Int64 tensor. The result tensor shape.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) reshapeTensor:(MPSGraphTensor *) tensor
                  withShapeTensor:(MPSGraphTensor *) shapeTensor
                             name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))
MPS_SWIFT_NAME( reshape(_:shapeTensor:name:) );

/// Creates a transpose operation and returns the result tensor.
///
/// Transposes the dimensions ``dimensionIndex`` and ``dimensionIndex2`` of the input tensor.
///
/// - Parameters:
///   - tensor: Tensor to be transposed.
///   - dimensionIndex: The first dimension index to be transposed.
///   - dimensionIndex2: The second dimension index to be transposed.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) transposeTensor:(MPSGraphTensor *) tensor
                          dimension:(NSUInteger) dimensionIndex
                      withDimension:(NSUInteger) dimensionIndex2
                               name:(NSString * _Nullable) name;

/// Creates a permutation operation and returns the result tensor.
///
/// Permutes the dimensions of the input tensor according to values in ``permutation``.
///
/// - Parameters:
///   - tensor: Tensor to be transposed.
///   - permutation: Array of numbers defining the permutation, must be of length `rank(tensor)`.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) transposeTensor:(MPSGraphTensor *) tensor
                        permutation:(NSArray<NSNumber *> *) permutation
                               name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0))
MPS_SWIFT_NAME( transpose(_:permutation:name:) );

/// Creates a slice operation and returns the result tensor.
///
/// - Parameters:
///   - tensor: Tensor to be sliced.
///   - dimensionIndex: Which dimension to slice.
///   - start: Starting index of the slice, can be negative to count from the end of the tensor dimension.
///   - length: Length of the slice.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.

-(MPSGraphTensor *) sliceTensor:(MPSGraphTensor *) tensor
                      dimension:(NSUInteger) dimensionIndex
                          start:(NSInteger) start
                         length:(NSInteger) length
                           name:(NSString * _Nullable) name;

/// Creates a strided slice operation and returns the result tensor.
///
/// Slices a tensor starting from ``starts``, stopping short before ``ends`` stepping
/// ``strides`` paces between each value. Semantics based on
/// [TensorFlow Strided Slice Op](https://www.tensorflow.org/api_docs/python/tf/strided_slice).
///
/// - Parameters:
///   - tensor: Tensor to be sliced.
///   - starts: Array of numbers specifying starting point per dimension.
///   - ends: Array of numbers specifying ending point per dimension.
///   - strides: Array of numbers specifying strides per dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) sliceTensor:(MPSGraphTensor *) tensor
                         starts:(NSArray<NSNumber *> *) starts
                           ends:(NSArray<NSNumber *> *) ends
                        strides:(NSArray<NSNumber *> *) strides
                           name:(NSString * _Nullable) name;

/// Creates strided slice operation and returns the result tensor.
///
/// Slices a tensor starting from ``starts``, stopping short before ``ends`` stepping
/// ``strides`` paces between each value. Semantics based on
/// [TensorFlow Strided Slice Op](https://www.tensorflow.org/api_docs/python/tf/strided_slice).
///
/// - Parameters:
///   - tensor: Tensor to be sliced.
///   - starts: Array of numbers specifying starting point per dimension.
///   - ends: Array of numbers specifying ending point per dimension.
///   - strides: Array of numbers specifying strides per dimension.
///   - startMask: Bitmask indicating dimensions whose ``starts`` values should be ignored.
///   - endMask: Bitmask indicating dimensions whose ``ends`` values should be ignored.
///   - squeezeMask: Bitmask indicating dimensions that should be squeezed out from the result.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) sliceTensor:(MPSGraphTensor *) tensor
                         starts:(NSArray<NSNumber *> *) starts
                           ends:(NSArray<NSNumber *> *) ends
                        strides:(NSArray<NSNumber *> *) strides
                      startMask:(uint32_t) startMask
                        endMask:(uint32_t) endMask
                    squeezeMask:(uint32_t) squeezeMask
                           name:(NSString * _Nullable) name;

/// Creates strided slice gradient operation and returns the result tensor.
///
/// - Parameters:
///   - inputGradientTensor: Input gradient.
///   - fwdInShapeTensor: Shape of the forward pass input = shape of gradient output.
///   - starts: Array of numbers specifying starting point per dimension.
///   - ends: Array of numbers specifying ending point per dimension.
///   - strides: Array of numbers specifying strides per dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) sliceGradientTensor:(MPSGraphTensor *) inputGradientTensor
                       fwdInShapeTensor:(MPSGraphTensor *) fwdInShapeTensor
                                 starts:(NSArray<NSNumber *> *) starts
                                   ends:(NSArray<NSNumber *> *) ends
                                strides:(NSArray<NSNumber *> *) strides
                                   name:(NSString * _Nullable) name;

/// Creates strided slice gradient operation and returns the result tensor.
///
/// - Parameters:
///   - inputGradientTensor: Input gradient.
///   - fwdInShapeTensor: Shape of the forward pass input = shape of gradient output.
///   - starts: Array of numbers specifying starting point per dimension.
///   - ends: Array of numbers specifying ending point per dimension.
///   - strides: Array of numbers specifying strides per dimension.
///   - startMask: Bitmask indicating dimensions whose `starts` values should be ignored.
///   - endMask: Bitmask indicating dimensions whose `ends` values should be ignored.
///   - squeezeMask: Bitmask indicating dimensions that should be squeezed out from the result.
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) sliceGradientTensor:(MPSGraphTensor *) inputGradientTensor
                       fwdInShapeTensor:(MPSGraphTensor *) fwdInShapeTensor
                                 starts:(NSArray<NSNumber *> *) starts
                                   ends:(NSArray<NSNumber *> *) ends
                                strides:(NSArray<NSNumber *> *) strides
                              startMask:(uint32_t) startMask
                                endMask:(uint32_t) endMask
                            squeezeMask:(uint32_t) squeezeMask
                                   name:(NSString * _Nullable) name;

/// Creates concatenation operation and returns the result tensor.
///
/// Concatenates two input tensors along the specified dimension. Tensors must be broadcast
/// compatible along all other dimensions, and have the same type.
///
/// - Parameters:
///   - tensor: First tensor to concatenate.
///   - tensor2: Second tensor to concatenate.
///   - dimensionIndex: The dimension to concatenate across, must be in range `- rank <= dimension < rank`.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) concatTensor:(MPSGraphTensor *) tensor
                      withTensor:(MPSGraphTensor *) tensor2
                       dimension:(NSInteger) dimensionIndex
                            name:(NSString * _Nullable) name;

/// Creates concatenation operation and returns the result tensor.
///
/// Concatenates all input tensors along the specified dimension. All inputs must be broadcast
/// compatible along all other dimensions, and have the same type.
///
/// - Parameters:
///   - tensors: Tensors to concatenate.
///   - dimensionIndex: The dimension to concatenate across, must be in range `- rank <= dimension < rank`.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) concatTensors:(NSArray<MPSGraphTensor *> *) tensors
                        dimension:(NSInteger) dimensionIndex
                             name:(NSString * _Nullable) name;

/// Creates concatenation operation and returns the result tensor.
///
/// Concatenates all input tensors along specified dimension. All inputs must be broadcast
/// compatible along all other dimensions, and have the same type. 
/// When interleave is specified, all tensors will be interleaved. To interleave, make sure to provide broadcast
/// compatible inputs along the specified dimension as well.
/// For example:
/// ```md 
///   operand0 = [1, 2, 3]
///   operand1 = [4, 5, 6]
///   concat([operand0, operand1], axis = 0, interleave = YES) = [1, 4, 2, 5, 3, 6]
/// ```
///
/// - Parameters:
///   - tensors: Tensors to concatenate.
///   - dimensionIndex: The dimension to concatenate across, must be in range `- rank <= dimension < rank`.
///   - interleave: Interleave input tensors,
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) concatTensors:(NSArray<MPSGraphTensor *> *) tensors
                        dimension:(NSInteger) dimensionIndex
                       interleave:(BOOL) interleave
                             name:(NSString * _Nullable) name;

/// Creates tile operation and returns the result tensor.
///
/// Creates a tensor which contains multiple copies of the input tensor along each dimension of the tensor.
///
/// - Parameters:
///   - tensor: The input tensor
///   - multiplier: How many copies per dimension MPSGraph produces.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) tileTensor:(MPSGraphTensor *) tensor
                withMultiplier:(MPSShape *) multiplier
                          name:(NSString * _Nullable) name;

/// Creates tile gradient operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradientTensor: The input gradient tensor.
///   - sourceTensor: The input tensor of the forward pass.
///   - multiplier: How many copies per dimension were done in the forward pass (see ``tileTensor:withMultiplier:name:``).
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) tileGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradientTensor
                                              sourceTensor:(MPSGraphTensor *) sourceTensor
                                            withMultiplier:(MPSShape *) multiplier
                                                      name:(NSString * _Nullable) name;

/// Creates padding operation and returns the result tensor.
///
/// - Parameters:
///   - tensor: The input tensor
///   - paddingMode: What kind of padding to apply.
///   - leftPadding: How much padding to apply to the input tensor before each dimension - must be of size `rank(tensor)`.
///   - rightPadding: How much padding to apply to the input tensor after each dimension - must be of size `rank(tensor)`.
///   - constantValue: Constant value to be used when ``paddingMode`` = ``MPSGraphPaddingModeConstant``.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)padTensor:(MPSGraphTensor *) tensor
             withPaddingMode:(MPSGraphPaddingMode)paddingMode
                 leftPadding:(MPSShape *) leftPadding
                rightPadding:(MPSShape *) rightPadding
               constantValue:(double)constantValue
                        name:(NSString * _Nullable) name;

/// Creates padding gradient operation and returns the result tensor.
///
/// - Parameters:
///   - incomingGradientTensor: The input gradient tensor.
///   - sourceTensor: The input tensor of the forward pass.
///   - paddingMode: What kind of padding to apply.
///   - leftPadding: How much padding to apply to the input tensor before each dimension - must be of size `rank(tensor)`.
///   - rightPadding: How much padding to apply to the input tensor after each dimension - must be of size `rank(tensor)`.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)padGradientWithIncomingGradientTensor:(MPSGraphTensor *) incomingGradientTensor
                                            sourceTensor:(MPSGraphTensor *) sourceTensor
                                             paddingMode:(MPSGraphPaddingMode)paddingMode
                                             leftPadding:(MPSShape *) leftPadding
                                            rightPadding:(MPSShape *) rightPadding
                                                    name:(NSString * _Nullable) name;

/// Creates space-to-depth2d operation and returns the result tensor.
///
/// This operation outputs a copy of the ``input`` tensor, where values from the
/// ``widthAxis`` and ``heightAxis`` dimensions are moved in spatial blocks of size
/// ``blockSize`` to the ``depthAxis`` dimension. Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``depthAxis`` dimension: with ``usePixelShuffleOrder=YES`` MPSGraph stores the
/// values of the spatial blocks  contiguosly within the ``depthAxis`` dimension, whereas
/// otherwise they are stored interleaved with existing values in the ``depthAxis`` dimension.
/// This operation is the inverse of ``depthToSpace2DTensor:widthAxis:heightAxis:depthAxis:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - widthAxis: Axis that defines the fastest running dimension within the block.
///   - heightAxis: Axis that defines the 2nd fastest running dimension within the block.
///   - depthAxis: Axis that defines the destination dimension, where to copy the blocks.
///   - blockSize: Size of the square spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the depth dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *)spaceToDepth2DTensor:(MPSGraphTensor *) tensor
                              widthAxis:(NSUInteger) widthAxis
                             heightAxis:(NSUInteger) heightAxis
                              depthAxis:(NSUInteger) depthAxis
                              blockSize:(NSUInteger) blockSize
                   usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates space-to-depth2d operation and returns the result tensor.
///
/// This operation outputs a copy of the ``input`` tensor, where values from the
/// ``widthAxisTensor`` and ``heightAxisTensor`` dimensions are moved in spatial blocks of size
/// ``blockSize`` to the ``depthAxisTensor`` dimension. Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``depthAxisTensor`` dimension: with ``usePixelShuffleOrder=YES`` MPSGraph stores the
/// values of the spatial blocks  contiguosly within the ``depthAxisTensor`` dimension, whereas
/// otherwise they are stored interleaved with existing values in the ``depthAxisTensor`` dimension.
/// This operation is the inverse of ``depthToSpace2DTensor:widthAxisTensor:heightAxisTensor:depthAxisTensor:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - widthAxisTensor: Axis that defines the fastest running dimension within the block.
///   - heightAxisTensor: Axis that defines the 2nd fastest running dimension within the block.
///   - depthAxisTensor: Axis that defines the destination dimension, where to copy the blocks.
///   - blockSize: Size of the square spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the depth dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *)spaceToDepth2DTensor:(MPSGraphTensor *) tensor
                        widthAxisTensor:(MPSGraphTensor *) widthAxisTensor
                       heightAxisTensor:(MPSGraphTensor *) heightAxisTensor
                        depthAxisTensor:(MPSGraphTensor *) depthAxisTensor
                              blockSize:(NSUInteger)blockSize
                   usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates depth-to-space2d operation and returns the result tensor.
///
/// This operation outputs a copy of the input tensor, where values from the 
/// ``depthAxis`` dimension are moved in spatial blocks of size ``blockSize`` to the
/// ``heightAxis`` and ``widthAxis`` dimensions.  Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``depthAxis`` dimension: with ``usePixelShuffleOrder = YES`` MPSGraph stores the values
/// of the spatial block contiguosly within the ``depthAxis`` dimension, whereas
/// without it they are stored interleaved with existing values in the ``depthAxisTensor`` dimension.
/// This operation is the inverse of ``spaceToDepth2DTensor:widthAxis:heightAxis:depthAxis:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - widthAxis: Axis that defines the fastest running dimension within the block.
///   - heightAxis: Axis that defines the 2nd fastest running dimension within the block.
///   - depthAxis: Axis that defines the source dimension, from which to copy the blocks.
///   - blockSize: Size of the square spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the depth dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)depthToSpace2DTensor:(MPSGraphTensor *) tensor
                              widthAxis:(NSUInteger) widthAxis
                             heightAxis:(NSUInteger) heightAxis
                              depthAxis:(NSUInteger) depthAxis
                              blockSize:(NSUInteger)blockSize
                   usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates depth-to-space2d operation and returns the result tensor.
///
/// This operation outputs a copy of the input tensor, where values from the
/// ``depthAxisTensor`` dimension are moved in spatial blocks of size ``blockSize`` to the
/// ``heightAxisTensor`` and ``widthAxisTensor`` dimensions.  Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``depthAxisTensor`` dimension: with ``usePixelShuffleOrder = YES`` MPSGraph stores the values
/// of the spatial block contiguosly within the ``depthAxisTensor`` dimension, whereas
/// without it they are stored interleaved with existing values in the ``depthAxisTensor`` dimension.
/// This operation is the inverse of ``spaceToDepth2DTensor:widthAxisTensor:heightAxisTensor:depthAxisTensor:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - widthAxisTensor: Axis that defines the fastest running dimension within the block.
///   - heightAxisTensor: Axis that defines the 2nd fastest running dimension within the block.
///   - depthAxisTensor: Axis that defines the source dimension, from which to copy the blocks.
///   - blockSize: Size of the square spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the depth dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)depthToSpace2DTensor:(MPSGraphTensor *) tensor
                        widthAxisTensor:(MPSGraphTensor *) widthAxisTensor
                       heightAxisTensor:(MPSGraphTensor *) heightAxisTensor
                        depthAxisTensor:(MPSGraphTensor *) depthAxisTensor
                              blockSize:(NSUInteger)blockSize
                   usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a space-to-batch operation and returns the result tensor.
///
/// This operation outputs a copy of the ``input`` tensor, where values from the
/// ``spatialAxes`` (for ``usePixelShuffleOrder=YES`` 1,2 or 3 axes supported, otherwise
/// limited only by ``MPSNDArray`` rank limitations) dimensions are moved in spatial blocks with
/// rectangular size defined by ``blockDimensions`` to the ``batchAxis`` dimension.
/// Use ``usePixelShuffleOrder``  to control how the data within spatial blocks is ordered
/// in the ``batchAxis`` dimension: with ``usePixelShuffleOrder=YES`` MPSGraph stores
/// the values of the spatial blocks contiguosly within the ``batchAxis`` dimension, whereas
/// otherwise they are stored interleaved with existing values in the ``batchAxis`` dimension.
/// Note: This operation is the inverse of ``batchToSpaceTensor:spatialAxes:batchAxis:blockDimensions:usePixelShuffleOrder:name:``.
/// Note: This operation is a generalization of ``spaceToDepth2DTensor:widthAxis:heightAxis:depthAxis:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - spatialAxes: Axes that define the dimensions containing the spatial blocks.
///   - batchAxis: Axis that defines the destination dimension, where to copy the blocks.
///   - blockDimensions: Defines the size of the rectangular spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the batch dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)spaceToBatchTensor:(MPSGraphTensor *) tensor
                          spatialAxes:(NSArray<NSNumber *> *) spatialAxes
                            batchAxis:(NSInteger) batchAxis
                      blockDimensions:(NSArray<NSNumber *> *) blockDimensions
                 usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                 name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1))
MPS_SWIFT_NAME( spaceToBatch(_:spatialAxes:batchAxis:blockDimensions:usePixelShuffleOrder:name:));

/// Creates a space-to-batch operation and returns the result tensor.
///
/// This operation outputs a copy of the ``input`` tensor, where values from the
/// ``spatialAxesTensor`` (for ``usePixelShuffleOrder=YES`` 1,2 or 3 axes supported, otherwise
/// limited only by ``MPSNDArray`` rank limitations) dimensions are moved in spatial blocks with
/// rectangular size defined by ``blockDimensionsTensor`` to the ``batchAxisTensor`` dimension.
/// Use ``usePixelShuffleOrder``  to control how the data within spatial blocks is ordered
/// in the ``batchAxisTensor`` dimension: with ``usePixelShuffleOrder=YES`` MPSGraph stores
/// the values of the spatial blocks contiguosly within the ``batchAxisTensor`` dimension, whereas
/// otherwise they are stored interleaved with existing values in the ``batchAxisTensor`` dimension.
/// Note: This operation is the inverse of ``batchToSpaceTensor:spatialAxesTensor:batchAxisTensor:blockDimensionsTensor:usePixelShuffleOrder:name:``.
/// Note: This operation is a generalization of ``spaceToDepth2DTensor:widthAxisTensor:heightAxisTensor:depthAxisTensor:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - spatialAxesTensor: Axes that define the dimensions containing the spatial blocks.
///   - batchAxisTensor: Axis that defines the destination dimension, where to copy the blocks.
///   - blockDimensionsTensor: Defines the size of the rectangular spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the batch dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)spaceToBatchTensor:(MPSGraphTensor *) tensor
                    spatialAxesTensor:(MPSGraphTensor *) spatialAxesTensor
                      batchAxisTensor:(MPSGraphTensor *) batchAxisTensor
                blockDimensionsTensor:(MPSGraphTensor *) blockDimensionsTensor
                 usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                 name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1))
MPS_SWIFT_NAME( spaceToBatch(_:spatialAxesTensor:batchAxisTensor:blockDimensionsTensor:usePixelShuffleOrder:name:));

/// Creates a batch-to-space operation and returns the result tensor.
///
/// This operation outputs a copy of the input tensor, where values from the 
/// ``batchAxis`` dimension are moved in spatial blocks of size ``blockDimensions`` to the
/// ``spatialAxes`` dimensions (for ``usePixelShuffleOrder=YES`` 1,2 or 3 axes supported,
/// otherwise limited only by ``MPSNDArray`` rank limitations).  Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``batchAxis`` dimension: with ``usePixelShuffleOrder = YES`` MPSGraph stores
/// the values of the spatial block contiguosly within the ``batchAxis`` dimension whereas
/// without it they are stored interleaved with existing values in the ``batchAxis`` dimension.
/// Note: This operation is the inverse of ``spaceToBatchTensor:spatialAxes:batchAxis:blockDimensions:usePixelShuffleOrder:name:``.
/// Note: This operation is a generalization of ``depthToSpace2DTensor:widthAxis:heightAxis:depthAxis:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - spatialAxes: Axes that define the dimensions containing the spatial blocks.
///   - batchAxis: Axis that defines the source dimension, from which to copy the blocks.
///   - blockDimensions: Defines the size of the rectangular spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the batch dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)batchToSpaceTensor:(MPSGraphTensor *) tensor
                          spatialAxes:(NSArray<NSNumber *> *) spatialAxes
                            batchAxis:(NSInteger) batchAxis
                      blockDimensions:(NSArray<NSNumber *> *) blockDimensions
                 usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                 name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1))
MPS_SWIFT_NAME( batchToSpace(_:spatialAxes:batchAxis:blockDimensions:usePixelShuffleOrder:name:));

/// Creates a batch-to-space operation and returns the result tensor.
///
/// This operation outputs a copy of the input tensor, where values from the
/// ``batchAxisTensor`` dimension are moved in spatial blocks of size ``blockDimensionsTensor`` to the
/// ``spatialAxesTensor`` dimensions (for ``usePixelShuffleOrder=YES`` 1,2 or 3 axes supported,
/// otherwise limited only by ``MPSNDArray`` rank limitations).  Use ``usePixelShuffleOrder``
/// to control how the data within spatial blocks is ordered in the
/// ``batchAxisTensor`` dimension: with ``usePixelShuffleOrder = YES`` MPSGraph stores
/// the values of the spatial block contiguosly within the ``batchAxisTensor`` dimension whereas
/// without it they are stored interleaved with existing values in the ``batchAxisTensor`` dimension.
/// Note: This operation is the inverse of ``spaceToBatchTensor:spatialAxesTensor:batchAxisTensor:blockDimensionsTensor:usePixelShuffleOrder:name:``.
/// Note: This operation is a generalization of ``depthToSpace2DTensor:widthAxisTensor:heightAxisTensor:depthAxisTensor:blockSize:usePixelShuffleOrder:name:``.
///
/// - Parameters:
///   - tensor: The input tensor.
///   - spatialAxesTensor: Axes that define the dimensions containing the spatial blocks.
///   - batchAxisTensor: Axis that defines the source dimension, from which to copy the blocks.
///   - blockDimensionsTensor: Defines the size of the rectangular spatial sub-block.
///   - usePixelShuffleOrder: Controls layout of the sub-blocks within the batch dimension.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.

-(MPSGraphTensor *)batchToSpaceTensor:(MPSGraphTensor *) tensor
                    spatialAxesTensor:(MPSGraphTensor *) spatialAxesTensor
                      batchAxisTensor:(MPSGraphTensor *) batchAxisTensor
                blockDimensionsTensor:(MPSGraphTensor *) blockDimensionsTensor
                 usePixelShuffleOrder:(BOOL)usePixelShuffleOrder
                                 name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1))
MPS_SWIFT_NAME( batchToSpace(_:spatialAxesTensor:batchAxisTensor:blockDimensionsTensor:usePixelShuffleOrder:name:));

/// Creates a reverse operation and return the result tensor.
///
/// Reverses a tensor on given axes.
/// Semantics based on [TensorFlow reverse op](https://www.tensorflow.org/api_docs/python/tf/reverse).
///
/// - Parameters:
///   - tensor: Tensor to be reversed.
///   - axesTensor: Tensor that specifies axes to be reversed (Axes must be unique and within normal axis range).
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) reverseTensor:(MPSGraphTensor *) tensor
                       axesTensor:(MPSGraphTensor *) axesTensor
                             name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a reverse operation and return the result tensor.
///
/// Reverses a tensor on given axes.
/// Semantics based on [TensorFlow reverse op](https://www.tensorflow.org/api_docs/python/tf/reverse).
///
/// - Parameters:
///   - tensor: Tensor to be reversed.
///   - axes: Axes to be reversed (Axes must be unique and within normal axis range).
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.

-(MPSGraphTensor *) reverseTensor:(MPSGraphTensor *) tensor
                             axes:(NSArray<NSNumber *> *) axes
                             name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a reverse operation and return the result tensor.
///
/// Reverses a tensor on all axes.
/// Semantics based on [TensorFlow reverse op](https://www.tensorflow.org/api_docs/python/tf/reverse).
///
/// - Parameters:
///   - tensor: Tensor to be reversed.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.

-(MPSGraphTensor *) reverseTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));


/// Creates a flatten2d operation and returns the result tensor.
///
/// Flattens dimensions before ``axis`` to ``result[0]`` and dimensions starting
/// from ``axis`` to ``result[1]`` and returns a rank-2 tensor as result.
///
/// - Parameters:
///   - tensor: Tensor to be flattened.
///   - axis: Axis around which to flatten.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) flatten2DTensor:(MPSGraphTensor *) tensor
                               axis:(NSInteger) axis
                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( flatten2D(_:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a flatten2d operation and returns the result tensor.
///
/// Flattens dimensions before ``axis`` to ``result[0]`` and dimensions starting
/// from ``axis`` to ``result[1]`` and returns a rank-2 tensor as result.
///
/// - Parameters:
///   - tensor: Tensor to be flattened.
///   - axisTensor: Axis around which to flatten.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) flatten2DTensor:(MPSGraphTensor *) tensor
                         axisTensor:(MPSGraphTensor *) axisTensor
                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( flatten2D(_:axisTensor:name:) )
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a broadcast operation and returns the result tensor.
///
/// Broadcasts values inside the tensor, starting from the trailing dimensions, to give it the correct shape.
/// This is equivalent to the broadcasting for arithmetic operations when operands have different shapes.
///
/// - Parameters:
///   - tensor: Tensor to be broadcasted
///   - shape: Shape of the result tensor
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) broadcastTensor:(MPSGraphTensor *) tensor
                            toShape:(MPSShape *) shape
                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( broadcast(_:shape:name:) )
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a broadcast operation and returns the result tensor.
///
/// Broadcasts values inside the tensor, starting from the trailing dimensions, to give it the correct shape.
/// This is equivalent to the broadcasting for arithmetic operations when operands have different shapes.
///
/// - Parameters:
///   - tensor: Tensor to be broadcasted.
///   - shapeTensor: 1D Int32 or Int64 tensor. Shape of the result tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) broadcastTensor:(MPSGraphTensor *) tensor
                      toShapeTensor:(MPSGraphTensor *) shapeTensor
                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( broadcast(_:shapeTensor:name:) )
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates shapeOf operation and returns the result tensor.
///
/// Returns a 1D Int32 tensor with value the static shape of the input tensor.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) shapeOfTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( shapeOf(_:name:) )
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a cast operation and returns the result tensor.
///
/// Returns input tensor casted to the dataType passed in.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - type: Input tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *)castTensor:(MPSGraphTensor *)tensor
                       toType:(MPSDataType)type
                         name:(NSString * _Nullable)name
MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Creates a reinterpret cast operation and returns the result tensor.
///
/// Returns input tensor (with element type `tensor_type`) reinterpreted to element type ``type``
/// passed in with the last dimension scaled by `sizeof(tensor_type) / sizeof(type)`. 
/// This operation is endianness agnostic and data will be reinterpreted with the endianness of the 
/// system.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - type: The element type of the returned tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
- (MPSGraphTensor *)reinterpretCastTensor:(MPSGraphTensor *)tensor
                                   toType:(MPSDataType)type
                                     name:(NSString *_Nullable)name
MPS_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3));

/// Creates a stack operation and returns the result.
///
/// Stacks all input tensors along ``axis`` into a result tensor of rank + 1. Tensors must be broadcast
/// compatible along all dimensions, and have the same type.
///
/// - Parameters:
///   - inputTensors: Input tensors.
///   - axis: The dimension to stack tensors into result. Must be in range `- rank + 1 <= dimension < rank + 1`.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) stackTensors:(NSArray<MPSGraphTensor *> *) inputTensors
                            axis:(NSInteger) axis
                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( stack(_:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a split operation and returns the result.
///
/// Splits the input tensor along ``axis`` into multiple result tensors of size determined by ``splitSizes``.
/// Requires that the sum of ``splitSizes`` is equal to the lenth of the input along ``axis``.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - splitSizes: The length of the result tensors along the split axis.
///   - axis: The dimension to split the input along.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(NSArray<MPSGraphTensor *> *) splitTensor:(MPSGraphTensor *) tensor
                                splitSizes:(NSArray<NSNumber *> *) splitSizes
                                      axis:(NSInteger) axis
                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( split(_:splitSizes:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a split operation and returns the result.
///
/// Splits the input tensor along ``axis`` into multiple result tensors of size determined by ``splitSizesTensor``.
/// Requires that the sum of ``splitSizesTensor`` is equal to the lenth of the input along ``axis``.
///
/// - Parameters:
///   - tensor: Input tensor
///   - splitSizesTensor: The length of the result tensors along the split axis
///   - axis: The dimension to split the input along
///   - name: The name for the operation
/// - Returns: A valid MPSGraphTensor object
-(NSArray<MPSGraphTensor *> *) splitTensor:(MPSGraphTensor *) tensor
                          splitSizesTensor:(MPSGraphTensor *) splitSizesTensor
                                      axis:(NSInteger) axis
                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( split(_:splitSizesTensor:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a split operation and returns the result.
///
/// Splits the input tensor along ``axis`` into ``numsplits`` result tensors of equal size.
/// Requires that the lenth of the input along ``axis`` is divisible by ``numSplits``.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - numSplits: The number of result tensors to split to.
///   - axis: The dimension to split the input along.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(NSArray<MPSGraphTensor *> *) splitTensor:(MPSGraphTensor *) tensor
                                 numSplits:(NSUInteger) numSplits
                                      axis:(NSInteger) axis
                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( split(_:numSplits:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates squeeze operation and returns the result.
///
/// Squeezes the tensor, removing any dimensions with size 1.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) squeezeTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( squeeze(_:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates squeeze operation and returns the result.
///
/// Squeezes the tensor, removing a dimension with size 1 at the specified axis.
/// Size must be 1 at specified axis.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axis: The axis to squeeze.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) squeezeTensor:(MPSGraphTensor *) tensor
                             axis:(NSInteger) axis
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( squeeze(_:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates squeeze operation and returns the result.
///
/// Squeezes the tensor, removing dimensions with size 1 at specified axes. 
/// Size must be 1 at all specified axes.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axes: The axes to squeeze.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) squeezeTensor:(MPSGraphTensor *) tensor
                             axes:(NSArray<NSNumber *> *) axes
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( squeeze(_:axes:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates squeeze operation and returns the result.
///
/// Squeezes the tensor, removing dimensions with size 1 at specified axes.
/// Size must be 1 at all specified axes.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axesTensor: The tensor containing the axes to squeeze.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object
-(MPSGraphTensor *) squeezeTensor:(MPSGraphTensor *) tensor
                       axesTensor:(MPSGraphTensor *) axesTensor
                             name:(NSString * _Nullable) name
MPS_SWIFT_NAME( squeeze(_:axesTensor:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates expand dimensions operation and returns the result.
///
/// Expands the tensor, inserting a dimension with size 1 at the specified axis.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axis: The axis to expand.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) expandDimsOfTensor:(MPSGraphTensor *) tensor
                                  axis:(NSInteger) axis
                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( expandDims(_:axis:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates expand dimensions operation and returns the result.
///
/// Expands the tensor, inserting dimensions with size 1 at specified axes.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axes: The axes to expand.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) expandDimsOfTensor:(MPSGraphTensor *) tensor
                                  axes:(NSArray<NSNumber *> *) axes
                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( expandDims(_:axes:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates expand dimensions operation and returns the result.
///
/// Expands the tensor, inserting dimensions with size 1 at specified axes.
///
/// - Parameters:
///   - tensor: Input tensor.
///   - axesTensor: The tensor containing the axes to expand.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.

-(MPSGraphTensor *) expandDimsOfTensor:(MPSGraphTensor *) tensor
                            axesTensor:(MPSGraphTensor *) axesTensor
                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( expandDims(_:axesTensor:name:) )
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates get coordindate operation and returns the result.
///
/// Creates a tensor of specified shape with value at index ```md [i_0, i_1, ... , i_N] = i_axis ``` 
/// For example, 
/// ```md 
/// coordinateAlongAxis(0, withShape=[5]) = [0, 1, 2, 3, 4] 
/// coordinateAlongAxis(0, withShape=[3,2]) = [[0, 0],
///                                            [1, 1],
///                                            [2, 2]]
/// ```
///
/// - Parameters:
///   - axis: The coordinate axis an element's value is set to. Negative values wrap around.
///   - shape: The shape of the result tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) coordinateAlongAxis:(NSInteger) axis
                              withShape:(MPSShape *) shape
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates get coordindate operation and returns the result.
///
/// See ``coordinateAlongAxis:withShape:name:``.
///
/// - Parameters:
///   - axisTensor: Scalar Int32 tensor. The coordinate axis an element's value is set to. Negative values wrap around.
///   - shape: The shape of the result tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) coordinateAlongAxisTensor:(MPSGraphTensor *) axisTensor
                                    withShape:(MPSShape *) shape
                                         name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates get coordindate operation and returns the result.
///
/// See ``coordinateAlongAxis:withShape:name:``.
///
/// - Parameters:
///   - axis: The coordinate axis an element's value is set to. Negative values wrap around.
///   - shapeTensor: 1D Int32 or Int64 tensor. The shape of the result tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) coordinateAlongAxis:(NSInteger) axis
                        withShapeTensor:(MPSGraphTensor *) shapeTensor
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates get coordindate operation and returns the result.
///
/// See ``coordinateAlongAxis:withShape:name:``.
///
/// - Parameters:
///   - axisTensor: Scalar Int32 tensor. The coordinate axis an element's value is set to. Negative values wrap around
///   - shapeTensor: 1D Int32 or Int64 tensor. The shape of the result tensor.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) coordinateAlongAxisTensor:(MPSGraphTensor *) axisTensor
                              withShapeTensor:(MPSGraphTensor *) shapeTensor
                                         name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphTensorShapeOps_h */
