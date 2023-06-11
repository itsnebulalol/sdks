/*
 JNFAutoreleasePool.h
 Java Native Foundation
 Copyright (c) 2008, Apple Inc.
 All rights reserved.

 Utility class used by the JNF_COCOA_ENTER()/JNF_COCOA_EXIT() macros
 from JNFJNI.h. Do not use this class or releated functions directly.
 */

#import <Foundation/Foundation.h>

#import <JavaNativeFoundation/JNFJNI.h>

JNF_BEGIN_DECLS

typedef void JNFAutoreleasePoolToken;

// JNFNativeMethodEnter - called on entry to each native method by the
// JNF_COCOA_ENTER(env) macro in JNFJNI.h
JNF_EXPORT extern JNFAutoreleasePoolToken *JNFNativeMethodEnter(void);

// JNFNativeMethodExit - called on exit from each native method by the
// JNF_COCOA_EXIT(env) macro in JNFJNI.h
JNF_EXPORT extern void JNFNativeMethodExit(JNFAutoreleasePoolToken *token);

JNF_END_DECLS
