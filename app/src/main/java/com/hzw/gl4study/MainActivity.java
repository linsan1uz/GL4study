package com.hzw.gl4study;

import static com.hzw.gl4study.MyGLSurfaceView.IMAGE_FORMAT_NV21;
import static com.hzw.gl4study.MyGLSurfaceView.IMAGE_FORMAT_RGBA;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;

import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private MyGLSurfaceView myGLSurfaceView;
    private static final int SAMPLE_TYPE  =  200;
    private Intent intent;
    private static final int SAMPLE_TYPE_KEY_TRIANGLE = 0;
    private static final int SAMPLE_TYPE_KEY_TEXTURE_MAP = 1;
    private static final int SAMPLE_TYPE_KEY_NV21_MAP = 2;
    private static final int SAMPLE_TYPE_KEY_VAO = 3;
    private CameraWrapper mCameraWrapper;


    private HandlerThread mBackgroundThread;
    private Handler mBackgroundHandler;
    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myGLSurfaceView = findViewById(R.id.my_gl_surface_view);
        myGLSurfaceView.getNativeRender().native_OnInit();
        intent = getIntent();
        Bundle bundle = intent.getExtras();
        int sampleType = (int) bundle.get("SampleType");
        myGLSurfaceView.getNativeRender().native_SetParamsInt(SAMPLE_TYPE,sampleType);
        switch (sampleType){
            case SAMPLE_TYPE_KEY_TRIANGLE:
                break;
            case SAMPLE_TYPE_KEY_TEXTURE_MAP:
                LoadRGBAImage();
                break;
            case SAMPLE_TYPE_KEY_NV21_MAP:
                LoadNV21Image();
                break;
            case SAMPLE_TYPE_KEY_VAO:
                break;
            default:
                break;
        }
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

    private void LoadNV21Image() {
        InputStream is = null;
        try {
            is = getAssets().open("YUV_Image_840x1074.NV21");
        } catch (IOException e) {
            e.printStackTrace();
        }

        int lenght = 0;
        try {
            lenght = is.available();
            byte[] buffer = new byte[lenght];
            is.read(buffer);
            myGLSurfaceView.getNativeRender().native_SetImageData(IMAGE_FORMAT_NV21, 840, 1074, buffer);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try
            {
                is.close();
            }
            catch(IOException e)
            {
                e.printStackTrace();
            }
        }

    }
    private void startBackgroundThread() {
        mBackgroundThread = new HandlerThread("CameraBackground");
        mBackgroundThread.start();
        mBackgroundHandler = new Handler(mBackgroundThread.getLooper());
    }

    /**
     * Stops the background thread and its {@link Handler}.
     */
    private void stopBackgroundThread() {
        mBackgroundThread.quitSafely();
        try {
            mBackgroundThread.join();
            mBackgroundThread = null;
            mBackgroundHandler = null;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void setWindowFlag() {
        Window window = getWindow();
        //隐藏顶部 StatuBar状态栏
        window.addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
        //隐藏底部 NavigationBar导航栏
        window.addFlags(WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS);
        window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }
}