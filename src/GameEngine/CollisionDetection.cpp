#include "CollisionDetection.h"
#include "ModelCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

CollisionDetection::CollisionDetection()
{
	//initalise vector, as glm doesn't initalise to 0,
	//this is mostly useful when porting the different verisions of openGL then the one used.
	//as the used version through the SDK is patched by Karsten.
    m_offSet = { 0, 0, 0 };
}

CollisionDetection::~CollisionDetection()
{
	// no memory clean up as smart pointer are used,
	// so as this goes out of scope the pointer are clean up.
}


void CollisionDetection::onInitalise()
{
	//get the position of the Entity
    m_lastPos = getEntity()->getTransform()->getPosition();
}

void CollisionDetection::setSize(glm::vec3 _size)
{
	//set the box size.
    m_boxSize.x = _size.x;
    m_boxSize.y = _size.y;
    m_boxSize.z = _size.z;
}

void CollisionDetection::setOffSet(glm::vec3 _offSet)
{
	//set the offset of the box
	m_offSet = _offSet;
}

void CollisionDetection::onTick()
{

    //getEntity()->getComponent<Transform>()->getRotation();
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
		//set entity position
        getEntity()->getTransform()->setPosition(_currPos);
		// set last position.
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
    glm::vec3 _a = getEntity()->getTransform()->getPosition() + m_offSet;
	glm::vec3& _as = this->m_boxSize;
	glm::vec3& _b = _pos;
	glm::vec3& _bs = _size;

	if (_a.x > _b.x) // a right of b
	{
		if (_a.x - _as.x > _b.x + _bs.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_b.x - _bs.x > _a.x + _as.x)
		{
			return false;
		}
	}

	if (_a.z > _b.z) // a front of b
	{
		if (_a.z - _as.z > _b.z + _bs.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_b.z - _bs.z > _a.z + _as.z)
		{
			return false;
		}
	}

	if (_a.y > _b.y) // a above b
	{
		if (_a.y - _as.y > _b.y + _bs.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_b.y - _bs.y > _a.y + _as.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 CollisionDetection::getCollisionRes(glm::vec3 _pos, glm::vec3 _size)
{
	float _amount = 0.1f;
	float _step = 0.1f;

	while (true)
	{
		if (!isColliding(_pos, _size)) break;
		_pos.x += _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.x -= _amount;
		_pos.x -= _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.x += _amount;
		_pos.z += _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.z -= _amount;
		_pos.z -= _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.z += _amount;
		_pos.y += _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.y -= _amount;
		_pos.y -= _amount;
		if (!isColliding(_pos, _size)) break;
		_pos.y += _amount;
		_amount += _step;
	}

	return _pos;
}
