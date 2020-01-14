#include "Component.h"
#include "Entity.h"
#include "Core.h"

Component::Component()
{
	//m_ticks = 5;
	m_compIsAlive = true;
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
    //return a smart point to entity
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
    //get a pointer to entity from there use it get core function to get
    //a smart pointer to core
    return getEntity()->getCore();
}

std::shared_ptr<Resources> Component::getResources()
{
    //use the get core class to quick access resources
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
        //onUpdate();

	//}
}

void Component::onGUI()
{

}


