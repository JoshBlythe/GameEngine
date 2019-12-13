#include "Component.h"
#include "Entity.h"
#include "Core.h"

Component::Component()
{
	m_ticks = 5;
	m_isAlive = true;
	//m_mesh = NULL;
	//m_material = NULL;
}

Component::~Component()
{
	//smart pointers used so no need to clean up pointers
}

void Component::OnDraw()
{
	std::cout << "This will be override! " << std::endl;
}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->GetCore();
}

std::shared_ptr<Resources> Component::getResources()
{
	return getCore()->getResources();
}

void Component::OnInitalise()
{
	//initalise SDL.
}

void Component::OnTick()
{
	for (int i = 0; i < m_ticks; i++)
	{
		//std::cout << "ticking through object! " << std::endl;
		OnUpdate();

	}
}

//void Object::begin()
//{
//	std::cout << "Begin function!" << std::endl;
//}


void Component::OnUpdate()
{
	std::cout << "This is Object Update! " << std::endl;
}




