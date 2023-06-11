//
//  CKSyncEngine.h
//  CloudKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <CloudKit/CKDefines.h>
#import <CloudKit/CKSyncEngineRecordZoneChangeBatch.h>

@class CKDatabase, CKOperationGroup, CKRecord, CKRecordID, CKRecordZone, CKRecordZoneID, CKSyncEngineConfiguration, CKSyncEngineEvent, CKSyncEngineFetchChangesOptions, CKSyncEngineSendChangesOptions, CKSyncEngineSendChangesContext, CKSyncEngineState, CKSyncEngineStateSerialization;
@protocol CKSyncEngineDelegate;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// `CKSyncEngine` encapsulates the logic of syncing data with a CloudKit database.
///
/// Syncing with CloudKit involves many moving pieces.
/// Apps need to schedule syncs, create and batch operations, subscribe to database changes,
/// listen for push notifications, store sync state, handle a multitude of errors, and more.
/// `CKSyncEngine` is designed to encapsulate this logic in a higher-level API.
///
/// # Start Your Sync Engine
///
/// Generally, you should initialize your `CKSyncEngine` soon after your process launches.
/// The sync engine will perform work in the background on your behalf, and it needs to be initialized
/// so that it can properly listen for push notifications and handle scheduled sync tasks.
///
/// When initializing your sync engine, you need to provide an object conforming to the ``CKSyncEngineDelegate`` protocol.
/// This protocol is the main method of communication between the sync engine and your app.
/// You also need to provide your last known version of the ``CKSyncEngine/State/Serialization``.
/// See ``CKSyncEngine/State`` and ``Event/StateUpdate`` for more details on the sync engine state.
///
/// Note that before using `CKSyncEngine` in your app, you need to add the CloudKit and remote notification capabilities.
///
/// # Sending Changes to the Server
///
/// In order to send changes to the server, you first need to tell the sync engine you have pending changes to send.
/// You can do this by adding pending changes to the sync engine's ``CKSyncEngine/state`` property.
///
/// When you add pending changes to the state, the sync engine will schedule a task to sync.
/// When the sync task runs, the sync engine will start sending changes to the server.
/// The sync engine will automatically send database changes from ``State/pendingDatabaseChanges``, but you need to provide the record zone changes yourself.
/// In order to send record zone changes, you need to return them from ``CKSyncEngineDelegate/nextRecordZoneChangeBatch(_:syncEngine:)``.
///
/// When the sync engine finishes sending a batch of changes to the server,
/// your `CKSyncEngineDelegate` will receive ``Event/sentDatabaseChanges(_:)`` and ``Event/sentRecordZoneChanges(_:)`` events.
/// These events will notify you of the success or failure of the changes you tried to send.
///
/// At a high level, sending changes to the server happens with the following order of operations:
///
/// 1. You add pending changes to ``CKSyncEngine/state``.
/// 2. You receive ``Event/willSendChanges(_:)`` in ``CKSyncEngineDelegate/handleEvent(_:syncEngine:)``
/// 3. If there are pending database changes, the sync engine sends the next batch.
/// 4. If any database changes were sent, your delegate receives``Event/sentDatabaseChanges(_:)``.
/// 5. Repeat from step 3 until all pending database changes are sent, then move on to record zone changes in step 6.
/// 6. The sync engine asks for the next batch of record zone changes by calling ``CKSyncEngineDelegate/nextRecordZoneChangeBatchToSend(_:syncEngine:)``.
/// 7. The sync engine sends the next record zone change batch to the server.
/// 8. If any record zone changes were sent, your delegate receives ``Event/sentRecordZoneChanges(_:)``.
/// 9. If you added any pending database changes during steps 6-8, the sync engine repeats from step 3. Otherwise, it repeats from step 6.
/// 10. When all pending changes are sent, your delegate receives ``Event/didSendChanges(_:)``.
///
/// # Fetching Changes from the Server
///
/// The sync engine will automatically listen for remote notifications, and it will fetch changes from the server when necessary.
/// Generally, you'll receive events in this order:
///
/// 1. Your delegate receives ``Event/willFetchChanges(_:)``.
/// 2. If there are new database changes to fetch, you receive batches of them in ``Event/fetchedDatabaseChanges(_:)`` events.
/// 3. If there are new record zone changes to fetch, you will receive ``Event/willFetchRecordZoneChanges(_:)`` for each zone that has new changes.
/// 4. The sync engine fetches record zone changes and gives you batches of them in ``Event/fetchedRecordZoneChanges(_:)`` events.
/// 5. Your delegate receives ``Event/didFetchRecordZoneChanges(_:)`` for each zone that had changes to fetch.
/// 6. Your delegate receives ``Event/didFetchChanges(_:)``, indicating that sync engine has finished fetching changes.
///
/// # Sync Scheduling
///
/// ## Automatic sync
///
/// By default, the sync engine will automatically schedule sync tasks on your behalf.
/// If the user is signed in, the device has a network connection, and the system is generally in a good state, these scheduled syncs will happen relatively quickly.
/// However, if the device has no network, is low on power, or is otherwise under a heavy load, these automatic syncs might be delayed.
/// Similarly, if the user isn't signed in to an account, the sync engine won't perform any sync tasks at all.
///
/// ## Manual sync
///
/// Generally, you should rely on this automatic sync behavior, but there may be some cases where you want to manually trigger a sync.
/// For example, if you have a pull-to-refresh UI, you can call ``CKSyncEngine/fetchChanges(_:)`` to tell the sync engine to fetch immediately.
/// Or if you want to provide some sort of "backup now" button, you can call ``CKSyncEngine/sendChanges(_:)`` to send to the server immediately.
///
/// ### Testing
///
/// These manual sync functions might also be useful during automated testing.
/// When writing automated tests, you can turn off automatic sync via ``CKSyncEngine/Configuration/automaticallySync``.
/// Then, you'll have complete control over the ordering of sync events.
/// This allows you to interject behavior in the sync flow and simulate specific sequences of events.
///
/// # Error Handling
///
/// There are some transient errors that the sync engine will handle automatically behind the scenes.
/// The sync engine will retry the operations for these transient errors automatically when it makes sense to do so.
/// Specifically, the sync engine will handle the following errors on your behalf:
///
/// * ``CKErrorCode/notAuthenticated``
/// * ``CKErrorCode/accountTemporarilyUnavailable``
/// * ``CKErrorCode/networkFailure``
/// * ``CKErrorCode/networkUnavailable``
/// * ``CKErrorCode/requestRateLimited``
/// * ``CKErrorCode/serviceUnavailable``
/// * ``CKErrorCode/zoneBusy``
///
/// When the sync engine encounters one of these errors, it will wait for the system to be in a good state and try again.
/// For example, if the server sends back a `.requestRateLimited` error, the sync engine will respect this throttle and try again after the retry-after time.
///
/// `CKSyncEngine` will _not_ handle errors that require application-specific logic.
/// For example, if you try to save a record and get a ``CKErrorCode/serverRecordChanged``, you need to handle that error yourself.
/// There are plenty of errors that the sync engine cannot handle on your behalf, see ``CKErrorCode`` for a list of all the possible errors.
///
/// # Accounts
///
/// `CKSyncEngine` monitors for account status, and it will only sync if there's an account signed in.
/// Because of this, you can initialize your `CKSyncEngine` at any time, regardless of account status.
/// If there is no account, or if the user disabled sync in settings, the sync engine will stay dormant in the background.
/// Once an account is available, the sync engine will start syncing automatically.
///
/// It will also listen for when the user signs in or out of their account.
/// When it notices an account change, it will send an ``Event/accountChange(_:)`` to your delegate.
/// It's your responsibility to react appropriately to this change and update your local persistence.
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
CK_SUBCLASSING_RESTRICTED
NS_SWIFT_SENDABLE
@interface CKSyncEngine : NSObject

