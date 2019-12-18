#include <iostream>
#include <memory>
#include <list>
#include <glm/glm.hpp>

//#include "GameEngine/GameEngine.h"

class Mesh;
class Ray;
class UserInput;
class Camera;

class Player
{
public:
	Player();
	~Player();
	 
	void InitPlayer(std::shared_ptr<Mesh> _obj, glm::vec3 _position);
	void Update();
	void IsSelected();
	void movePosition();

	void moveCamera(float _deltaTime);

private:

	bool m_isSelected;

	glm::vec3 m_unitPosition;

	std::list<std::shared_ptr<Mesh>> m_playerUnits;

	std::weak_ptr<UserInput> m_inputMang;
	std::weak_ptr<Camera> m_cam;
	
};
