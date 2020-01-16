#include <GameEngine/GameEngine.h>

#include <memory>

struct cameraMovement : public Component
{
//amounts and delta store
  float _camMove;
  float _camRot;
  float _delta;

  //store current data
  glm::vec3 _currPos;
  glm::vec3 _currRot;
  
  //update values
  glm::vec3 _moveZ;
  glm::vec3 _moveX;
  glm::vec3 _rotator;

  void onInitalise()
  {
    //_delta = getCore()->getEnviroment()->getDelts();
	_currPos = getEntity()->getTransform()->getPosition();
	_currRot = getEntity()->getTransform()->getRotation();

	//initalise the move directions
	_moveZ = { 0, 0, -1 };
	_moveX = { -1, 0, 0 };
	_rotator = { 0, -1, 0 };

	//initalise the amount to move
    _camMove = 1.0f;
    _camRot = 1.0f;
  }

  void onTick()
  {
      //std::cout << getCore()->getEnviroment()->getDelts() << std::endl;

      if (getCore()->getKeyboard()->getKey(GE_UP))
	  {
		  //update Camera Position - Move Forward 

          //std::cout << _currPos.x << _currPos.z << std::endl;
          _currPos += _camMove * _moveZ * getCore()->getEnviroment()->getDelts();
		  getEntity()->getTransform()->setPosition(_currPos);
	  }
      if (getCore()->getKeyboard()->getKey(GE_DOWN))
	  {
		  //update Camera Position - Move Backwards
		  _currPos -= _camMove * _moveZ * getCore()->getEnviroment()->getDelts();
		  getEntity()->getTransform()->setPosition(_currPos);
	  }
      if (getCore()->getKeyboard()->getKey(GE_LEFT))
	  {
		  //update Camera Position - Move Backwards
		  //getEntity()->getTransform()->setPosition(glm::vec3(-_camMove, 0, 0));
		  _currPos += _camMove * _moveX * getCore()->getEnviroment()->getDelts();
		  getEntity()->getTransform()->setPosition(_currPos);
	  }
      if (getCore()->getKeyboard()->getKey(GE_RIGHT))
	  {
		  //update Camera Position - Move Backwards
		  _currPos -= _camMove * _moveX * getCore()->getEnviroment()->getDelts();
		  getEntity()->getTransform()->setPosition(_currPos);
	  }

	  //rotate Camara
	  if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_Q))
	  {
		  //update Camera Position - Move Backwards
		  _currRot -= _camRot * _rotator;
		  getEntity()->getTransform()->setRotation(_currRot);
	  }
	  if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_E))
	  {
		  //update Camera Position - Move Backwards
		  _currRot += _camRot * _rotator;
		  getEntity()->getTransform()->setRotation(_currRot);
	  }

	  
  }
};

struct movePlayer : public Component
{
	//amounts and delta store
	float _camMove;
	float _camRot;
	float _delta;

	//store current data
	glm::vec3 _currPos;
	glm::vec3 _currRot;

	//update values
	glm::vec3 _moveZ;
	glm::vec3 _moveX;
	glm::vec3 _rotator;

	void onInitalise()
	{
        //_delta = getCore()->getEnviroment()->getDelts();
		_currPos = getEntity()->getTransform()->getPosition();
		_currRot = getEntity()->getTransform()->getRotation();

		_moveZ = { 0, 0, -1 };
		_moveX = { -1, 0, 0 };
		_rotator = { 0, -1, 0 };

        _camMove = 1.0f;
        _camRot = 1.0f;
	}

	void onTick()
    {
        if (getCore()->getKeyboard()->getKey(GE_W))
		{
			//update Camera Position - Move Forward 
			//std::cout << _currPos.x << _currPos.z << std::endl;
			_currPos += _camMove * _moveZ * getCore()->getEnviroment()->getDelts();
			getEntity()->getTransform()->setPosition(_currPos);
		}
        if (getCore()->getKeyboard()->getKey(GE_S))
		{
			//update Camera Position - Move Backwards
			// std::cout << _currPos.x << _currPos.z << std::endl;
			_currPos -= _camMove * _moveZ * getCore()->getEnviroment()->getDelts();
			getEntity()->getTransform()->setPosition(_currPos);
		}
        if (getCore()->getKeyboard()->getKey(GE_A))
		{
			//update Camera Position - Move Backwards
			_currPos += _camMove * _moveX * getCore()->getEnviroment()->getDelts();
			getEntity()->getTransform()->setPosition(_currPos);
		}
        if (getCore()->getKeyboard()->getKey(GE_D))
		{
			//update Camera Position - Move Backwards
			_currPos -= _camMove * _moveX * getCore()->getEnviroment()->getDelts();
			getEntity()->getTransform()->setPosition(_currPos);
		}

		//rotate Camara
        if (getCore()->getKeyboard()->getKey(GE_Q))
		{
			//update Camera Position - Move Backwards
			_currRot -= _camRot * _rotator * getCore()->getEnviroment()->getDelts();
            getEntity()->getTransform()->setRotation(_currRot);
		}
        if (getCore()->getKeyboard()->getKey(GE_E))
		{
			//update Camera Position - Move Backwards
			_currRot += _camRot * _rotator * getCore()->getEnviroment()->getDelts();
			getEntity()->getTransform()->setRotation(_currRot);
		}
	}
};

