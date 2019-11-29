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
	
	void setRotation(float m_rotX, float m_rotY, float m_rotZ) 
	{ m_objectRotation.x = m_rotX, m_objectRotation.y = m_rotY, m_objectRotation.z = m_rotZ; }
	
	void setScale(float m_scaX, float m_scaY, float m_scaZ) 
	{ m_objectScale.x = m_scaX, m_objectScale.y = m_scaY, m_objectScale.z = m_scaZ; }

	glm::vec3 GetPosition() { return m_objectPosition; }
	glm::vec3 GetRotation() { return m_objectRotation; }
	glm::vec3 GetScale() { return m_objectScale; }

	glm::mat4 GetModel(); 

protected:
	//position
	glm::vec3 m_objectPosition;
	//rotation
	glm::vec3 m_objectRotation;
	//scale
	glm::vec3 m_objectScale;
};
