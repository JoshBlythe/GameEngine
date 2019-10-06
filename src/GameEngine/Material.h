#include <glm/glm.hpp>

#include <string>

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


