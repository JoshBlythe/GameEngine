#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

class Core;

class Screen
{
public:
	Screen();
	~Screen();

    glm::vec2 getScreen() { return m_screenSize; }

private:
    friend class Core;

	glm::vec2 m_screenSize;
    std::weak_ptr<Core> m_core;

};

