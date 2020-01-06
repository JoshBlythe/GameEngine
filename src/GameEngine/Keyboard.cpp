#include "Keyboard.h"
#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
	//m_inputManger = std::make_shared<UserInput>();

    _keys = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::getKey(SDL_Scancode _key)
{
    //works
        if (_keys[_key] && _keys[SDL_KEYDOWN])
        {
            return true;
        }

        return false;


        //if (isKeyPressed(_key) && _keys[SDL_KEYDOWN])
        //{
        //	return true;
        //}





	//if (m_inputManger->isKey(_key))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

}

bool Keyboard::isKeyPressed(int _key)
{
	for (size_t i = 0; i < m_keysPressed.size(); i++)
	{

		if (m_keysPressed.at(i) == _key)
		{
			//m_keysPressed.push_back(_key);
			return true;
		}
		else
		{
			m_keysPressed.push_back(_key);
		}


	}

    return false;
}

