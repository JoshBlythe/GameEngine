/**
* Forward declaration Class's used within the Class
*/
class Material;

/**
* Class includes.
*/
#include "Resource.h"

/**
* Initalisation of the class, it inherits from Resource.
*/
class Shader : public Resource
{
public:

	/**
	* This function takes in a string and loads the material and shader.
	*/
    void load(std::string& _fileName);

    std::shared_ptr<rend::Shader> m_shaderIntern; /*!< Shared pointer to rend shader. */

	/**
	* This function takes in a shader and is used to set it to another shader context.
	*/
    void setShader(std::shared_ptr<Shader> _shader);

	std::weak_ptr<Material> m_mat; /*!< Weak pointer to Material. */

};