int main(int argc, char* argv[])
{
	//initalise the engine
    std::shared_ptr<Core> _core = Core::onInitalise(argc, argv);
	
	//add entities to core
	//create a single in-game object
	//adding Camera
	std::shared_ptr<Entity> _cam = _core->addEntity();
	std::shared_ptr<Entity> _catUnit = _core->addEntity();
	std::shared_ptr<Entity> _catUnitTest = _core->addEntity();
	std::shared_ptr<Entity> _map = _core->addEntity();

	//adding simple content to engine
	std::shared_ptr<Camera> _camera = _cam->addComponent<Camera>();
	std::shared_ptr<MeshRender> _renderMesh = _catUnit->addComponent<MeshRender>();
	std::shared_ptr<MeshRender> _renderMeshTest = _catUnitTest->addComponent<MeshRender>();
	std::shared_ptr<MeshRender> _renderMap = _map->addComponent<MeshRender>();

    //load mesh from file
	std::shared_ptr<Mesh> _unitMesh = _core->getResources()->load<Mesh>("curuthers/curuthers");
	std::shared_ptr<Mesh> _unitMeshTest = _core->getResources()->load<Mesh>("curuthers/curuthers");
	std::shared_ptr<Mesh> _mapMesh = _core->getResources()->load<Mesh>("graveyard/graveyard");
	
	//set mesh
	_renderMesh->setMesh(_unitMesh);
	_renderMeshTest->setMesh(_unitMeshTest);
	_renderMap->setMesh(_mapMesh);

	//load texture from file
	std::shared_ptr<Material> _material = _core->getResources()->load<Material>("curuthers/Whiskers_diffuse");
	std::shared_ptr<Material> _materialTest = _core->getResources()->load<Material>("curuthers/Whiskers_diffuse");
	std::shared_ptr<Material> _mapMat = _core->getResources()->load<Material>("graveyard/graveyard");
	
	//set texture
	_renderMesh->setMaterial(_material);
	_renderMeshTest->setMaterial(_materialTest);
	_renderMap->setMaterial(_mapMat);

	//set scale
    _catUnit->getTransform()->setScale(glm::vec3(0.2, 0.2, 0.2));
	_catUnitTest->getTransform()->setScale(glm::vec3(0.2, 0.2, 0.2));

	//set the position of the camera
	//set position of models
    _catUnit->getTransform()->setPosition(glm::vec3(0, 0, -4));
	_catUnitTest->getTransform()->setPosition(glm::vec3(2, 0, -4));
    _map->getTransform()->setPosition(glm::vec3(0, -2, -8));
    //_cam->getTransform()->setPosition(glm::vec3(0, 0, 0));

	//sound loading
	//load sound source from file
	std::shared_ptr<Sound> _hornSound = _core->getResources()->load<Sound>("sound/dixie_horn");
	
	//get sound source
	_hornSound = _core->getResources()->load<Sound>("sound/dixie_horn");
	//need for sound to load, loading of the sound file
	//playing sound from camera
	_cam->addComponent<SoundSource>()->setSound(_hornSound);
	
    //set collision box size


	//add collision component to mesh
    std::shared_ptr<CollisionDetection> _catCollsion = _catUnit->addComponent<CollisionDetection>();
    std::shared_ptr<CollisionDetection> _catCollsionTest = _catUnitTest->addComponent<CollisionDetection>();
	
	//TODO: ADD BACK AND FIX STATIC COLLISION
    std::shared_ptr<ModelCollider> _mapCollsion = _map->addComponent<ModelCollider>();


    _catUnit->getCollision()->setSize(glm::vec3(0.3, 0.3, 0.3));
    _catUnitTest->getCollision()->setSize(glm::vec3(0.3, 0.3, 0.3));
	//_map->getComponent<ModelCollider>()->setSize(glm::vec3(1, 1, 1));

	//add player for GUI
	std::shared_ptr<Player> _player = _cam->addComponent <Player>();
	
	//add movement to camera.
    _cam->addComponent<cameraMovement>();
    _catUnit->addComponent<movePlayer>();
	
	//start the engine's main loop
	_core->runCore();

	//system("PAUSE");

	//std::cout << "GamesEngine" << std::endl;

	return 0;
}
