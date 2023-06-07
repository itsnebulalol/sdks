//
//  MPSGraphArithmeticOps.h
//  MetalPerformanceShadersGraph
//
//  Created on 11/10/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphArithmeticOps_h
#define MPSGraphArithmeticOps_h

#import <MetalPerformanceShadersGraph/MPSGraph.h>

NS_ASSUME_NONNULL_BEGIN


MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraph(MPSGraphArithmeticOps)


#pragma mark - UnaryArithmeticOps

/// Identity op - it copies input tensor values to output
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) identityWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name;

/// It applies natural exponent
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) exponentWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name;

/// It applies exponent with base 2
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) exponentBase2WithTensor:(MPSGraphTensor *) tensor
                                       name:(NSString * _Nullable) name;

/// It applies exponent with base 10
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) exponentBase10WithTensor:(MPSGraphTensor *) tensor
                                        name:(NSString * _Nullable) name;

/// It applies natural log to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logarithmWithTensor:(MPSGraphTensor *) tensor
                                   name:(NSString * _Nullable) name;

/// It applies log with base 2 to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logarithmBase2WithTensor:(MPSGraphTensor *) tensor
                                        name:(NSString * _Nullable) name;

/// It applies log with base 10 to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logarithmBase10WithTensor:(MPSGraphTensor *) tensor
                                         name:(NSString * _Nullable) name;

/// It applies square to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) squareWithTensor:(MPSGraphTensor *) tensor
                                name:(NSString * _Nullable) name;

/// It applies square root to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) squareRootWithTensor:(MPSGraphTensor *) tensor
                                    name:(NSString * _Nullable) name;

/// It returns reverse square root of input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) reverseSquareRootWithTensor:(MPSGraphTensor *) tensor
                                           name:(NSString * _Nullable) name;

/// It applies reciprocal to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) reciprocalWithTensor:(MPSGraphTensor *) tensor
                                    name:(NSString * _Nullable) name;

/// It applies absolute to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) absoluteWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name;

/// Return the absolute square of the input tensor.
///
/// - Parameters:
///   - tensor: input tensor.
///   - name: name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) absoluteSquareWithTensor:(MPSGraphTensor *) tensor
                                        name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( absoluteSquare(tensor:name:) );

/// It applies negative to input tensor elements
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) negativeWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name;

/// Gets back sign of input tensor elements,
/// `1.0 ifx > 0, -0.0 if x = -0.0, +0.0 ifx = +0.0, or -1.0 if x < 0. Returns 0.0 if x is a NaN.`
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) signWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Gets back signbit of input tensor elements,
/// `true` if the sign bit is set for the floating-point value in x; otherwise returns `false`
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) signbitWithTensor:(MPSGraphTensor *) tensor
                                 name:(NSString * _Nullable) name;

/// Output tensor of elements with ceil of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) ceilWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with floor of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) floorWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with round of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) roundWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with round of input tensor elements,
/// Round values to integral value using round to nearest even rounding mode in floating-point format.
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) rintWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with sin of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) sinWithTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name;

/// Output tensor of elements with cos of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) cosWithTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name;

/// Output tensor of elements with tan of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) tanWithTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name;

/// Output tensor of elements with sinh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) sinhWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with cosh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) coshWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with tanh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) tanhWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with asin of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) asinWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with acos of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) acosWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with atan of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) atanWithTensor:(MPSGraphTensor *) tensor
                              name:(NSString * _Nullable) name;

/// Output tensor of elements with asinh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) asinhWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with acosh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) acoshWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with acosh of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) atanhWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with logical not of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) notWithTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name;

/// Output tensor of elements with isInfinite of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) isInfiniteWithTensor:(MPSGraphTensor *) tensor
                                    name:(NSString * _Nullable) name;

/// Output tensor of elements with isFinite of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) isFiniteWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name;

/// Output tensor of elements with isNaN of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) isNaNWithTensor:(MPSGraphTensor *) tensor
                               name:(NSString * _Nullable) name;

/// Output tensor of elements with erf of input tensor elements,
///
/// - Parameters:
///   - tensor: Input tensor
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) erfWithTensor:(MPSGraphTensor *) tensor
                             name:(NSString * _Nullable) name;

/// Truncate op - floor for positive inputs, ceil for negative.
///
/// - Parameters:
///   - tensor: The input
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) truncateWithTensor:(MPSGraphTensor *) tensor
                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( truncate(_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0));

