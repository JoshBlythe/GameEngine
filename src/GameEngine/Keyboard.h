#include <SDL2/SDL.h>
#include <memory>
#include <vector>

class Core;
class UserInput;
class Camera;

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    //void CameraMovement(float _deltatime);

//#define SDL_KEYDOWN

	bool getKey(SDL_Scancode _key);

private:
	friend class Core;

    std::shared_ptr<UserInput> m_inputManger;

	std::weak_ptr<Core> m_kCore;

};
