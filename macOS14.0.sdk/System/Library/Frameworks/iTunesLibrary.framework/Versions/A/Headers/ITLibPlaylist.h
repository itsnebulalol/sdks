/*!
	@file		ITLibPlaylist.h
	@copyright	© 2012-2021 Apple Inc.
 */

#import <iTunesLibrary/ITLibMediaEntity.h>
#import <iTunesLibrary/ITLibDefines.h>

NS_ASSUME_NONNULL_BEGIN

/*!
	@enum		ITLibDistinguishedPlaylistKind
    @abstract	These constants specify the possible kinds of playlists.
 
	@constant	ITLibDistinguishedPlaylistKindNone
				The playlist is not a distinguished playlist.
	@constant	ITLibDistinguishedPlaylistKindMovies
				The playlist contains all the movies in the iTunes Library.
	@constant	ITLibDistinguishedPlaylistKindTVShows
				The playlists contains all the TV shows in the iTunes Library.
	@constant	ITLibDistinguishedPlaylistKindMusic
				The playlist contains all the music items in the iTunes Library.
	@constant	ITLibDistinguishedPlaylistKindAudiobooks
				The playlist contains all the audiobooks in the iTunes Library
	@constant	ITLibDistinguishedPlaylistKindRingtones
				The playlist contains all the ringtones in the iTunes Library.
	@constant	ITLibDistinguishedPlaylistKindPodcasts
				The playlist contains all the podcasts in the iTunes library
	@constant	ITLibDistinguishedPlaylistKindVoiceMemos
				The playlist contains all voice memos.
	@constant	ITLibDistinguishedPlaylistKindApplications
				The playlist contains all the iOS applications of the user in iTunes.
	@constant	ITLibDistinguishedPlaylistKindPurchases
				The playlist contains all the user's purchases in the iTunes Store.
	@constant	ITLibDistinguishedPlaylistKindiTunesU
				The playlist contains the user's iTunesU items.
	@constant	ITLibDistinguishedPlaylistKind90sMusic
				The playlist is the default 90's music iTunes playlist.
	@constant	ITLibDistinguishedPlaylistKindMyTopRated
				The playlist is the default Top Rated smart playlist generated by iTunes.
	@constant	ITLibDistinguishedPlaylistKindTop25MostPlayed
				The playlist is the default 25 Most Played smart playlist generated by iTunes.
	@constant	ITLibDistinguishedPlaylistKindRecentlyPlayed
				The playlist is the default Recently Played smart playlist generated by iTunes .
	@constant	ITLibDistinguishedPlaylistKindRecentlyAdded
				The playlist is the default Recently Added smart playlist generated by iTunes.
	@constant	ITLibDistinguishedPlaylistKindMusicVideos
				The playlist is the default Music Videos smart playlist generated by iTunes.
	@constant	ITLibDistinguishedPlaylistKindClassicalMusic
				The playlist is the default Classical Music smart playlist generated by iTunes.
	@constant	ITLibDistinguishedPlaylistKindLibraryMusicVideos
				The playlist contains all music videos in the iTunes Library. This is NOT the same as the default Music Videos smart playlist.
	@constant	ITLibDistinguishedPlaylistKindLibraryHomeVideos
				The playlist contains all homes videos in the iTunes Library.
	@constant	ITLibDistinguishedPlaylistKindMusicShowsAndMovies
				The playlist is the default Music Shows and Movies smart playlist generated by iTunes.
*/
typedef NS_ENUM( NSUInteger, ITLibDistinguishedPlaylistKind )
{
	ITLibDistinguishedPlaylistKindNone = 0,
	ITLibDistinguishedPlaylistKindMovies = 1,
	ITLibDistinguishedPlaylistKindTVShows = 2,
	ITLibDistinguishedPlaylistKindMusic = 3,
	ITLibDistinguishedPlaylistKindAudiobooks = 4,
	ITLibDistinguishedPlaylistKindBooks = ITLibDistinguishedPlaylistKindAudiobooks,
	ITLibDistinguishedPlaylistKindRingtones = 5,
	ITLibDistinguishedPlaylistKindPodcasts = 7,
	ITLibDistinguishedPlaylistKindVoiceMemos = 14,
	ITLibDistinguishedPlaylistKindPurchases = 16,
	ITLibDistinguishedPlaylistKindiTunesU = 26,
	ITLibDistinguishedPlaylistKind90sMusic = 42,
	ITLibDistinguishedPlaylistKindMyTopRated = 43,
	ITLibDistinguishedPlaylistKindTop25MostPlayed = 44,
	ITLibDistinguishedPlaylistKindRecentlyPlayed = 45,
	ITLibDistinguishedPlaylistKindRecentlyAdded = 46,
	ITLibDistinguishedPlaylistKindMusicVideos = 47,
	ITLibDistinguishedPlaylistKindClassicalMusic = 48,
	ITLibDistinguishedPlaylistKindLibraryMusicVideos = 49,
	ITLibDistinguishedPlaylistKindHomeVideos = 50,
	ITLibDistinguishedPlaylistKindApplications = 51,
	ITLibDistinguishedPlaylistKindLovedSongs = 52,
	ITLibDistinguishedPlaylistKindMusicShowsAndMovies = 53,

} API_UNAVAILABLE(ios);

