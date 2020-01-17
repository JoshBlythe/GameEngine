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
    /**
    * This Class inherits from Resource, it purpose is to load in the data of a OGG file.
    */
	virtual ~Sound();

	/**
	* This function takes in a string and loads the material and shader.
	@param _fileName takes in a string, this will be the file name and the folder it is inside of.
	*/
	void onLoad(const std::string &_path);
	
	/**
	* This function returns the buffere ID .
	@return A BufferID.
	@see m_bufferID.
	*/
	ALuint getBufferID();

private:
	ALuint m_bufferID; /*!< Varibale holds the buffer id. */
    ALenum m_format; /*!< Varibale holds the format. */
    ALsizei m_frequ; /*!< Varibale holds the frequency. */

	/**
	* This function Loads the sound ogg file .
	@param _fileName takes in a string, this will be the file name and the folder it is inside of.
	@param _buffer is a vector of type char which holds the buffer.
	@param _format is the format of the ogg file.
	@param _freq is the fequency of the file.
	*/
	void load_ogg(const std::string& _fileName, 
		std::vector<char>& _buffer, ALenum& _format, ALsizei& _freq);
};
