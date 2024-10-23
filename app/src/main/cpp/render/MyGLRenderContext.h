//
// Created by fqf17 on 2024/10/23.
//

#ifndef GL4STUDY_MYGLRENDERCONTEXT_H
#define GL4STUDY_MYGLRENDERCONTEXT_H


#include <stdint.h>
#include "../sample/GLSampleBase.h"

class MyGLRenderContext {
    //构造函数

    MyGLRenderContext();

    //析构函数

    ~MyGLRenderContext();
public:

    void SetImageData(int format, int width, int height, uint8_t *pData);

    void SetParamsInt(int paramType, int value);

    void OnSurfaceCreated();

    void OnSurfaceChanged(int width, int height);

    void OnDrawFrame();

    static MyGLRenderContext* GetInstance();
    static void DestroyInstance();
private:
    static MyGLRenderContext *m_pContext;
    GLSampleBase *m_Sample;
};


#endif //GL4STUDY_MYGLRENDERCONTEXT_H
