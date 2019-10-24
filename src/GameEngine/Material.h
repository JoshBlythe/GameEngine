#pragma once
//includes
#include <string>

//include libraries
#include <glm/glm.hpp>
#include "GL/glew.h"

class Material
{
public:
	Material();
	~Material();

	int LoadTexture(std::string TextureFile);

	void apply();

private:

};


