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

	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Core> getCore();

	virtual void onLoad(const std::string& _fileName);

private:
    std::string m_pathLocation;
	
	friend class Resources;

    std::weak_ptr<Resources> m_resources;
    std::weak_ptr<Core> m_core;
};

#endif // !_Resource_
