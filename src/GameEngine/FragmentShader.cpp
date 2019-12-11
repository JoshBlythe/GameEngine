#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
	m_fragmentShaderSrc =
		"void main()"\
		"{"\
		"	gl_FragColor = vec4(0, 0, 1, 1);"\
		"}"\
		"";
}

FragmentShader::~FragmentShader()
{
	glDeleteShader(m_fragmentShaderID);
}

GLuint FragmentShader::FragmentShaderInit()
{	
	//fragment shader
	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragmentShaderID, 1, &m_fragmentShaderSrc, NULL);
	glCompileShader(m_fragmentShaderID);

	/*if (!_success)
	{
		throw Exception("Reset State Fragment shader, Success Error! ");
	}*/

	return m_fragmentShaderID;

}


