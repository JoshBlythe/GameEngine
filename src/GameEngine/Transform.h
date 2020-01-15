/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef  _Transform_
#define _Transform_ 

/**
* Included Libraries.
*/
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
* MeshRender Class includes.
*/
#include "Component.h"

/**
* Initalisation of the class. This class Inherits from Component.
*/
class Transform : public Component
{
public:
	Transform();
    virtual ~Transform();

	//initalise Values
	/**
	* This function is used to set/change the Position of a Entity.
	*/
	void setPosition(glm::vec3 _posVec);

	/**
	* This function is used to set/change the Rotation of a Entity.
	*/
	void setRotation(glm::vec3 _rotVec);

	/**
	* This function is used to set/change the Scale of a Entity.
	*/
	void setScale(glm::vec3 _scaVec);

	/**
	* This function is used to get the Position of a Entity.
	*/
	glm::vec3 getPosition();
	/**
	* This function is used to get the Rotation of a Entity.
	*/
	glm::vec3 getRotation();
	/**
	* This function is used to get the Scale of a Entity.
	*/
	glm::vec3 getScale();

	/**
	* This function is used to the model, by creating a identity matrix, translating it/roatating
	* and scaling it.
	*/
    glm::mat4 getModel();

protected:
	//position
	glm::vec3 m_objectPosition; /*!< Varibale used to store the Postion. */
	//rotation
	glm::vec3 m_objectRotation; /*!< Varibale used to store the Rotation. */
	//scale
	glm::vec3 m_objectScale; /*!< Varibale used to store the Scale. */
};

#endif // ! _Transform_
