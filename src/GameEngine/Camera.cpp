#include "Camera.h"
#include "Core.h"
#include "Screen.h"
#include "Entity.h"
#include "Transform.h"

#include <glm/glm.hpp>

Camera::Camera()
{
	//std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();
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
	
	glm::mat4 m_projMat = glm::perspective(45.0f, (float)_windowW / (float)_windowY, 0.1f, 100.0f);

	return m_projMat;
}

std::shared_ptr<Camera> Camera::InitCamera()
{
	m_camSelf.lock() = getCore()->getCamera();

	return m_camSelf.lock();
}
