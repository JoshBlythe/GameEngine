#include "Resource.h"
#include "RendInc.h"

class Mesh : public Resource
{
public:
	Mesh();
	~Mesh();

	std::shared_ptr<rend::Mesh> _internal;

	void onLoad(const std::string& _fileName);
};
