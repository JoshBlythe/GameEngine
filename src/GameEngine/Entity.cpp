#include "Entity.h"
#include "Component.h"


Entity::Entity()
{
}

Entity::~Entity()
{
}

//std::shared_ptr<Object> Entity::addObject()
//{
//	std::shared_ptr<Object> obj = std::make_shared<Object>();
//
//	m_objects.push_back(obj);
//
//	return obj;
//}

void Entity::Ticks()
{
	//std::cout << "ticking through! " << std::endl;
		for (m_tick = 0; m_tick < 5; m_tick++)
		{
			Update();
		}	
}

void Entity::Update()
{
	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		(*m_it)->onTick();
	}
}


void Entity::OnDisplay()
{
	//interate though the list and draw each Object

	for (std::list<std::shared_ptr<Component>>::iterator m_it =
		m_component.begin(); m_it != m_component.end(); m_it++)
	{
		(*m_it)->OnDraw();
	}
}
