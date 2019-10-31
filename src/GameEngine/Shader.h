
//#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Shader
{
public:
	Shader() {}
	Shader(std::string _vert, std::string _frag);
	~Shader();

	//void Draw();
	void SetUniform(glm::vec4 _position);
	void SetUniform(float _setUniform);

	GLuint GetID() { return m_shaderID; }

private:
	GLuint m_shaderID;

};
