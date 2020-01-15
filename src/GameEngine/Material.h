/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Material_
#define _Material_ 

/**
* Included Libraries.
*/
#include <vector>
#include <iostream>

/**
* Forward declaration Class's used within the Class
*/
class Shader;
class Resources;

/**
* Entity Class includes.
*/
#include "Resource.h"
//class MaterialAttribute;

/**
* Initalisation of the class, it inherits from Resource
*/
class Material : public Resource
{
public:

	/**
	* This function takes in a string and loads the material and shader.
	*/
	void onLoad(const std::string& _fileName);

	
	std::shared_ptr<rend::Shader> m_rnShader; /*!< Shared pointer to rend shader. */
	std::shared_ptr<rend::Texture> m_rnTexture;  /*!< Shared pointer to rend Texture. */
	
	std::shared_ptr<Shader> m_shader; /*!< Shared pointer to shader. */
};

#endif // !_Material_