#include "Exception.h"



Exception::Exception(const std::string & exp)
{
	this->exp = exp;
}

Exception::~Exception() throw()
{
}

void Exception::Error()
{
	throw(Exception(""));
}
