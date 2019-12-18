#include "UserInput.h"

void UserInput::onTick()
{
	currMousePos();
}

void UserInput::isKey(int _key)
{

}


void UserInput::currMousePos()
{
	SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

bool UserInput::isMouseClicked()
{
	if (SDL_GetMouseState(&m_mouseX, &m_mouseY) 
		&& SDL_BUTTON(SDL_BUTTON_LEFT) || SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		//return false, as the mouse button is realsed after the press.
		//m_mouseClicked = false;
		return true;
	}

	return false;
}
