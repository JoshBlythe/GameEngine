#include "Exception.h"

Exception::Exception(const std::string & exp)
{
	this->m_exp = exp;
}

Exception::~Exception() throw(){}

const char * Exception::Error() const throw()
{
	return m_exp.c_str();
}

