#include <glm/glm.hpp>


class Ray
{
public:

	Ray newRay(glm::ivec2 _pos, glm::vec3 _dir);

private:
	glm::ivec2 m_rayPos;
	glm::vec3 m_rayDir;
		
};
