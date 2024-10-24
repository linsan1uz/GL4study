//
// Created by fqf17 on 2024/10/23.
//

#include "MyGLRenderContext.h"
#include <TriangleSample.h>
#include "LogUtil.h"
#include "TextureSample.h"

MyGLRenderContext* MyGLRenderContext::m_pContext = nullptr;
const int SAMPLE_TYPE  =   200;
const int SAMPLE_TYPE_KEY_TRIANGLE = 0;
const int SAMPLE_TYPE_KEY_TEXTURE_MAP = 1;

MyGLRenderContext::MyGLRenderContext()
{
    //m_Sample = new TextureSample();
}

MyGLRenderContext::~MyGLRenderContext()
{
    if (m_Sample)
    {
        delete m_Sample;
        m_Sample = nullptr;
    }

}


void MyGLRenderContext::SetParamsInt(int paramType, int value)
{
    LOGCATE("MyGLRenderContext::SetParamsInt paramType = %d, value = %d", paramType, value);

    if (paramType == SAMPLE_TYPE)
    {
        switch (value)
        {
            case SAMPLE_TYPE_KEY_TRIANGLE:
                m_Sample = new TriangleSample();
                break;
            case SAMPLE_TYPE_KEY_TEXTURE_MAP:
                m_Sample = new TextureSample();
                break;
            /*case SAMPLE_TYPE_KEY_YUV_TEXTURE_MAP:
                m_Sample = new NV21TextureMapSample();
                break;*/
            default:
                break;
        }
    }

}

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pData)
{
    LOGCATE("MyGLRenderContext::SetImageData format=%d, width=%d, height=%d, pData=%p", format, width, height, pData);
    NativeImage nativeImage;
    nativeImage.format = format;
    nativeImage.width = width;
    nativeImage.height = height;
    nativeImage.ppPlane[0] = pData;

    switch (format)
    {
        case IMAGE_FORMAT_NV12:
        case IMAGE_FORMAT_NV21:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
            break;
        case IMAGE_FORMAT_I420:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
            nativeImage.ppPlane[2] = nativeImage.ppPlane[1] + width * height / 4;
            break;
        default:
            break;
    }

    if (m_Sample)
    {
        m_Sample->LoadImage(&nativeImage);
    }

}

void MyGLRenderContext::OnSurfaceCreated()
{
    LOGCATE("MyGLRenderContext::OnSurfaceCreated");
    glClearColor(1.0f,1.0f,0.5f, 1.0f);
}

void MyGLRenderContext::OnSurfaceChanged(int width, int height)
{
    LOGCATE("MyGLRenderContext::OnSurfaceChanged [w, h] = [%d, %d]", width, height);
    glViewport(0, 0, width, height);
}

void MyGLRenderContext::OnDrawFrame()
{
    LOGCATE("MyGLRenderContext::OnDrawFrame");
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if (m_Sample)
    {
        m_Sample->Init();
        m_Sample->Draw();
    }
}

MyGLRenderContext *MyGLRenderContext::GetInstance()
{
    LOGCATE("MyGLRenderContext::GetInstance");
    if (m_pContext == nullptr)
    {
        m_pContext = new MyGLRenderContext();
    }
    return m_pContext;
}

void MyGLRenderContext::DestroyInstance()
{
    LOGCATE("MyGLRenderContext::DestroyInstance");
    if (m_pContext)
    {
        delete m_pContext;
        m_pContext = nullptr;
    }

}

