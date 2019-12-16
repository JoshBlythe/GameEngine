#include "MeshRender.h"

MeshRender::MeshRender()
{
	
}

MeshRender::~MeshRender()
{
}

void MeshRender::OnInitalise()
{
	m_geMaterial = getCore()->getResources()->load<Material>("../resources/rend/samples/curuthers/meshTexShader");

	glm::vec3 a1 = glm::vec3(0, 0.4f, 0);
	glm::vec3 b1 = glm::vec3(-0.5f, -0.5f, 0);
	glm::vec3 c1 = glm::vec3(0.5f, -0.5f, 0);

	/*glm::vec3 a2 = glm::vec3(0, 1.5f, 0);
	glm::vec3 b2 = glm::vec3(-0.5f, 0.5f, 0);
	glm::vec3 c2 = glm::vec3(0.5f, 0.5f, 0);*/
	
	////create buffer for collision
	//_buffer = getCore()->getGraphicalContext()->createBuffer();
	////push the trinagles into it to be used later
	//_buffer->add(glm::vec2(a1.x, a1.y));
	//_buffer->add(glm::vec2(b1.x, b1.y));
	//_buffer->add(glm::vec2(c1.x, c1.y));
}

void MeshRender::SetMesh(std::shared_ptr<Mesh> _mesh)
{
	this->_mesh = _mesh->_internal;
}

void MeshRender::SetMaterial(std::shared_ptr<Material> _material)
{
	this->_text = _material->_rnTexture;
}

void MeshRender::OnDraw()
{
	//might need to check this
	std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();

	//check if there is a texture
	if (_text)
	{
		//if there is use
		_mesh->setTexture("u_Texture", _text);
	}
	else
	{
		// throw exception letting the user know ther was a issue
		throw Exception("Texture not Initalised!");
	}

	//check if there is a shader
	if (m_geMaterial->_rnShader)
	{
		m_geMaterial->_rnShader->setUniform("u_Model", _trans->GetModel());
		m_geMaterial->_rnShader->setUniform("u_Projection", getCore()->getCamera()->GetProj());

	}
	else
	{
		throw Exception("Texture is incorrect! Fix the Texture.");
	}
	
	//set mesh
	m_geMaterial->_rnShader->setMesh(_mesh);
	//render
	m_geMaterial->_rnShader->render();

}


