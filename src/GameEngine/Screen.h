/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Screen_
#define _Screen_

/**
* Included Libraries.
*/
#include <glm/gtc/matrix_transform.hpp>
#include <memory>


/**
* Forward declaration Class's used within the Class
*/
class Core;

class Screen
{
public:
    /**
    * This Class is used to define the screens width and Height, core then uses these variables
    * to initalise the SDL Window.
    */
	Screen();
	~Screen();

	/**
	* Function returns the screens coordinates.
	@return A vec2 that stores the screen coordinates.
	@see m_screenSize
	*/
	glm::vec2 getScreen();

private:
    friend class Core; /*!< Friend Class, allows access to the private variables of Core. */

	glm::vec2 m_screenSize; /*!< Variable which holds the Screens width and height. */
    std::weak_ptr<Core> m_core; /*!< Weak pointer to Core, used to return a smart pointer of Core. */

};

#endif // !_Screen_
