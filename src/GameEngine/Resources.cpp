#include "Resources.h"

std::shared_ptr<Core> Resources::getCore()
{
	return m_core.lock();
}