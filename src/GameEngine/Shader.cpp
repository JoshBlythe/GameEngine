#include "Shader.h"
#include "FragmentShader.h"
#include "VertexShader.h"

Shader::Shader()
{
	success = 0;
}

Shader::~Shader()
{
	//clean up shaders
	glDetachShader(m_shaderID, _vertShader->InitVertShader());

	glDetachShader(m_shaderID, _fragmentShader->FragmentShaderInit());
}

void Shader::CheckFragInit()
{
}

void Shader::CheckVertxInit()
{
}

GLuint Shader::ProgramID()
{
	//program
	m_shaderID = glCreateProgram();
	glAttachShader(m_shaderID, _vertShader->InitVertShader());
	glAttachShader(m_shaderID, _fragmentShader->FragmentShaderInit());
	glBindAttribLocation(m_shaderID, 0, "in_Position");

	

	if (glGetError() != GL_NO_ERROR)
	{
		throw Exception("Program Error: glGetError is not Equal to No Error. ");
	}

	glLinkProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw Exception("Program, Success Error! ");
	}
	return m_shaderID;
}
