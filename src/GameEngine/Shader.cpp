#include "Shader.h"

std::shared_ptr<Shader> Shader::load(std::string path)
{
	std::shared_ptr<Shader> _shader = std::make_shared<Shader>();

	//convert location in string above to fstream format to be then used
	std::fstream _vertReadIn(path);

	//create fstream from string
	//std::fstream _vertLoc(_vertFile);

	//if file didn't open
	if (!_vertReadIn.is_open())
	{
		//throw below exception message 
		throw Exception("Error during opening of vertex shader file");
	}

	//file data
	std::string _vertfileData;
	//file line
	std::string _vertfileLine;

	//while file hasn't closed
	while (!_vertReadIn.eof())
	{
		//get the current line
		std::getline(_vertReadIn, _vertfileLine);
		//store data.
		_vertfileData += _vertfileLine + "\n";
	}

	return _shader;
}