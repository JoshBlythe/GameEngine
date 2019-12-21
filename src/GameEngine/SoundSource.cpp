#include "SoundSource.h"
#include "Sound.h"
#include "Entity.h"


SoundSource::~SoundSource()
{
	alDeleteSources(1, &m_sourceId);
	//alDeleteBuffers(1, &bufferId);
	//alcMakeContextCurrent(NULL);
	//alcDestroyContext(m_context);
	//alcCloseDevice(m_device);
}

//void SoundSource::onInitialise()
//{
//
//}

void SoundSource::onTick()
{

	//abort();
	while (true)
	{
		m_state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &m_state);
		
		if (m_state == AL_STOPPED)
		{
			//std::cout << "Sound Stopped!" << std::endl;
			//setAutoRemove(m_compIsAlive);
			//getEntity()->getComponent<SoundSource>()->m_compIsAlive = false;
            m_compIsAlive == false;
            //alDeleteSources(1, &m_sourceId);
			break;
		}

	}
	//setAutoRemove(m_compIsAlive);
}

void SoundSource::setAutoRemove(bool _autoRemove)
{
	_autoRemove = getEntity()->getComponent<SoundSource>()->m_compIsAlive;

	_autoRemove = false;
}

void SoundSource::setSound(std::shared_ptr<Sound> _sound)
{
	m_sourceId = 0;
	alGenSources(1, &m_sourceId);

	alSource3f(m_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(m_sourceId, AL_BUFFER, _sound->getBufferID());
	alSourcePlay(m_sourceId);

	//setAutoRemove(m_compIsAlive);
}
