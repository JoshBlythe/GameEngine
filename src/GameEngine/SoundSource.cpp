#include "SoundSource.h"
#include "Sound.h"
#include "Entity.h"


SoundSource::~SoundSource()
{
	//clean up of source ID
	alDeleteSources(1, &m_sourceId);
}

void SoundSource::onTick()
{
		m_state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &m_state);
		
		//check if the sound has stopped
		if (m_state == AL_STOPPED)
		{
			//std::cout << "Sound Stopped!" << std::endl;
			//if it has then flag the component to be deleted
            m_compIsAlive = false;
		}
}


void SoundSource::setSound(std::shared_ptr<Sound> _sound)
{
	m_sourceId = 0;
	alGenSources(1, &m_sourceId);

	alSource3f(m_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(m_sourceId, AL_BUFFER, _sound->getBufferID());
	//play the sound
	alSourcePlay(m_sourceId);

}
