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

	bool keyPressed(int _key);
	void isKey(int _key);
	void isKeyPressed(int _key);
	void isKeyReleased(int _key);


private:
	std::vector<int> m_keys;
	std::vector<int> m_keysPressed;
	std::vector<int> m_keysReleased;
	
	friend class Core;

    std::weak_ptr<UserInput> m_inputManger;
    std::weak_ptr<Camera> m_camera;


	std::weak_ptr<Core> m_kCore;

};
