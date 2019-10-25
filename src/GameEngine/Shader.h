
//#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Exception.h"

class Shader
{
public:
	Shader();
	~Shader();
	
	GLuint PositionID();
	GLuint VaoID();

	GLuint VertShader();
	GLuint FragShader();

	GLuint ProgramID();
private:

	const GLfloat positions[9] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	const GLchar *vertexShaderSrc;
	const GLchar *fragmentShaderSrc;

	GLuint positionVboId;
	GLuint vaoID;

	GLint success = 0;

	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	
	GLuint prgramId;
};