/// Initializes a `CKSyncEngine` with the given configuration.
/// See properties on ``CKSyncEngineConfiguration`` for more details on all the options.
- (instancetype)initWithConfiguration:(CKSyncEngineConfiguration *)configuration NS_SWIFT_NAME(init(_:));

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The database this sync engine will sync with.
@property (atomic, readonly, strong) CKDatabase *database;

/// A collection of state properties used to efficiently manage sync engine operation.
/// See ``CKSyncEngineState`` for more details.
@property (atomic, readonly, strong) CKSyncEngineState *state;

#pragma mark - Fetching and Sending

/// Fetches changes from the server immediately, bypassing the system scheduler.
///
/// By default, the sync engine will automatically fetch changes from the server for you, and you should not have to call this function.
/// However, you can call this if for some reason you need to ensure all changes have been fetched from the server before proceeding.
/// For example, you might use this in your tests to simulate specific sync scenarios.
///
/// Fetching changes from the server might result in some events being posted to your delegate via `handleEvent`.
/// For example, you might receive a `CKSyncEngineWillFetchChangesEvent` or `CKSyncEngineWillFetchChangesEvent`.
/// This will not complete until all the relevant events have been handled by your delegate.
- (void)fetchChangesWithCompletionHandler:(nullable void (NS_SWIFT_SENDABLE ^)(NSError * _Nullable error))completionHandler;

