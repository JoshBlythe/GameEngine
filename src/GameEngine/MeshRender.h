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
	/**
	* This Class inherits from Component, it can be attached to a Entity to set a current model and
	* then render it.
	* Before renders the model it check to see first if a texture has been loaded in, then if a shader
	* was loaded. If either hasnt been set then a Exception is thrown.
	* Finally it sets the mesh through rend then renders it.
	*/
	MeshRender();
	virtual ~MeshRender();

	/**
	* This function is for the initalisation of the class, it overwrites the onInitalise in Component.
	*/
	void onInitalise();
	/**
	* This function takes in a Mesh and sets it to the current Mesh.
	@param _mesh takes a Mesh shared pointer and sets the Mesh passed in to m_mesh to be used in this function.
	*/
	void setMesh(std::shared_ptr<Mesh> _mesh);
	
	/**
	* This function takes in a Material and sets it to the current Material.
	@param _material takes in shared pointer, it is used to set the Material to the m_material inside this function.
	*/
	void setMaterial(std::shared_ptr<Material> _material);
	
	/**
	* This function is for the drawing of objects in this class, it overwrites the onDraw in Component.
	*/
	void onDraw();

	/**
	* This function returns the current Mesh.
	@return A context of Mesh
	*/
	std::shared_ptr<Mesh> getMesh();

private:

	std::shared_ptr<Material> m_material; /*!< Pointer to Material Class of the Game Engine. */
	std::shared_ptr<Mesh> m_mesh; /*!< Pointer to Mesh function of the Game Engine. */
};

#endif // !_MeshRender_
