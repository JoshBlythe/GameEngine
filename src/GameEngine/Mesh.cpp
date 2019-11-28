#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::onLoad(const std::string& _fileName)
{
	std::fstream file(_fileName);

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

}
