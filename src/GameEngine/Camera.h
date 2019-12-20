#include <glm/glm.hpp>

class Ray;
class Screen;

#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera();

	void onInitalise();

	glm::mat4 GetView();
	glm::mat4 GetProj();

	Ray createRay(glm::ivec2 _mouseCoords, int _windowW, int _windowH);

	//std::shared_ptr<Camera> InitCamera();

private:
	std::weak_ptr<Camera> m_camSelf;

	glm::mat4 m_projMat;
};
