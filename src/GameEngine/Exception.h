#include <iostream>
#include <string>

class Exception
{
public:
	Exception(const std::string &exp);
	virtual ~Exception() throw();

	void Error();

private:

	std::string exp;

};