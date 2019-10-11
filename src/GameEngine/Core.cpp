#include "Core.h"

Core::Core()
{
}

std::shared_ptr<Core> Core::initalize()
{
	return std::shared_ptr<Core>();
}

Core::~Core()
{
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e = std::make_shared<Entity>();
	m_entities.push_back(e);

	return e;
}

bool Core::initaliseGlew()
{
	glewExperimental = GL_TRUE;

	GLenum errorInit = glewInit();

	if (GLEW_OK != errorInit)
	{
		std::cerr << "Error: GLEW failed to initialise with message: "
			<< glewGetErrorString(errorInit) << std::endl;
		
		return false;
	}

	return true;
}

void Core::runCore()
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
	m_windowX = GetSystemMetrics(SM_CXSCREEN);
	m_windowY = GetSystemMetrics(SM_CYSCREEN);
	m_windowW = 5;
	m_windowH = 25;

	//create window
	m_window = SDL_CreateWindow("Game Engine Assignment!",
		m_windowX, m_windowY, m_windowW, m_windowH,
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

	//call initalise GLEW function to set up GLEW
	if (!initaliseGlew())
	{
		throw std::exception();
		//return -1;
	}

	//enable depth testing, ensures triangles are draw in front no matter.
	glEnable(GL_DEPTH_TEST);

	//set loop condition
	m_systemLoop = true;
	//loop condition
	while (m_systemLoop)
	{

	}

}


