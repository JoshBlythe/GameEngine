#pragma once

#include <string>
#include <memory>
#include <fstream>

#include "Exception.h"
#include "RendInc.h"

class Core;
class Resources;

class Resource
{
public:
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
