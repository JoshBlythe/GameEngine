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

	void OnDraw();

private:

	SDL_Window * m_Window;
	GLuint positionVboId;
	GLuint vaoID;

	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint prgramId;
};
