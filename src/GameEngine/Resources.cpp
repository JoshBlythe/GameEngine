#include "Resources.h"

std::shared_ptr<Core> Resources::getCore()
{
    //return a shared pointer to Core
	return m_core.lock();
}
