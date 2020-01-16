/**
* Included Libraries.
*/
#include <SDL2/SDL.h>
#include <memory>
#include <vector>

//define the key // this is needed for all keys in game

/**
* Define Camera Movement keys.
*/
#define GE_UP SDLK_UP
#define GE_DOWN SDLK_DOWN
#define GE_LEFT SDLK_LEFT
#define GE_RIGHT SDLK_RIGHT
//Player Movement
/**
* Define Player Movement keys.
*/
#define GE_W SDLK_w
#define GE_S SDLK_s
#define GE_A SDLK_a
#define GE_D SDLK_d
//Player Rotate
/**
* Define Player Rotate Movement keys.
*/
#define GE_Q SDLK_q
#define GE_E SDLK_e

/**
* Forward declaration Class's used within the Class
*/
class Core;
class UserInput;
class Camera;

/**
* Initalisation of the class.
*/
class Keyboard
{
public:
	/**
	* This class is used to handle user input from the keyboard, if a key is pressed or released it is moved into or removed from the vectors defined below.
	* It also defines the keys which can be pressed by the user above.
	*/
    Keyboard();
    ~Keyboard();

	/**
	* This function check if key is pressed and returns true if it is.
	* If it isn't the function will return false.
	*/
    bool getKey(int _key);

private:
	friend class Core; /*!< Friend Class, allows access to the private variables of Core. */
	const Uint8* _keys; /*!< Variable used to initalise the key. */

    std::vector<int> m_keys;  /*!< Vector to store all keys pressed. */
	std::vector<int> m_keysPressed; /*!< Vector to store if a key pressed. */
	std::vector<int> m_keysReleased; /*!< Vector to store all keys released. */

	std::weak_ptr<Core> m_kCore; /*!< Weak pointer to Core. */

};
