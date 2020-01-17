/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Resource_
#define _Resource_

/**
* Included Libraries.
*/
#include <string>
#include <memory>
#include <fstream>

/**
* Forward declaration Class's used within the Class
*/
class Core;
class Resources;

/**
* Class includes.
*/
#include "Exception.h"
#include "RendInc.h"

class Resource
{
public:
	/**
	* This class is similar to component, however it has different resources attached to it.
	* The onLoad virtual function is overwritten by the deriving class's attached to it.
	*/
	Resource();
	~Resource();

	/**
	* This function returns a context of Resources
	@return A pointer of Resources.
	*/
	std::shared_ptr<Resources> getResources();

	/**
	* This function returns a context of Core
	@return A pointer of Core.
	*/
	std::shared_ptr<Core> getCore();

	/**
	* This function takes in a _filename, it is virtual so class's that inherit from it will overwrite this function.
	@param _fileName takes in a string, this will be the file name and the folder it is inside of.
	*/
	virtual void onLoad(const std::string& _fileName);

private:
	friend class Resources; /*!< Friend Class, allows access to the private variables of Resources. */
	
    std::string m_pathLocation; /*!< path location name. */

    std::weak_ptr<Resources> m_resources; /*!< Weak pointer to Resources. */
    std::weak_ptr<Core> m_core; /*!< Weak pointer to Core. */
};

#endif // !_Resource_
