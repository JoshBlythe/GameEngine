#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"
#include "Resources.h"
#include "Camera.h"
//#include "Enviroment.h"
//#include "stb_vorbis.h"

std::shared_ptr<Core> Core::OnInitalise()
{
	std::shared_ptr<Core> c_rtn = std::make_shared<Core>();
	//referencing c to weak_ptr of care
	//this will be used to moving up through the hierearchy
	c_rtn->m_self = c_rtn;

	c_rtn->m_resources = std::make_shared<Resources>();

	c_rtn->getResources()->m_core = c_rtn;

	//c_rtn->m_enviroment = std::make_shared<Enviroment>();

	c_rtn->CreateWindow();

	c_rtn->m_graphicalContext = rend::Context::initialize();

	//c_rtn->m_enviroment

	//return core
	return c_rtn;
}

Core::~Core()
{
	//clean up SDL
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	/*alcMakeContextCurrent(NULL);
	alcDestroyContext(_context);
	alcCloseDevice(_device);*/
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e_rtn = std::make_shared<Entity>();
	
	e_rtn->m_entSelf = e_rtn;
	e_rtn->m_core = m_self;

	m_entities.push_back(e_rtn); 

	e_rtn->addComponent<Transform>();

	return e_rtn;
}

std::shared_ptr<Resources> Core::getResources()
{
	return m_resources;
}

std::shared_ptr<Camera> Core::getCamera()
{
	return m_camera.lock();
}

std::shared_ptr<Screen> Core::getScreen()
{
	return m_screen;
}


void Core::CreateWindow()
{
	m_screen = std::make_shared<Screen>();

	m_windowW = m_screen->GetScreen().x;
	m_windowH = m_screen->GetScreen().y;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw Exception("SDL_Init Error: ");
	}

	//create window
	m_window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		m_windowW, m_windowH, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!m_window)
	{
		throw Exception("Error Creating SDL_Window!");
	}

	if (!SDL_GL_CreateContext(m_window))
	{
		throw Exception("Error during SDL_GL_CreatContext!");
	}


	// open up OpenAL and the device
	//_device = alcOpenDevice(NULL);
	//
	//if (_device == NULL)
	//{
	//	throw Exception("Failed to open audio device!");
	//}

	////create audio OpenAL context
	//_context = alcCreateContext(_device, NULL);

	//if (_context == NULL)
	//{
	//	alcCloseDevice(_device);
	//	throw Exception("Audio Device Context failed to initalise!");
	//}

	////set current context
	//if (!alcMakeContextCurrent)
	//{
	//	alcDestroyContext(_context);
	//	alcCloseDevice(_device);
	//	throw Exception("Failed to set current context of Audio Device!");
	//}
}


void Core::runCore()
{
	//m_enviroment = std::make_shared<Enviroment>();

	//loop variable
	bool m_looper = true;
	//loop condition
	while (m_looper)
	{
		//loop through m_entites using iterator.
		for (std::list<std::shared_ptr<Entity>>::iterator 
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			(*iter)->Ticks();
		}
		
		//check if a items within the list has been flagged to be deleted
		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end();)
		{
			//unasign pointer allowing use to access Entity functions
			//check if the item is still alive
			if ((*iter)->m_isAlive == false)
			{
				//if so delete it and set iter to equal new list size
				iter = m_entities.erase(iter);
			}
			else
			{
				//else contiune interating through the list
				iter++;
			}
		}

		//onDisplay loop
		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			(*iter)->OnDisplay();
		}

		SDL_GL_SwapWindow(m_window);
	}

}


