#include "SoundSource.h"
#include "Sound.h"


SoundSource::~SoundSource()
{
	alDeleteSources(1, &m_sourceId);
	//alDeleteBuffers(1, &bufferId);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);
	alcCloseDevice(m_device);
}

void SoundSource::onInitialise()
{
	// open up OpenAL and the device
	m_device = alcOpenDevice(NULL);
	
	if (m_device == NULL)
	{
		throw Exception("Failed to open audio device!");
	}

	//create audio OpenAL context
	m_context = alcCreateContext(m_device, NULL);

	if (m_context == NULL)
	{
		alcCloseDevice(m_device);
		throw Exception("Audio Device Context failed to initalise!");
	}

	//set current context
	if (!alcMakeContextCurrent)
	{
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
		throw Exception("Failed to set current context of Audio Device!");
	}
}

void SoundSource::onTick()
{
	while (true)
	{
		ALint _state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &_state);
		
		if (_state == AL_STOPPED)
		{
			break;
		}

	}
}

void SoundSource::setSound(std::shared_ptr<Sound> _sound)
{
	m_sourceId = 0;
	alGenBuffers(m_sourceId, &m_sourceId);

	alSource3f(m_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(m_sourceId, AL_BUFFER, _sound->getBufferID());
	alSourcePlay(m_sourceId);
}