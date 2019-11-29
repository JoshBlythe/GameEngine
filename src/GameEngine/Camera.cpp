#include "Camera.h"
#include "Core.h"
#include "Screen.h"
#include "Entity.h"
#include "Transform.h"

#include <glm/glm.hpp>

Camera::Camera()
{

}

Camera::~Camera()
{
}

glm::mat4 Camera::GetView()
{
	glm::mat4 m_viewMat = glm::inverse(getEntity()->getComponent<Transform>()->GetModel());

	return m_viewMat;
}

glm::mat4 Camera::GetProj()
{
	int _windowW = getCore()->getScreen()->GetScreen().x;
	int _windowY = getCore()->getScreen()->GetScreen().y;
	
	glm::mat4 m_projMat = glm::perspective(45.0f, (float)_windowW / (float)_windowY, 1.0f, 100.f);

	return m_projMat;
}
