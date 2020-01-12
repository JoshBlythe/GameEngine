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

class Enviroment
{
public:
	/**
	* Contructor of Enviroment.
	*/
    Enviroment(int argc, char** argv);
	~Enviroment();

	/**
	* Initalise Delta time.
	*/
	void initDelts();
	/**
	* This function returns the file location.
	*/
    std::string fileLocations();
	/**
	* This function returns the Delta time.
	*/
	float getDelts() { return m_lastTime; }

private:
	friend class Core; /*!< Friend Class, allows access to the private variables of Camera. */

	//initalise variable
	float m_lastTime; /*!< Variable used to store the Delta time. */
	std::string fullpath; /*!< Variable used to store the full path. */
	std::string baseName; /*!< Variable used to store the base path. */
	std::string dirName; /*!< Variable used to store the dir path. */

	std::weak_ptr<Core> m_eCore; /*!< Weak pointer to Core. */
};
