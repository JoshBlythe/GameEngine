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


