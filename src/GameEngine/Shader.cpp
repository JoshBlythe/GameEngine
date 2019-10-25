#include "Shader.h"

Shader::Shader()
{
	vertexShaderSrc =
		"attribute vec3 in_Position;"\
		""\
		"void main()"\
		"{"\
		"	gl_Position = vec4(in_Position, 1.0);"\
		"}"\
		"";

	fragmentShaderSrc =
		"void main()"\
		"{"\
		"	gl_FragColor = vec4(0, 0, 1, 1);"\
		"}"\
		"";
}

Shader::~Shader()
{
	//clean up shaders
	/*glDetachShader(prgramId, vertexShaderID);
	glDeleteShader(vertexShaderID);
	glDetachShader(prgramId, fragmentShaderID);
	glDeleteShader(fragmentShaderID);*/
}

GLuint Shader::PositionID()
{
	//set position of VBO
	positionVboId = 0;

	//Creates a VBO on the GPU and binds it to position 1
	glGenBuffers(1, &positionVboId);

	if (!positionVboId)
	{
		throw Exception("position VBO ID Genbuffer Error: Cannot bind to CPU. ");
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionVboId);

	//upload a copy of data from memory to the created VBO 
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions),
		positions, GL_STATIC_DRAW);

	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return positionVboId;
}

GLuint Shader::VaoID()
{
	//initalising the vao
	vaoID = 0;
	//create new VAO on GPU and bind it
	glGenVertexArrays(1, &vaoID);

	if (!vaoID)
	{
		throw Exception("VAO ID Genbuffer Error: Cannot bind to CPU. ");
	}

	glBindVertexArray(vaoID);

	//bind the position VBO, then assign it to a position 0 on the bound VAO and flag it for use
	glBindBuffer(GL_ARRAY_BUFFER, positionVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(0);
	
	return vaoID;
}

GLuint Shader::VertShader()
{
	//vertex shader
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderID);
	GLint success = 0;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	//check for success if not throw exeption
	if (!success)
	{
		throw Exception("Reset State Vertex shader, Success Error! ");
	}

	return vertexShaderID;
}

GLuint Shader::FragShader()
{
	//fragment shader
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderID);
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw Exception("Reset State Fragment shader, Success Error! ");
	}

	return fragmentShaderID;
}

GLuint Shader::ProgramID()
{
	//program
	prgramId = glCreateProgram();
	glAttachShader(prgramId, vertexShaderID);
	glAttachShader(prgramId, fragmentShaderID);
	glBindAttribLocation(prgramId, 0, "in_Position");

	if (glGetError() != GL_NO_ERROR)
	{
		throw Exception("Program Error: glGetError is not Equal to No Error. ");
	}

	glLinkProgram(prgramId);
	glGetProgramiv(prgramId, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw Exception("Program, Success Error! ");
	}
	return prgramId;
}

