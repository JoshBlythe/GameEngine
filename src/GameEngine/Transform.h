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
    /**
    * This Class inherits from Component, its purpose is to set the Entity Transform/Scale/Rotation
	@see setPosition
	@see setRotation
	@see setScale
    * a transform is applied to every entity on its creation. This is done in the addEntity function in core.
    * The Class also allows for the Transform/Scale/Rotation to be obtained or updated.
    */
	Transform();
    virtual ~Transform();

	//initalise Values
	/**
	* This function is used to set/change the Position of a Entity.
	@param _posVec takes in vector, this is used to set the Entity position.
	*/
	void setPosition(glm::vec3 _posVec);

	/**
	* This function is used to set/change the Rotation of a Entity.
	@param _rotVec takes in vector, this is used to set the Entity Rotation.
	*/
	void setRotation(glm::vec3 _rotVec);

	/**
	* This function is used to set/change the Scale of a Entity.
	@param _scaVec takes in vector, this is used to set the Entity Scale.
	*/
	void setScale(glm::vec3 _scaVec);

	/**
	* This function is used to get the Position of a Entity.
	@return The Position.
	@see m_objectPosition;
	*/
	glm::vec3 getPosition();
	
	/**
	* This function is used to get the Rotation of a Entity.
	@return The Rotation.
	@see m_objectRotation;
	*/
	glm::vec3 getRotation();
	
	/**
	* This function is used to get the Scale of a Entity.
	@return The Scale.
	@see m_objectScale;
	*/
	glm::vec3 getScale();

	/**
	* This function is used to the model, by creating a identity matrix, translating it/roatating
	* and scaling it.
	@return The Model Matrix.
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
