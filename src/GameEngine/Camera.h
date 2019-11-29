#include <glm/glm.hpp>

#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera();

	glm::mat4 GetView();
	glm::mat4 GetProj();
};
