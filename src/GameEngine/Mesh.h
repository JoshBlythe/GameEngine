#include "Resource.h"
#include "RendInc.h"

#include <vector>

class ModelCollider;
struct CollisionTrig;

class Mesh : public Resource
{
public:
	Mesh();
	~Mesh();

	std::shared_ptr<rend::Mesh> _internal;

	void getFaces(std::vector<CollisionTrig>& _out);

	void onLoad(const std::string& _fileName);
};
