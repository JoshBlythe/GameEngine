#include <iostream>
#include <list>
#include <memory>
#include <iostream>

#include "Object.h"

class Core;

class Entity : public Object
{
public:
	Entity();
	~Entity();

	//create object template without value
	template<typename T> 
	std::shared_ptr<T> addObject()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		return rtn;
	}

	//create object template with value
	template <typename T, typename V>
	std::shared_ptr<T> addObject()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(U);
		return rtn;
	}

	void update();

	void display();

private:

	std::list < std::shared_ptr<Object>> m_objects;
	std::weak_ptr<Core> m_core;
};
