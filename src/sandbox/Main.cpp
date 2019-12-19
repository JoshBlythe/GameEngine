//#include <GameEngine/GameEngine.h>
#include <memory>
//#include <iostream>

#define KEY_UP SDL_VKUP

#include <GameEngine/GameEngine.h>
//#include "TestScene.h"

struct Rotator : public Component
{
  float rot;

  void OnInitalise()
  {
    rot = 0;
  }

  void OnTick()
  {
    rot+= 0.001f;
    getEntity()->GetTransform()->setRotation(glm::vec3(0, rot, 0));

    // if(getCore()->getKeyboard()->getKey(KEY_UP))
    // // move forward
  }
};

int main(int argc, char* argv[])
{
	//initalise the engine
    std::shared_ptr<Core> _core = Core::OnInitalise(argc, argv);
	
	//add entities to core
	//create a single in-game object
	//adding Camera
	std::shared_ptr<Entity> _cam = _core->addEntity();
	std::shared_ptr<Entity> _catUnit = _core->addEntity();
	std::shared_ptr<Entity> _map = _core->addEntity();

	_cam->addComponent<Rotator>();

	//adding simple content to engine
	std::shared_ptr<Camera> _camera = _cam->addComponent<Camera>();
	std::shared_ptr<MeshRender> _renderMesh = _catUnit->addComponent<MeshRender>();
	std::shared_ptr<MeshRender> _renderMap = _map->addComponent<MeshRender>();

	//add collision component to mesh
	std::shared_ptr<CollisionDetection> _catCollsion = _catUnit->addComponent<CollisionDetection>();
	std::shared_ptr<CollisionDetection> _mapCollsion = _map->addComponent<CollisionDetection>();
	//load mesh from file
	std::shared_ptr <Mesh> _unitMesh = _core->getResources()->load<Mesh>("curuthers/curuthers");
	std::shared_ptr<Mesh> _mapMesh = _core->getResources()->load<Mesh>("graveyard/graveyard");

	//set mesh
	_renderMesh->SetMesh(_unitMesh);
	_renderMap->SetMesh(_mapMesh);

	//load texture from file
	std::shared_ptr<Material> _material = _core->getResources()->load<Material>("curuthers/Whiskers_diffuse");
	std::shared_ptr<Material> _mapMat = _core->getResources()->load<Material>("graveyard/graveyard");
	
	//set texture
	_renderMesh->SetMaterial(_material);
	_renderMap->SetMaterial(_mapMat);

	
	//set scale
	_catUnit->GetTransform()->setScale(glm::vec3(0.2, 0.2, 0.2));

	//set the position of the camera
	//set position of models
	_catUnit->GetTransform()->setPosition(glm::vec3(0, 0, -4));
	_map->GetTransform()->setPosition(glm::vec3(0, -2, -8));
	_cam->GetTransform()->setPosition(glm::vec3(0, 0, 0));

	//set collision box size
	//_catUnit->getCollision()->setSize(glm::vec3(1, 1, 1));
	//_map->getCollision()->setSize(glm::vec3(1, 1, 1));

	//add collision
	//catUnit->addComponent<CollisionDetection>();
	//catUnit->getCollision()->setSize(glm::vec3(1, 1, 1));

	//sound loading

	//need for sound to load, loading of the sound file
	std::shared_ptr<Sound> _hornSound = _core->getResources()->load<Sound>("sound/dixie_horn");
	_hornSound = _core->getResources()->load<Sound>("sound/dixie_horn");

	//playing sound from camera
	_cam->addComponent<SoundSource>()->setSound(_hornSound);

	//start the engine's main loop
	_core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
