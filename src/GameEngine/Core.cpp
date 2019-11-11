#include "Core.h"
#include "Entity.h"
#include "Screen.h"

std::shared_ptr<Core> Core::initalize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	//referencing c to weak_ptr of care
	//this will be used to moving up through the hierearchy
	c->m_self = c;
	//return core
	return c;
}

Core::~Core()
{
	//clean up SDL
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e = std::make_shared<Entity>();
	
	e->entity = m_self;
	
	m_entities.push_back(e);

	return e;
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

	if (!SDL_GL_CreateContext(m_window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw Exception("Glew Init Error: ");
	}


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
		
		//onDisplay loop
		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			(*iter)->OnDisplay();
		}

	}
}


