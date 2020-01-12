/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Resources_
#define _Resources_

/**
* Included Libraries.
*/
#include <memory>
#include <list>
#include <string>

/**
* Forward declaration Class's used within the Class
*/
class Core;
class Resource;

/**
* Class includes, includes rend library contexts.
*/
#include "RendInc.h"

/**
* Initalisation of the class.
*/
class Resources
{
public:
	Resources() {};
	~Resources() {};

	/**
	* Calls the load function of the type passed into function.
	*/

	//TODO: Do cache system.
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

	/**
	* Create a Resource, adds it to the list.
	*/
	template<typename T>
	std::shared_ptr<T> createResource()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

        m_resources.push_back(t_rtn);

		return t_rtn;

	}

	/**
	* Returns pointe to Core, used to go up the hierachy.
	*/
	std::shared_ptr<Core> getCore();

private:
	friend class Core; /*!< Friend Class, allows access to the private variables of Core. */

    std::list<std::shared_ptr<Resource>> m_resources; /*!< Vector to store all the loaded resources. */
	std::weak_ptr<Core> m_core; /*!< Weak pointer to Core, used to return a smart pointer of Core. */

};

#endif // !_Resources_
