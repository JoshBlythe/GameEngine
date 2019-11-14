#pragma once
//#include <iostream>
#include <string>

class Exception
{
public:
	Exception(const std::string &exp);
	virtual ~Exception() throw();

	virtual const char* Error() const throw();

	void pollForError();

private:

	std::string m_exp;

};
