#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Enviroment.h"
#include "CollisionDetection.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Ticks()
{
	//do the delta time here.
	//float time = SDL_GetTicks();
	//float _differ = time - GetCore()->getEnviroment()->getDelts();

	//std::cout << "ticking through! " << std::endl;
	//will change to be delta time to run on system loop.
		//for (int m_tick = 0; m_tick < 5; m_tick++)
		{
			Update();
			
		}	
}

void Entity::Update()
{
	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		(*m_it)->OnTick();
	}



	//deleted a component if flagged to be deleted
	for (auto it = m_component.begin(); it != m_component.end();)
	{
		if ((*it)->m_isAlive == false)
		{
			it = m_component.erase(it);
		}
		else
		{

			it++;
		}
	}

}


void Entity::OnDisplay()
{
	//interate though the list and draw each Object

	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		try
		{
			(*m_it)->OnDraw();

		}
		catch (Exception& e)
		{
			//catch the broken entity
			std::cout << "Exception: " << e.Error() << std::endl;
			//then delete it
		}

	}
}

void Entity::KillEntity()
{
	//flagging a entity to be deleted
	m_isAlive = false;
}

std::shared_ptr<Transform> Entity::GetTransform()
{
	return _trans.lock();
}

std::shared_ptr<CollisionDetection> Entity::getCollision()
{
	//return m_checkCol.lock();
	return getComponent<CollisionDetection>();
}

std::shared_ptr<Core> Entity::GetCore()
{
	//lock weak pointer to return shared pointer to core.
	return m_core.lock();
}
