#include <SDL2/SDL.h>
#include <memory>
#include <vector>

//define the key // this is needed for all keys in game
#define GE_UP SDLK_UP
#define GE_DOWN SDLK_DOWN
#define GE_LEFT SDLK_LEFT
#define GE_RIGHT SDLK_RIGHT
//Player Movement
#define GE_W SDLK_W
#define GE_S SDLK_S
#define GE_A SDLK_A
#define GE_D SDLK_D
//Player Rotate
#define GE_Q SDLK_Q
#define GE_E SDLK_E

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

    bool getKey(int _key);

private:
	friend class Core;
	const Uint8* _keys;

    //std::shared_ptr<UserInput> m_inputManger;
	std::vector<int> m_keys;
	std::vector<int> m_keysPressed;
	std::vector<int> m_keysReleased;

	std::weak_ptr<Core> m_kCore;

};
