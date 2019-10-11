#include <iostream>
#include <memory>

#include "Transform.h"
#include "Mesh.h"
#include "Material.h"

class Object : public Transform

{
public:
	Object();
	~Object();

	void setMesh(std::shared_ptr<Mesh> mesh) { m_mesh = mesh; }
	void setMaterial(std::shared_ptr<Material> mat) { m_material = mat; }


	void Draw();

	float getPos() { return m_objectPosition.x, m_objectPosition.y, m_objectPosition.z; }

protected:
	
	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Material> m_material;

};