package com.xingzy;

public class BsPathcher {

    static {
        System.loadLibrary("native-lib");
    }

    public static native void bsPatch(String oldApk, String patch, String output);
}
