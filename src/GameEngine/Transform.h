#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	~Transform();

	//initalise Values
	void setPosition(glm::vec3 _posVec)
	{
		m_objectPosition.x = _posVec.x, m_objectPosition.y = _posVec.y, m_objectPosition.z = _posVec.z;
	}
	
	void setRotation(glm::vec3 _posVec)
	{
		m_objectRotation.x = _posVec.x, m_objectRotation.y = _posVec.y, m_objectRotation.z = _posVec.z;
	}
	
	void setScale(glm::vec3 _posVec)
	{
		m_objectScale.x = _posVec.x, m_objectScale.y = _posVec.y, m_objectScale.z = _posVec.z;
	}

    glm::vec3 getPosition() { return m_objectPosition; }
    glm::vec3 getRotation() { return m_objectRotation; }
    glm::vec3 getScale() { return m_objectScale; }

    glm::mat4 getModel();

protected:
	//position
	glm::vec3 m_objectPosition;
	//rotation
	glm::vec3 m_objectRotation;
	//scale
	glm::vec3 m_objectScale;
};
