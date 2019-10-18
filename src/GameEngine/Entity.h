#include <iostream>
#include <list>
#include <memory>

class Core;
class Object;

class Entity
{
public:
	Entity();
	~Entity();

	//create object template without value
	template<typename T> 
	std::shared_ptr<T> addObject()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		m_objects.push_back(rtn);
		return rtn;
	}

	//create object template with value
	template <typename T, typename V>
	std::shared_ptr<T> addObject()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(V);
		m_objects.push_back(rtn);
		return rtn;
	}

	void update();
	void ticks();
	void display();

private:

	std::list < std::shared_ptr<Object>> m_objects;
	std::weak_ptr<Core> m_core;
};
