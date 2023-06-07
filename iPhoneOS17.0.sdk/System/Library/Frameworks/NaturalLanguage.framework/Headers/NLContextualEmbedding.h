/*    NLContextualEmbedding.h
      Copyright (c) 2022-2023, Apple Inc. All rights reserved.
*/

#import <Foundation/Foundation.h>
#import <NaturalLanguage/NLEmbedding.h>
#import <NaturalLanguage/NLLanguage.h>
#import <NaturalLanguage/NLScript.h>
#import <NaturalLanguage/NLTokenizer.h>

NS_ASSUME_NONNULL_BEGIN

@class NLContextualEmbeddingResult;

/* NLContextualEmbedding is a class representing a model that computes sequences of embedding vectors for natural-language utterances. Predefined contextual embeddings are provided for certain languages/scripts.
*/

NS_CLASS_AVAILABLE(14_0, 17_0)
@interface NLContextualEmbedding : NSObject

- (instancetype)init NS_UNAVAILABLE;

/* Each embedding model has a string identifier that uniquely identifies it. When an embedding is used for training, keep track of the identifier. It should be used to locate the same embedding at inference time.
*/
+ (nullable instancetype)contextualEmbeddingWithModelIdentifier:(NSString *)modelIdentifier;

typedef NSString *NLContextualEmbeddingKey NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT NLContextualEmbeddingKey const NLContextualEmbeddingKeyLanguages;
FOUNDATION_EXPORT NLContextualEmbeddingKey const NLContextualEmbeddingKeyScripts;
FOUNDATION_EXPORT NLContextualEmbeddingKey const NLContextualEmbeddingKeyRevision;

/* Search the catalog of available embeddings by languages, scripts, or revision numbers.
*/
+ (NSArray<NLContextualEmbedding *> *)contextualEmbeddingsForValues:(NSDictionary<NLContextualEmbeddingKey, id> *)valuesDictionary;

/* Convenience APIs for finding the most recent embedding suitable for handling the given language or script.
*/
+ (nullable NLContextualEmbedding *)contextualEmbeddingWithLanguage:(NLLanguage)language;
+ (nullable NLContextualEmbedding *)contextualEmbeddingWithScript:(NLScript)script;

/* Metadata associated with an embedding.
*/
@property (readonly, copy) NSString *modelIdentifier;
@property (readonly, copy) NSArray <NLLanguage> *languages;
@property (readonly, copy) NSArray <NLScript> *scripts;
@property (readonly) NSUInteger revision;
@property (readonly) NSUInteger dimension;

/* When an NLContextualEmbedding is created, the model is not loaded by default until it is needed. The load and unload methods can be used to control when the model is loaded. The return value of load indicates whether it succeeded. The load method will fail if the necessary assets for the specified model are not present on device, in which case hasAvailableAssets and requestEmbeddingAssetsWithCompletionHandler: can be used to manage the loading of the assets.
*/
- (BOOL)loadWithError:(NSError **)error;
- (void)unload;

/* This is the method for applying an embedding to a string and obtaining the resulting embedding vectors, encapsulated in an NLContextualEmbeddingResult object. If the language of the string is known, it may be specified here, otherwise it will be inferred from the string.
*/
- (nullable NLContextualEmbeddingResult *)embeddingResultForString:(NSString *)string language:(nullable NLLanguage)language error:(NSError **)error;

/* A given NLContextualEmbedding can be loaded and used only if the necessary assets have been loaded onto the current device. Clients may use hasAvailableAssets to determine whether they are, and if they have not been, clients may put in a request for those assets. If they are available for loading, then they will be requested and at some point will be loaded and made available on the device, and the completion handler will be called on an arbitrary queue. The completion handler may be called immediately if the state of the assets is already known or if an error occurs.
*/

typedef NS_ENUM(NSInteger, NLContextualEmbeddingAssetsResult) {
   NLContextualEmbeddingAssetsResultAvailable,
   NLContextualEmbeddingAssetsResultNotAvailable,
   NLContextualEmbeddingAssetsResultError
} NS_SWIFT_NAME(NLContextualEmbedding.AssetsResult);

@property (readonly) BOOL hasAvailableAssets;
- (void)requestEmbeddingAssetsWithCompletionHandler:(void (^)(NLContextualEmbeddingAssetsResult result, NSError * _Nullable error))completionHandler;

@end

/* NLContextualEmbeddingResult is a class representing the embedding vectors resulting from applying a contextual embedding to a given string. Each embedding vector represents a given range in the string.
*/

NS_CLASS_AVAILABLE(14_0, 17_0)
@interface NLContextualEmbeddingResult : NSObject

- (instancetype)init NS_UNAVAILABLE;

@property (readonly, copy) NSString *string;
@property (readonly, copy) NLLanguage language;

- (nullable NSArray <NSNumber *> *)tokenVectorAtIndex:(NSUInteger)characterIndex tokenRange:(nullable NSRangePointer)tokenRange NS_REFINED_FOR_SWIFT;
- (void)enumerateTokenVectorsInRange:(NSRange)range usingBlock:(void (NS_NOESCAPE ^)(NSArray <NSNumber *> *tokenVector, NSRange tokenRange, BOOL *stop))block NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
