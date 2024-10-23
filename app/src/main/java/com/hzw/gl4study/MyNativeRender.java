package com.hzw.gl4study;

/**
 * Create by fqf17 on 2024/10/23 22:15
 */
public class MyNativeRender {
    static {
        System.loadLibrary("native-render");
    }

    public native void native_OnInit();

    public native void native_OnUnInit();

    protected native void native_SetParamsInt(int paramType, int value);

    public native void native_SetImageData(int format, int width, int height, byte[] bytes);

    public native void native_OnSurfaceCreated();

    public native void native_OnSurfaceChanged(int width, int height);

    public native void native_OnDrawFrame();
}
