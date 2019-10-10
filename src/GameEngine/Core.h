#include <iostream>
#include <Windows.h>
#include <memory>

#include <SDL2/SDL.h>
#include <GL/glew.h>


class Core
{
public:

	std::shared_ptr<Core> Application = std::make_shared<Core>();

	~Core();
	bool initaliseGlew();
	void RunCore();

private:
	Core();

	int windowX;
	int windowY;
	int windowW;
	int windowH;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};