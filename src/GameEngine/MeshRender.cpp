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
	return m_mesh;
}

void MeshRender::setMesh(std::shared_ptr<Mesh> _mesh)
{
	this->m_mesh = _mesh;
}

void MeshRender::setMaterial(std::shared_ptr<Material> _material)
{
	this->m_material = _material;
	//this->m_geMaterial = _material->_rnShader;
}

void MeshRender::onDraw()
{
	//get the transform
	std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();

	//check if there is a texture
	if (m_material->m_rnTexture)
	{
		//if there is use
		m_mesh->_internal->setTexture("u_Texture", m_material->m_rnTexture);
	}
	else
	{
		// throw exception letting the user know ther was a issue
		throw Exception("Texture not Initalised!");
	}

	//check if there is a shader
	if (m_material->m_rnShader)
	{
		m_material->m_rnShader->setUniform("u_Model", _trans->getModel());
		m_material->m_rnShader->setUniform("u_View", getCore()->getCamera()->getView());
		m_material->m_rnShader->setUniform("u_Projection", getCore()->getCamera()->getProj());

	}
	else
	{
		throw Exception("Texture is incorrect! Fix the Texture.");
	}
	
	//set mesh
	m_material->m_rnShader->setMesh(m_mesh->_internal);
	//render
	m_material->m_rnShader->render();

}


