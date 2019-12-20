#pragma once

#include <iostream>
#include <memory>

//#include "Mesh.h"
//#include "Material.h"
class Core;
class Entity;
class Resources;

class Component
{
public:
	Component();
	~Component();

	friend class Entity;
	//void setMesh(std::shared_ptr<Mesh> mesh) { m_mesh = mesh; }
	//void setMaterial(std::shared_ptr<Material> mat) { m_material = mat; }

	//float getPos() { return m_objectPosition.x, m_objectPosition.y, m_objectPosition.z; }

	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Resources> getResources();

	//void getEntity();  //shared_ptr of entity

	virtual void onDraw();
	virtual void onInitalise();
	//virtual void begin();
	virtual void onTick();
	//virtual void onDisplay();

	virtual void OnUpdate();
protected:
	
	std::weak_ptr<Entity> entity;
	int m_ticks;
	bool m_compIsAlive;
	//std::shared_ptr<Mesh> m_mesh;
	//std::shared_ptr<Material> m_material;

};