/// Fetches changes from the server with the specified options.
/// See ``fetchChangesWithCompletionHandler:`` for more information.
- (void)fetchChangesWithOptions:(CKSyncEngineFetchChangesOptions *)options completionHandler:(nullable void (NS_SWIFT_SENDABLE ^)(NSError * _Nullable error))completionHandler NS_SWIFT_ASYNC_NAME(fetchChanges(_:)) NS_SWIFT_NAME(fetchChanges(_:completionHandler:));

/// Sends any pending changes to the server immediately, bypassing the system scheduler.
///
/// By default, the sync engine will automatically send changes to the server for you, and you should not have to call this function.
/// However, you can call this if for some reason you need to ensure all changes have been sent to the server before proceeding.
/// For example, you might consider using this in your tests to simulate specific sync scenarios.
///
/// Sending changes to the server might result in some events being posted to your delegate via `handleEvent`.
/// For example, you might receive a `CKSyncEngineWillSendChangesEvent` or `CKSyncEngineDidSendChangesEvent`.
/// This function will not return until all the relevant events have been handled by your delegate.
- (void)sendChangesWithCompletionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler;

/// Sends pending changes to the server with the specified options.
/// See discussion in ``sendChangesWithCompletionHandler:`` for more information.
- (void)sendChangesWithOptions:(CKSyncEngineSendChangesOptions *)options completionHandler:(nullable void (NS_SWIFT_SENDABLE ^)(NSError * _Nullable error))completionHandler NS_SWIFT_ASYNC_NAME(sendChanges(_:)) NS_SWIFT_NAME(sendChanges(_:completionHandler:));

/// Cancels any currently executing or pending sync operations.
///
/// Note that cancellation does not happen synchronously, and it's possible some in-flight operations will succeed.
- (void)cancelOperationsWithCompletionHandler:(nullable void (NS_SWIFT_SENDABLE ^)(void))completionHandler;

@end

#pragma mark - Delegate

/// An interface by which `CKSyncEngine` communicates with your application.
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
@protocol CKSyncEngineDelegate <NSObject>

/// Called when an event occurs during the sync engine's operation.
///
/// This is how you receive updates about local state changes, fetched changes, sent changes, and more.
/// See ``CKSyncEngineEventType`` and ``CKSyncEngineEvent`` for all the possible events that might be posted.
///
/// ## Event ordering
///
/// Events will be given to your delegate serially.
/// You will not receive the next event until you have returned from this function for the previous event.
- (void)syncEngine:(CKSyncEngine *)syncEngine handleEvent:(CKSyncEngineEvent *)event NS_SWIFT_NAME(syncEngine(_:handleEvent:));

/// Called to get the next batch of record zone changes to send to the server.
///
/// The sync engine will call this function when it's about to to send changes to the server.
/// This might happen during an automatically scheduled sync or as a result of you calling `sendChanges`.
/// Provide the next batch of record zone changes to send by returning them from this function.
///
/// Once the sync engine starts sending changes, it will continue until there are no more pending changes to send.
/// You can return `nil` to indicate that you have no more pending changes for now.
/// The next time the sync engine tries to sync, it will call this again to get any new pending changes.
///
/// ## Sending changes for specific zones
///
/// When you call `sendChanges` for a specific set of zone IDs, you should make sure to only send changes for those zones.
/// You can do this by checking the `zoneIDs` property on ``CKSyncEngineSendChangesContext/options``.
///
/// For example, you might have some code like this:
///
/// ```objc
/// - (CKSyncEngineRecordZoneChangeBatch *)syncEngine:(CKSyncEngine *)syncEngine nextRecordZoneChangeBatchForContext:(CKSyncEngineSendChangesContext *)context {
///     NSArray<CKRecordZoneID *> *zoneIDs = context.options.zoneIDs;
///
///     NSArray<CKSyncEnginePendingRecordZoneChange *> *pendingChangesToSave = syncEngine.state.pendingRecordZoneChanges;
///     if (zoneIDs != nil) {
///         NSMutableArray<CKSyncEnginePendingRecordZoneChange *> *filteredChanges = [NSMutableArray new];
///         for (CKSyncEnginePendingRecordZoneChange *pendingChange in pendingChangesToSave) {
///             if ([zoneIDs containsObject:pendingChange.recordID.zoneID]) {
///                 [filteredChanges addObject:pendingChange];
///             }
///         }
///         pendingChangesToSave = filteredChanges;
///     }
///
///     CKSyncEngineRecordZoneChangeBatch *batch = [[CKSyncEngineRecordZoneChangeBatch alloc] initWithPendingChanges:pendingChangesToSave recordProvider:^CKRecord * _Nullable(CKRecordID *recordID) {
///         return [self recordToSaveForRecordID:recordID];
///     }];
///
///     return batch;
/// }
/// ```
- (nullable CKSyncEngineRecordZoneChangeBatch *)syncEngine:(CKSyncEngine *)syncEngine nextRecordZoneChangeBatchForContext:(CKSyncEngineSendChangesContext *)context NS_SWIFT_NAME(syncEngine(_:nextRecordZoneChangeBatch:));

