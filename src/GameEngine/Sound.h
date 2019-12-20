#include <AL/al.h>
#include <AL/alc.h>

#include "Resource.h"

class Sound : public Resource
{
public:
	~Sound();

	void onLoad(const std::string &_path);
	ALuint getBufferID() { return m_bufferID; }

private:
	ALuint m_bufferID;
    ALenum m_format;
    ALsizei m_frequ;

	void load_ogg(const std::string& _fileName, 
		std::vector<char>& _buffer, ALenum& _format, ALsizei& _freq);
};
