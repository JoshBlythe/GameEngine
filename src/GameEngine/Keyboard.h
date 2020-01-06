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
