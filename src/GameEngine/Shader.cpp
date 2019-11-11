#include "Shader.h"
#include "FragmentShader.h"
#include "VertexShader.h"

Shader::Shader()
{
	m_success = 0;
}

Shader::~Shader()
{
	//clean up shaders
	glDetachShader(m_shaderID, m_vertexShaderID);
	glDetachShader(m_shaderID, m_fragmentShaderID);
}

GLuint Shader::ProgramID()
{
	m_vertexShaderID = _vertShader->InitVertShader();
	glShaderSource(m_vertexShaderID, 1, &_vertShader->VertSrc, NULL);
	glCompileShader(m_vertexShaderID);

	if (!m_success)
	{
		throw Exception("Reset State Vertex shader, Success Error! ");
	}

	m_fragmentShaderID = _fragmentShader->FragmentShaderInit();
	glGetShaderiv(m_fragmentShaderID, GL_COMPILE_STATUS, &m_success);
	
	if (!m_success)
	{
		throw Exception("Reset State Fragment shader, Success Error! ");
	}
		 
	//program
	m_shaderID = glCreateProgram();
	glAttachShader(m_shaderID, m_vertexShaderID);
	glAttachShader(m_shaderID, m_fragmentShaderID);
	glBindAttribLocation(m_shaderID, 0, "in_Position");

	if (glGetError() != GL_NO_ERROR)
	{
		throw Exception("Program Error: glGetError is not Equal to No Error. ");
	}

	glLinkProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_LINK_STATUS, &m_success);

	if (!m_success)
	{
		throw Exception("Program, Success Error! ");
	}
	return m_shaderID;
}
