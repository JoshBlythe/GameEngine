#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Enviroment.h"
#include "CollisionDetection.h"
#include "ModelCollider.h"

Entity::Entity()
{
    m_entIsAlive = true;
}

Entity::~Entity()
{
}

void Entity::Ticks()
{
	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		(*m_it)->onTick();
	}

	//deleted a component if flagged to be deleted
	for (auto it = m_component.begin(); it != m_component.end();)
	{
		if ((*it)->m_compIsAlive == false)
		{
			it = m_component.erase(it);
		}
		else
		{
			it++;
		}
	}
	//Update();
}

//void Entity::Update()
//{
//
//	
//
//}


void Entity::onDisplay()
{
	//interate though the list and draw each Object

	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		try
		{
			(*m_it)->onDraw();

		}
		catch (Exception& e)
		{
			//catch the broken entity
			std::cout << "Exception: " << e.Error() << std::endl;
			//then delete it
		}

	}
}

void Entity::killEntity()
{
	//flagging a entity to be deleted
	m_entIsAlive = false;
}

std::shared_ptr<Transform> Entity::getTransform()
{
	return m_trans.lock();
}

std::shared_ptr<CollisionDetection> Entity::getCollision()
{
	//return m_checkCol.lock();
	return getComponent<CollisionDetection>();
}

std::shared_ptr<ModelCollider> Entity::getModelCollision()
{
	return getComponent<ModelCollider>();
}

std::shared_ptr<Core> Entity::getCore()
{
	//lock weak pointer to return shared pointer to core.
	return m_core.lock();
}
