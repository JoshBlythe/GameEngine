#include "Keyboard.h"
//#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
    _keys = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::getKey(int _key)
{
    //loop through the keypressed vector
    for (size_t i = 0; i < m_keysPressed.size(); i++)
        {
            //check if the key pressed is in the vector
            if (m_keysPressed.at(i) == _key)
            {
                //return true if it is
                return true;
            }
        }
        //if not in the vector then return false.
        return false;

}