@optional

/// Called to determine whether the sync engine should fetch changes for a particular zone.
///
/// The default implementation always returns true, so the sync engine will fetch changes for all zones by default.
/// If you don't want it to fetch changes for a particular zone, you can return false for that zone.
///
/// This function will be called any time the sync engine is about to fetch changes.
- (BOOL)syncEngine:(CKSyncEngine *)syncEngine shouldFetchChangesForZoneID:(CKRecordZoneID *)zoneID NS_SWIFT_NAME(syncEngine(_:shouldFetchChanges:));

@end

#pragma mark - Misc

/// A set of options to use when fetching changes from the server.
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
CK_SUBCLASSING_RESTRICTED
NS_SWIFT_SENDABLE
@interface CKSyncEngineFetchChangesOptions : NSObject

/// The scope of zone IDs in which to fetch changes.
/// For example, if you only want to fetch changes for a particular zone, you can set the zone ID here.
/// If this is `nil`, then the request will include all zones.
@property (nullable, nonatomic, copy) NSArray<CKRecordZoneID *> *zoneIDs;

/// The operation group to use for the underlying operations when fetching changes.
///
/// You might set an operation group with a particular name in order to help you analyze telemetry in the CloudKit Console.
@property (nonatomic, strong) CKOperationGroup *operationGroup;

/// Initializes a new set of request options with the given zone IDs and operation group.
/// 
/// If no operation group is specified, a default one will be used.
- (instancetype)initWithZoneIDs:(nullable NSArray<CKRecordZoneID *> *)zoneIDs
                 operationGroup:(nullable CKOperationGroup *)operationGroup;

@end

/// A set of options to use when sending changes to the server.
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
CK_SUBCLASSING_RESTRICTED
NS_SWIFT_SENDABLE
@interface CKSyncEngineSendChangesOptions : NSObject

/// The scope of zone IDs in which to send changes.
/// 
/// For example, if you only want to send changes for a particular zone, you can set the zone ID here.
/// If this is `nil`, then this will send changes for all zones.
@property (nullable, nonatomic, copy) NSArray<CKRecordZoneID *> *zoneIDs;

/// The operation group to use for the underlying operations when sending changes.
///
/// You might set an operation group with a particular name in order to help you analyze telemetry in the CloudKit Console.
@property (nonatomic, strong) CKOperationGroup *operationGroup;

/// Initializes a new set of request options with the given zone IDs and operation group.
/// 
/// If no operation group is specified, a default one will be used.
- (instancetype)initWithZoneIDs:(nullable NSArray<CKRecordZoneID *> *)zoneIDs
                 operationGroup:(nullable CKOperationGroup *)operationGroup;

@end

API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
typedef NS_ENUM(NSInteger, CKSyncEngineSyncReason) {

    /// This sync was scheduled automatically by the sync engine.
    CKSyncEngineSyncReasonScheduled,

    /// This sync was requested manually by calling `fetchChanges` or `sendChanges`.
    CKSyncEngineSyncReasonManual,
};

/// The context of an attempt to send changes to the server.
///
/// The sync engine might attempt to send changes to the server for many reasons.
/// For example, if you call `sendChanges`, it'll try to send changes immediately.
/// Or if you add pending changes to the state, it'll schedule a sync and send changes when the scheduler task runs.
/// This object represents one of those attempts to send changes.
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
NS_REFINED_FOR_SWIFT
CK_SUBCLASSING_RESTRICTED
NS_SWIFT_SENDABLE
@interface CKSyncEngineSendChangesContext : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The reason why the sync engine is attempting to send changes.
@property (nonatomic, readonly) CKSyncEngineSyncReason reason;

/// The options being used for this attempt to send changes.
@property (nonatomic, readonly) CKSyncEngineSendChangesOptions *options;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
