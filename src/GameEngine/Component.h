#pragma once
//#include <SDL2/SDL.h>
//#include <GL/glew.h>
#include <iostream>
#include <memory>

//#include "Transform.h"
//#include "Mesh.h"
//#include "Material.h"

class Entity;

class Component 

{
public:
	Component();
	~Component();


	//void setMesh(std::shared_ptr<Mesh> mesh) { m_mesh = mesh; }
	//void setMaterial(std::shared_ptr<Material> mat) { m_material = mat; }

	//float getPos() { return m_objectPosition.x, m_objectPosition.y, m_objectPosition.z; }

	std::shared_ptr<Entity> getEntity();
	//void getEntity();  //shared_ptr of entity

	virtual void OnDraw();
	//virtual void onInitalise();
	//virtual void begin();
	virtual void onTick();
	//virtual void onDisplay();

	virtual void OnUpdate();
protected:
	
	std::weak_ptr<Entity> entity;

	//std::shared_ptr<Mesh> m_mesh;
	//std::shared_ptr<Material> m_material;

};