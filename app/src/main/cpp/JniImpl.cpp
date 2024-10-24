#include "com_hzw_gl4study_MyNativeRender.h"
#include "util/LogUtil.h"
#include <MyGLRenderContext.h>
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_hzw_gl4study_MyNativeRender
 * Method:    native_OnInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1OnInit
(JNIEnv *env, jobject instance){
    MyGLRenderContext::GetInstance();
}

/*
 * Class:     com_hzw_gl4study_MyNativeRender
 * Method:    native_OnUnInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1OnUnInit
(JNIEnv *env, jobject instance){
    MyGLRenderContext::DestroyInstance();
}

/*
 * Class:     com_hzw_gl4study_MyNativeRender
 * Method:    native_OnSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1SetParamsInt
(JNIEnv *, jobject instance, jint paramType, jint value){
    MyGLRenderContext::GetInstance()->SetParamsInt(paramType,value);
}

JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1SetImageData
(JNIEnv *env, jobject instance, jint format, jint width, jint height, jbyteArray imageData){
    int len = env->GetArrayLength (imageData);
    uint8_t* buf = new uint8_t[len];
    env->GetByteArrayRegion(imageData, 0, len, reinterpret_cast<jbyte*>(buf));
    MyGLRenderContext::GetInstance()->SetImageData(format, width, height, buf);
    delete[] buf;
    env->DeleteLocalRef(imageData);
}

JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1OnSurfaceCreated
(JNIEnv *env, jobject instance){
    MyGLRenderContext::GetInstance()->OnSurfaceCreated();
}

/*
 * Class:     com_hzw_gl4study_MyNativeRender
 * Method:    native_OnSurfaceChanged
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1OnSurfaceChanged
(JNIEnv *env, jobject instance, jint width, jint height){
    MyGLRenderContext::GetInstance()->OnSurfaceChanged(width, height);
}

/*
 * Class:     com_hzw_gl4study_MyNativeRender
 * Method:    native_OnDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hzw_gl4study_MyNativeRender_native_1OnDrawFrame
(JNIEnv *env, jobject instance){
    MyGLRenderContext::GetInstance()->OnDrawFrame();
}

#ifdef __cplusplus
}
#endif
