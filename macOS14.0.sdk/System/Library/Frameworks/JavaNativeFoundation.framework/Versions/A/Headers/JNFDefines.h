/*
 *  JNFDefines.h
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

#ifndef JNFDefines_h
#define JNFDefines_h

#include <os/availability.h>
#include <sys/cdefs.h>

#define JNF_BEGIN_DECLS \
    __BEGIN_DECLS \
    API_UNAVAILABLE_BEGIN(ios)

#define JNF_END_DECLS \
    API_UNAVAILABLE_END \
    __END_DECLS

#define JNF_EXPORT __attribute__((visibility("default")))

#define JNF_DEPRECATED __deprecated_msg("This functionality is longer supported, and current versions of Java no longer require this system framework.")

#endif /* JNFDefines_h */
