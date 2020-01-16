#include "Enviroment.h"

//#include <stdio.h>
#include <filesystem>
#ifndef _WIN32
#include <dirent.h>
#endif

Enviroment::Enviroment(int argc, char** argv)
{
#ifdef _WIN32
    char _strExePath[MAX_PATH];
    GetModuleFileName(NULL, _strExePath, MAX_PATH);
	m_fullpath = _strExePath;

	m_baseName = m_fullpath.substr(m_fullpath.find_last_of("\\"));
	m_baseName = m_baseName.substr(0, m_baseName.length() - 4);
    std::string _dirname = m_fullpath.substr(0, m_fullpath.find_last_of("\\"));

    //share / {basename} is found;
#ifdef _DEBUG
	m_dirName = _dirname + "/../../resources";

#else
	m_dirName = _dirname + "/resources";
#endif

#else
    char _path[FILENAME_MAX] = {0};
    DIR* _dir = NULL;

    _dir = opendir("resources");

    if(_dir)
    {
        m_dirName = "resources";
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

      fgets(_path, FILENAME_MAX, _process);
          pclose(_process);

      m_dirName = _path;
      m_dirName += "/resources";
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
    return m_dirName;
}

float Enviroment::getDelts()
{
	return m_deltaTime;
}
