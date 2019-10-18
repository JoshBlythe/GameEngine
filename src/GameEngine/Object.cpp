#include "Object.h"

Object::Object()
{
	m_mesh = NULL;
	m_material = NULL;
}

Object::~Object()
{
	//smart pointers used so no need to clean up pointers
}

void Object::Draw()
{

}

std::shared_ptr<Entity> Object::getEntity()
{
	return std::shared_ptr<Entity>();
}

void Object::onInitalise()
{
	//initalise SDL.
}

void Object::onTicks()
{
	std::cout << "ticking through object! " << std::endl;
}

void Object::begin()
{
	std::cout << "Begin function!" << std::endl;
}

void Object::onDisplay()
{
	//OpenGL renderer section.
	std::cout << "Display!" << std::endl;
}

void Object::update()
{
	std::cout << "This is Object Update! " << std::endl;
}



