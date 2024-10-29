//
// Created by fanqifu on 2024/10/24 星期四.
//

#ifndef GL4STUDY_NV21SAMPLE_H
#define GL4STUDY_NV21SAMPLE_H


#include "GLSampleBase.h"
#include "ImageDef.h"

class NV21Sample: public GLSampleBase {
public:
    NV21Sample(){
        m_yTextureId = GL_NONE;
        m_uvTextureId = GL_NONE;

        m_ySamplerLoc = GL_NONE;
        m_uvSamplerLoc = GL_NONE;
    }
    ~NV21Sample(){
        NativeImageUtil::FreeNativeImage(&m_RenderImage);
    }
    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();

    virtual void Draw();
private:
    GLuint m_yTextureId;
    GLuint m_uvTextureId;

    GLint m_ySamplerLoc;
    GLint m_uvSamplerLoc;

    NativeImage m_RenderImage;
};


#endif //GL4STUDY_NV21SAMPLE_H
