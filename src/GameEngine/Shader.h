//#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>

class VertexShader;
class FragmentShader;
#include "Exception.h"

class Shader
{
public:
	Shader();
	~Shader();

	//void Draw();

	GLuint ProgramID();

	GLuint GetID() { return m_shaderID; }

private:

	std::shared_ptr<FragmentShader> _fragmentShader;
	std::shared_ptr<VertexShader> _vertShader;

	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	GLuint m_shaderID;

	GLint m_success;

};
