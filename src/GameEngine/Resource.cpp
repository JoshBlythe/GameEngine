#include "Resource.h"
#include "Resources.h"

Resource::Resource()
{
}

Resource::~Resource()
{
}

void Resource::onLoad(const std::string& _fileName)
{
	//will be overridden by drivied classes, onLoad Functions.
}

std::shared_ptr<Resources> Resource::getResources()
{
	return _resources.lock();
}

std::shared_ptr<Core> Resource::getCore()
{
	return _core.lock();
}