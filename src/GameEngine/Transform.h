#include <glm/glm.hpp>
#include "GL/glew.h"

class Transform
{
public:
	Transform();
	~Transform();

	//initalise Values
	void setObjPosition(float m_posX, float m_posY, float m_posZ) 
	{ m_objectPosition.x = m_posX, m_objectPosition.y = m_posY, m_objectPosition.z = m_posZ; }
	
	void setObjRotation(float m_rotX, float m_rotY, float m_rotZ) 
	{ m_objectRotation.x = m_rotX, m_objectRotation.y = m_rotY, m_objectRotation.z = m_rotZ; }
	
	void setObjScale(float m_scaX, float m_scaY, float m_scaZ) 
	{ m_objectScale.x = m_scaX, m_objectScale.y = m_scaY, m_objectScale.z = m_scaZ; }


protected:
	//position
	glm::vec3 m_objectPosition;
	//rotation
	glm::vec3 m_objectRotation;
	//scale
	glm::vec3 m_objectScale;
};