#pragma once
#include <glm/gtc/matrix_transform.hpp>

class Screen
{
public:
	Screen();
	~Screen();

	glm::vec2 GetScreen() { return m_screenSize; }

private:

	glm::vec2 m_screenSize;

};

