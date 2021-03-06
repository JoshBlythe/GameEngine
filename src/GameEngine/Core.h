/**
* Included Libraries.
*/
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <list>
#include <memory>

/**
* Forward declaration Class's used within the Class
*/
//class Entity;
class Screen;
class Resources;
class Mesh;
class Material;
class Camera;
class Keyboard;
class Enviroment;
class GUI;
//class CollisionDetection;

/**
* Core Class includes.
*/
#include "RendInc.h"
#include "Exception.h"
#include "Entity.h"

/**
* Initalisation of the class.
*/

/**
* The Core class is the base of the Engine, classes and sub-system either are initalised or travers up the Core to again access other classes which,
* branch off from core.
* The core also holds a list of all the entities currently alive in the Engine.
*/
class Core
{
public:
	/**
	* This function, initalised the Core of the Engein. It Create a context of it's self, along with
	* other components which are reliant of Core.
	* The function takes in int and char, which are used in the Enviroment system. 
	*/
    static std::shared_ptr<Core> onInitalise(int argc, char** argv);

	/**
	* This function adds a Entity, to the list of Entities held by Core.
	*/
	std::shared_ptr<Entity> addEntity();

	/**
	* Defines the Type passed in.
	*/
	template<typename T>
	/**
	* This function returns a Entity if it has a component type passed into function, attached to it.
	@param _list a reference of a list passed into the function, its purpose to store any Entities, that have the passed in component type.
	*/
    void getEntities(std::list<std::shared_ptr<Entity>>& _list)
	{
		//std::shared_ptr<T> t_rtn = std::make_shared<T>();
        bool _isComponentFound;

        for (auto it = m_entities.begin();
            it != m_entities.end(); it++)
        {
            _isComponentFound = (*it)->hasComponent<T>();

            //_isComponentFound = m_entities.at(it)
            if (_isComponentFound)
			{
				//might need to pushback into v instead.
                _list.push_back(*it);
				//std::cout << (*it) << std::endl;
				
			}
		}
	}

	/**
	* Function to return a shared pointer to Resource.
	@return A Context of Resources.
	*/
	std::shared_ptr<Resources> getResources();
	
	/**
	* Function to return a shared pointer to Camera.
	@return A Context of Camera.
	*/
	std::shared_ptr<Camera> getCamera();
	
	/**
	* Function to return a shared pointer to Screen.
	@return A Context of Screen.
	*/
	std::shared_ptr<Screen> getScreen();
	
	/**
	* Function to return a shared pointer to Enviroment.
	@return A Context of Enviroment.
	*/
	std::shared_ptr<Enviroment> getEnviroment();
	
	/**
	* Function to return a shared pointer to Keyboard.
	@return A Context of Enviroment.
	*/
	std::shared_ptr<Keyboard> getKeyboard();

	/**
	* Function to return a shared pointer to rend Context.
	@return A Context of rend::Context.
	*/
	std::shared_ptr<rend::Context> getGraphicalContext();

	/**
	* Function to return a shared pointer to GUI.
	@return A Context of GUI.
	*/
	std::shared_ptr<GUI> getGUI();

	/**
	* Function is used to initalise the SDL Window.
	*/
    void windowInit();
	/**
	* Function is used to initalise the AL Audio.
	*/
    void soundInit();

	/**
	* Function is used to return the window width.
	@return Window Width.
	@see m_windowW.
	*/
	int getWindowW();
	
	/**
	* Function is used to return the window height.
	@return Window Height.
	@see m_windowH.
	*/
	int getWindowH();

	/**
	* Core deconstructor, used to clean up any raw pointer that didn't get wrapped by a smart pointer.
	* This is anything initalised during soundInit. SDL raw pointer are cleaned up in rend.
	*/
	~Core();

    //main loop
	/**
	* This is the Main Engine loop, handles the updating/displaying of components. Also handles
	* user input.
	*/
	void runCore();
	
	//stop running main loop
	void stopCore();

private:
	//friend classes, allows the class to access private variaibles of core
	friend class Camera; /*!< Friend Class, allows access to the private variables of Camera. */
	friend class Resources; /*!< Friend Class, allows access to the private variables of Resources. */
	//initalise SDL window;
	SDL_Window* m_window; /*!< Initalise SDL window. */

	//initalie OpenAL varibales
	ALCdevice* m_device; /*!< Initalise ALC Device. */
	ALCcontext* m_context; /*!< Initalise ALC Context. */

	//pointer to self
	std::weak_ptr <Core> m_self;  /*!< Weak pointer to it's self 'Core', this is used to create a context of itself, and when going up the hierachy. */

	//smart pointer to classes
	std::shared_ptr<Screen> m_screen; /*!< Smart pointer to screen class. */
	std::shared_ptr<Resources> m_resources; /*!< Smart pointer to Resource class. */
	std::shared_ptr<Enviroment> m_enviroment; /*!< Smart pointer to Enviroment class. */
	std::shared_ptr<Keyboard> m_keyboard; /*!< Smart pointer to keyboard class. */
	//smart pointer to rend context class
	std::shared_ptr <rend::Context> m_graphicalContext; /*!< Smart pointer to rend Context class. */

	//camera pointer
	std::weak_ptr<Camera> m_camera; /*!< weak pointer to Camera class. */
	std::shared_ptr<GUI> m_gui; /*!< Smart pointer to GUI class. */

	//store width and height of screen to use
	int m_windowW; /*!< Variable used to store Window Width. */
	int m_windowH; /*!< Variable used to store Window Height. */

	//system loop variable
	bool m_systemLoop; /*!< Variable used for system loop. */

	//list of all entities added to the engine.
	std::list <std::shared_ptr<Entity>> m_entities; /*!< Vector of all Entities, held in Core. */
};
