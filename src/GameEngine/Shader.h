#include "Resource.h"

class Shader : public Resource
{
public:
	std::shared_ptr<rend::Shader> _shaderIntern;

	std::shared_ptr<Shader> load(std::string _path);
	
};
