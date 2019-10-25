#include "Exception.h"



Exception::Exception(const std::string & exp)
{
	this->m_exp = exp;
}

Exception::~Exception() throw()
{
}

void Exception::Error()
{
	throw(Exception(""));
}
