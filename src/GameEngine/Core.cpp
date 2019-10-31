#include "Core.h"

#include "Entity.h"

std::shared_ptr<Core> Core::initalize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	//referencing c to weak_ptr of care
	//this will be used to moving up through the hierearchy
	c->m_self = c;
	//return core
	return c;
}

Core::~Core()
{
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e = std::make_shared<Entity>();
	
	e->getCore() = m_self;
	
	m_entities.push_back(e);

	return e;
}

void Core::runCore()
{
	//loop variable
	bool m_looper = true;
	//loop condition
	while (m_looper)
	{
		//loop through m_entites using iterator.
		for (std::list<std::shared_ptr<Entity>>::iterator 
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			(*iter)->Ticks();
		}
		
		//onDisplay loop
		for (std::list<std::shared_ptr<Entity>>::iterator
			iter = m_entities.begin(); iter != m_entities.end(); iter++)
		{
			//unasign pointer allowing use to access Entity functions
			(*iter)->OnDisplay();
		}

	}
}


