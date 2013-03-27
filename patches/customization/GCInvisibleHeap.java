package com.taobao.gcih;


public class GCInvisibleHeap {
	static {
		System.loadLibrary("gcih");
	}

	public static void printObjectInfo(Object obj) {
		System.out.println("Object address:[0x" + Long.toHexString(getObjectAddress(obj))  + "]");
		System.out.println("Object mark:[0x" + Long.toHexString(getObjectMark(obj)) + "]");
		System.out.println("Object size:[" + Integer.toString(getObjectSize(obj)) + "] bytes");

	}
	public static native Object moveIn(Object obj) throws OutOfMemoryError;
	
	public static native void moveOut();
	
	public static native void printStackInfo();

	public static native void printHeapInfo();

	public static native void foo();

	public static native long getObjectAddress(Object obj);

	public static native long getObjectMark(Object obj);

	public static native int getObjectSize(Object obj);

	public static native long getStartAddress();

	public static native long getEndAddress();

	public static native long getNextAvailableAddress();
	
	public static native long getNarrowOopBase();
	
	public static native int getNarrowOopShift();
	
	public static native boolean isUseCompressedOops();
		
	public static native void info(Object obj, String str);

}
