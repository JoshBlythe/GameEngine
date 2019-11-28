#pragma once
#include <vector>

#include "Resource.h"

class Shader;
//class MaterialAttribute;

class Material : public Resource
{
public:
	void setShader(std::weak_ptr<Shader> _shader);
	std::shared_ptr<Shader> getShader();

private:

	std::shared_ptr<rend::Shader> _rnShader;
	std::shared_ptr<rend::Texture> _rnTexture;
	//std::weak_ptr<Shader> m_shader;
	//std::vector <std::shared_ptr<MaterialAttribute>> m_attributes;
};


