#pragma once

#include <string>
#include <memory>

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
	std::string _pathLocation;
	
	friend class Resources;

	std::weak_ptr<Resources> _resources;
	std::weak_ptr<Core> _core;
};
