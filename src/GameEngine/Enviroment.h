#include <SDL2/SDL.h>

#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>

#include "Exception.h"

#ifdef _WIN32
	#include <Windows.h>
#endif // _WIN32

class Core;

class Enviroment
{
public:
	Enviroment();
	~Enviroment();

	void initDelts();
    std::string fileLocations();
	float getDelts() { return m_lastTime; }

private:
	//initalise variable
	float m_lastTime;
	std::string fullpath;
	std::string baseName;
	std::string dirName;

    //char* argv[];

	friend class Core;
	std::weak_ptr<Core> m_eCore;
};
