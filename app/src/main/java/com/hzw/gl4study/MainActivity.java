package com.hzw.gl4study;

import static com.hzw.gl4study.MyGLSurfaceView.IMAGE_FORMAT_RGBA;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;

import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private MyGLSurfaceView myGLSurfaceView;
    private static final int SAMPLE_TYPE  =  200;

    private static final int SAMPLE_TYPE_KEY_TRIANGLE = 0;
    private static final int SAMPLE_TYPE_KEY_TEXTURE_MAP = 1;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myGLSurfaceView = findViewById(R.id.my_gl_surface_view);
        myGLSurfaceView.getNativeRender().native_OnInit();
        myGLSurfaceView.getNativeRender().native_SetParamsInt(SAMPLE_TYPE,SAMPLE_TYPE_KEY_TEXTURE_MAP);
        LoadRGBAImage();
        myGLSurfaceView.requestRender();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        myGLSurfaceView.getNativeRender().native_OnUnInit();
    }

    private void LoadRGBAImage() {
        @SuppressLint("ResourceType")
        InputStream is = this.getResources().openRawResource(R.drawable.dzzz);
        Bitmap bitmap;
        try {
            bitmap = BitmapFactory.decodeStream(is);
            if (bitmap != null) {
                int bytes = bitmap.getByteCount();
                ByteBuffer buf = ByteBuffer.allocate(bytes);
                bitmap.copyPixelsToBuffer(buf);
                byte[] byteArray = buf.array();
                //Log.i(TAG, "LoadRGBAImage: "+byteArray.hashCode());
                myGLSurfaceView.getNativeRender().native_SetImageData(IMAGE_FORMAT_RGBA, bitmap.getWidth(), bitmap.getHeight(), byteArray);
            }
        }
        finally
        {
            try
            {
                is.close();
            }
            catch(IOException e)
            {
                Log.e(TAG, "LoadRGBAImage: wrong",e);
            }
        }
    }
}