#include "Player.h"
#include "GameEngine/UserInput.h"
#include "GameEngine/Camera.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::InitPlayer(std::shared_ptr<Mesh> _obj, glm::vec3 _position)
{
	m_playerUnits.push_back(_obj);
	m_unitPosition = _position;
}

void Player::movePosition()
{
	if (m_inputMang.lock()->isMouseClicked())
	{

	}
	//return glm::vec3();
}

void Player::moveCamera(float _deltaTime)
{
	float _speed = 1.0f * _deltaTime;

	/*if ()
	{

	}*/
}
