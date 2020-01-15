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

glm::mat4 Transform::getModel()
{
	// create ident mat4
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
