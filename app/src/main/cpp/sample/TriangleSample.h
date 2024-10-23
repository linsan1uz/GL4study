//
// Created by fqf17 on 2024/10/23.
//

#ifndef GL4STUDY_TRIANGLESAMPLE_H
#define GL4STUDY_TRIANGLESAMPLE_H


#include "GLSampleBase.h"

class TriangleSample : public GLSampleBase {

public:
    TriangleSample();
    ~TriangleSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();

    virtual void Draw(int screenW, int screenH);
};


#endif //GL4STUDY_TRIANGLESAMPLE_H