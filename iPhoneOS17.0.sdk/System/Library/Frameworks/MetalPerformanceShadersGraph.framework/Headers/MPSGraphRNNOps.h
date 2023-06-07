//
//  MPSGraphRNNOps.h
//  MPSGraphRNNOps
//
//  Created by trantalaiho on 9/29/21.
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#ifndef MPSGraphRNNOps_h
#define MPSGraphRNNOps_h


#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

/// Activation modes for RNN ops.
typedef NS_ENUM(NSUInteger, MPSGraphRNNActivation)
{
    /// Pass through activation.
    MPSGraphRNNActivationNone           MPS_ENUM_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4)) MPS_SWIFT_NAME(none)   =  0L,
    /// ReLU activation.
    MPSGraphRNNActivationRelu           MPS_ENUM_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4)),
    /// Tanh activation.
    MPSGraphRNNActivationTanh           MPS_ENUM_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4)),
    /// Sigmoid activation.
    MPSGraphRNNActivationSigmoid        MPS_ENUM_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4)),
    /// Hard sigmoid activation.
    MPSGraphRNNActivationHardSigmoid    MPS_ENUM_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4)),
};

/// Defines a single gate (vanilla) RNN operation.
MPS_CLASS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4))
@interface MPSGraphSingleGateRNNDescriptor : MPSGraphObject<NSCopying>

/// If set then the input sequence is passed in reverse time order to the layer. 
/// Note: Ignored when ``bidirectional = YES``.
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL reverse;

/// If set then the input sequence is traversed in both directions and the two results 
/// are concatenated together on the channel-axis. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL bidirectional;


/// If set then the layer will produce training state tensor as a secondary output. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL training;

/// Activation function to use with the RNN op. 
/// Default value: ``MPSGraphRNNActivationRelu``.
@property (readwrite, nonatomic) MPSGraphRNNActivation activation;

/// Creates a single gate RNN descriptor with default values.
+(nullable instancetype) descriptor;

@end

/// Defines a Long Short Term Memory (LSTM) operation.
MPS_CLASS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4))
@interface MPSGraphLSTMDescriptor : MPSGraphObject<NSCopying>

/// If set then the input sequence is passed in reverse time order to the layer. 
/// Note: Ignored when ``bidirectional = YES``.
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL reverse;

/// If set then the input sequence is traversed in both directions and the two results 
/// are concatenated together on the channel-axis. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL bidirectional;

/// If set then this layer will produce the internal cell of the LSTM unit as secondary output. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL produceCell;

/// If set then the layer will produce training state tensor as a secondary or third output. 
/// Default value: ``NO``
@property (readwrite, nonatomic) BOOL training;

/// If set then the layer will use the gate-ordering `[ i, z, f, o ]` instead of default `[ i, f, z, o ]`. 
/// Default value: ``NO``
@property (readwrite, nonatomic) BOOL forgetGateLast;

/// Activation function to use with the input gate of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationSigmoid``.
@property (readwrite, nonatomic) MPSGraphRNNActivation inputGateActivation;

/// Activation function to use with the forget gate of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationSigmoid``.
@property (readwrite, nonatomic) MPSGraphRNNActivation forgetGateActivation;

/// Activation function to use with the cell gate of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationTanh``.
@property (readwrite, nonatomic) MPSGraphRNNActivation cellGateActivation;

/// Activation function to use with the output gate of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationSigmoid``.
@property (readwrite, nonatomic) MPSGraphRNNActivation outputGateActivation;

/// Activation function to use with the current cell value of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationTanh``.
@property (readwrite, nonatomic) MPSGraphRNNActivation activation;

/// Creates an LSTM descriptor with default values.
+(nullable instancetype) descriptor;

@end

/// Defines a Gated Recurrent Unit (GRU) operation.
MPS_CLASS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0))
@interface MPSGraphGRUDescriptor : MPSGraphObject<NSCopying>

/// If set then the input sequence is passed in reverse time order to the layer. 
/// Note: Ignored when ``bidirectional = YES``.
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL reverse;

/// If set then the input sequence is traversed in both directions and the two results 
/// are concatenated together on the channel-axis. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL bidirectional;

/// If set then the layer will produce training state tensor as a secondary or third output. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL training;

/// If set then the layer will use the gate-ordering `[ r, z, o ]` instead of default `[ z, r, o ]`. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL resetGateFirst;

