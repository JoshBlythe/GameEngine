#include "Keyboard.h"
#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
	m_inputManger = std::make_shared<UserInput>();

    const Uint8* _keys = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::getKey(SDL_Scancode _key)
{
	//if (SDL_KEYUP)
	//{
	//	if (_key == SDL_SCANCODE_W)
	//	{
	//		return true;
	//	}
	//}

	if (m_inputManger->isKeyPressed(_key))
	{
		return true;
	}
	else
	{
		return false;
	}

}

