#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"

class UserInput : public Component
{
public:
	UserInput();
	~UserInput();

	void onTick();

	void isKey(int _key);
	void isKeyPressed(int _key);
	void isKeyReleased(int _key);

	void currMousePos();

	//glm::vec3 rayPosition(Ray _ray, int  _xPos, int _yPos);

	int getCurrentMouseX() { return m_mouseX; }
	int getCurrentMouseY() { return m_mouseY; }
	bool isMouseClicked();

private:
	std::vector<int> m_keys;
	std::vector<int> m_keysPressed;
	std::vector<int> m_keysReleased;

	int m_mouseX;
	int m_mouseY;
	bool m_mouseClicked;
};