#include "Mesh.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

	std::cout << fn << std::endl;
	std::ifstream file(fn.c_str());

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
