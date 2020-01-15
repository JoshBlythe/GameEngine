#include "Mesh.h"
#include "Core.h"
#include "Enviroment.h"
#include "ModelCollider.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::getFaces(std::vector<CollisionTrig>& _out)
{
	//need to loop through the models faces and push there position into the vector
	for (auto it = _internal->faces.begin(); it != _internal->faces.end(); it++)
	{
		CollisionTrig _ct;

		_ct.a = it->pa;
		_ct.b = it->pb;
		_ct.c = it->pc;

		//m_modelFaces.push_back(_ct);
		_out.push_back(_ct);
	}

}

void Mesh::onLoad(const std::string& _fileName)
{
    std::string _fileloc = getCore()->getEnviroment()->fileLocations();
	std::string fn = _fileloc + "/" +  _fileName + ".obj";
	//create mesh from graphical context in core
	_internal = getCore()->getGraphicalContext()->createMesh(); //getCore()->m_graphicalContext->createMesh();
	

	//std::cout << fn << std::endl;
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
