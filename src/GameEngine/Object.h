#include <iostream>
#include <memory>

#include "Mesh.h"
#include "Material.h"

class Object
{
public:
	Object();
	~Object();

	void GetMesh(std::shared_ptr<Mesh> mesh);
	void setMaterial(std::shared_ptr<Material> mat);

protected:

	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Material> m_material;

};