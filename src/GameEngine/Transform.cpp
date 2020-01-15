#include "Transform.h"

Transform::Transform()
{
	//set default scale
    m_objectScale = glm::vec3( 1,1,1 );
    //initalise varaibles ensuring that they aren't set to random memory
    //as my laptop doesn't have the patched version of OpenGL
    m_objectPosition = glm::vec3(0,0,0);
    m_objectRotation = glm::vec3(0,0,0);
}

Transform::~Transform()
{

}

void Transform::setPosition(glm::vec3 _posVec)
{
	m_objectPosition.x = _posVec.x;
	m_objectPosition.y = _posVec.y;
	m_objectPosition.z = _posVec.z;
}

void Transform::setRotation(glm::vec3 _rotVec)
{
	m_objectRotation.x = _rotVec.x;
	m_objectRotation.y = _rotVec.y;
	m_objectRotation.z = _rotVec.z;
}

void Transform::setScale(glm::vec3 _scaVec)
{
	m_objectScale.x = _scaVec.x;
	m_objectScale.y = _scaVec.y;
	m_objectScale.z = _scaVec.z;
}

glm::vec3 Transform::getPosition()
{
	return m_objectPosition;
}

glm::vec3 Transform::getRotation()
{
	return m_objectRotation;
}

glm::vec3 Transform::getScale()
{
	return m_objectScale;
}

glm::mat4 Transform::getModel()
{
	// create identity mat4
	glm::mat4 _m(1.0f);

	// trans pos, 
	_m = glm::translate(_m, m_objectPosition);

	// rotate x, rot y, rot z, 
	_m = glm::rotate(_m, m_objectRotation.x, glm::vec3(1, 0, 0));
	_m = glm::rotate(_m, m_objectRotation.y, glm::vec3(0, 1, 0));
	_m = glm::rotate(_m, m_objectRotation.z, glm::vec3(0, 0, 1));

	// then scale, 
	_m = glm::scale(_m, m_objectScale);

	//return ident
	return _m;
}
