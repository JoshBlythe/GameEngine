#include "Resource.h"

class Shader : public Resource
{
public:
	std::shared_ptr<rend::Shader> _shaderIntern;

	void load(std::string& _fileName);
	
};
