#include "Material.h"
#include "Shader.h"
#include "Core.h"
#include "stb_image.h"


void Material::onLoad(const std::string& _fileName)
{
	/*std::string fn = _fileName + ".png";
	
	const int _stringLength = fn.size();

	char _fileLocation[30];
	
	strcpy(_fileLocation, fn.c_str());

	_rnShader = getCore()->m_graphicalContext->createShader();
	_rnTexture = getCore()->m_graphicalContext->createTexture();

	int _w = 0;
	int _h = 0;
	int _bpp = 0;

	unsigned char *_data = stbi_load(_fileLocation, &_w, &_h, &_bpp, 3);

	if (!_data)
	{
		throw Exception("Unable to load texture file!");
	}

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

	stbi_image_free(_data);*/

}

//void Material::setShader(std::weak_ptr<Shader> _shader)
//{
//	//_shader.lock()->_shaderIntern;
//}


//std::shared_ptr<Shader> Material::getShader()
//{
//	//std::shared_ptr<Shader> _shader = std::make_shared<Shader>();
//
//	////m_shader.lock();
//
//	//return _shader;
//}
