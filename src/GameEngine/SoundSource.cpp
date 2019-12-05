#include "SoundSource.h"
#include "Sound.h"


void SoundSource::setSound(std::shared_ptr<Sound> _sound)
{
	m_sourceId = 0;
	alGenBuffers(m_sourceId, &m_sourceId);

	alSource3f(m_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(m_sourceId, AL_BUFFER, _sound->getBufferID());
	alSourcePlay(m_sourceId);
}