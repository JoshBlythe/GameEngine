#include <iostream>
#include <list>
#include <memory>
#include <iostream>

#include "Object.h"

class Core;

class Entity
{
public:
	Entity();
	~Entity();

	std::shared_ptr<Object> addObject();

	void display();

private:

	std::list < std::shared_ptr<Object>> m_objects;
	std::weak_ptr<Core> m_core;
};
