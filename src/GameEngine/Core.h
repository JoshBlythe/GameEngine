#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <list>
#include <memory>

//#include "Entity.h"
class Entity;
class Screen;

class Core
{
public:
	static std::shared_ptr<Core> OnInitalise();

	std::shared_ptr<Entity> addEntity();

	void CreateWindow();

	~Core();
	//main loop
	void runCore();
	//stop running main loop
	void stopCore();


private:
	//Core();

	std::weak_ptr <Core> m_self;

	std::shared_ptr<Screen> m_screen;

	int m_windowW;
	int m_windowH;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	bool m_systemLoop;

	std::list < std::shared_ptr<Entity>> m_entities;
};