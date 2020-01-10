#include <glm/glm.hpp>
#include <vector>

class Core;
class Entity;
class Mesh;

#include "Component.h"



class CollisionDetection : public Component
{
public:
	CollisionDetection();
	~CollisionDetection();

	void onInitalise();
	void setSize(glm::vec3 _size);
	void setOffSet(glm::vec3 _offSet);

private:
	void onTick();

	void collisionLoop();
	void collideStaticMesh();
	bool isColliding(glm::vec3 _pos, glm::vec3 _size);
	glm::vec3 getCollisionRes(glm::vec3 _pos, glm::vec3 _size);
	//bool triangle_intersect(glm::vec3 a1, glm::vec3 b1, glm::vec3 c1,
		//glm::vec3 a2, glm::vec3 b2, glm::vec3 c2);

	friend class Core;

	glm::vec3 m_boxSize;
	glm::vec3 m_offSet;
	glm::vec3 m_lastPos;

	std::weak_ptr<Core> m_cldCore;
};
