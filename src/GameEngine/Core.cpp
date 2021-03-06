#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"
#include "Resources.h"
#include "Enviroment.h"
#include "Camera.h"
#include "Keyboard.h"
//#include "CollisionDetection.h"
#include "GUI.h"

#include <AL/al.h>
#include <AL/alc.h>

//#include "stb_vorbis.h"

std::shared_ptr<Core> Core::onInitalise(int argc, char** argv)
{
	std::shared_ptr<Core> c_rtn = std::make_shared<Core>();
	//referencing c_rtn to weak_ptr of core
	//this will be used to moving up through the hierearchy
	c_rtn->m_self = c_rtn;
	
	//initalise screen
	c_rtn->m_screen = std::make_shared<Screen>();
	c_rtn->getScreen()->m_core = c_rtn;

	//initalise SDL window
	c_rtn->windowInit();
	//pass sdl window into context to ensure rend doesn't hold onto sdl once the engine has
	//closed
	c_rtn->m_graphicalContext = rend::Context::initialize(c_rtn->m_window);

    //initalise Resources
	c_rtn->m_resources = std::make_shared<Resources>();
	c_rtn->getResources()->m_core = c_rtn;

	//initalise keyboard
    c_rtn->m_keyboard = std::make_shared<Keyboard>();
    c_rtn->getKeyboard()->m_kCore = c_rtn;

    //initalise Enviroment
    c_rtn->m_enviroment = std::make_shared<Enviroment>(argc, argv);
	c_rtn->getEnviroment()->m_eCore = c_rtn;

	//c_rtn->m_collision = std::make_shared<CollisionDetection>();
	//c_rtn->getCollision()->m_cldCore = c_rtn;
	//c_rtn->getCamera()->m_camSelf = c_rtn;
	//c_rtn->m_camera = std::make_shared<Camera>();
	//c_rtn->m_enviroment = std::make_shared<Enviroment>();

    //here needs to be included for sound to run
    c_rtn->soundInit();

	c_rtn->m_gui = std::make_shared<GUI>(c_rtn);

	//return core
	return c_rtn;
}

Core::~Core()
{
	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);
	alcCloseDevice(m_device);
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e_rtn = std::make_shared<Entity>();
	
	e_rtn->m_entSelf = e_rtn;
	e_rtn->m_core = m_self;

	m_entities.push_back(e_rtn); 

	//add a transform to each entity
	e_rtn->m_trans = e_rtn->addComponent<Transform>();
    //e_rtn->m_entIsAlive = true;

	return e_rtn;
}

std::shared_ptr<Resources> Core::getResources()
{
	return m_resources;
}

std::shared_ptr<Camera> Core::getCamera()
{
	//std::cout << m_camera.lock().get() << std::endl;
	return m_camera.lock();
}

std::shared_ptr<Screen> Core::getScreen()
{
	//gets a context of Screen
	return m_screen;
}

std::shared_ptr<Enviroment> Core::getEnviroment()
{
	//gets a context of Enviroment
	return m_enviroment;
}

std::shared_ptr<Keyboard> Core::getKeyboard()
{
	//gets a context of Keyboard
	return m_keyboard;
}

std::shared_ptr<rend::Context> Core::getGraphicalContext()
{
	//gets a context of rend Context
	return m_graphicalContext;
}

std::shared_ptr<GUI> Core::getGUI()
{
	//gets a context of GUI
	return m_gui;
}


void Core::windowInit()
{
	//get screen coordinates from keyboard
    m_windowW = m_screen->getScreen().x;
    m_windowH = m_screen->getScreen().y;

	//initalise SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw Exception("SDL_Init Error: ");
	}

	//create window
	m_window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		m_windowW, m_windowH, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	//check if window initalised
	if (!m_window)
	{
		throw Exception("Error Creating SDL_Window!");
	}

	//check if create context in null
	if (!SDL_GL_CreateContext(m_window))
	{
		throw Exception("Error during SDL_GL_CreatContext!");
	}
}

void Core::soundInit()
{
	// open up OpenAL and the device
	m_device = alcOpenDevice(NULL);

	if (m_device == NULL)
	{
		throw Exception("Failed to open audio device!");
	}

	//create audio OpenAL context
	m_context = alcCreateContext(m_device, NULL);

	if (m_context == NULL)
	{
		alcCloseDevice(m_device);
		throw Exception("Audio Device Context failed to initalise!");
	}

	//set current context
	if (!alcMakeContextCurrent(m_context))
	{
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
		throw Exception("Failed to set current context of Audio Device!");
	}

	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
}

int Core::getWindowW()
{
	return m_windowW;
}

int Core::getWindowH()
{
	return m_windowH;
}


void Core::runCore()
{
	//loop variable
	bool m_looper = true;
	//loop condition
	while (m_looper)
	{
		SDL_Event m_event = { 0 };

		while (SDL_PollEvent(&m_event))
		{
			if (m_event.type == SDL_QUIT)
			{
				m_looper = false;
				//throw Exception("Close temp");
			}
			// if key is down, add it to the keys Pressed vector in keyboard
            else if(m_event.type == SDL_KEYDOWN)
            {
                //add the key to vector
                m_keyboard->m_keysPressed.push_back(m_event.key.keysym.sym);
            }
			// if key is up, add it to the keys Released vector in keyboard
            else if (m_event.type == SDL_KEYUP)
            {
                for (size_t i = 0; i < m_keyboard->m_keysPressed.size(); i++ )
                {
                    if(m_keyboard->m_keysPressed.at(i) == m_event.key.keysym.sym)
                    {
                        //remove key from vector
                        m_keyboard->m_keysPressed.erase(m_keyboard->m_keysPressed.begin()+ i);
                        //ensure the next value isn't missed
                        i--;
                    }
                }
                //m_keyboard->m_keysReleased.push_back(m_event.key.keysym.sym);
            }
		}


		//call the enviroment initalise function
		getEnviroment()->updateDelts();
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
            if ((*iter)->m_entIsAlive == false)
            {
                //TODO:
                //should before deleting the entity delete all the components attached to it

                //if so delete it and set iter to equal new list size
                iter = m_entities.erase(iter);
            }
            else
            {
                //else contiune interating through the list
               iter++;
            }
        }

		//clear screen before render
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//onDisplay loop
		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			//std::cout << "?" << std::endl;
            (*iter)->onDisplay();
		}

		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			//std::cout << "?" << std::endl;
			(*iter)->onGUI();
		}

		//tell the engine which window to use
		SDL_GL_SwapWindow(m_window);
	}

}