/*!
	@enum		ITLibPlaylistKind
	@abstract	These constants specify the possible kinds of playlists.
 
	@constant	ITLibPlaylistKindRegular
				A normal playlist created by the user or by iTunes (e.g. "Music", "Movies", "Brit-Pop Mix" or "My Awesome Stone Roses Playlist").
	@constant	ITLibPlaylistKindSmart
				A smart playlist whose contents are dynamically generated by evaluating a set of rules. (e.g. "90s Music" or "Songs From 1999").
	@constant	ITLibPlaylistKindGenius
				A saved Genius playlist.
	@constant	ITLibPlaylistKindFolder
				A playlist folder created by the user or by iTunes (e.g. "My Playlist Folder" or "Genius Mixes").
	@constant	ITLibPlaylistKindGeniusMix
				A Genius Mix playlist.
 */
typedef NS_ENUM( NSUInteger, ITLibPlaylistKind )
{
	ITLibPlaylistKindRegular,
	ITLibPlaylistKindSmart,
	ITLibPlaylistKindGenius,
	ITLibPlaylistKindFolder,
	ITLibPlaylistKindGeniusMix

} API_UNAVAILABLE(ios);

@class ITLibMediaItem;

/*!
 @abstract	A playlist is a collection of related media items. (Media items are described in ITLibMediaItem Class Reference.) 
			Each playlist has a name, a set of attributes, and a unique identifier that persists across application launches.
*/
API_UNAVAILABLE(ios)
ITLIB_EXPORT @interface ITLibPlaylist : ITLibMediaEntity
{
	NSMutableArray * _items;
	NSMutableArray * _playableItems;
}

/*! @abstract The name or title of this playlist. */
@property (readonly, nonatomic, copy) NSString* name;

/*! @abstract Whether this playlist is the primary playlist. */
@property (readonly, nonatomic, assign, getter=isPrimary) BOOL primary API_AVAILABLE(macos(12.0));

/*! @abstract The unique identifier of this playlist' parent. */
@property (readonly, nonatomic, retain, nullable) NSNumber* parentID;

/*! @abstract Whether this playlist is visible. */
@property (readonly, nonatomic, assign, getter=isVisible) BOOL visible;

/*! @abstract Whether or not every item in this playlist is exposed via this API.  Generally true but not that useful. */
@property (readonly, nonatomic, assign, getter=isAllItemsPlaylist) BOOL allItemsPlaylist DEPRECATED_MSG_ATTRIBUTE( "not useful" );

/*! @abstract The media items contained within this playlist. */
@property (readonly, nonatomic, retain) NSArray<ITLibMediaItem *> * items;

/*! @abstract The distinguished kind of this playlist. */
@property (readonly, nonatomic, assign) ITLibDistinguishedPlaylistKind distinguishedKind;

/*! @abstract The kind of this playlist. */
@property (readonly, nonatomic, assign) ITLibPlaylistKind kind;

/*! @abstract Whether this playlist is the primary playlist. */
@property (readonly, nonatomic, assign, getter=isMaster) BOOL master API_DEPRECATED_WITH_REPLACEMENT("primary", macos(10.6, API_TO_BE_DEPRECATED));

@end

/*!
 * @constant ITLibPlaylistPropertyName.
 * @abstract Retrieves the name or title of the playlist. See @link name @/link.
 */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyName;

/*! @constant ITLibPlaylistPropertyAllItems. See allItemsPlaylist. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyAllItemsPlaylist;

/*! @constant ITLibPlaylistPropertyDistinguisedKind. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyDistinguisedKind;

/*! @constant ITLibPlaylistPropertyPrimary. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyPrimary API_AVAILABLE(macos(12.0));

/*! @constant ITLibPlaylistPropertyParentPersistentID. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyParentPersistentID;

/*! @constant ITLibPlaylistPropertyVisible. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyVisible;

/*! @constant ITLibPlaylistPropertyItems. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyItems;

/*! @constant ITLibPlaylistPropertyFolder. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyKind;

/*! @constant ITLibPlaylistPropertyMaster. */
ITLIB_EXPORT ITLIB_EXTERN NSString * const ITLibPlaylistPropertyMaster API_DEPRECATED_WITH_REPLACEMENT("ITLibPlaylistPropertyPrimary", macos(10.6, API_TO_BE_DEPRECATED));

NS_ASSUME_NONNULL_END
