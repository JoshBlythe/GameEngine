#include "Material.h"
#include "Shader.h"

void Material::setShader(std::weak_ptr<Shader> _shader)
{
	_shader.lock()->_shaderIntern;
}


std::shared_ptr<Shader> Material::getShader()
{
	std::shared_ptr<Shader> _shader = std::make_shared<Shader>();

	//m_shader.lock();

	return _shader;
}
