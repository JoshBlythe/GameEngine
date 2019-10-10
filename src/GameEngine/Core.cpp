#include "Core.h"

Core::Core()
{
}

Core::~Core()
{
}

void Core::RunCore()
{
	//initalise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		//print error if cant
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	//use OpenGL Version 4
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	//else use OpenGl Version 3
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//set profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	//above has initalised SDL
	// ....................
	//initalise window parameters
	windowX = GetSystemMetrics(SM_CXSCREEN);
	windowY = GetSystemMetrics(SM_CYSCREEN);
	windowW = 5;
	windowH = 25;

	//create window
	m_window = SDL_CreateWindow("Game Engine Assignment!",
		windowX, windowY, windowW, windowH,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	//error check if window creates
	if (m_window == NULL)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	}

	//create renderer
	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//error check if renderer creates

	if (m_renderer == NULL)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;

	}


}

