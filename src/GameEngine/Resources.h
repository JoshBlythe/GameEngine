#pragma once

#include <memory>
#include <list>
#include <string>

#include "RendInc.h"

class Core;
class Resource;

class Resources
{
public:
	Resources() {};
	~Resources() {};

	template<typename T>
	std::shared_ptr<T> load(const std::string& _path)
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

        t_rtn->m_core = m_core;

		t_rtn->onLoad(_path);

		/*for (auto it = _resources.begin(); it != _resources.end(); it++)
		{
			t_rtn = std::dynamic_pointer_cast<T>(*it);
			if (t_rtn)
			{
				return t_rtn;
			}
		}*/
		return t_rtn;
//		throw Exception("Specified Type was not found");
	}

	template<typename T>
	std::shared_ptr<T> createResource()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

        m_resources.push_back(t_rtn);

		return t_rtn;

	}

	std::shared_ptr<Core> getCore();

private:
	friend class Core;

    std::list<std::shared_ptr<Resource>> m_resources;
	std::weak_ptr<Core> m_core;

};
