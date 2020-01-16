#include "Player.h"

#include "GameEngine/GameEngine.h"


Player::Player()
{
}

Player::~Player()
{
}


void Player::onGUI()
{
    //get the GUI from the GUI class, have to get it from core.
    // this function will set the GUI.
	getCore()->getGUI()->setTexture();
}
