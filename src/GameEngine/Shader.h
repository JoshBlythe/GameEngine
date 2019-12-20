#include "Resource.h"

class Shader : public Resource
{
public:
    std::shared_ptr<rend::Shader> m_shaderIntern;

	void load(std::string& _fileName);
	
};
