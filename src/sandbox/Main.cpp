#include <GameEngine/Core.h>

#include <memory>
#include <iostream>


int main()
{
	//initalise the engine
	std::shared_ptr<Core> core = Core::initalize();
	//create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();
	
	//adding simple conent to engine
	std::shared_ptr<Object> testingObj = entity->addObject();

	//start the engine's main loop
	core->runCore();

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}