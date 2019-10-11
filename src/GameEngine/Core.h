#include <iostream>
#include <Windows.h>
#include <memory>
#include <list>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Entity.h"

class Core
{
public:

	static std::shared_ptr<Core> initalize();

	std::shared_ptr<Entity> addEntity();

	~Core();
	//bool initaliseGlew();
	void runCore();
	void stopCore();


private:
	Core();

	int windowX;
	int windowY;
	int windowW;
	int windowH;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::list < std::shared_ptr<Entity>> entities;
};