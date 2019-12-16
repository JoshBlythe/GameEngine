#include <glm/glm.hpp>
#include <vector>

class Entity;
class Mesh;

#include "Component.h"



class CollisionDetection : public Component
{
public:
	CollisionDetection();
	~CollisionDetection();

	void onInit();
	void setSize(glm::vec3 _size);
	void setOffSet(glm::vec3 _offSet);

private:
	void onTick();

	void collisionLoop();
	bool isColliding(glm::vec3 _pos, glm::vec3 _size);
	glm::vec3 getCollisionRes(glm::vec3 _pos, glm::vec3 _size);
	//bool triangle_intersect(glm::vec3 a1, glm::vec3 b1, glm::vec3 c1,
		//glm::vec3 a2, glm::vec3 b2, glm::vec3 c2);

	glm::vec3 m_boxSize;
	glm::vec3 m_offSet;
	glm::vec3 m_lastPos;
};
