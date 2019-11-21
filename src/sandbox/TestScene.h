#pragma once
#include <GameEngine/GameEngine.h>
//#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class TestScene : public Component
{
public:
	TestScene();
	virtual ~TestScene();

	void OnInitalise();
	void OnDraw();

private:

	std::sr1::shared_ptr<GameEngine::Context> _context;
	std::sr1::shared_ptr<GameEngine::Shader> _shader;
	std::sr1::shared_ptr<GameEngine::Buffer> _buffer;
	std::sr1::shared_ptr<GameEngine::Mesh> _mesh;

	const GLchar *vertexShaderSrc;
	const GLchar *fragmentShaderSrc;

	//std::shared_ptr<Shader> _shader = std::make_shared<Shader>();

	SDL_Window * m_Window;
	GLuint positionVboId;
	GLuint vaoID;

	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint prgramId;
};
