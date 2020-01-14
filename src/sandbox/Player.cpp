#include "Player.h"

#include "GameEngine/GameEngine.h"


Player::Player()
{
}

Player::~Player()
{
}

//void Player::initPlayer(std::shared_ptr<Mesh> _obj, glm::vec3 _position)
//{
//	m_playerUnits.push_back(_obj);
//	m_unitPosition = _position;
//}
//
//void Player::movePosition()
//{
//	if (m_inputMang.lock()->isMouseClicked())
//	{
//
//	}
//	//return glm::vec3();
//}
//
//void Player::moveCamera(float _deltaTime)
//{
//	float _speed = 1.0f * _deltaTime;
//
//	/*if ()
//	{
//
//	}*/
//}

void Player::onGUI()
{
	getCore()->getGUI()->setTexture();
}
