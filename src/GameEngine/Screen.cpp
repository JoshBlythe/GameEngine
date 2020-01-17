#include "Screen.h"

Screen::Screen() 
{
	m_screenSize.x = 1400;
	m_screenSize.y = 900;
}
Screen::~Screen()
{

}

glm::vec2 Screen::getScreen()
{
	return m_screenSize;
}
