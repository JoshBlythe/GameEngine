#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "VertexShader.h"
#include "Exception.h"


class FragmentShader : public VertexShader 
{
public:
	FragmentShader();
	~FragmentShader();

	GLuint FragmentShaderInit();

private:
	//stores the fragment shader for now, will need to move into a file.
	const GLchar *fragmentShaderSrc;
	//fragment shader ID
	GLuint fragmentShaderID;

	GLint _success = GetSuccess();
};
