package com.taobao.java.util.crc;

import java.util.zip.Checksum;

/**
 * An wrapper of IPP CRC32 checksum that uses the same polynomial as the
 * built-in native CRC32.
 * 
 * 
 * 
 * The IPP CRC32 is ~2x as fast as Sun's native java.util.zip.CRC32 in Java 1.6
 * 
 * @see java.util.zip.CRC32
 */

public class TCrc32 implements Checksum {
    public static native void registerNatives();

    static {
        registerNatives();
    }

    private int crc;

    /**
     * Creates a new TCrc32 object.
     */
    public TCrc32() {
    }

    /**
     * Updates CRC-32 with specified byte.
     */
    public void update(int b) {
        byte[] buf = new byte[1];
        buf[0] = (byte) b;
        crc = updateBytes(crc, buf, 0, 1);
    }

    /**
     * Updates CRC-32 with specified array of bytes.
     */
    public void update(byte[] b, int off, int len) {
        if (b == null) {
            throw new NullPointerException();
        }
        if (off < 0 || len < 0 || off > b.length - len) {
            throw new ArrayIndexOutOfBoundsException();
        }
        crc = updateBytes(crc, b, off, len);
    }

    /**
     * Updates checksum with specified array of bytes.
     * 
     * @param b
     *            the array of bytes to update the checksum with
     */
    public void update(byte[] b) {
        crc = updateBytes(crc, b, 0, b.length);
    }

    /**
     * Resets CRC-32 to initial value.
     */
    public void reset() {
        crc = 0;
    }

    /**
     * Returns CRC-32 value.
     */
    public long getValue() {
        return (long) crc & 0xffffffffL;
    }

    private native static int updateBytes(int crc, byte[] b, int off, int len);
}
