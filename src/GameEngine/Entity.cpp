#include "Entity.h"
#include "Object.h"


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

void Entity::update()
{
	for (std::list<std::shared_ptr<Object>>::iterator it = 
		m_objects.begin(); it != m_objects.end(); it++)
	{
		(*it)->update();
	}
}

void Entity::ticks()
{
	//std::cout << "ticking through! " << std::endl;
	for (tick = 0; tick < 5; tick++)
	{
		std::cout << tick << std::endl;
	}
}

void Entity::display()
{
	//interate though the list and draw each Object
}
