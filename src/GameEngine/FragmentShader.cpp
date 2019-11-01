#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
	fragmentShaderSrc = 
		"void main()"\
		"{"\
		"	gl_FragColor = vec4(0, 0, 1, 1);"\
		"}"\
		"";
}

FragmentShader::~FragmentShader()
{
	glDeleteShader(fragmentShaderID);
}

GLuint FragmentShader::FragmentShaderInit()
{	
	//fragment shader
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderID);
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &_success);

	if (!_success)
	{
		throw Exception("Reset State Fragment shader, Success Error! ");
	}

	return fragmentShaderID;

}


