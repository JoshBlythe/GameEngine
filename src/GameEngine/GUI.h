#include <glm/glm.hpp>

//#include "Component.h"
#include "RendInc.h"

class Core;
class Material;
class Shader;

class GUI
{
public:
	GUI(std::shared_ptr<Core> _core);
	~GUI();

	void setTexture();

private:

	std::shared_ptr<Material> m_material;
	std::shared_ptr<Shader> m_shader;

	std::shared_ptr<rend::Mesh> m_rnMesh;
	std::shared_ptr<rend::Buffer> m_rnBuffer;
	std::shared_ptr<rend::Shader> m_rnShader;

	std::weak_ptr<Core> m_playerCore;
};