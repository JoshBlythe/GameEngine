/**
* Included Libraries.
*/
#include <AL/al.h>
#include <AL/alc.h>

/**
* Class includes.
*/
#include "Resource.h"

/**
* Initalisation of the class, it inherits from Resource
*/
class Sound : public Resource
{
public:
	virtual ~Sound();

	/**
	* This function takes in a string and loads the material and shader.
	*/
	void onLoad(const std::string &_path);
	/**
	* This function returns the buffere ID .
	*/
	ALuint getBufferID() { return m_bufferID; }

private:
	ALuint m_bufferID; /*!< Varibale holds the buffer id. */
    ALenum m_format; /*!< Varibale holds the format. */
    ALsizei m_frequ; /*!< Varibale holds the frequency. */

	/**
	* This function Loads the sound ogg file .
	*/
	void load_ogg(const std::string& _fileName, 
		std::vector<char>& _buffer, ALenum& _format, ALsizei& _freq);
};
