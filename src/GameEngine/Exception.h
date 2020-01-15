/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Exception_
#define _Exception_

/**
* Included Libraries.
*/
//#include <iostream>
#include <string>

/**
* Initalisation of the class.
*/
class Exception
{
public:
	Exception(const std::string &exp);
	virtual ~Exception() throw();

	/**
	* Used to throw the execption.
	*/
	virtual const char* Error() const throw();

	/**
	* Function used to return for OpenGL Error.
	*/
	void pollForError();

private:

	std::string m_exp; /*!< Variable used to store exeption. */

};

#endif // !_Exception_
