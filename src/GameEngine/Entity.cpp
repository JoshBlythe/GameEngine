#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::shared_ptr<Object> Entity::addObject()
{
	std::shared_ptr<Object> obj = std::make_shared<Object>();

	m_objects.push_back(obj);

	return obj;
}

void Entity::update()
{
	std::cout << "Updating Entity!!" << std::endl;
}

void Entity::display()
{
	//interate though the list and draw each Object
}
