#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <list>
#include <memory>
#include "RendInc.h"

#include "Exception.h"

//#include "Entity.h"
class Entity;
class Screen;
class Resources;
class Mesh;
class Material;
class Camera;
class Enviroment;
//class CollisionDetection;

class Core
{
public:
    static std::shared_ptr<Core> onInitalise(int argc, char** argv);

	std::shared_ptr<Entity> addEntity();

	template<typename T, typename V>
	std::shared_ptr<T> getEntity(V v)
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

		for (auto it = m_entities.begin();
			it != m_entities.end(); it++)
		{
			t_rtn = std::dynamic_pointer_cast<T>(*it);
			if (t_rtn)
			{
				return t_rtn;
			}
		}

		throw Exception("Specified Entity Type was not found");

	}

	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Camera> getCamera();
	std::shared_ptr<Screen> getScreen();
	std::shared_ptr<Enviroment> getEnviroment();
	//std::shared_ptr<CollisionDetection> getCollision();
	std::shared_ptr<rend::Context> getGraphicalContext();

    void windowInit();
    void soundInit();

    int getWindowW() {return m_windowW;}
    int getWindowH() {return m_windowH;}

	~Core();
	//main loop
	void runCore();
	//stop running main loop
	void stopCore();

private:

	//initalise SDL window;
	SDL_Window* m_window;

	//initalie OpenAL varibales
	ALCdevice* m_device;
	ALCcontext* m_context;

	//ALCdevice* _device;
	//ALCcontext* _context;

	//friend classes, allows the class to access private variaibles of core
	friend class Camera;
	friend class Mesh;
	friend class Shader;
	friend class Material;
    //friend class Screen;
	//friend class Sound;
	//friend class CollsionDetection;

	//Core();
	//pointer to self
	std::weak_ptr <Core> m_self;

	//pointer to screen
	std::shared_ptr<Screen> m_screen;
	std::shared_ptr<Resources> m_resources;
	std::shared_ptr<Enviroment> m_enviroment;
	std::shared_ptr <rend::Context> m_graphicalContext;

	//camera pointer
	std::weak_ptr<Camera> m_camera;

	// TODO: Remove?
	//std::shared_ptr<CollisionDetection> m_collision;

	int m_windowW;
	int m_windowH;

	//system loop variable
	bool m_systemLoop;

	std::list <std::shared_ptr<Entity>> m_entities;
};
