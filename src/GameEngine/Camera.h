#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera();

	glm::mat4 GetView() { return m_viewMat; }
	glm::mat4 GetProj() { return m_projMat; }

private:

	glm::mat4 m_viewMat;
	glm::mat4 m_projMat;

};
