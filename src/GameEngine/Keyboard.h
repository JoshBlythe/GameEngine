#include <SDL2/SDL.h>
#include <memory>
#include <vector>

//define the key // this is needed for all keys in game
#define GE_UP SDLK_UP
#define GE_DOWN SDLK_DOWN
#define GE_LEFT SDLK_LEFT
#define GE_RIGHT SDLK_RIGHT
//Player Movement
#define GE_W SDLK_w
#define GE_S SDLK_s
#define GE_A SDLK_a
#define GE_D SDLK_d
//Player Rotate
#define GE_Q SDLK_q
#define GE_E SDLK_e

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


    void isKey(int _key);
	bool isKeyPressed(int _key);

private:
	friend class Core;
	const Uint8* _keys;

    //std::shared_ptr<UserInput> m_inputManger;
	std::vector<int> m_keys;
	std::vector<int> m_keysPressed;
	std::vector<int> m_keysReleased;

	std::weak_ptr<Core> m_kCore;

};
