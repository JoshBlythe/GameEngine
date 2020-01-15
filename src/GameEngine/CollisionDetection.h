/**
* Included Libraries.
*/
#include <glm/glm.hpp>
#include <vector>

/**
* Forward declaration Class's used within the Class
*/
class Core;
class Entity;
class Mesh;
/**
* Componet Class included, for inheritance.
*/
#include "Component.h"

/**
* Collision Inherits from the Component Class
*/
class CollisionDetection : public Component
{
public:
	/**
	* This Class is used to handle Collision between Entities that have a Collision component
	* attached to them, this can be either 'CollisionDetection' or 'ModelCollider'.
	* To do this the onTick function calls the collisionLoop and CollideStaticMesh functions
	* these get Entities if they have a either component stated above attached them and add them to 
	* a list and check for collision with all varibles in the list.
	*/
	CollisionDetection();
	virtual ~CollisionDetection();

	/**
	* The Initalise function for Collision, this overwrites the inherited Class 'Component'
	* onInitalise function.
	*/
	void onInitalise();
	
	/**
	* This Function is used to set the size of the Collision box.
	*/
	void setSize(glm::vec3 _size);
	/**
	* This Function is used to set the offset of the Collision box.
	*/
	void setOffSet(glm::vec3 _offSet);

private:
	/**
	* The onTick function for Collision, this overwrites the inherited Class 'Component'
	* onTick function. 
	*/
	void onTick();
	/**
	* This Function handles the Box Collision, for all Entities that have a,
	* CollsionDetection Component attached to it.
	*/
	void collisionLoop();
	/**
	* This Function handles the Static Model Collision, for all Entities that have a,
	* ModelCollision, Component attached to it.
	*/
	void collideStaticMesh();
	/**
	* This Function Checks for Collision between the objects, passed through to it by
	* the Collision Loop.
	*/
	bool isColliding(glm::vec3 _pos, glm::vec3 _size);
	/**
	* This Function handles the collsion of the objects passed to it by the 
	* the isCollision Function.
	*/
	glm::vec3 getCollisionRes(glm::vec3 _pos, glm::vec3 _size);
	//bool triangle_intersect(glm::vec3 a1, glm::vec3 b1, glm::vec3 c1,
		//glm::vec3 a2, glm::vec3 b2, glm::vec3 c2);

	friend class Core; /*!< Friend Class, allows access to the private variables of Core. */

	glm::vec3 m_boxSize; /*!< Initalision of the Box Size. */
	glm::vec3 m_offSet; /*!< Initalision of the Box offset. */
	glm::vec3 m_lastPos; /*!< Initalision Entities last position. */

	//std::weak_ptr<Core> m_cldCore;
};