/// Return bitwise not of tensor, takes in only integer dataTypes
///
/// - Parameters:
///   - tensor: input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseNOTWithTensor:(MPSGraphTensor *) tensor
                                    name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseNOT(_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return population count of a tensor, takes in only integer dataTypes
///
/// - Parameters:
///   - tensor: input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwisePopulationCountWithTensor:(MPSGraphTensor *) tensor
                                                name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwisePopulationCount(_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return the complex conjugate of the input tensor.
///
/// - Parameters:
///   - tensor: input tensor.
///   - name: name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) conjugateWithTensor:(MPSGraphTensor *) tensor
                                   name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( conjugate(tensor:name:) );

#pragma mark - BinaryArithmeticOps

/// Create Add op and return the result tensor, it supports broadcasting as well 
/// ```md 
/// resultTensor = primaryTensor + secondaryTensor 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) additionWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                              secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                         name:(NSString * _Nullable) name
MPS_SWIFT_NAME( addition(_:_:name:) );



/// Create Subtract op and return the result tensor, it supports broadcasting as well 
/// ```md 
/// resultTensor = primaryTensor - secondaryTensor 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) subtractionWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                 secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( subtraction(_:_:name:) );



/// Create Multiply op and return the result tensor, it supports broadcasting as well 
/// ```md 
/// resultTensor = primaryTensorsecondaryTensor 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) multiplicationWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                    secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( multiplication(_:_:name:) );

/// Create Divide op and return the result tensor, it supports broadcasting as well 
/// ```md 
/// resultTensor = primaryTensor / secondaryTensor 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) divisionWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                              secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                         name:(NSString * _Nullable) name
MPS_SWIFT_NAME( division(_:_:name:) );


/// Create modulo op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor % secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) moduloWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                            secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                       name:(NSString * _Nullable) name
MPS_SWIFT_NAME( modulo(_:_:name:) );


/// Create power op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = pow(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) powerWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                           secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( power(_:_:name:) );


/// Create minimum op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = min(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) minimumWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                             secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( minimum(_:_:name:) );


/// Create maximum op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = max(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) maximumWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                             secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                        name:(NSString * _Nullable) name
MPS_SWIFT_NAME( maximum(_:_:name:) );

/// Create Minimum op and return the result tensor, it supports broadcasting as well. If any of the operands is NaN, NaN is returned 
/// ```md 
/// resultTensor = isNaN(primaryTensor) || isNan(secondaryTensor) ? NaN : min(primaryTensor, secondaryTensor) 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) minimumWithNaNPropagationWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                               secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                          name:(NSString * _Nullable) name
                                                MPS_SWIFT_NAME( minimumWithNaNPropagation(_:_:name:) )
                                                MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Create Maximum op and return the result tensor, it supports broadcasting as well. If any of the operands is NaN, NaN is returned 
/// ```md 
/// resultTensor = isNaN(primaryTensor) || isNan(secondaryTensor) ? NaN : max(primaryTensor, secondaryTensor) 
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) maximumWithNaNPropagationWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                               secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                          name:(NSString * _Nullable) name
                                                MPS_SWIFT_NAME( maximumWithNaNPropagation(_:_:name:) )
                                                MPS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0));

/// Create equal op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor == secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) equalWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                           secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                      name:(NSString * _Nullable) name
MPS_SWIFT_NAME( equal(_:_:name:) );


/// Create not equal op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor != secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) notEqualWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                              secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                         name:(NSString * _Nullable) name
MPS_SWIFT_NAME( notEqual(_:_:name:) );


/// Create lessThan op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor < secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) lessThanWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                              secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                         name:(NSString * _Nullable) name
MPS_SWIFT_NAME( lessThan(_:_:name:) );


/// Create lessThanOrEqualTo op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor <= secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) lessThanOrEqualToWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                       secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( lessThanOrEqualTo(_:_:name:) );


/// Create greaterThan op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor > secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) greaterThanWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                 secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( greaterThan(_:_:name:) );


/// Create greaterThanOrEqual op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor < secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) greaterThanOrEqualToWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                          secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                     name:(NSString * _Nullable) name
MPS_SWIFT_NAME( greaterThanOrEqualTo(_:_:name:) );


/// Create logical AND op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor && secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalANDWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalAND(_:_:name:) );


/// Create logical OR op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = primaryTensor || secondaryTensor
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                               secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                          name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalOR(_:_:name:) );


/// Create logical NAND op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = !(primaryTensor && secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalNANDWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                 secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalNAND(_:_:name:) );


/// Create logical NOR op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = !(primaryTensor || secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalNORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalNOR(_:_:name:) );


/// Create logical XOR op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = XOR(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalXORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalXOR(_:_:name:) );


/// Create logical XNOR op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = XNOR(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) logicalXNORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                 secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( logicalXNOR(_:_:name:) );


/// Create logical atan2 op and return the result tensor, it supports broadcasting as well.
/// Graph computes arc tangent of primaryTensor over secondaryTensor.
/// ```md
/// resultTensor = atan2(primaryTensor, secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) atan2WithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                           secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                      name:(NSString * _Nullable) name;

