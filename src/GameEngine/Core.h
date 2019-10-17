//#include <iostream>
#include <Windows.h>
//#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Entity.h"

class Core
{
public:

	static std::shared_ptr<Core> initalize();

	std::shared_ptr<Entity> addEntity();

	~Core();
	//main loop
	void runCore();
	//stop running main loop
	void stopCore();


private:
	Core();

	bool m_systemLoop;

	/*int m_windowX;
	int m_windowY;
	int m_windowW;
	int m_windowH;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;*/

	std::list < std::shared_ptr<Entity>> m_entities;
};