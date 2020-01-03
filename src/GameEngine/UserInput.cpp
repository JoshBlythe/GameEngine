#include "UserInput.h"

UserInput::UserInput()
{
}

UserInput::~UserInput()
{
}

void UserInput::onTick()
{
	//update current mouse position.
	currMousePos();

	//erase pressed and releases each frame
	m_keysPressed.clear();
	m_keysReleased.clear();

}

bool UserInput::keyPressed(int _key)
{
	isKeyPressed(_key);
	
	return true;
}

void UserInput::isKey(int _key)
{
	//loop through 
	for (size_t i = 0; i < m_keys.size(); i++)
	{
		//if key is in the vector
		if (_key = m_keys[i])
		{
			//to next item in the list
			continue;
		}
		else
		{
			//if not in the vector then add it
			m_keys.push_back(_key);
		}
		 
	}

}

bool UserInput::isKeyPressed(int _key)
{
	//check is key is pressed.
	if (_key == SDL_KEYDOWN)
	{
		//isKey(_key);

		for (size_t i = 0; i < m_keysPressed.size(); i++)
		{
			if (_key = m_keysPressed[i])
			{

				return true;
				//continue;
			}
			else
			{
				//add key to vector
				m_keysPressed.push_back(_key);
				//return
				return true;
			}
		}
	}

	return false;

	//isKeyReleased(_key);
}

void UserInput::isKeyReleased(int _key)
{
	if (_key == SDL_KEYUP)
	{
		for (size_t i = 0; i < m_keysReleased.size(); i++)
		{
			if (_key = m_keysReleased[i])
			{
				continue;
			}
			else
			{
				m_keysReleased.push_back(_key);
			}
		}

	}
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
