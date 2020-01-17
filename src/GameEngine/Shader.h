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
    * This Class inherits from Resource, it purpose is to load in the data of a Shader file (.glsl) format.
    */
    virtual ~Shader();

	/**
	* This function takes in a string and loads the material and shader.
	@param _fileName takes in a string, this will be the file name and the folder it is inside of.
	*/
    void onLoad(const std::string& _fileName);

	/**
	* This function takes in a shader and is used to set it to another shader context.
	*/
    void setShader(std::shared_ptr<Shader> _shader);

    std::shared_ptr<rend::Shader> m_shaderIntern; /*!< Shared pointer to rend shader. */
	std::weak_ptr<Material> m_mat; /*!< Weak pointer to Material. */

};
