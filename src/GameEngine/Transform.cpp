#include "Transform.h"

Transform::Transform()
{
	m_objectScale = { 1,1,1 };
}

Transform::~Transform()
{
}

glm::mat4 Transform::GetModel()
{
	/*glm::mat4 m_idenMat = glm::scale(glm::rotate(glm::rotate(glm::rotate(
		glm::translate(m_idenMat, m_objectPosition),m_objectRotation.x, glm::vec3(1, 0, 0)), m_objectRotation.y, glm::vec3(0, 1, 0)), m_objectRotation.z, glm::vec3(0, 0, 1)), m_objectScale);*/

	glm::mat4 m(1.0f);

	m = glm::translate(m, m_objectPosition);

	m = glm::rotate(m, m_objectRotation.x, glm::vec3(1, 0, 0));
	m = glm::rotate(m, m_objectRotation.y, glm::vec3(0, 1, 0));
	m = glm::rotate(m, m_objectRotation.z, glm::vec3(0, 0, 1));

	m = glm::scale(m, m_objectScale);

		//glm::translate(glm::mat4(1.0f), m_objectPosition);
	// create ident mat4, then do the following
	// trans pos, 
	// rotate x, rot y, rot z, 
	// then scale sca, 
	//return ident

	return m;
}