/// If set then the layer will compute the intermediate value as `c[t] = ( b + (h[t-1] m ) R^T) r[t]`. 
/// Otherwise it's computed as `c[t] = (h[t-1] r[t] m) R^T`. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL resetAfter;

/// If set then the layer will compute the final value as `h[t] = z[t] h[t-1] + (1-z[t]) o[t]`. 
/// Otherwise it's computed as `h[t] = (1-z[t]) h[t-1] + z[t] o[t]`. 
/// Default value: ``NO``.
@property (readwrite, nonatomic) BOOL flipZ;

/// Activation function to use with the z-gate of the GRU op. 
/// Default value: ``MPSGraphRNNActivationSigmoid``.
@property (readwrite, nonatomic) MPSGraphRNNActivation updateGateActivation;

/// Activation function to use with the r-gate of the GRU op. 
/// Default value: ``MPSGraphRNNActivationSigmoid``.
@property (readwrite, nonatomic) MPSGraphRNNActivation resetGateActivation;

/// Activation function to use with the o-gate of the LSTM op. 
/// Default value: ``MPSGraphRNNActivationTanh``.
@property (readwrite, nonatomic) MPSGraphRNNActivation outputGateActivation;

/// Creates an GRU descriptor with default values.
+(nullable instancetype) descriptor;

@end

MPS_CLASS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4))
@interface MPSGraph(MPSGraphRNNOps)

