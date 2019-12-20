#include "Component.h"
#include "Entity.h"
#include "Core.h"

Component::Component()
{
	//m_ticks = 5;
	//m_compIsAlive = true;
	//m_mesh = NULL;
	//m_material = NULL;
}

Component::~Component()
{
	//smart pointers used so no need to clean up pointers
}

void Component::onDraw()
{
	//std::cout << "This will be override! " << std::endl;
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

void Component::onInitalise()
{
	
}

void Component::onTick()
{
	//for (int i = 0; i < m_ticks; i++)
	//{
		//std::cout << "ticking through object! " << std::endl;
		OnUpdate();

	//}
}

//void Object::begin()
//{
//	std::cout << "Begin function!" << std::endl;
//}


void Component::OnUpdate()
{
	//std::cout << "This is Object Update! " << std::endl;
}




