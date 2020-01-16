/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _ModelCollider_
#define _ModelCollider_

/**
* Included Libraries.
*/
#include <glm/glm.hpp>
#include <sr1/zero_initialized>
#include <sr1/memory>

#include <vector>

/**
* Class includes.
*/
#include "Component.h"


/**
* Extent Store the Extent min and max values.
*/
struct Extent
{
  glm::vec3 max;
  glm::vec3 min;
};

/**
* CollisionTrig Stores the triangle positions (this is for each face).
*/
struct CollisionTrig
{
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
};

/**
* This is the Column Collider, used to split the Model it different Column's to test for collision,
* is more optimual then testing against the whole model each time.
*/
struct ColliderColumn
{
	glm::vec3 position;
	glm::vec3 size;
	std::vector<CollisionTrig> faces;

  bool isColliding(glm::vec3 position, glm::vec3 size);

  void getColliding(glm::vec3 position, glm::vec3 size,
    std::vector<CollisionTrig>& collisions);
};

/**
* Initalisation of the class, it inherits from Component.
*/
class ModelCollider : public Component
	/**
	* This Class inherits from Component, this allows it to be attached to a Entity,
	* the purpose of the class is to test collision against the faces of a Model,
	* The faces of the currents models faces are stored in rend.
	* To get the faces the function calls the mesh within resouces, which has the current mesh's
	* faces passed to it from the MeshRender class, once it has the current mesh it pushes all the faces
	* into a vector which passed into the pass, this is the allFaces vector below.
	* The class then checks collision on a per faces bases.
	*/
{
    std::vector<CollisionTrig> m_allFaces; /*!< Vector to store all the faces, used to get the faces from Game Engine Mesh. */
	//glm::vec3 position;

  std::vector<std::sr1::shared_ptr<ColliderColumn> > cols; /*!< Vector stores all the collision columns. */
  Extent extent;
  std::sr1::zero_initialized<float> resolution; /*!< Resolution Variable. */
  std::sr1::zero_initialized<float> tryStep; /*!< try step Variable. */
  std::sr1::zero_initialized<float> maxStep;/*!< max step Variable. */
  std::sr1::zero_initialized<float> tryInc; /*!< try inc Variable. */
  std::sr1::zero_initialized<float> maxInc; /*!< max inc Variable. */
  std::vector<CollisionTrig> collisions; /*!< Vector for all collision. */

	void getColliding(glm::vec3 position, glm::vec3 size,
	  std::vector<CollisionTrig>& collisions);

	/**
	* Generate Extent function.
	*/
  void generateExtent(); 
  /**
  * Function to add each face into Collider Column cols vector.
  */
  void addFace(CollisionTrig face);
  /**
  * Function to get the faces normal.
  */
  glm::vec3 faceNormal(CollisionTrig& face);

public:
	/**
	* on initalise function, overwrites the components on initalise.
	*/
  void onInitalise();
  /**
  * Function returns the Extent.
  */
  Extent getExtent();

  /**
  * Checks if there is a collision takes in a Face, position and size.
  */
  bool isColliding(CollisionTrig& face, glm::vec3 position,
    glm::vec3 size);

  /**
  * Checks if there is a collision takes a position and size.
  */
  bool isColliding(glm::vec3 position, glm::vec3 size);
  /**
  * Get Colliding.
  */
  void getColliding(glm::vec3 position, glm::vec3 size);

  /**
  * This function gets the collision Response
  */
  glm::vec3 getCollisionResponse(glm::vec3 position,
    glm::vec3 size, bool& solved);

};

#endif // !_ModelCollider_
