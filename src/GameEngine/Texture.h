#include "Resource.h"

class Texture : public Resource
{
public:
	std::shared_ptr<rend::Texture> _texture;
};
