#include "Enviroment.h"

Enviroment::Enviroment()
{
	
};

Enviroment::~Enviroment()
{

};

void Enviroment::initDelts()
{
	//storing this variable
	m_lastTime = SDL_GetTicks();
};

void Enviroment::fileLocations()
{
#ifdef _WIN32
	char strExePath[MAX_PATH];
	GetModuleFileName(NULL, strExePath, MAX_PATH);
	fullpath = strExePath;
	
	baseName = dirName.substr(fullpath.find_last_of("\\"));
	baseName = baseName.substr(0, baseName.length() - 4);

	//share / {basename} is found;
#endif

}