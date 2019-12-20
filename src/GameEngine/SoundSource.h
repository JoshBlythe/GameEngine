#include <AL/al.h>
#include <AL/alc.h>

class Sound;
class Entity;

#include "Component.h"

class SoundSource : public Component
{
public:

	~SoundSource();

	//void onInitialise();
	void onInitialise(std::shared_ptr<Sound> _sound);
	void onTick();
	void setAutoRemove(bool _autoRemove);
	void setSound(std::shared_ptr<Sound> _sound);

private:

	ALint m_state;
	ALuint m_sourceId;
	bool m_autoRemove;

};
