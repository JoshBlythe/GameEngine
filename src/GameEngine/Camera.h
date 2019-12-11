#include <glm/glm.hpp>

#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera();

	glm::mat4 GetView();
	glm::mat4 GetProj();

	std::shared_ptr<Camera> InitCamera();

private:
	std::weak_ptr<Camera> m_camSelf;
};
