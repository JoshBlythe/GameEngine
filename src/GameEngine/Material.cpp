#include "Material.h"
#include "Shader.h"
#include "Core.h"
#include "Enviroment.h"
#include "Resources.h"


#include "stb_image.h"


void Material::onLoad(const std::string& _fileName)
{
	std::string _fileloc = getCore()->getEnviroment()->fileLocations();
	std::string fn = _fileloc + "/" + _fileName + ".png";
	
	//const int _stringLength = fn.size();

	//char _fileLocation[fn.size() + 1 ];
	
	//strcpy(_fileLocation, fn.c_str());


	int _w = 0;
	int _h = 0;
	int _bpp = 0;

	unsigned char *_data = stbi_load(fn.c_str(), &_w, &_h, &_bpp, 3);

	if (_data)
	{
		_rnTexture = getCore()->getGraphicalContext()->createTexture();
		//throw Exception("Unable to load texture file!");
		_rnTexture->setSize(_w, _h);

		for (int y = 0; y <_h; y++)
		{
			for (int x = 0; x < _w; x++)
			{
				int _r = y * _w * 3 + x * 3;

				_rnTexture->setPixel(x, y, glm::vec3(
					_data[_r] / 255.0f,
					_data[_r + 1] / 255.0f,
					_data[_r + 2] / 255.0f
				));
			}
		}

		stbi_image_free(_data);
	}

	fn = _fileloc + "/" + _fileName + ".glsl";
	
	//std::string fn = _fileName + ".txt";


	//convert location in string above to fstream format to be then used
	std::fstream _vertReadIn(fn.c_str());

	//create fstream from string
	//std::fstream _vertLoc(_vertFile);

	//if file didn't open
	if (!_vertReadIn.is_open())
	{
		//TODO: If not open, try to load default one instead.
		//std::cout << fn << std::endl;
		//throw below exception message 
        //throw Exception("Error during opening of vertex shader file");
        m_shader = getCore()->getResources()->load<Shader>("/shader/meshTexShader");
        _rnShader = m_shader->m_shaderIntern;

    }

    _rnShader = getCore()->getGraphicalContext()->createShader();

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

	_rnShader->parse(_vertfileData);
}

void Material::setShader(std::shared_ptr<Shader> _shader)
{
    this->_rnShader = _shader->m_shaderIntern;
}


std::shared_ptr<Shader> Material::getShader()
{
	std::shared_ptr<Shader> _shader = std::make_shared<Shader>();

	//_shader->load(_filename);

	return _shader;
}
