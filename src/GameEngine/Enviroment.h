/**
* Included Libraries.
*/
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <filesystem>

/**
* Check if Windows is OS, if it is include library.
*/
#ifdef _WIN32
	#include <Windows.h>
#endif // _WIN32

/**
* Forward declaration Class's used within the Class
*/
class Core;

/**
* Enviroment Class includes.
*/
#include "Exception.h"

/**
* Contructor of Enviroment.
*/
class Enviroment
{
public:
	/**
	* This Class is used to get the current enviroment (the local path to load resources from).
	* It also initalises Delta time to be then called by other classes/function in the engine.
	*/
    Enviroment(int argc, char** argv);
	~Enviroment();

	/**
	* Initalise Delta time.
	*/
	void updateDelts();
	
	/**
	* This function returns the file location.
	@return A string of the full local path to the resource folder.
	*/
    std::string fileLocations();
	
	/**
	* This function returns the Delta time.
	@return A float of the delta time.
	@see m_deltaTime.
	*/
	float getDelts();

private:
	friend class Core; /*!< Friend Class, allows access to the private variables of Camera. */

	//initalise variable
	float m_lastTime; /*!< Variable used to store the Last time. */
	float m_deltaTime; /*!< Variable used to store the Delta time. */
	std::string m_fullpath; /*!< Variable used to store the full path. */
	std::string m_baseName; /*!< Variable used to store the base path. */
	std::string m_dirName; /*!< Variable used to store the dir path. */

	std::weak_ptr<Core> m_eCore; /*!< Weak pointer to Core. */
};
