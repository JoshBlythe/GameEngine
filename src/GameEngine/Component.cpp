#include "Component.h"

Component::Component()
{
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
	return std::shared_ptr<Entity>();
}

//void Object::onInitalise()
//{
//	//initalise SDL.
//}

void Component::onTick()
{
	std::cout << "ticking through object! " << std::endl;
	OnUpdate();
}

//void Object::begin()
//{
//	std::cout << "Begin function!" << std::endl;
//}

//void Object::onDisplay()
//{
//	//OpenGL renderer section.
//	std::cout << "Display!" << std::endl;
//}

void Component::OnUpdate()
{
	std::cout << "This is Object Update! " << std::endl;
}



