#include "Mesh.h"

std::shared_ptr<Mesh> load(std::string _filePath)
{
	std::shared_ptr<Mesh> _mesh = std::make_shared<Mesh>();

	std::fstream file(_filePath);

	if (!file.is_open())
	{
		throw Exception("Error Loading Objects File Data");
	}

	std::string _obj;
	std::string _fileLine;

	while (!file.eof())
	{
		std::getline(file, _fileLine);
		_obj += _fileLine + "\n";
	}

	return _mesh;
}
