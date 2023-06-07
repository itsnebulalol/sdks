//
//  SFErrors.h
//  SpeechRecognition
//
//  Created by Donovan Voss on 10/25/22.
//  Copyright © 2022 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const SFSpeechErrorDomain;
typedef NS_ERROR_ENUM (SFSpeechErrorDomain, SFSpeechErrorCode) {
    /** Error may include `NSUnderlyingErrorKey` in `userInfo`.*/
    SFSpeechErrorCodeInternalServiceError,

    /** Audio input timestamp overlaps or precedes prior audio input. */
    SFSpeechErrorCodeAudioDisordered,
    
    /**
     Audio input is in unexpected format.
     
     The back end may be able to cope by loading matching models on demand, but this is still an error the client really ought to resolve on its end.
     */
    SFSpeechErrorCodeUnexpectedAudioFormat,
    
    /** Selected locale/options does not have an appropriate model available or downloadable. */
    SFSpeechErrorCodeNoModel,
    
    /** The selected modules do not have an audio format in common. */
    SFSpeechErrorCodeIncompatibleAudioFormats,
  
    /** Querying the SpeechRecognizerWorker's JIT LME profile failed. */
    SFSpeechErrorCodeInvalidJitProfile,
    
    // MARK: CustomLM data related errors
    /** templates were malformed **/
    SFSpeechErrorCodeUndefinedTemplateClassName,

    /** A custom language model file was malformed **/
    SFSpeechErrorCodeMalformedSupplementalModel,
    
    /** An abstract base class method was called **/
    SFSpeechErrorCodeUnimplementedFunctionality,
    
    // MARK: Objective-C output wrapper related errors
    /** Module's result task failed  **/
    SFSpeechErrorCodeModuleOutputFailed
};

NS_ASSUME_NONNULL_END
