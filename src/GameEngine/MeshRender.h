#pragma once
#include <GameEngine/GameEngine.h>

#include <SDL2/SDL.h>
#include <GL/glew.h>

class MeshRender : public Component
{
public:
	MeshRender();
	virtual ~MeshRender();

	void onInitalise();
	void SetMesh(std::shared_ptr<Mesh> _mesh);
	void SetMaterial(std::shared_ptr<Material> _material);
	void onDraw();

	std::shared_ptr<Mesh> getMesh();

private:

	//std::shared_ptr<Mesh> m_geMesh;
	std::shared_ptr<Shader> m_geShader;
	std::shared_ptr<Material> m_geMaterial;

	//std::sr1::shared_ptr<GameEngine::Context> _context;
	//TODO REMOVE GAMEENGINE 
	std::sr1::shared_ptr<GameEngine::Shader> _shader;
	std::sr1::shared_ptr<GameEngine::Buffer> _buffer;
	std::sr1::shared_ptr<GameEngine::Texture> _text;
	std::sr1::shared_ptr<Mesh> _mesh;

};
