#include "Player.h"

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

glm::vec3 Player::movePosition()
{
	if (true)
	{

	}
	return glm::vec3();
}
