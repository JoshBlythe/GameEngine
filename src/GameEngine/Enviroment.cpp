#include "Enviroment.h"

//#include <stdio.h>
#include <filesystem>
#ifndef _WIN32
#include <dirent.h>
#endif

Enviroment::Enviroment(int argc, char** argv)
{
#ifdef _WIN32
    char strExePath[MAX_PATH];
    GetModuleFileName(NULL, strExePath, MAX_PATH);
    fullpath = strExePath;

    baseName = fullpath.substr(fullpath.find_last_of("\\"));
    baseName = baseName.substr(0, baseName.length() - 4);
    std::string dirname = fullpath.substr(0, fullpath.find_last_of("\\"));

    //share / {basename} is found;
    dirName =  dirname + "/../../resources";
#else
    char path[FILENAME_MAX] = {0};
    DIR* dir = NULL;

    dir = opendir("resources");

    if(dir)
    {
        dirName = "resources";
    }
    else
    {
     std::string _command = "cd \"$(dirname \"$(which " + std::string(argv[0]) + ")\")\"; cd ..; pwd | tr -d '\n'";

     std::cout << _command << std::endl;
     std::FILE *_process = popen(_command.c_str(), "r");

     if(!_process)
     {
        throw Exception("Issue Loading File Source, on Linux!");
     }

      fgets(path, FILENAME_MAX, _process);
          pclose(_process);

      dirName = path;
      dirName += "/resources";
    }

    std::cout<< dirName << std::endl;

   //return _command;

#endif
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
    return dirName;
}
