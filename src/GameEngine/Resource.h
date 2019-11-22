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
	Resource() {};
	~Resource() {};

	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Core> getCore();

private:
	std::string _pathLocation;

	std::weak_ptr<Core> _core;
	std::weak_ptr<Resources> _resources;
};
