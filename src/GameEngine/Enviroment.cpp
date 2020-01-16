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
	m_fullpath = strExePath;

	m_baseName = m_fullpath.substr(m_fullpath.find_last_of("\\"));
	m_baseName = m_baseName.substr(0, m_baseName.length() - 4);
    std::string dirname = m_fullpath.substr(0, m_fullpath.find_last_of("\\"));

    //share / {basename} is found;
#ifdef _DEBUG
    dirName =  dirname + "/../../resources";

#else
	dirName = dirname + "/resources";
#endif

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

    //std::cout<< dirName << std::endl;

   //return _command;

#endif

	m_lastTime = SDL_GetTicks();
	m_deltaTime = 0;
};

Enviroment::~Enviroment()
{

};

void Enviroment::updateDelts()
{
	//storing this variable
	

	//initalise delta time
	//do this in envirmoent then return time
	//float _lastTime = getEnviroment()->getDelts();

	float time = SDL_GetTicks();
	float _differ = time - m_lastTime;
	m_deltaTime = _differ / 1000.0f;
	m_lastTime = time;

};


std::string Enviroment::fileLocations()
{
    return dirName;
}

float Enviroment::getDelts()
{
	return m_deltaTime;
}
