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
		//create context of face
		CollisionTrig _ct;

		//store faces of model in CollisionTrig
		_ct.a = it->pa;
		_ct.b = it->pb;
		_ct.c = it->pc;

		//pushing back the faces into vector, passed in.
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

	//if file couldn't open then throw a exception
	if (!file.is_open())
	{
		throw Exception("Error Loading Objects File Data");
	}

	//if did, initalise variables
	std::string _obj;
	std::string _fileLine;

	//file file is open
	while (!file.eof())
	{
		//read the data inside it
		std::getline(file, _fileLine);
		_obj += _fileLine + "\n";
	}

	//pass the data to rend.
	_internal->parse(_obj);
}
