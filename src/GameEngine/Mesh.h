#include "Resource.h"

class Mesh :public Resource
{
public:


	std::shared_ptr<rend::Mesh> _internal;
	std::shared_ptr<Mesh> load(std::string _filePath);

};
