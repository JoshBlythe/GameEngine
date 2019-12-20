#include "SoundSource.h"
#include "Sound.h"


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
	//while (true)
	//{
	//	m_state = 0;
	//	alGetSourcei(m_sourceId, AL_SOURCE_STATE, &m_state);
	//	
	//	if (m_state == AL_STOPPED)
	//	{
	//		//std::cout << "Sound Stopped!" << std::endl;
	//		//alDeleteSources(1, &m_sourceId);
	//		//m_compIsAlive == false;
	//		break;
	//	}

	//}

	//setAutoRemove(m_compIsAlive);
}

void SoundSource::setAutoRemove(bool _autoRemove)
{
	while (true)
	{
		m_state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &m_state);

		//std::cout << "Sound Stopped!" << std::endl;
		if (m_state == AL_STOPPED)
		{
			alDeleteSources(1, &m_sourceId);
			_autoRemove == false;
			break;
		}

	}
}

void SoundSource::setSound(std::shared_ptr<Sound> _sound)
{
	m_sourceId = 0;
	alGenSources(1, &m_sourceId);

	alSource3f(m_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(m_sourceId, AL_BUFFER, _sound->getBufferID());
	alSourcePlay(m_sourceId);
}