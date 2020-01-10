#include "CollisionDetection.h"
#include "ModelCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

CollisionDetection::CollisionDetection()
{
	m_offSet = { 0, 0, 0 };
}

CollisionDetection::~CollisionDetection()
{
}


void CollisionDetection::onInitalise()
{
    m_lastPos = getEntity()->getTransform()->getPosition();
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
	collideStaticMesh();
	collisionLoop();
}

void CollisionDetection::collisionLoop()
{
	//vector of entities which have collision attached to them
    std::list<std::shared_ptr<Entity>> _allCollisionTag;

	//get entity based on its component
    getCore()->getEntities<CollisionDetection>(_allCollisionTag);


	glm::vec3 _currPos = getEntity()->getTransform()->getPosition() + m_offSet;
	//std::cout << _currPos.x << _currPos.y << _currPos.z << std::endl;

    for (std::list<std::shared_ptr<Entity>>::iterator it = _allCollisionTag.begin();
		it != _allCollisionTag.end(); it++)
	{
		//stop is colliding with itself
		if (*it == getEntity())
		{
			continue;
		}

		std::shared_ptr<CollisionDetection> _cd =
			(*it)->getComponent<CollisionDetection>();

		//call functions to check for collision
		glm::vec3 _sp = _cd->getCollisionRes(_currPos, m_boxSize);
		
		_currPos = _sp;
		_currPos = _currPos - m_offSet;
        getEntity()->getTransform()->setPosition(_currPos);
		m_lastPos = _currPos;

	}
}

void CollisionDetection::collideStaticMesh()
{
	std::list<std::shared_ptr<Entity>> _staticTag;

	getCore()->getEntities<ModelCollider>(_staticTag);

	glm::vec3 _currPos = getEntity()->getTransform()->getPosition(); +m_offSet;

	for (std::list<std::shared_ptr<Entity>>::iterator it = _staticTag.begin(); 
		it != _staticTag.end(); it++)
	{
		std::shared_ptr<ModelCollider> _staticMesh = (*it)->getComponent<ModelCollider>();

		bool _solved = false;
		glm::vec3 _sp = _staticMesh->getCollisionResponse(_currPos, m_boxSize, _solved);
		
		if (_solved)
		{
			_currPos = _sp;
		}
		else
		{
			_sp = m_lastPos + m_offSet;
		}

		_currPos = _currPos - m_offSet;
		getEntity()->getTransform()->setPosition(_currPos);
		m_lastPos = _currPos;

	}
}

bool CollisionDetection::isColliding(glm::vec3 _pos, glm::vec3 _size)
{
    glm::vec3 a = getEntity()->getTransform()->getPosition() + m_offSet;
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
