#include "Mesh.h"
#include "Core.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::onLoad(const std::string& _fileName)
{
	std::string fn = _fileName + ".obj";
	_internal = getCore()->m_graphicalContext->createMesh();

	std::fstream file(fn);

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

	_internal->parse(_obj);
}
