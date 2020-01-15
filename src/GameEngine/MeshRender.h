/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _MeshRender_
#define _MeshRender_

/**
* Included Libraries.
*/
#include <SDL2/SDL.h>
#include <GL/glew.h>

/**
* MeshRender Class includes.
*/
#include <GameEngine/GameEngine.h>

/**
* Initalisation of the class. This class Inherits from Component.
*/
class MeshRender : public Component
{
public:
	MeshRender();
	virtual ~MeshRender();

	/**
	* This function is for the initalisation of the class, it overwrites the onInitalise in Component.
	*/
	void onInitalise();
	/**
	* This function takes in a Mesh and sets it to the current Mesh.
	*/
	void setMesh(std::shared_ptr<Mesh> _mesh);
	/**
	* This function takes in a Material and sets it to the current Material.
	*/
	void setMaterial(std::shared_ptr<Material> _material);
	/**
	* This function is for the drawing of objects in this class, it overwrites the onDraw in Component.
	*/
	void onDraw();

	/**
	* This function returns the current Mesh.
	*/
	std::shared_ptr<Mesh> getMesh();

private:

	std::shared_ptr<Material> m_geMaterial; /*!< Pointer to Material Class of the Game Engine. */
	std::sr1::shared_ptr<Mesh> _mesh; /*!< Pointer to Mesh function of the Game Engine. */
};

#endif // !_MeshRender_
