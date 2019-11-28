#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <list>
#include <memory>
#include "RendInc.h"

//#include "Entity.h"
class Entity;
class Screen;
class Resources;
class Enviroment;

class Core
{
public:
	static std::shared_ptr<Core> OnInitalise();

	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Resources> getResources();

	void CreateWindow();

	~Core();
	//main loop
	void runCore();
	//stop running main loop
	void stopCore();

protected:
	//initalise SDL window;
	SDL_Window* m_window;

	//initalie OpenAL varibales
	ALCdevice* _device;
	ALCcontext* _context;

private:
	//Core();
	std::weak_ptr <Core> m_self;

	std::shared_ptr<Screen> m_screen;
	std::shared_ptr<Resources> m_resources;
	std::shared_ptr<Enviroment> m_enviroment;
	std::shared_ptr <rend::Context> m_graphicalContext;

	int m_windowW;
	int m_windowH;

	//SDL_Renderer* m_renderer;

	bool m_systemLoop;

	std::list <std::shared_ptr<Entity>> m_entities;
};