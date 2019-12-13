#pragma once
#include <vector>
#include <iostream>

#include "Resource.h"


class Shader;
//class MaterialAttribute;

class Material : public Resource
{
public:
	void onLoad(const std::string& _fileName);

	void setShader(std::shared_ptr<Shader> _shader);
	std::shared_ptr<Shader> getShader();

	std::shared_ptr<rend::Shader> _rnShader;
	std::shared_ptr<rend::Texture> _rnTexture;
	//std::weak_ptr<Shader> m_shader;
	//std::vector <std::shared_ptr<MaterialAttribute>> m_attributes;
};


