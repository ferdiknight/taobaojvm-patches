#include "include/GCIH_Stub.h"

#include <stdio.h>
#include <stdlib.h>

static JavaVM* java_vm;
static JNIEnv* env;

static JNINativeMethod methods[] = {
	{"printStackInfo", "()V", (void *)&GCIH_PrintStackInfo},
	{"printHeapInfo", "()V", (void *)&GCIH_PrintHeapInfo},
	{"moveIn", "(Ljava/lang/Object;)Ljava/lang/Object;", (void *)&GCIH_MoveIn},
	{"moveOut","()V", (void *)&GCIH_MoveOut},

	{"foo", "()V", (void *)&GCIH_Foo},

	{"getObjectAddress", "(Ljava/lang/Object;)J", (void *)&GCIH_GetObjectAddress},
	{"getObjectMark", "(Ljava/lang/Object;)J", (void *)&GCIH_GetObjectMark},
	{"getObjectSize", "(Ljava/lang/Object;)I", (void *)&GCIH_GetObjectSize},
	{"info", "(Ljava/lang/Object;Ljava/lang/String;)V", (void *)&GCIH_Info},

	{"getStartAddress", "()J", (void *)&GCIH_GetStartAddress},
	{"getEndAddress", "()J", (void *)&GCIH_GetEndAddress},
	{"getNextAvailableAddress", "()J", (void *)&GCIH_GetNextAvailableAddress},

	{"isUseCompressedOops", "()Z", (void *)&GCIH_IsUseCompressedOops},
	{"getNarrowOopBase", "()J", (void *)&GCIH_GetNarrowOopBase},
	{"getNarrowOopShift", "()I", (void *)&GCIH_GetNarrowOopShift},
};

static void registerNatives(JNIEnv * env) {
	jclass clazz = (*env)->FindClass(env, "com/taobao/gcih/GCInvisibleHeap");
	(*env)->RegisterNatives(env, clazz, methods, sizeof(methods)/sizeof(methods[0]));
	return;
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
	printf("JNI_OnLoad\n");
	java_vm=vm;
	if ((*vm)->GetEnv(java_vm, (void **)&env, JNI_VERSION_1_6) == JNI_OK) {
		registerNatives(env);
		return JNI_VERSION_1_6;
	}
	return JNI_ERR;
}


