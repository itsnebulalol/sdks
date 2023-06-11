//
//  MPSGraphMemoryOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 11/10/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphMemoryOps_h
#define MPSGraphMemoryOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraphVariableOp : MPSGraphOperation

/// shape of the variable
@property (readonly, nonnull, nonatomic) MPSShape *shape;

/// dataType of the variable
@property (readonly, nonatomic) MPSDataType dataType;

@end

MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MemoryOps)

/// Create a placeholder op and return the result tensor
///
/// - Parameters:
///   - shape: shape of the output tensor, nil shape will result in an unranked tensor
///   - dataType: dataType of the placeholder tensor
///   - name: name for the placeholder operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) placeholderWithShape:(MPSShape * _Nullable) shape
                                dataType:(MPSDataType) dataType
                                    name:(NSString * _Nullable) name
MPS_SWIFT_NAME( placeholder(shape:dataType:name:) );

/// Create a placeholder op and return the result tensor 
/// dataType of the placeholder tensor set to MPSDataTypeFloat32
///
/// - Parameters:
///   - shape: shape of the output tensor, nil shape will result in an unranked tensor
///   - name: name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) placeholderWithShape:(MPSShape * _Nullable) shape
                                    name:(NSString * _Nullable) name
MPS_SWIFT_NAME( placeholder(shape:name:) );


/// Create a constant op and return the result tensor
///
/// - Parameters:
///   - data: data for the tensor, number of bytes should be sizeof(dataType)numberOfElements
///   - shape: shape of the output tensor, has to be statically shaped
///   - dataType: dataType of theconstant tensor
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithData:(NSData *) data
                               shape:(MPSShape *) shape
                            dataType:(MPSDataType) dataType
MPS_SWIFT_NAME( constant(_:shape:dataType:) );

/// Create a constant op and return the result tensor
///
/// - Parameters:
///   - scalar: scalar to fill the entire tensor values with
///   - dataType: dataType of the constant tensor
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithScalar:(double) scalar
                              dataType:(MPSDataType) dataType
MPS_SWIFT_NAME( constant(_:dataType:) );

/// Create a constant op and return the result tensor
///
/// - Parameters:
///   - scalar: scalar to fill the entire tensor values with
///   - shape: shape of the output tensor.
///   - dataType: dataType of the constant tensor
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithScalar:(double) scalar
                                 shape:(MPSShape *) shape
                              dataType:(MPSDataType) dataType
MPS_SWIFT_NAME( constant(_:shape:dataType:) );

/// Create a complex constant op with MPSDataTypeComplexFloat32 data type and return the result tensor.
///
/// - Parameters:
///   - realPart: the real part of the complex scalar to fill the entire tensor values with.
///   - imaginaryPart: the imaginary part of the complex scalar to fill the entire tensor values with.
///   - dataType: dataType of the constant tensor.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithRealPart:(double) realPart
                           imaginaryPart:(double) imaginaryPart
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( complexConstant(realPart:imaginaryPart:) );

/// Create a complex constant op and return the result tensor.
///
/// - Parameters:
///   - realPart: the real part of the complex scalar to fill the entire tensor values with.
///   - imaginaryPart: the imaginary part of the complex scalar to fill the entire tensor values with.
///   - dataType: dataType of the constant tensor.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithRealPart:(double) realPart
                           imaginaryPart:(double) imaginaryPart
                                dataType:(MPSDataType) dataType
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( complexConstant(realPart:imaginaryPart:dataType:) );

/// Create a complex constant op and return the result tensor.
///
/// - Parameters:
///   - realPart: the real part of the complex scalar to fill the entire tensor values with.
///   - imaginaryPart: the imaginary part of the complex scalar to fill the entire tensor values with.
///   - shape: shape of the output tensor, has to be statically shaped.
///   - dataType: dataType of the constant tensor.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) constantWithRealPart:(double) realPart
                           imaginaryPart:(double) imaginaryPart
                                   shape:(MPSShape *) shape
                                dataType:(MPSDataType) dataType
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( complexConstant(realPart:imaginaryPart:shape:dataType:) );

/// Create a variable op and return the result tensor
///
/// - Parameters:
///   - data: data for the tensor, number of bytes should be sizeof(dataType)numberOfElements
///   - shape: shape of the output tensor, has to be statically shaped
///   - dataType: dataType of theconstant tensor
///   - name: name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) variableWithData:(NSData *) data
                               shape:(MPSShape *) shape
                            dataType:(MPSDataType) dataType
                                name:(NSString * _Nullable) name;

/// Create a read op which reads at this point of execution of the graph and return the result tensor
///
/// - Parameters:
///   - variable: variable resource tensor to read from
///   - name: name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) readVariable:(MPSGraphTensor *) variable
                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( read(_:name:) );

/// Create a read op which reads at this point of execution of the graph and return the result tensor
///
/// - Parameters:
///   - variable: variable resource tensor to read from
///   - tensor: tensor to assign to variable
///   - name: name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphOperation *) assignVariable:(MPSGraphTensor *) variable
                    withValueOfTensor:(MPSGraphTensor *) tensor
                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( assign(_:tensor:name:) );


@end


NS_ASSUME_NONNULL_END

#endif /* MPSGraphMemoryOps_h */
