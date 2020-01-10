#pragma once

#ifndef _ModelCollider_
#define _ModelCollider_

#include "Component.h"
//#include <qsoft/qsoft.h>

#include <glm\glm.hpp>
#include <sr1/zero_initialized>
#include <sr1/memory>

#include <vector>

struct Extent
{
  glm::vec3 max;
  glm::vec3 min;
};

struct CollisionTrig
{
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
};

struct ColliderColumn
{
	glm::vec3 position;
	glm::vec3 size;
	std::vector<CollisionTrig> faces;

  bool isColliding(glm::vec3 position, glm::vec3 size);

  void getColliding(glm::vec3 position, glm::vec3 size,
    std::vector<CollisionTrig>& collisions);
};

class ModelCollider : public Component
{
	std::vector<CollisionTrig> allFaces;
	glm::vec3 position;

  std::vector<std::sr1::shared_ptr<ColliderColumn> > cols;
  Extent extent;
  std::sr1::zero_initialized<float> resolution;
  std::sr1::zero_initialized<float> tryStep;
  std::sr1::zero_initialized<float> maxStep;
  std::sr1::zero_initialized<float> tryInc;
  std::sr1::zero_initialized<float> maxInc;
  std::vector<CollisionTrig> collisions;

	void getColliding(glm::vec3 position, glm::vec3 size,
	  std::vector<CollisionTrig>& collisions);

  void generateExtent();
  void addFace(CollisionTrig face);
  glm::vec3 faceNormal(CollisionTrig& face);

public:
  void onInitalise();
  Extent getExtent();


  bool isColliding(CollisionTrig& face, glm::vec3 position,
    glm::vec3 size);

  bool isColliding(glm::vec3 position, glm::vec3 size);
  void getColliding(glm::vec3 position, glm::vec3 size);

  glm::vec3 getCollisionResponse(glm::vec3 position,
    glm::vec3 size, bool& solved);

};

#endif // !_ModelCollider_
