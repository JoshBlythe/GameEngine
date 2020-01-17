/**
* Included Libraries.
*/
#include <glm/glm.hpp>

/**
* Forward declaration Class's used within the Class
*/
class Core;
class Material;
class Shader;

/**
* Entity Class includes.
*/
//#include "Component.h"
#include "RendInc.h"

/**
* Initalisation of the class.
*/
class GUI
{
public:
	/**
	* This class is used to Initalise the GUI variables, this is done it its constructor, it also goes through core to get a shader resource and load it.
	* Then will draw the GUI in the setTexture function.
	@param _core takes a shared pointer of core, this is used to initalise GUI in Core and get a context of Core.
	*/
	GUI(std::shared_ptr<Core> _core);
	~GUI();

	/**
	* This function draws the GUI, by multiple the pixel by a specified amount to get a red square.
	*/
	void setTexture();

private:

	std::shared_ptr<Material> m_material; /*!< Shared pointer to Material, used to return a smart pointer of Material. */
	std::shared_ptr<Shader> m_shader; /*!< Shared pointer to Shader, used to return a smart pointer of Shader. */

	std::shared_ptr<rend::Mesh> m_rnMesh; /*!< Shared pointer to rend Mesh, used to return a smart pointer of rend Mesh. */
	std::shared_ptr<rend::Buffer> m_rnBuffer; /*!< Shared pointer to rend Buffer, used to return a smart pointer of rend Buffer. */
	std::shared_ptr<rend::Shader> m_rnShader; /*!< Shared pointer to rend Shader, used to return a smart pointer of rend Shader. */
	 
	std::weak_ptr<Core> m_playerCore; /*!< Weak pointer to Core, used to return a smart pointer of Core. */
};