#include "UserInput.h"

void UserInput::onTick()
{
	getMousePos();
}

void UserInput::isKey(int _key)
{
}


void UserInput::getMousePos()
{
	SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

bool UserInput::isMouseClicked()
{
	if (m_mouseClicked)
	{
		//return false, as the mouse button is realsed after the press.
		m_mouseClicked = false;
		return true;
	}

	return false;
}
