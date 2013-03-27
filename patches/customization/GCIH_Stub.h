#ifndef _GCIH_STUB_INCLUDE_H
#define _GCIH_STUB_INCLUDE_H
#include <jni.h>

// declaration copied from hotspot/src/share/utilities/globalDefinitions.hpp
typedef unsigned char u_char;
typedef u_char*       address;
typedef unsigned int  juint;

extern jlong    GCIH_GetStartAddress() ;
extern jlong    GCIH_GetEndAddress();
extern jlong    GCIH_GetNextAvailableAddress();
extern void     GCIH_Foo();
extern void     GCIH_PrintStackInfo();
extern void     GCIH_PrintHeapInfo();
extern jlong    GCIH_GetObjectAddress(JNIEnv* env ,jclass cls, jobject obj);
extern jint     GCIH_GetObjectSize(JNIEnv* env , jclass cls, jobject obj);
extern jlong    GCIH_GetObjectMark(JNIEnv* env , jclass cls, jobject obj);
extern jobject  GCIH_MoveIn(JNIEnv* env, jclass cls, jobject obj);
extern void     GCIH_MoveOut();
extern address  GCIH_GetNarrowOopBase();
extern int      GCIH_GetNarrowOopShift();
extern jboolean GCIH_IsUseCompressedOops();
extern jboolean GCIH_IsUseGCIH();
extern void GCIH_outputMemContent(JNIEnv * env , jclass cls,jobject obj);
extern void GCIH_Info(JNIEnv * env , jclass cls,jobject obj,jstring str);
#endif //_GCIH_STUB_INCLUDE_H

