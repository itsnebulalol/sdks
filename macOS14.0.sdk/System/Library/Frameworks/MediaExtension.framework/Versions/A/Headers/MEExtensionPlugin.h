/*
	File:  MEExtensionPlugin.h
	
	Framework:	MediaExtension
 
	Copyright © 2023 Apple Inc. All rights reserved.

	To report bugs, go to:  http://developer.apple.com/bugreporter/

*/

#ifndef MEExtensionPlugin_h
#define MEExtensionPlugin_h

/*!
	@abstract		Extension point names identify a bundle as a particular type of extension.
	@constant		kMEFormatReaderExtensionPointName
		The extension point name for MediaExtension MediaToolbox format readers.
	@constant		kMEVideoDecoderExtensionPointName
		The extension point name for MediaExtension VideoToolbox decoders.
*/
#define kMEFormatReaderExtensionPointName					@"com.apple.mediaextension.formatreader"
#define kMEVideoDecoderExtensionPointName					@"com.apple.mediaextension.videodecoder"


/*!
	@abstract		Extension attribute field keys for MediaExtension format reader plugin bundles.
	@constant		kMEFormatReaderClassImplementationID
		The identifier for the format reader. This should be of the form "com.apple.mediatoolbox.formatreader.xxx".
	@constant		kMEFormatReaderUTTypeArrayKey
		The array of UTType identifiers	 supported by the format reader plugin.
	@constant		kMEFormatReaderFileNameExtensionArrayKey
		The array of file extensions supported by the format reader plugin. This should include file extensions for any type of related files.
	@constant		kMEFormatReaderObjectNameKey
		The user readable name for the format reader.
*/
#define kMEFormatReaderClassImplementationIDKey				@"ClassImplementationID"
#define kMEFormatReaderUTTypeArrayKey						@"MTUTTypeArray"
#define kMEFormatReaderFileNameExtensionArrayKey			@"MTFileNameExtensionArray"
#define kMEFormatReaderObjectNameKey						@"ObjectName"

/*!
	@abstract		Extension attribute field keys for MediaExtension video decoder plugin bundles.
	@constant		kMEVideoDecoderClassImplementationIDKey
		The identifier for the decoder. This should be of the form "com.apple.videotoolbox.videodecoder.xxx".
	@constant		kMEVideoDecoderCodecTypeKey
		The four character code for the codec type, as a string.
	@constant		kMEVideoDecoderObjectNameKey
		The user readable name for the decoder.
*/
#define kMEVideoDecoderClassImplementationIDKey				@"ClassImplementationID"
#define kMEVideoDecoderCodecTypeKey							@"CodecType"
#define kMEVideoDecoderObjectNameKey						@"ObjectName"


#endif /* MEExtensionPlugin_h */
