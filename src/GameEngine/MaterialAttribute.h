#include <string>
#include <memory>

class Texture;

class MaterialAttribute
{
public:
	std::string m_name;
	int m_type;
	float m_floatValue;

	std::weak_ptr<Texture> m_textureValue;
};