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
	/**
	* Initalisation of the class.
	*/
	Resources() {};
	~Resources() {};

	/**
	* Defines the key passed in.
	*/
	template<typename T>
	/**
	* Function takes in a Resource defined by T, it will add the resource to a list (adding it to the cache)
	* Calls the load function of the type passed into function.
	* When called again the function will check if the Resource has been loaded before, if it has then it will reuse it from
	* the cache, if it hasn't then it will add it to the cache and load it.
	@param _path, this is the path of the Resource to be loaded.
	*/
	std::shared_ptr<T> load(const std::string& _path)
	{
		for (size_t i = 0; i < m_resources.size(); i++)
		{
			if (m_resources.at(i)->m_pathLocation == _path)
			{
				return std::dynamic_pointer_cast<T>(m_resources.at(i));
			}
		}

		std::shared_ptr<T> t_rtn = std::make_shared<T>();
		t_rtn->m_resources = m_core.lock()->m_resources;
        t_rtn->m_core = m_core;
		t_rtn->onLoad(_path);


		return t_rtn;
		//throw Exception("Specified Type was not found");
	}

	/**
	* Defines the key passed in.
	*/
	template<typename T>
	/**
	* Create a Resource, adds it to the list.
	*/
	std::shared_ptr<T> createResource()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

        m_resources.push_back(t_rtn);

		return t_rtn;

	}

	/**
	* Returns pointer to Core, used to go up the hierachy.
	@return A pointer of Core.
	*/
	std::shared_ptr<Core> getCore();

private:
	friend class Core; /*!< Friend Class, allows access to the private variables of Core. */

    std::vector<std::shared_ptr<Resource>> m_resources; /*!< Vector to store all the loaded resources. */
	std::weak_ptr<Core> m_core; /*!< Weak pointer to Core, used to return a smart pointer of Core. */

};

#endif // !_Resources_
