#include "VertexShader.h"

VertexShader::VertexShader()
{
	vertexShaderSrc =
		"attribute vec3 in_Position;"\
		""\
		"void main()"\
		"{"\
		"	uniform mat4 in_model;"\
		"	gl_Position = vec4(in_Position *in_model, 1.0);"\
		"}"\
		"";

	success = 0;
}

VertexShader::~VertexShader()
{
	glDeleteShader(vertexShaderID);
}

GLuint VertexShader::InitVertShader()
{
	//vertex shader
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderID);

	//success = 0;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	//check for success if not throw exeption
	if (!success)
	{
		throw Exception("Reset State Vertex shader, Success Error! ");
	}

	return vertexShaderID;
}
