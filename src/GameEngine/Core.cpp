#include "Core.h"

Core::Core()
{
}

std::shared_ptr<Core> Core::initalize()
{
	return std::shared_ptr<Core>();
}

Core::~Core()
{
}


std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr <Entity> e = std::make_shared<Entity>();
	m_entities.push_back(e);

	return e;
}

void Core::runCore()
{
	//loop through m_entites using iterator.
	for (std::list<std::shared_ptr<Entity>>::iterator 
		iter = m_entities.begin(); iter != m_entities.end(); iter++)
	{
		//unasign pointer allowing use to access Entity functions
		(*iter)->update();
	}

}


