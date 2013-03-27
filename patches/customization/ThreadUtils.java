package com.taobao.java.util.vm;

public class ThreadUtils {

    /* For autonumbering anonymous threads. */
    private static int threadInitNumber;
    private static synchronized int nextThreadNum() {
        return threadInitNumber++;
    }

    public static Thread newThreadWithStackSize(long stackSize, Runnable task) {
        return new Thread(null, task, "ThreadWithStackSize-" + nextThreadNum(), stackSize);
    }
}
