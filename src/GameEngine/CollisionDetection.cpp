#include "CollisionDetection.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

CollisionDetection::CollisionDetection()
{
}

CollisionDetection::~CollisionDetection()
{
}


void CollisionDetection::onInit()
{
	m_lastPos = getEntity()->GetTransform()->GetPosition();
}

void CollisionDetection::setSize(glm::vec3 _size)
{
	//m_boxSize = _size;
	m_boxSize.x = _size.x, m_boxSize.y = _size.y, m_boxSize.z = _size.z;
}

void CollisionDetection::setOffSet(glm::vec3 _offSet)
{
	m_offSet = _offSet;
}

void CollisionDetection::onTick()
{
	collisionLoop();
}

void CollisionDetection::collisionLoop()
{
	std::vector<std::shared_ptr<Entity>> _aabb;

	getCore()->getEntity<CollisionDetection>(_aabb);
	glm::vec3 _currPos = getEntity()->GetTransform()->GetPosition();

	for (std::vector<std::shared_ptr<Entity>>::iterator it = _aabb.begin();
		it != _aabb.end(); it++)
	{
		if (*it == getEntity())
		{
			continue;
		}

		std::shared_ptr<CollisionDetection> _cd =
			(*it)->getComponent<CollisionDetection>();

		glm::vec3 _sp = _cd->getCollisionRes(_currPos, m_boxSize);
		
		_currPos = _sp;
		_currPos = _currPos - m_offSet;
		getEntity()->GetTransform()->setPosition(_currPos);
		m_lastPos = _currPos;

	}
}

bool CollisionDetection::isColliding(glm::vec3 _pos, glm::vec3 _size)
{
	glm::vec3 a = getEntity()->GetTransform()->GetPosition() + m_offSet;
	glm::vec3& as = this->m_boxSize;
	glm::vec3& b = _pos;
	glm::vec3& bs = _size;

	if (a.x > b.x) // a right of b
	{
		if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.x - bs.x > a.x + as.x)
		{
			return false;
		}
	}

	if (a.z > b.z) // a front of b
	{
		if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.z - bs.z > a.z + as.z)
		{
			return false;
		}
	}

	if (a.y > b.y) // a above b
	{
		if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.y - bs.y > a.y + as.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 CollisionDetection::getCollisionRes(glm::vec3 _pos, glm::vec3 _size)
{
	float amount = 0.1f;
	float step = 0.1f;

	while (true)
	{
		if (!isColliding(_pos, _size)) break;
		_pos.x += amount;
		if (!isColliding(_pos, _size)) break;
		_pos.x -= amount;
		_pos.x -= amount;
		if (!isColliding(_pos, _size)) break;
		_pos.x += amount;
		_pos.z += amount;
		if (!isColliding(_pos, _size)) break;
		_pos.z -= amount;
		_pos.z -= amount;
		if (!isColliding(_pos, _size)) break;
		_pos.z += amount;
		_pos.y += amount;
		if (!isColliding(_pos, _size)) break;
		_pos.y -= amount;
		_pos.y -= amount;
		if (!isColliding(_pos, _size)) break;
		_pos.y += amount;
		amount += step;
	}

	return _pos;
}

//bool CollisionDetection::triangle_intersect(glm::vec3 a1, glm::vec3 b1, glm::vec3 c1, glm::vec3 a2, glm::vec3 b2, glm::vec3 c2)
//{
//	int NoDivTriTriIsect(float V0[3], float V1[3], float V2[3],
//		float U0[3], float U1[3], float U2[3]);
//
//	if (NoDivTriTriIsect((float*)&a1, (float*)&b1, (float*)&c1,
//		(float*)&a2, (float*)&b2, (float*)&c2) == 1)
//	{
//		return true;
//	}
//
//	return false;
//}
