#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::InitPlayer(std::shared_ptr<Mesh> _obj)
{
	m_playerUnits.push_back(_obj);
}