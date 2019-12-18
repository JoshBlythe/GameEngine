#include "MeshRender.h"

MeshRender::MeshRender()
{
	
}

MeshRender::~MeshRender()
{
}

void MeshRender::OnInitalise()
{
	//std::string _fileloc = getCore()->getEnviroment()->fileLocations();
	m_geMaterial = getCore()->getResources()->load<Material>("../resources/rend/samples/curuthers/meshTexShader");

}

void MeshRender::SetMesh(std::shared_ptr<Mesh> _mesh)
{
	this->_mesh = _mesh->_internal;
}

void MeshRender::SetMaterial(std::shared_ptr<Material> _material)
{
	this->_text = _material->_rnTexture;
	//this->m_geMaterial = _material->_rnShader;
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


