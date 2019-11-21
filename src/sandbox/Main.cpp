//#include <GameEngine/GameEngine.h>
#include <memory>
#include <iostream>

#include "TestScene.h"

int main()
{
	//initalise the engine
	std::shared_ptr<Core> core = Core::OnInitalise();
	//create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();
	
	//adding simple conent to engine
	std::shared_ptr<TestScene> testing = entity->addComponent<TestScene>();
	
	//std::shared_ptr<GameEngine::Mesh> mesh = core->getResources()->loadResource<Mesh>("")

	
	std::shared_ptr<Transform> tran = entity->getComponent<Transform>();
	//tran->getEntity()->getComponent<Transform>();
	//start the engine's main loop
	core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
