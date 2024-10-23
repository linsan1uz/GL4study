//
// Created by fqf17 on 2024/10/23.
//

#ifndef GL4STUDY_GLSAMPLEBASE_H
#define GL4STUDY_GLSAMPLEBASE_H
#include "stdint.h"
#include <GLES3/gl3.h>
#include <ImageDef.h>

class GLSampleBase
{
public:
    GLSampleBase()
    {
        m_ProgramObj = 0;
        m_VertexShader = 0;
        m_FragmentShader = 0;
    }

    virtual ~GLSampleBase()
    {

    }

    //virtual void LoadImage(NativeImage *pImage) = 0;

    virtual void Init() = 0;
    virtual void Draw() = 0;


protected:
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_ProgramObj;
};

#endif //GL4STUDY_GLSAMPLEBASE_H
