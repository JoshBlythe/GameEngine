#include "Keyboard.h"
#include "UserInput.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

Keyboard::Keyboard()
{
    const Uint8* _keys = SDL_GetKeyboardState(NULL);
}

void Keyboard::CameraMovement(float _deltatime)
{
    float _camMove = 0.01f * _deltatime;

    //if(m_inputManger.lock()->isKeyPressed(SDL_SCANCODE_W))
    //{
      //  m_camera.lock()->getEntity()->getTransform()->setPosition(glm::vec3(_camMove, 0, 0));
    //}
}
