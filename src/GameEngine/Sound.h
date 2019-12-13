#include <AL/al.h>
#include <AL/alc.h>

#include "Resource.h"

class Sound : public Resource
{
public:
	void onLoad(const std::string &_path);
	ALuint getBufferID() { return m_bufferID; }

private:
	ALuint m_bufferID;
	ALenum _format;
	ALsizei _frequ;

	void load_ogg(const std::string& _fileName, 
		std::vector<char>& _buffer, ALenum& _format, ALsizei& _freq);
};
