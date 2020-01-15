#include "Shader.h"
#include "Core.h"
#include "Enviroment.h"
#include "Material.h"

void Shader::onLoad(const std::string& _fileName)
{
    //m_shaderIntern = std::make_shared<rend::Shader>();
    //get enviroment
    std::string _fileloc = getCore()->getEnviroment()->fileLocations();
	//abort();
	std::string fn = _fileloc + "/" + _fileName + ".glsl";
	
	//convert location in string above to fstream format to be then used
	std::fstream _readIn(fn.c_str());

	//if file didn't open
	if (!_readIn.is_open())
	{
		//throw below exception message 
		throw Exception("Error during opening of vertex shader file");
	}

	m_shaderIntern = getCore()->getGraphicalContext()->createShader();
	//file data
    std::string _fileData;
	//file line
    std::string _fileLine;

	//while file hasn't closed
	while (!_readIn.eof())
	{
		//get the current line
        std::getline(_readIn, _fileLine);
		//store data.
        _fileData += _fileLine + "\n";
	}

    m_shaderIntern->parse(_fileData);
}

void Shader::setShader(std::shared_ptr<Shader> _shader)
{
    m_mat.lock()->m_rnShader = _shader->m_shaderIntern;
}
