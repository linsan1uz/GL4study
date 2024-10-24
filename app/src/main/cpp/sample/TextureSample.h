//
// Created by fanqifu on 2024/10/24 星期四.
//

#ifndef GL4STUDY_TEXTURESAMPLE_H
#define GL4STUDY_TEXTURESAMPLE_H


#include "GLSampleBase.h"

class TextureSample: public GLSampleBase {
public:
    TextureSample();

    ~TextureSample();

    void LoadImage(NativeImage *pImage);

    virtual void Init();

    virtual void Draw();

private:
    void CreateTexture();
    void DeleteTexture();

    GLuint m_TextureId;
    GLint m_SamplerLoc;
    NativeImage m_RenderImage;
};


#endif //GL4STUDY_TEXTURESAMPLE_H
