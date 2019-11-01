#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Exception.h"

class VertexShader
{
public:
	VertexShader();
	~VertexShader();

	GLuint InitVertShader();

	GLint GetSuccess() { return success; }

private:
	const GLfloat positions[9] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};


	const GLchar *vertexShaderSrc;

	GLuint vertexShaderID;
	GLint success;
};
