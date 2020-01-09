#include "Resource.h"

class Material;

class Shader : public Resource
{
public:
    std::string load(std::string& _fileName);

    std::shared_ptr<rend::Shader> m_shaderIntern;

    void setShader(std::shared_ptr<Shader> _shader);

private:

    std::weak_ptr<Material> m_mat;
};
