#include "Sound.h"

//#ifndef STB_VORBIS_INCLUDE_STB_VORBIS_H
//#define STB_VORBIS_INCLUDE_STB_VORBIS_H
#include "stb_vorbis.h"

void Sound::onLoad(const std::string &_path)
{
	m_bufferID = 0;

	ALenum _format = 0;
	ALsizei _frequ = 0;
	std::vector<char> _bufferData;

	alGenBuffers(1, &m_bufferID);

	//load_ogg not found
	load_ogg(_path, _bufferData, _format, _frequ);

	alBufferData(m_bufferID, _format, &_bufferData[0],
		static_cast<ALsizei>(_bufferData.size()), _frequ);

}

void Sound::load_ogg(const std::string& _fileName, std::vector<char>& _buffer, ALenum& _format, ALsizei& _freq)
{
	int _channel = 0;
	int _sampleRate = 0;
	short* _output = NULL;


	size_t _sample = stb_vorbis_decode_filename
	(_fileName.c_str(), &_channel, &_sampleRate, &_output);

	if (_sample == -1)
	{
		throw Exception("Error during loading OGG!");
	}
	
	// Record the sample rate required by OpenAL
	_freq = _sampleRate;

	// Record the format required by OpenAL
	if (_channel == 1)
	{
		_format = AL_FORMAT_MONO16;
	}
	else
	{
		_format = AL_FORMAT_STEREO16;
	}

	// Force format to be mono (Useful for positional audio)
	// format = AL_FORMAT_MONO16;
	// freq *= 2;

	_buffer.resize(sizeof(*_output) *_channel * _sample);
	memcpy(&_buffer.at(0), _output, _buffer.size());

	//clean up the read data
	free(_output);
}