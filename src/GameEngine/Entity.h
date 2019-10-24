#include <iostream>
#include <list>
#include <memory>

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
		m_component.push_back(rtn);
		return rtn;
	}

	//create object template with value
	template <typename T, typename V>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(V);
		m_component.push_back(rtn);
		return rtn;
	}

	void ticks();
	void update();
	void display();

private:

	int tick;

	std::list < std::shared_ptr<Component>> m_component;
	std::weak_ptr<Core> m_core;
};
