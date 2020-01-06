#include "Keyboard.h"
#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
	m_inputManger = std::make_shared<UserInput>();

    _keys = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::getKey(SDL_Scancode _key)
{
    //works on windows
        if (_keys[_key])
		{
			return true;
		}

        return false;



	//if (m_inputManger->isKey(_key))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

}

