/**
* Included Libraries.
*/
#include <glm/glm.hpp>

/**
* Forward declaration Class's used within the Class
*/
class Ray;
class Screen;

/**
* Componet Class included, for inheritance.
*/
#include "Component.h"

/**
* Camera Inherits from the Component Class
*/
class Camera : public Component
{
public:
	Camera();
	~Camera();

	/**
	* The Initalise function for Camera, this overwrites the inherited Class 'Component'
	* onInitalise function.
	*/
	void onInitalise();
	/**
	* This Function, initalises, sets then returns the View materix
	*/
	glm::mat4 GetView();
	/**
	* This Function, initalises, sets then returns the Projection materix
	*/
	glm::mat4 GetProj();

	Ray createRay(glm::ivec2 _mouseCoords, int _windowW, int _windowH);

	//std::shared_ptr<Camera> InitCamera();

private:
	std::weak_ptr<Camera> m_camSelf; /*!< weak pointer, pointing to it's self. */

	glm::mat4 m_projMat; /*!< Projection Materix Vaiable. */
};
