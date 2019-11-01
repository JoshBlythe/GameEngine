#include <iostream>
#include <list>
#include <memory>

#include "Exception.h"

class Core;
class Component;

class Entity
{
public:
	Entity();
	~Entity();

	//create object template without value
	template<typename T> 
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		
		rtn->entity = m_self;
		m_component.push_back(rtn);
		return rtn;
	}

	//create object template with value
	template <typename T, typename V>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(V);
		
		rtn->entity = m_self;
		m_component.push_back(rtn);
		return rtn;
	}

	template<typename T>
	std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		for (auto it = m_component.begin(); 
			it != m_component.end(); it++)
		{
			rtn = std::dynamic_pointer_cast<T>(*it);
			if (rtn)
			{
				return rtn;
			}
		}
		
		throw Exception("Specified Type was not found");
	}

	std::shared_ptr<Core> getCore();

	void Ticks();
	void Update();
	virtual void OnDisplay();

private:

	friend class Core;

	int m_tick;

	std::list < std::shared_ptr<Component>> m_component;
	std::weak_ptr<Core> m_core;
	std::weak_ptr<Entity> m_self;
};
