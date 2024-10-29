//
// Created by fanqifu on 2024/10/25 星期五.
//

#ifndef GL4STUDY_VAOSAMPLE_H
#define GL4STUDY_VAOSAMPLE_H


#include "GLSampleBase.h"

class VaoSample : public GLSampleBase{
public:
    VaoSample();

    ~VaoSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();
    virtual void Draw();
    virtual void Destroy();
private:
    GLuint m_VaoId;
    GLuint m_VboIds[2];
};


#endif //GL4STUDY_VAOSAMPLE_H
