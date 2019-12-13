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

std::string Enviroment::fileLocations()
{
#ifdef _WIN32
	char strExePath[MAX_PATH];
	GetModuleFileName(NULL, strExePath, MAX_PATH);
	fullpath = strExePath;
	
	baseName = fullpath.substr(fullpath.find_last_of("\\"));
	baseName = baseName.substr(0, baseName.length() - 4);
	std::string dirname = fullpath.substr(0, fullpath.find_last_of("\\"));

	//share / {basename} is found;
	return dirname + "/../../resources";
#else 
	std::string _command = "cd `dirname \\ `which" + std::string(argv[0]) + "\\``; cd ..; pwd | tr -d '\n'";

	FILE popen;
	std::string _process = popen(_command.c_str(), "r");

#endif
	
}