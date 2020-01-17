#include "Material.h"
#include "Shader.h"
#include "Core.h"
#include "Enviroment.h"
#include "Resources.h"

#include "stb_image.h"

Material::~Material()
{
}

void Material::onLoad(const std::string& _fileName)
{
    //get the file location from the Enviroment getEnviroment function
	std::string _fileloc = getCore()->getEnviroment()->fileLocations();
    //create a string which holds the full file path
	std::string fn = _fileloc + "/" + _fileName + ".png";

    //initalise variables
	int _w = 0;
	int _h = 0;
	int _bpp = 0;

	unsigned char *_data = stbi_load(fn.c_str(), &_w, &_h, &_bpp, 3);

    //check for data
	if (_data)
	{
        //create a texture
		m_rnTexture = getCore()->getGraphicalContext()->createTexture();
		//throw Exception("Unable to load texture file!");
        //set the size of the texture
		m_rnTexture->setSize(_w, _h);

		for (int y = 0; y <_h; y++)
		{
			for (int x = 0; x < _w; x++)
			{
				int _r = y * _w * 3 + x * 3;

				m_rnTexture->setPixel(x, y, glm::vec3(
					_data[_r] / 255.0f,
					_data[_r + 1] / 255.0f,
					_data[_r + 2] / 255.0f
				));
			}
		}

		stbi_image_free(_data);
	}

    //load the shader related to the texture.
    fn = _fileloc + "/" + _fileName + ".glsl";
	
	//convert location in string above to fstream format to be then used
	std::fstream _vertReadIn(fn.c_str());

	//create fstream from string
	//std::fstream _vertLoc(_vertFile);

	//if file didn't open
	if (!_vertReadIn.is_open())
	{
        //TODO: If not open, try to load default one instead.
        //this could work by passing the data string from shader.
        //throw Exception("Error during opening of vertex shader file");

        //create new shader for defualt shader
        std::shared_ptr<Shader> _defualtShader = getResources()->load<Shader>("/shader/meshTexShader");
        
		//set rend context in material to be the rend context of the defualt shader.
        //m_rnShader = _defualtShader->m_shaderIntern;
		return;
    }

    //create a shader.
    m_rnShader = getCore()->getGraphicalContext()->createShader();

    //file data
    std::string _vertfileData;
    //file line
    std::string _vertfileLine;

	//if (!_vertReadIn.is_open())
	//{
	//	throw Exception("File couldnt open");
	//}

    //while file hasn't closed
    while (!_vertReadIn.eof())
    {
        //get the current line
        std::getline(_vertReadIn, _vertfileLine);
        //store data.
        _vertfileData += _vertfileLine + "\n";
    }

	m_rnShader->parse(_vertfileData);
}

//void Material::setShader(std::shared_ptr<Shader> _shader)
//{
//    this->_rnShader = _shader->m_shaderIntern;
//}


