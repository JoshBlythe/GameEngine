#include <memory>
#include <iostream>

class Core;

class Entity
{
public:
	Entity();
	~Entity();


private:

	std::weak_ptr<Core> core;
};
