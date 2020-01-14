#include "GUI.h"
#include "Core.h"
#include "Resource.h"
#include "Resources.h"
#include "Material.h"
#include "Shader.h"

GUI::GUI(std::shared_ptr<Core> _core)
{
	m_playerCore = _core;

	m_shader = _core->getResources()->load<Shader>("/shader/GUIShader");

	m_rnMesh = _core->getGraphicalContext()->createMesh();
	m_rnBuffer = _core->getGraphicalContext()->createBuffer();

	//first tringle points
	m_rnBuffer->add(glm::vec2(0, 0));
	m_rnBuffer->add(glm::vec2(0, 1));
	m_rnBuffer->add(glm::vec2(1, 1));


	//second triangle points
	m_rnBuffer->add(glm::vec2(1, 1));
	m_rnBuffer->add(glm::vec2(1, 0));
	m_rnBuffer->add(glm::vec2(0, 0));

	m_rnMesh->setBuffer("a_Position", m_rnBuffer);
}

GUI::~GUI()
{
}

void GUI::setTexture()
{
	//m_shader->m_shaderIntern
	//m_material->m_rnShader
	m_shader->m_shaderIntern->setUniform("u_Model", glm::scale(glm::mat4(1.0f), glm::vec3(100.0f, 100.0f, 1.0f)));

	m_shader->m_shaderIntern->setUniform("u_Projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));

	m_shader->m_shaderIntern->setMesh(m_rnMesh);
	m_shader->m_shaderIntern->render();
}
