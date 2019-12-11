#include "Resource.h"

class Texture : public Resource
{
public:
	std::shared_ptr<rend::Texture> _textureintern;

	std::shared_ptr<Texture> load(std::string path);
};
