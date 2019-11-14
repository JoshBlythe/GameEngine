#include <sr1/memory>
#include "RendInc.h"

#include "Core.h"
#include "Entity.h"
#include "Screen.h"


std::shared_ptr<Core> Core::OnInitalise()
{
	std::shared_ptr<Core> c_rtn = std::make_shared<Core>();
	//referencing c to weak_ptr of care
	//this will be used to moving up through the hierearchy
	c_rtn->m_self = c_rtn;
	//return core
	return c_rtn;
}

Core::~Core()
{
	//clean up SDL
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e_rtn = std::make_shared<Entity>();
	
	e_rtn->entity = m_self;
	
	m_entities.push_back(e_rtn);

	return e_rtn;
}

void Core::CreateWindow()
{
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

	/*if (glewInit() != GLEW_OK)
	{
		throw Exception("Glew Init Error: ");
	}*/

	//calls glewInit, and checks if it was successful
	//if not will through a exeption.
	std::sr1::shared_ptr<GameEngine::Context> _context = GameEngine::Context::initialize(m_window);
	std::sr1::shared_ptr<GameEngine::Shader> _shader = _context->createShader();



}


void Core::runCore()
{
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

	}
}


