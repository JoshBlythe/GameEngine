#include "Transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

glm::mat4 Transform::GetModel()
{
	glm::mat4 m_identityMat = glm::translate(
		glm::rotate(glm::rotate(glm::rotate(glm::scale(m_identityMat, m_objectScale),
			m_objectRotation.x, glm::vec3(1, 0, 0)), 
			m_objectRotation.y, glm::vec3(0, 1, 0)),  
			m_objectRotation.z, glm::vec3(0, 0, 1)), 
			m_objectPosition);

		//glm::translate(glm::mat4(1.0f), m_objectPosition);
	// create ident mat4, then do the following
	// trans pos, 
	// rotate x, rot y, rot z, 
	// then scale sca, 
	//return ident

	return m_identityMat;
}
