#include "Shader.h"
#include "Core.h"
#include "Enviroment.h"
#include "Material.h"

void Shader::load(std::string& _fileName)
{
    //m_shaderIntern = std::make_shared<rend::Shader>();
    //get enviroment
    std::string _fileloc = getCore()->getEnviroment()->fileLocations();

    std::string fn = _fileName + _fileName + ".glsl";
	//_shaderIntern = getCore()->m_graphicalContext->createShader();
	
	//convert location in string above to fstream format to be then used
	std::fstream _vertReadIn(fn.c_str());

	//if file didn't open
	if (!_vertReadIn.is_open())
	{
		//throw below exception message 
		throw Exception("Error during opening of vertex shader file");
	}

	//file data
    std::string _fileData;
	//file line
    std::string _fileLine;

	//while file hasn't closed
	while (!_vertReadIn.eof())
	{
		//get the current line
        std::getline(_vertReadIn, _fileLine);
		//store data.
        _fileData += _fileLine + "\n";
	}

    //m_shaderIntern->parse(_vertfileData);
}

void Shader::setShader(std::shared_ptr<Shader> _shader)
{
    m_mat.lock()->m_rnShader = _shader->m_shaderIntern;
}
