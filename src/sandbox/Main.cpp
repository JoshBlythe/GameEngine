//#include <GameEngine/GameEngine.h>
#include <memory>
#include <iostream>

#include "TestScene.h"

int main()
{
	//initalise the engine
	std::shared_ptr<Core> core = Core::initalize();
	//create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();
	
	//adding simple conent to engine
	std::shared_ptr<TestScene> testing = entity->addComponent<TestScene>();

	//start the engine's main loop
	core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}

//	glewExperimental = GL_TRUE;
//
//	GLenum errorInit = glewInit();
//
//	if (GLEW_OK != errorInit)
//	{
//		std::cerr << "Error: GLEW failed to initialise with message: "
//			<< glewGetErrorString(errorInit) << std::endl;
//		
//		return false;
//	}
//
//	return true;


////initalise SDL
//if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//{
//	//print error if cant
//	std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
//}

////use OpenGL Version 4
//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
////else use OpenGl Version 3
//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
////set profile
//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

////above has initalised SDL
//// ....................
////initalise window parameters
//m_windowX = GetSystemMetrics(SM_CXSCREEN);
//m_windowY = GetSystemMetrics(SM_CYSCREEN);
//m_windowW = 5;
//m_windowH = 25;

////create window
//m_window = SDL_CreateWindow("Game Engine Assignment!",
//	m_windowX, m_windowY, m_windowW, m_windowH,
//	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

////error check if window creates
//if (m_window == NULL)
//{
//	std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
//}

////create renderer
//m_renderer = SDL_CreateRenderer(m_window, -1,
//	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

//SDL_GLContext m_glContext = SDL_GL_CreateContext(m_window);

////error check if renderer creates

//if (m_renderer == NULL)
//{
//	std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
//}

////call initalise GLEW function to set up GLEW
//if (!initaliseGlew())
//{
//	throw std::exception();
//	//return -1;
//}

////enable depth testing, ensures triangles are draw in front no matter.
//glEnable(GL_DEPTH_TEST);

////set loop condition
//m_systemLoop = true;
////loop condition
//while (m_systemLoop)
//{
//	SDL_Event incomingEvent;

//	while (SDL_PollEvent(&incomingEvent))
//	{
//		switch (incomingEvent.type)
//		{
//		case SDL_QUIT:
//			m_systemLoop = false;
//			break;
//		}
//	}

//	//draw world

//	//update camera

//	//specify the colour to clear the framebuffer
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

//	//display above colour to framebuffer
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	//tell renderer to display content of the screen
//	SDL_GL_SwapWindow(m_window);


//}

//SDL_GL_DeleteContext(m_glContext);
//SDL_DestroyWindow(m_window);
//SDL_Quit();