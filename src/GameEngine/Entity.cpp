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

void Entity::ticks()
{
	//std::cout << "ticking through! " << std::endl;
		for (tick = 0; tick < 5; tick++)
		{
			update();
		}	
}

void Entity::update()
{
	for (std::list<std::shared_ptr<Component>>::iterator it =
		m_component.begin(); it != m_component.end(); it++)
	{
		(*it)->update();
	}
}


void Entity::display()
{
	//interate though the list and draw each Object

	std::cout << "displaying" << std::endl;
}
