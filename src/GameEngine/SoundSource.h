/**
* Included Libraries.
*/
#include <AL/al.h>
#include <AL/alc.h>

/**
* Forward declaration Class's used within the Class
*/
class Sound;
class Entity;

/**
* MeshRender Class includes.
*/
#include "Component.h"

/**
* Initalisation of the class. This class Inherits from Component.
*/
class SoundSource : public Component
{
public:
    /**
    * This Class inherits from Component, it purpose is to play a sound loaded in from the
    * the resource Sub-System. Using the function setSound below allows you to set the sound
    * that you want to play, this class can be attached to a Entity as it inherits from Component.
    */
	virtual ~SoundSource();

	//void onInitialise();
	//void onInitialise(std::shared_ptr<Sound> _sound);
	/**
	* This function is for the updating of the function, it overwrites the onTick in Component.
	*/
	void onTick();
	//void setAutoRemove(bool _autoRemove);
	/**
	* This function sets the sound.
	*/
	void setSound(std::shared_ptr<Sound> _sound);

private:

	ALint m_state; /*!< Variable which holds the state. */
	ALuint m_sourceId; /*!< Variable which holds the source ID. */
	//bool m_autoRemove; /*!< Variable which holds the state. */

};
