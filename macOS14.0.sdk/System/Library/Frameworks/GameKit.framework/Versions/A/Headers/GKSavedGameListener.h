// Copyright © Apple Inc. All rights reserved.

#import <Foundation/NSObjCRuntime.h> // NS_ASSUME_NONNULL_BEGIN
#import <objc/NSObject.h> // NSObject

@class NSArray;
@class GKPlayer;
@class GKSavedGame;

NS_ASSUME_NONNULL_BEGIN
NS_CLASS_AVAILABLE(10_10, 8_0) __WATCHOS_PROHIBITED __TVOS_UNAVAILABLE
@protocol GKSavedGameListener <NSObject>
@optional

/// Called when a player’s saved game data has been modified.
- (void)player:(GKPlayer *)player didModifySavedGame:(GKSavedGame *)savedGame NS_AVAILABLE(10_10, 8_0) __TVOS_UNAVAILABLE;

/// Called when a conflict has arisen between different versions of the same saved game. This can happen when multiple devices write to the same saved game while one or more is offline. The application should determine the correct data to use, then call resolveConflictingSavedGames:withData:completionHandler:. This may require data merging or asking the user.
- (void)player:(GKPlayer *)player hasConflictingSavedGames:(NSArray<GKSavedGame *> *)savedGames NS_AVAILABLE(10_10, 8_0) __TVOS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
