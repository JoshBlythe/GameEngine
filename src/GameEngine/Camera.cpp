#include "Camera.h"
#include "Core.h"
#include "Screen.h"
#include "Entity.h"
#include "Transform.h"
#include "Ray.h"
#include "Screen.h"

#include <glm/glm.hpp>

Camera::Camera()
{
	//std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();
}

Camera::~Camera()
{
}

void Camera::onInitalise()
{
	getCore()->m_camera = getEntity()->getComponent<Camera>();
}

glm::mat4 Camera::getView()
{
    glm::mat4 m_viewMat = glm::inverse(getEntity()->getComponent<Transform>()->getModel());

	return m_viewMat;
}

glm::mat4 Camera::getProj()
{
    //std::cout<< getCore()->getWindowW() << std::endl;
    //std::cout << "[]" << getCore()->getScreen()->getScreen().x << std::endl;
    //int _windowW = getCore()->getScreen()->getScreen().x;
    //int _windowY = getCore()->getScreen()->getScreen().y;

    //TODO:CHECK IF PASSING THE VALUE THEN USING IS COURSING THE ODD POSITIONING OF CAMERA AND MODEL
    int _windowW = getCore()->getWindowH();
    int _windowY = getCore()->getWindowH();
	
	glm::mat4 m_projMatbsc = glm::perspective(45.0f, (float)_windowW / (float)_windowY, 0.1f, 100.0f);

	return m_projMatbsc;
}

Ray Camera::createRay(glm::ivec2 _mouseCoords, int _windowW, int _windowH)
{
	Ray _ray;

	//m_viewMat = glm::mat4(1);
	//GetView();

	float _xPlane = ((float)_mouseCoords.x / (float)_windowW) * 2.0f - 1.0f;
	float _yPlane = ((float)_mouseCoords.y / (float)_windowH) * 2.0f - 1.0f;

	//store vector for both near and far planes
	glm::vec4 m_nearView = { _xPlane, _yPlane, -1, 1 };
	glm::vec4 m_farView = { _xPlane, _yPlane, 1, 1 };

	//create matrix
	m_projMat = glm::perspective(0.7f, (float)_windowW / (float)_windowH, 0.1f, 100.0f);

	//multiple by inverse matrix
	m_nearView = glm::inverse(m_projMat) * m_nearView;
	m_farView = glm::inverse(m_projMat) * m_farView;

	//divide vector by w value
	m_nearView /= m_nearView.w;
	m_farView /= m_farView.w;


	// set rays origin and direction.
	_ray.m_rayPos = m_nearView;
	_ray.m_rayDir = glm::normalize(m_farView - m_nearView);

	return _ray;
}