/// Return bitwise AND of binary representations of 2 integer tensors
///
/// - Parameters:
///   - primaryTensor: primary input tensor, must be integer dataType
///   - secondaryTensor: secondary input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseANDWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseAND(_:_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return bitwise OR of binary representations of 2 integer tensors
///
/// - Parameters:
///   - primaryTensor: primary input tensor, must be integer dataType
///   - secondaryTensor: secondary input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                               secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                          name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseOR(_:_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return bitwise XOR of binary representations of 2 integer tensors
///
/// - Parameters:
///   - primaryTensor: primary input tensor, must be integer dataType
///   - secondaryTensor: secondary input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseXORWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                           name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseXOR(_:_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return bitwise left shifted binary representations of primary integer tensor by secondary tensor amount
///
/// - Parameters:
///   - primaryTensor: primary input tensor, must be integer dataType
///   - secondaryTensor: secondary input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseLeftShiftWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                      secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                 name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseLeftShift(_:_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));

/// Return bitwise right shifted binary representations of primary integer tensor by secondary tensor amount
///
/// - Parameters:
///   - primaryTensor: primary input tensor, must be integer dataType
///   - secondaryTensor: secondary input tensor, must be integer dataType
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) bitwiseRightShiftWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                       secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                                  name:(NSString * _Nullable) name
MPS_SWIFT_NAME( bitwiseRightShift(_:_:name:) )
MPS_AVAILABLE_STARTING(macos(13.0), ios(16.1), tvos(16.1));


#pragma mark - TernaryArithmeticOps

/// Create select op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = select(predicateTensor, truePredicateTensor, falseSelectTensor)
/// ```
///
/// - Parameters:
///   - predicateTensor: tensor with predicate tensor
///   - truePredicateTensor: tensor we get values from if predicate is true
///   - falseSelectTensor: tensor we get values from if predicate is false
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) selectWithPredicateTensor:(MPSGraphTensor *) predicateTensor
                          truePredicateTensor:(MPSGraphTensor *) truePredicateTensor
                         falsePredicateTensor:(MPSGraphTensor *) falseSelectTensor
                                         name:(NSString * _Nullable) name
MPS_SWIFT_NAME( select(predicate:trueTensor:falseTensor:name:) );

/// Create select op and return the result tensor, it supports broadcasting as well
/// ```md
/// resultTensor = clamp(tensor, minValueTensor, maxValueTensor)
/// ```
///
/// - Parameters:
///   - predicateTensor: tensor with input values
///   - truePredicateTensor: tensor with min values to clamp to
///   - falseSelectTensor: tensor with max values to clamp to
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) clampWithTensor:(MPSGraphTensor *) tensor
                     minValueTensor:(MPSGraphTensor *) minValueTensor
                     maxValueTensor:(MPSGraphTensor *) maxValueTensor
                               name:(NSString * _Nullable) name
MPS_SWIFT_NAME( clamp(_:min:max:name:) );



#pragma mark - ConvenienceMathOps
/// Create DivideNoNaN op and return the result tensor, it supports broadcasting as well, returns 0 if divisor is 0
/// ```md
/// resultTensor = select(secondaryTensor, primaryTensor / secondaryTensor, 0)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) divisionNoNaNWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                   secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                              name:(NSString * _Nullable) name
MPS_SWIFT_NAME( divisionNoNaN(_:_:name:) );

/// Create floorModulo op and return the result tensor, it supports broadcasting as well, returns 0 if divisor is 0
/// ```md
/// resultTensor = primaryTensor - (floor(primaryTensor / secondaryTensor) * secondaryTensor)
/// ```
///
/// - Parameters:
///   - primaryTensor: LHS tensor of the binary Op
///   - secondaryTensor: RHS tensor of the binary Op
///   - name: Name for the operation
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) floorModuloWithPrimaryTensor:(MPSGraphTensor *) primaryTensor
                                 secondaryTensor:(MPSGraphTensor *) secondaryTensor
                                            name:(NSString * _Nullable) name
MPS_SWIFT_NAME( floorModulo(_:_:name:) );

#pragma mark - ComplexOps

/// Return the real part of a tensor.
///
/// - Parameters:
///   - tensor: input tensor.
///   - name: name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) realPartOfTensor:(MPSGraphTensor *) tensor
                                name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( realPartOfTensor(tensor:name:) );

/// Return the imaginary part of a tensor.
///
/// - Parameters:
///   - tensor: input tensor.
///   - name: name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) imaginaryPartOfTensor:(MPSGraphTensor *) tensor
                                     name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( imaginaryPartOfTensor(tensor:name:) );

/// Return a complex tensor from the two input tensors.
///
/// - Parameters:
///   - realTensor: the real part of the complex tensor.
///   - imaginaryTensor: the imaginary part of the complex tensor.
///   - name: name for the operation.
/// - Returns: A valid MPSGraphTensor object.
-(MPSGraphTensor *) complexTensorWithRealTensor:(MPSGraphTensor *) realTensor
                                imaginaryTensor:(MPSGraphTensor *) imaginaryTensor
                                           name:(NSString * _Nullable) name
MPS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
MPS_SWIFT_NAME( complexTensor(realTensor:imaginaryTensor:name:) );

@end

NS_ASSUME_NONNULL_END

#endif /* MPSGraphArithmeticOps_h */
