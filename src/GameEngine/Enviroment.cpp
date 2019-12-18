#include "Enviroment.h"
#include "stdio.h"

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

	//initalise delta time
	//do this in envirmoent then return time
	//float _lastTime = getEnviroment()->getDelts();

	float time = SDL_GetTicks();
	float _differ = time - m_lastTime;
	m_lastTime = _differ / 1000.0f;
	m_lastTime = time;

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
    //char *argv[];


    std::string _command = "cd `dirname \\ `which" + std::string(argv[0]) + "\\``; cd ..; pwd | tr -d '\n'";

   // FILE *popen;

   FILE *_process = popen(_command.c_str(), "r");

   if(!_process)
   {
       throw Exception("Issue Loading File Source, on Linux!");
   }
#endif
	
}
