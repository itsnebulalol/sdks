#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIWindowSceneGeometryPreferencesReality.h>)
//
//  UIWindowSceneGeometryPreferencesReality.h
//  UIKit
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <UIKit/UIWindowSceneGeometryPreferences.h>
#import <UIKit/UIWindowSceneGeometry.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// Used as the value for a dimension of a size related preference when wanting to leave it unchanged.
UIKIT_EXTERN const CGFloat UIProposedSceneSizeNoPreference API_AVAILABLE(xros(1.0)) API_UNAVAILABLE(ios, tvos, macos, watchos);

UIKIT_EXTERN API_AVAILABLE(xros(1.0)) API_UNAVAILABLE(ios, tvos, macos, watchos)
@interface UIWindowSceneGeometryPreferencesReality : UIWindowSceneGeometryPreferences

- (instancetype)init NS_REFINED_FOR_SWIFT;

/// Creates a geometry preference with a specific size (specifying UIProposedSceneSizeNoPreference for any dimension of size, will specify no preference, keeping that dimension the same if possible)
- (instancetype)initWithSize:(CGSize)size NS_REFINED_FOR_SWIFT;

/// The preferred size, minimumSize, maximumSize, and resizingRestrictions. Any dimension set to UIProposedSceneSizeNoPreference will retain the existing values.
- (instancetype)initWithSize:(CGSize)size minimumSize:(CGSize)minimumSize maximumSize:(CGSize)maximumSize resizingRestrictions:(UIWindowSceneResizingRestrictions)resizingRestrictions NS_REFINED_FOR_SWIFT;

/// Create a new preference using the existing effective geometry
- (instancetype)initWithCurrentEffectiveGeometry:(UIWindowSceneGeometry *)effectiveGeometry;

/// The preferred system size. Use UIProposedSceneSizeNoPreference to use existing value
@property (nonatomic, assign) CGSize size NS_REFINED_FOR_SWIFT;

/// The preferred minimum size. UIProposedSceneSizeNoPreference to use default value
@property (nonatomic, assign) CGSize minimumSize NS_REFINED_FOR_SWIFT;

/// The preferred maximum size. UIProposedSceneSizeNoPreference for a given to use default value
@property (nonatomic, assign) CGSize maximumSize NS_REFINED_FOR_SWIFT;

/// The user resizable restrictions on the window scene
@property (nonatomic, assign) UIWindowSceneResizingRestrictions resizingRestrictions NS_REFINED_FOR_SWIFT;
@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UIWindowSceneGeometryPreferencesReality.h>
#endif
