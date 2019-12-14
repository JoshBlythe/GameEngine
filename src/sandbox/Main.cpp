//#include <GameEngine/GameEngine.h>
#include <memory>
#include <iostream>

#include <GameEngine/GameEngine.h>
//#include "TestScene.h"

int main()
{
	//initalise the engine
	std::shared_ptr<Core> core = Core::OnInitalise();
	//create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();
	
	//adding simple conent to engine
	std::shared_ptr<MeshRender> renderMesh = entity->addComponent<MeshRender>();
	
	//uni path before having file location
	//C:/Users/s4908021/gep_sdk-20191121/GameEngine/resources/rend/samples/curuthers/curuthers
	//D:/Users/JoshComputer/Documents/GEP/GameEngine/
	//../resources/rend/samples/
	std::shared_ptr <Mesh> mesh = core->getResources()->load<Mesh>("curuthers/curuthers");
	renderMesh->SetMesh(mesh);

	std::shared_ptr<Shader> _meshTexShader = core->getResources()->load<Shader>("shader/meshTexShader");

	std::shared_ptr<Material> _material = core->getResources()->load<Material>("curuthers/Whiskers_diffuse");
	//_material->setShader(_meshTexShader);
	renderMesh->SetMaterial(_material);

	std::shared_ptr<Transform> tran = entity->getComponent<Transform>();
	entity->GetTransform()->setPosition(glm::vec3(0, 0, -15));
	//tran->getEntity()->getComponent<Transform>();

	//need for sound to load, loading of the sound file
	//std::shared_ptr<Sound> _hornSound = core->getResources()->load<Sound>("sound/dixie_horn");
	//_hornSound = core->getResources()->load<Sound>("sound/dixie_horn");

	std::shared_ptr<Entity> cam = core->addEntity();
	//playing sound from camera
	//cam->addComponent<SoundSource>()->setSound(_hornSound);

	//std::make_shared<Camera>();
	std::shared_ptr<Camera> camera = cam->addComponent<Camera>();
	cam->GetTransform()->setPosition(glm::vec3(0, 0, 10));

	//start the engine's main loop
	core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
