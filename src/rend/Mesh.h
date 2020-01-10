#include <sr1/vector>
#include <sr1/memory>

#include <string>

#include "mathutil.h"

namespace rend
{

struct Buffer;
struct Context;
struct Shader;
struct TextureAdapter;

struct Face
{
	vec3 pa;
	vec3 pb;
	vec3 pc;

	vec2 tca;
	vec2 tcb;
	vec2 tcc;

	vec3 na;
	vec3 nb;
	vec3 nc;

	vec2 lmca;
	vec2 lmcb;
	vec2 lmcc;
};

struct BufferData
{
  std::string name;
  std::sr1::shared_ptr<Buffer> buffer;
};

struct TextureData
{
  std::string name;
  std::sr1::shared_ptr<TextureAdapter> texture;
};

struct Mesh
{
  void setBuffer(const std::string& name, const std::sr1::shared_ptr<Buffer>& buffer);
  void setTexture(const std::string& name, const std::sr1::shared_ptr<TextureAdapter>& texture);
  void parse(const std::string& data);

  

private:
  friend struct Context;
  friend struct Shader;

  std::sr1::shared_ptr<Context> context;
  std::sr1::vector<std::sr1::shared_ptr<BufferData> > buffers;
  std::sr1::vector<std::sr1::shared_ptr<TextureData> > textures;
  std::sr1::vector<Face> faces;

  void safeParse(const std::string& data, std::string& currentLine);

};

}
