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
	//returns a shared pointer of Resources
    return m_resources.lock();
}

std::shared_ptr<Core> Resource::getCore()
{
	//returns a shared pointer of core.
    return m_core.lock();
}
