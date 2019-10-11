#include <iostream>
#include <memory>

#include "Mesh.h"
#include "Material.h"

class Object
{
public:
	Object();
	~Object();

	void setMesh(std::shared_ptr<Mesh> mesh) { m_mesh = mesh; }
	void setMaterial(std::shared_ptr<Material> mat) { m_material = mat; }


	//initalise Values
	void setObjPosition(float m_posX, float m_posY, float m_posZ) { m_objectPosition.x = m_posX, m_objectPosition.y = m_posY, m_objectPosition.z = m_posZ; }
	void setObjRotation(float m_rotX, float m_rotY, float m_rotZ) { m_objectRotation.x = m_rotX, m_objectRotation.y = m_rotY, m_objectRotation.z = m_rotZ; }
	void setObjScale(float m_scaX, float m_scaY, float m_scaZ) { m_objectScale.x = m_scaX, m_objectScale.y = m_scaY, m_objectScale.z = m_scaZ; }

	glm::vec3 getPosition() { return glm::vec3(m_objectPosition.x, m_objectPosition.y, m_objectPosition.z); }


	void Draw();

protected:

	//position
	glm::vec3 m_objectPosition;
	//rotation
	glm::vec3 m_objectRotation;
	//scale
	glm::vec3 m_objectScale;

	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Material> m_material;

};