/// Creates a single-gate RNN operation and returns the value and optionally training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows: 
/// ```md 
/// for t = 0 to T-1 
///   z[t] = x[t] W^T + (h[t-1]m) R^T + b
///   h[t] = activation( z[t] ), where
/// ``` 
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
///  See ``MPSGraphSingleGateRNNDescriptor`` for different `activation` options.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO``
///             then the layout is [T,N,H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2, depending on value of ``descriptor.training``. The layout of the both outputs are [T,N,H] or [T,N,2H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) singleGateRNNWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                 inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                        bias:(MPSGraphTensor * _Nullable) bias
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                        mask:(MPSGraphTensor * _Nullable) mask
                                                  descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNN(_:recurrentWeight:inputWeight:bias:initState:mask:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN operation and returns the value and optionally training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = x[t] W^T + (h[t-1]m) R^T + b
///   h[t] = activation( z[t] ), where
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
///  See ``MPSGraphSingleGateRNNDescriptor`` for different `activation` options.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2, depending on value of ``descriptor.training``. The layout of the both outputs are [T,N,H] or [T,N,2H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) singleGateRNNWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                 inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                        bias:(MPSGraphTensor * _Nullable) bias
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                  descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNN(_:recurrentWeight:inputWeight:bias:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN operation and returns the value and optionally training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = x[t] W^T + (h[t-1]m) R^T + b
///   h[t] = activation( z[t] ), where
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
///  See ``MPSGraphSingleGateRNNDescriptor`` for different `activation` options.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2, depending on value of ``descriptor.training``. The layout of the both outputs are [T,N,H] or [T,N,2H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) singleGateRNNWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                  descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNN(_:recurrentWeight:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case `inputWeight = nil` and ``bidirectional = NO`` then the layout is [T,N,H] and for `inputWeight = nil` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H]. Note: For ``bidirectional`` this tensor must have a static shape.
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``singleGateRNNWithSourceTensor`` with ``descriptor.training = true``.
///   - stateGradient: Input gradient coming from the future timestep - optional, if missing assumes zeroes.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it. 
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState.
-(NSArray<MPSGraphTensor *> *) singleGateRNNGradientsWithSourceTensor:(MPSGraphTensor *) source
                                                      recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                       sourceGradient:(MPSGraphTensor *) sourceGradient
                                                               zState:(MPSGraphTensor *) zState
                                                        stateGradient:(MPSGraphTensor * _Nullable) stateGradient
                                                          inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                                 bias:(MPSGraphTensor * _Nullable) bias
                                                            initState:(MPSGraphTensor * _Nullable) initState
                                                                 mask:(MPSGraphTensor * _Nullable) mask
                                                           descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNNGradients(_:recurrentWeight:sourceGradient:zState:stateGradient:inputWeight:bias:initState:mask:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case `inputWeight = nil` and ``bidirectional = NO`` then the layout is [T,N,H] and for `inputWeight = nil` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H]. Note: For ``bidirectional`` this tensor must have a static shape.
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``singleGateRNNWithSourceTensor`` with ``descriptor.training = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState.
-(NSArray<MPSGraphTensor *> *) singleGateRNNGradientsWithSourceTensor:(MPSGraphTensor *) source
                                                      recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                       sourceGradient:(MPSGraphTensor *) sourceGradient
                                                               zState:(MPSGraphTensor *) zState
                                                          inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                                 bias:(MPSGraphTensor * _Nullable) bias
                                                            initState:(MPSGraphTensor * _Nullable) initState
                                                                 mask:(MPSGraphTensor * _Nullable) mask
                                                           descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNNGradients(_:recurrentWeight:sourceGradient:zState:inputWeight:bias:initState:mask:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case `inputWeight = nil` and ``bidirectional = NO`` then the layout is [T,N,H] and for `inputWeight = nil` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H]. Note: For ``bidirectional`` this tensor must have a static shape.
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``singleGateRNNWithSourceTensor`` with ``descriptor.training = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState.
-(NSArray<MPSGraphTensor *> *) singleGateRNNGradientsWithSourceTensor:(MPSGraphTensor *) source
                                                      recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                       sourceGradient:(MPSGraphTensor *) sourceGradient
                                                               zState:(MPSGraphTensor *) zState
                                                          inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                                 bias:(MPSGraphTensor * _Nullable) bias
                                                            initState:(MPSGraphTensor * _Nullable) initState
                                                           descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNNGradients(_:recurrentWeight:sourceGradient:zState:inputWeight:bias:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a single-gate RNN gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case `inputWeight = nil` and ``bidirectional = NO`` then the layout is [T,N,H] and for `inputWeight = nil` and ``bidirectional = YES`` the layout is [T,N,2H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,H,H] and otherwise it is [H,H]. Note: For ``bidirectional`` this tensor must have a static shape.
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``singleGateRNNWithSourceTensor`` with ``descriptor.training = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [2H,I] and otherwise it is [H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [2H] and otherwise it is [H].
///   - initState: Initial internal state of the RNN `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The RNN op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState.
-(NSArray<MPSGraphTensor *> *) singleGateRNNGradientsWithSourceTensor:(MPSGraphTensor *) source
                                                      recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                                       sourceGradient:(MPSGraphTensor *) sourceGradient
                                                               zState:(MPSGraphTensor *) zState
                                                            initState:(MPSGraphTensor * _Nullable) initState
                                                           descriptor:(MPSGraphSingleGateRNNDescriptor *) descriptor
                                                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( singleGateRNNGradients(_:recurrentWeight:sourceGradient:zState:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM operation and returns the value tensor and optionally the cell state tensor and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `c` and optionally `z` that are defined recursively as follows: 
/// ```md
/// for t = 0 to T-1
///   z[t] = [i, f, z, o][t] = f( (h[t-1] m) R^T + x'[t] + p c[t-1] )
///   x'[t] = x[t] W^T + b
///   c[t] = f[t]c[t-1] + i[t]z[t]
///   h[t] = o[t]g(c[t]), where
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `c[t]` is the second output (optional),
/// `z[t]` is either the second or third output (optional), `h[-1]` is ``initCell``.  and `h[-1]` is ``initState``.
/// `p` is an optional peephole vector.
/// See ``MPSGraphLSTMDescriptor`` for different ``activation`` options for `f()` and `g()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - peephole: Tensor containing the peephole vector `v` - optional, if missing assumes zeroes. Shape is [4H], ie. a vector for each gate, or [2,4H] for bidirectional.
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 or 3, depending on values of ``descriptor.produceCell`` and ``descriptor.training``.
///     The layout of the both state and cell outputs are [T,N,H] or [T,N,2H] for bidirectional, and the layout of the trainingState output is [T,N,4H] or [T,N,8H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) LSTMWithSourceTensor:(MPSGraphTensor *) source
                                    recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                        inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                               bias:(MPSGraphTensor * _Nullable) bias
                                          initState:(MPSGraphTensor * _Nullable) initState
                                           initCell:(MPSGraphTensor * _Nullable) initCell
                                               mask:(MPSGraphTensor * _Nullable) mask
                                           peephole:(MPSGraphTensor * _Nullable) peephole
                                         descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTM(_:recurrentWeight:inputWeight:bias:initState:initCell:mask:peephole:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM operation and returns the value tensor and optionally the cell state tensor and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `c` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = [i, f, z, o][t] = f( (h[t-1] m) R^T + x'[t] + p c[t-1] )
///   x'[t] = x[t] W^T + b
///   c[t] = f[t]c[t-1] + i[t]z[t]
///   h[t] = o[t]g(c[t]), where
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `c[t]` is the second output (optional),
/// `z[t]` is either the second or third output (optional), `h[-1]` is ``initCell``.  and `h[-1]` is ``initState``.
/// `p` is an optional peephole vector.
/// See ``MPSGraphLSTMDescriptor`` for different ``activation`` options for `f()` and `g()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 or 3, depending on values of ``descriptor.produceCell`` and ``descriptor.training``.
///     The layout of the both state and cell outputs are [T,N,H] or [T,N,2H] for bidirectional, and the layout of the trainingState output is [T,N,4H] or [T,N,8H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) LSTMWithSourceTensor:(MPSGraphTensor *) source
                                    recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                        inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                               bias:(MPSGraphTensor * _Nullable) bias
                                          initState:(MPSGraphTensor * _Nullable) initState
                                           initCell:(MPSGraphTensor * _Nullable) initCell
                                         descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTM(_:recurrentWeight:inputWeight:bias:initState:initCell:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM operation and returns the value tensor and optionally the cell state tensor and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `c` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = [i, f, z, o][t] = f( (h[t-1] m) R^T + x'[t] + p c[t-1] )
///   x'[t] = x[t] W^T + b
///   c[t] = f[t]c[t-1] + i[t]z[t]
///   h[t] = o[t]g(c[t]), where
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `c[t]` is the second output (optional),
/// `z[t]` is either the second or third output (optional), `h[-1]` is ``initCell``.  and `h[-1]` is ``initState``.
/// `p` is an optional peephole vector.
/// See ``MPSGraphLSTMDescriptor`` for different ``activation`` options for `f()` and `g()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 or 3, depending on values of ``descriptor.produceCell`` and ``descriptor.training``.
///     The layout of the both state and cell outputs are [T,N,H] or [T,N,2H] for bidirectional, and the layout of the trainingState output is [T,N,4H] or [T,N,8H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) LSTMWithSourceTensor:(MPSGraphTensor *) source
                                    recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                          initState:(MPSGraphTensor * _Nullable) initState
                                           initCell:(MPSGraphTensor * _Nullable) initCell
                                         descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTM(_:recurrentWeight:initState:initCell:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The third output of ``LSTMWithSourceTensor`` with ``descriptor.training = true``.
///   - cellOutputFwd: The second output of ``LSTMWithSourceTensor`` with ``descriptor.training = true`` or ``descriptor.produceCell = true``.
///   - stateGradient: Input gradient for state coming from the future timestep - optional, if missing assumes zeroes.
///   - cellGradient: Input gradient for cell coming from the future timestep - optional, if missing assumes zeroes.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - peephole: Tensor containing the peephole vector `v` - optional, if missing assumes zeroes. Shape is [8H], ie. a vector for each gate.
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it. 
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for peephole, for initState and for initCell.
-(NSArray<MPSGraphTensor *> *) LSTMGradientsWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                              sourceGradient:(MPSGraphTensor *) sourceGradient
                                                      zState:(MPSGraphTensor *) zState
                                               cellOutputFwd:(MPSGraphTensor *) cellOutputFwd
                                               stateGradient:(MPSGraphTensor * _Nullable) stateGradient
                                                cellGradient:(MPSGraphTensor * _Nullable) cellGradient
                                                 inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                        bias:(MPSGraphTensor * _Nullable) bias
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                    initCell:(MPSGraphTensor * _Nullable) initCell
                                                        mask:(MPSGraphTensor * _Nullable) mask
                                                    peephole:(MPSGraphTensor * _Nullable) peephole
                                                  descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTMGradients(_:recurrentWeight:sourceGradient:zState:cellOutputFwd:stateGradient:cellGradient:inputWeight:bias:initState:initCell:mask:peephole:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The third output of ``LSTMWithSourceTensor`` with ``descriptor.training = true``.
///   - cellOutputFwd: The second output of ``LSTMWithSourceTensor`` with ``descriptor.training = true`` or ``descriptor.produceCell = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState and for initCell.
-(NSArray<MPSGraphTensor *> *) LSTMGradientsWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                              sourceGradient:(MPSGraphTensor *) sourceGradient
                                                      zState:(MPSGraphTensor *) zState
                                               cellOutputFwd:(MPSGraphTensor *) cellOutputFwd
                                                 inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                        bias:(MPSGraphTensor * _Nullable) bias
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                    initCell:(MPSGraphTensor * _Nullable) initCell
                                                        mask:(MPSGraphTensor * _Nullable) mask
                                                  descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTMGradients(_:recurrentWeight:sourceGradient:zState:cellOutputFwd:inputWeight:bias:initState:initCell:mask:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The third output of ``LSTMWithSourceTensor`` with ``descriptor.training = true``.
///   - cellOutputFwd: The second output of ``LSTMWithSourceTensor`` with ``descriptor.training = true`` or ``descriptor.produceCell = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState and for initCell.
-(NSArray<MPSGraphTensor *> *) LSTMGradientsWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                              sourceGradient:(MPSGraphTensor *) sourceGradient
                                                      zState:(MPSGraphTensor *) zState
                                               cellOutputFwd:(MPSGraphTensor *) cellOutputFwd
                                                 inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                        bias:(MPSGraphTensor * _Nullable) bias
                                                   initState:(MPSGraphTensor * _Nullable) initState
                                                    initCell:(MPSGraphTensor * _Nullable) initCell
                                                  descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTMGradients(_:recurrentWeight:sourceGradient:zState:cellOutputFwd:inputWeight:bias:initState:initCell:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates an LSTM gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,4H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,8H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,4H,H] and otherwise it is [4H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The third output of ``LSTMWithSourceTensor`` with ``descriptor.training = true``.
///   - cellOutputFwd: The second output of ``LSTMWithSourceTensor`` with ``descriptor.training = true`` or ``descriptor.produceCell = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [8H,I] and otherwise it is [4H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [8H] and otherwise it is [4H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - initCell: Initial internal cell of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The LSTM op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for ``sourceGradient`` and ``mask``.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState and for initCell.
-(NSArray<MPSGraphTensor *> *) LSTMGradientsWithSourceTensor:(MPSGraphTensor *) source
                                             recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                              sourceGradient:(MPSGraphTensor *) sourceGradient
                                                      zState:(MPSGraphTensor *) zState
                                               cellOutputFwd:(MPSGraphTensor *) cellOutputFwd
                                                  descriptor:(MPSGraphLSTMDescriptor *) descriptor
                                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( LSTMGradients(_:recurrentWeight:sourceGradient:zState:cellOutputFwd:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(12.3), ios(15.4), tvos(15.4));

/// Creates a GRU operation and return the value and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows: 
/// ```md 
/// for t = 0 to T-1 
///   z[t] = fz( (h[t-1] m) R^T + x[t] W^T + b ),
///   r[t] = fr( (h[t-1] m) R^T + x[t] W^T + b ),
///   c[t] = (h[t-1] r[t] m) R^T
///   o[t] = fo( c[t] + x[t] W^T + b )
///   h[t] = z[t]h[t-1] + (1-z[t])o[t]
/// ``` 
/// If ``resetAfter = YES`` then `c[t]` is replaced by
/// ```md 
///   c[t] = ( (h[t-1] m) R^T + b2 ) r[t]
/// ``` 
/// If ``flipZ = YES`` then `h[t]` is replaced by
/// ```md 
///   h[t] = (1-z[t])h[t-1] + z[t]o[t].
/// ``` 
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional  ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
/// `b2` is an optional ``resetBias`` vector, only used when ``resetAfter = YES``.
/// See ``MPSGraphGRUDescriptor`` for different `activation` options for `f()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - secondaryBias: Tensor containing the secondary bias vector `b2` - optional, if missing assumes zeroes. Only used with ``reset_after = YES``. Shape is [H], ie. a vector for each gate, or [2H] for bidirectional.
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 depending on value of  ``descriptor.training``.
///            The layout of the state output is [T,N,H] or [T,N,2H] for bidirectional,
///            and the layout of the trainingState output is [T,N,3H] or [T,N,6H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) GRUWithSourceTensor:(MPSGraphTensor *) source
                                   recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                       inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                              bias:(MPSGraphTensor * _Nullable) bias
                                         initState:(MPSGraphTensor * _Nullable) initState
                                              mask:(MPSGraphTensor * _Nullable) mask
                                     secondaryBias:(MPSGraphTensor * _Nullable) secondaryBias
                                        descriptor:(MPSGraphGRUDescriptor *) descriptor
                                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRU(_:recurrentWeight:inputWeight:bias:initState:mask:secondaryBias:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Creates a GRU operation and return the value and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = fz( (h[t-1] m) R^T + x[t] W^T + b ),
///   r[t] = fr( (h[t-1] m) R^T + x[t] W^T + b ),
///   c[t] = (h[t-1] r[t] m) R^T
///   o[t] = fo( c[t] + x[t] W^T + b )
///   h[t] = z[t]h[t-1] + (1-z[t])o[t]
/// ```
/// If ``resetAfter = YES`` then `c[t]` is replaced by
/// ```md
///   c[t] = ( (h[t-1] m) R^T + b2 ) r[t]
/// ```
/// If ``flipZ = YES`` then `h[t]` is replaced by
/// ```md
///   h[t] = (1-z[t])h[t-1] + z[t]o[t].
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional  ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
/// `b2` is an optional ``resetBias`` vector, only used when ``resetAfter = YES``.
/// See ``MPSGraphGRUDescriptor`` for different `activation` options for `f()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 depending on value of  ``descriptor.training``.
///            The layout of the state output is [T,N,H] or [T,N,2H] for bidirectional,
///            and the layout of the trainingState output is [T,N,3H] or [T,N,6H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) GRUWithSourceTensor:(MPSGraphTensor *) source
                                   recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                       inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                              bias:(MPSGraphTensor * _Nullable) bias
                                         initState:(MPSGraphTensor * _Nullable) initState
                                        descriptor:(MPSGraphGRUDescriptor *) descriptor
                                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRU(_:recurrentWeight:inputWeight:bias:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Creates a GRU operation and return the value and optionally the training state tensor.
///
/// This operation returns tensors `h` and optionally `z` that are defined recursively as follows:
/// ```md
/// for t = 0 to T-1
///   z[t] = fz( (h[t-1] m) R^T + x[t] W^T + b ),
///   r[t] = fr( (h[t-1] m) R^T + x[t] W^T + b ),
///   c[t] = (h[t-1] r[t] m) R^T
///   o[t] = fo( c[t] + x[t] W^T + b )
///   h[t] = z[t]h[t-1] + (1-z[t])o[t]
/// ```
/// If ``resetAfter = YES`` then `c[t]` is replaced by
/// ```md
///   c[t] = ( (h[t-1] m) R^T + b2 ) r[t]
/// ```
/// If ``flipZ = YES`` then `h[t]` is replaced by
/// ```md
///   h[t] = (1-z[t])h[t-1] + z[t]o[t].
/// ```
/// `W` is optional ``inputWeight``, `R` is ``recurrentWeight``, `b` is optional  ``bias``, `m` is optional ``mask``,
/// `x[t]` is ``source`` `h[t]` is the first output, `z[t]` is the second output (optional) and `h[-1]` is ``initState``.
/// `b2` is an optional ``resetBias`` vector, only used when ``resetAfter = YES``.
/// See ``MPSGraphGRUDescriptor`` for different `activation` options for `f()`.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array of size 1 or 2 depending on value of  ``descriptor.training``.
///            The layout of the state output is [T,N,H] or [T,N,2H] for bidirectional,
///            and the layout of the trainingState output is [T,N,3H] or [T,N,6H] for bidirectional.
-(NSArray<MPSGraphTensor *> *) GRUWithSourceTensor:(MPSGraphTensor *) source
                                   recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                       inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                              bias:(MPSGraphTensor * _Nullable) bias
                                        descriptor:(MPSGraphGRUDescriptor *) descriptor
                                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRU(_:recurrentWeight:inputWeight:bias:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Creates a GRU gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``GRUWithSourceTensor`` with  ``descriptor.training = true``.
///   - outputFwd: The first output of ``GRUWithSourceTensor`` with ``descriptor.training = true``.
///   - stateGradient: Input gradient for state coming from the future timestep - optional, if missing assumes zeroes.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - mask: Tensor containing the mask `m` - optional, if missing assumes ones. Useful for dropout.
///   - secondaryBias: Tensor containing the secondary bias vector `b2` - optional, if missing assumes zeroes. Only used with ``reset_after = YES``. Shape is [H], ie. a vector for each gate, or [2H] for bidirectional.
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for `sourceGradient` and `mask`. 
/// In case an input is nil, no gradient will be returned for it. 
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState, for secondaryBias.
-(NSArray<MPSGraphTensor *> *) GRUGradientsWithSourceTensor:(MPSGraphTensor *) source
                                            recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                             sourceGradient:(MPSGraphTensor *) sourceGradient
                                                     zState:(MPSGraphTensor *) zState
                                                  outputFwd:(MPSGraphTensor *) outputFwd
                                              stateGradient:(MPSGraphTensor * _Nullable) stateGradient
                                                inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                       bias:(MPSGraphTensor * _Nullable) bias
                                                  initState:(MPSGraphTensor * _Nullable) initState
                                                       mask:(MPSGraphTensor * _Nullable) mask
                                              secondaryBias:(MPSGraphTensor * _Nullable) secondaryBias
                                                 descriptor:(MPSGraphGRUDescriptor *) descriptor
                                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRUGradients(_:recurrentWeight:sourceGradient:zState:outputFwd:stateGradient:inputWeight:bias:initState:mask:secondaryBias:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Creates a GRU gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``GRUWithSourceTensor`` with  ``descriptor.training = true``.
///   - outputFwd: The first output of ``GRUWithSourceTensor`` with ``descriptor.training = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - initState: Initial internal state of the LSTM `h[-1]` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [N,2H] and otherwise it is [N,H].
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for `sourceGradient` and `mask`.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias, for initState.
-(NSArray<MPSGraphTensor *> *) GRUGradientsWithSourceTensor:(MPSGraphTensor *) source
                                            recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                             sourceGradient:(MPSGraphTensor *) sourceGradient
                                                     zState:(MPSGraphTensor *) zState
                                                  outputFwd:(MPSGraphTensor *) outputFwd
                                                inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                       bias:(MPSGraphTensor * _Nullable) bias
                                                  initState:(MPSGraphTensor * _Nullable) initState
                                                 descriptor:(MPSGraphGRUDescriptor *) descriptor
                                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRUGradients(_:recurrentWeight:sourceGradient:zState:outputFwd:inputWeight:bias:initState:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Creates a GRU gradient operation and returns the gradient tensor values.
///
/// - Parameters:
///   - source: Tensor containing the source data `x[t]` - shape should be [T,N,I]. In case ``inputWeight = nil`` and ``bidirectional = NO`` then the layout is [T,N,3H] and for ``inputWeight = nil`` and ``bidirectional = YES`` the layout is [T,N,6H].
///   - recurrentWeight: Tensor containing the recurrent weights `R`. For ``bidirectional`` the layout is [2,3H,H] and otherwise it is [3H,H].
///   - sourceGradient: Input gradient, that is gradient of a tensor wrt. to first output of the forward pass.
///   - zState: The second output of ``GRUWithSourceTensor`` with  ``descriptor.training = true``.
///   - outputFwd: The first output of ``GRUWithSourceTensor`` with ``descriptor.training = true``.
///   - inputWeight: Tensor containing the input weights matrix `W` - optional, if missing assumes diagonal unit-matrix. For ``bidirectional`` the layout is [6H,I] and otherwise it is [3H,I].
///   - bias: Tensor containing the bias `b` - optional, if missing assumes zeroes. For ``bidirectional`` the layout is [6H] and otherwise it is [3H].
///   - descriptor: The GRU op definition.
///   - name: The name for the operation.
/// - Returns: A valid MPSGraphTensor array containing gradients for each input tensor, except for `sourceGradient` and `mask`.
/// In case an input is nil, no gradient will be returned for it.
/// The order of the gradients will be: for source, for recurrentWeight, for inputWeight, for bias.
-(NSArray<MPSGraphTensor *> *) GRUGradientsWithSourceTensor:(MPSGraphTensor *) source
                                            recurrentWeight:(MPSGraphTensor *) recurrentWeight
                                             sourceGradient:(MPSGraphTensor *) sourceGradient
                                                     zState:(MPSGraphTensor *) zState
                                                  outputFwd:(MPSGraphTensor *) outputFwd
                                                inputWeight:(MPSGraphTensor * _Nullable) inputWeight
                                                       bias:(MPSGraphTensor * _Nullable) bias
                                                 descriptor:(MPSGraphGRUDescriptor *) descriptor
                                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( GRUGradients(_:recurrentWeight:sourceGradient:zState:outputFwd:inputWeight:bias:descriptor:name:))
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

@end

NS_ASSUME_NONNULL_END
#endif /* MPSGraphRNNOps_h */
