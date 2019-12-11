//#include <GameEngine/GameEngine.h>
#include <memory>
#include <iostream>

//#include <GameEngine/GameEngine.h>
#include "TestScene.h"

int main()
{
	//initalise the engine
	std::shared_ptr<Core> core = Core::OnInitalise();
	//create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();
	
	//adding simple conent to engine
	std::shared_ptr<TestScene> testing = entity->addComponent<TestScene>();
	
	//uni path before having file location
	//C:/Users/s4908021/gep_sdk-20191121/GameEngine/resources/rend/samples/curuthers/curuthers
	std::shared_ptr <Mesh> mesh = core->getResources()->load<Mesh>("D:/Users/JoshComputer/Documents/GEP/GameEngine/resources/rend/samples/curuthers/curuthers");
	testing->SetMesh(mesh);

	//std::shared_ptr<Material> _material = core->getResources()->load<Material>("D:/Users/JoshComputer/Documents/GEP/GameEngine/resources/rend/samples/curuthers/Whiskers_diffuse");
	//testing->SetMaterial(_material);

	std::shared_ptr<Transform> tran = entity->getComponent<Transform>();
	entity->GetTransform()->setPosition(glm::vec3(0, 0, -15));
	//tran->getEntity()->getComponent<Transform>();

	std::shared_ptr<Entity> cam = core->addEntity();
	//std::make_shared<Camera>();
	std::shared_ptr<Camera> camera = cam->addComponent<Camera>();
	cam->GetTransform()->setPosition(glm::vec3(0, 0, 10));

	//start the engine's main loop
	core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
