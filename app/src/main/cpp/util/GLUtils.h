#ifndef GL4STUDY_GL_UTILS_H_
#define GL4STUDY_GL_UTILS_H_

#include <GLES3/gl3.h>

class GLUtils
{
public:
	static GLuint LoadShader(GLenum shaderType, const char *pSource);

	static GLuint CreateProgram(const char *pVertexShaderSource, const char *pFragShaderSource, GLuint &vertexShaderHandle,
								GLuint &fragShaderHandle);

	static void DeleteProgram(GLuint &program);

	static void CheckGLError(const char *pGLOperation);
};
#endif //