#include "VertexShader.h"
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
}

VertexShader::~VertexShader()
{
	glDeleteShader(vertexShaderID);
}

bool VertexShader::LoadFile(std::string _verShader)
{
	std::ifstream vertexFile(_verShader);

	char *m_vertexShader = NULL;

	if (vertexFile.is_open())
	{
		// Find out how many characters are in the file
		vertexFile.seekg(0, vertexFile.end);
		int m_length = (int)vertexFile.tellg();
		vertFile.seekg(0, vertexFile.beg);

		// Create our buffer
		m_vertexShader = new char[m_length + 1];

		// Transfer data from file to buffer
		vertexFile.read(m_vertexShader, m_length);

		// Check it reached the end of the file
		if (!vertexFile.eof())
		{
			vertexFile.close();
			throw Exception("WARNING: could not read vertex shader from file! ");
			return false;
		}

		// Find out how many characters were actually read
		m_length = (int)vertexFile.gcount();

		// Needs to be NULL-terminated
		m_vertexShader[m_length] = 0;

		vertFile.close();
	}
	else
	{
		throw Exception("WARNING: could not read vertex shader from file! ");
		
		return false;
	}

	return true;
}

GLuint VertexShader::InitVertShader()
{
	//vertex shader
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderID);

	//success = 0;
	//glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	////check for success if not throw exeption
	//if (!success)
	//{
	//	throw Exception("Reset State Vertex shader, Success Error! ");
	//}

	return vertexShaderID;
}
