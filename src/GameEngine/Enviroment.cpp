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
	char strExePath[MAX_PATH];
	GetModuleFileName(NULL, strExePath, MAX_PATH);
	fullpath = strExePath;
	
	basename = dirName.substr(fullpath.find_last_of("\\"));
	basename = basename.substr(0, basename.length() - 4);

	//share / {basename} is found;

}