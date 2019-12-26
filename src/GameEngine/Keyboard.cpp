#include "Keyboard.h"
#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
    const Uint8* _keys = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::keyPressed(int _key)
{
	isKeyPressed(_key);
	
	return true;
}

void Keyboard::isKey(int _key)
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

void Keyboard::isKeyPressed(int _key)
{
	//check is key is pressed.
	if (_key == SDL_KEYDOWN)
	{
		isKey(_key);

		for (size_t i = 0; i < m_keysPressed.size(); i++)
		{
			if (_key = m_keysPressed[i])
			{
				continue;
				//return true;
			}
			else
			{
				m_keysPressed.push_back(_key);
			}
		}
	}
	//else
	//{
	//	//isKeyReleased(_key);
	//	return false;
	//}

}

void Keyboard::isKeyReleased(int _key)
{
	if (_key == SDL_KEYUP || _key != SDL_KEYDOWN)
	{
		for (size_t i = 0; i < m_keysReleased.size(); i++)
		{
			if (_key = m_keysReleased[i])
			{
				continue;
				//return true;
			}
			else
			{
				m_keysReleased.push_back(_key);
			}
		}

	}
	//else
	//{
	//	return false;
	//}
}

//void Keyboard::CameraMovement(float _deltatime)
//{
//    float _camMove = 0.01f * _deltatime;
//
//    if(m_inputManger.lock()->keyPressed(SDL_SCANCODE_W))
//    {
//        m_camera.lock()->getEntity()->getTransform()->setPosition(glm::vec3(_camMove, 0, 0));
//    }
//	
//}
