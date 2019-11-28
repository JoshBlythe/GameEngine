#include <SDL2/SDL.h>

#include <iostream>
#include <string>

#ifdef _WIN32 || _WIN64
	#include <Windows.h>
#endif // _WIN32 || _WIN64



class Enviroment
{
public:
	Enviroment();
	~Enviroment();

	void initDelts();
	void fileLocations();
	float getDelts() { return m_lastTime; }

private:
	//initalise variable
	float m_lastTime;
	std::string fullpath;
	std::string baseName;
	std::string dirName;
};
