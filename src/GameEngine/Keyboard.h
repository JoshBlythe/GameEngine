#include <SDL2/SDL.h>

#include "memory"

class UserInput;
class Camera;

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    void CameraMovement(float _deltatime);

private:

    std::weak_ptr<UserInput> m_inputManger;
    std::weak_ptr<Camera> m_camera;

};
