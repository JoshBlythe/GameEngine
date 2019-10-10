#include <iostream>
#include <memory>

class Core
{
public:

	std::shared_ptr<Core> Application = std::make_shared<Core>();

	~Core();
	void RunCore();

private:
	Core();
};