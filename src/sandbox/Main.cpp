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
	
	std::shared_ptr <Mesh> mesh = core->getResources()->load<Mesh>("samples\curuthers");
	testing->SetMesh(mesh);

	
	std::shared_ptr<Transform> tran = entity->getComponent<Transform>();
//	entity->GetTransform()->setPosition(glm::vec3(10.0f, 0.0f, 0.0f));
	tran->getEntity()->getComponent<Transform>();
	//start the engine's main loop
	core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
