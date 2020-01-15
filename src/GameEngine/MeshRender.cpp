#include "MeshRender.h"

MeshRender::MeshRender()
{
	
}

MeshRender::~MeshRender()
{
}

void MeshRender::onInitalise()
{
	//std::string _fileloc = getCore()->getEnviroment()->fileLocations();
    //m_geMaterial = getCore()->getResources()->load<Material>("/shader/meshTexShader");

}

std::shared_ptr<Mesh> MeshRender::getMesh()
{
	return _mesh;
}

void MeshRender::setMesh(std::shared_ptr<Mesh> _mesh)
{
	this->_mesh = _mesh;
}

void MeshRender::setMaterial(std::shared_ptr<Material> _material)
{
	this->m_geMaterial = _material;
	//this->m_geMaterial = _material->_rnShader;
}

void MeshRender::onDraw()
{
	//might need to check this
	std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();

	//check if there is a texture
	if (m_geMaterial->m_rnTexture)
	{
		//if there is use
		_mesh->_internal->setTexture("u_Texture", m_geMaterial->m_rnTexture);
	}
	else
	{
		// throw exception letting the user know ther was a issue
		throw Exception("Texture not Initalised!");
	}

	//check if there is a shader
	if (m_geMaterial->m_rnShader)
	{
        m_geMaterial->m_rnShader->setUniform("u_Model", _trans->getModel());
		m_geMaterial->m_rnShader->setUniform("u_View", getCore()->getCamera()->GetView());
		m_geMaterial->m_rnShader->setUniform("u_Projection", getCore()->getCamera()->GetProj());

	}
	else
	{
		throw Exception("Texture is incorrect! Fix the Texture.");
	}
	
	//set mesh
	m_geMaterial->m_rnShader->setMesh(_mesh->_internal);
	//render
	m_geMaterial->m_rnShader->render();

}


