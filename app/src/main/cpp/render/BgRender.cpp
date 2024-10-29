//
// Created by fanqifu on 2024/10/25 星期五.
//

#include "LogUtil.h"
#include "GLUtils.h"
#include "BgRender.h"
BgRender *BgRender::m_Instance = nullptr;

#define VERTEX_POS_LOC  0
#define TEXTURE_POS_LOC 1
const char vShaderStr[] =
        "#version 300 es                            \n"
        "layout(location = 0) in vec4 a_position;   \n"
        "layout(location = 1) in vec2 a_texCoord;   \n"
        "out vec2 v_texCoord;                       \n"
        "void main()                                \n"
        "{                                          \n"
        "   gl_Position = a_position;               \n"
        "   v_texCoord = a_texCoord;                \n"
        "}                                          \n";

const char fShaderStr[] =
        "#version 300 es\n"
        "precision mediump float;\n"
        "in vec2 v_texCoord;\n"
        "layout(location = 0) out vec4 outColor;\n"
        "uniform sampler2D s_TextureMap;\n"
        "void main()\n"
        "{\n"
        "    outColor = texture(s_TextureMap, v_texCoord);\n"
        "}";

const GLfloat vVertices[] = {
        -1.0f, -1.0f, 0.0f, // bottom left
        1.0f, -1.0f, 0.0f, // bottom right
        -1.0f,  1.0f, 0.0f, // top left
        1.0f,  1.0f, 0.0f, // top right
};

BgRender::BgRender() {
    m_VaoIds[2] = {GL_NONE};
    m_VboIds[3] = {GL_NONE};
    m_ImageTextureId = GL_NONE;
    m_FboTextureId = GL_NONE;
    m_SamplerLoc = GL_NONE;
    m_FboId = GL_NONE;
    m_ProgramObj = GL_NONE;
    m_VertexShader = GL_NONE;
    m_FragmentShader = GL_NONE;

    m_IsGLContextReady = false;
}

BgRender::~BgRender() {
    if (m_RenderImage.ppPlane[0])
    {
        NativeImageUtil::FreeNativeImage(&m_RenderImage);
        m_RenderImage.ppPlane[0] = nullptr;
    }
}

void BgRender::Init() {

}

void BgRender::UnInit() {

}

void BgRender::DestroyGlesEnv() {

}

void BgRender::Draw() {

}

void BgRender::SetIntParams(int paramType, int param) {

}

void BgRender::SetImageData(uint8_t *pData, int width, int height) {

}

int BgRender::CreateGlesEnv() {
    return 0;
}

