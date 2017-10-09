#include "Parameter.h"



Parameter::Parameter(Token* token)
{
	mytoken = token;
}


Parameter::~Parameter()
{
}
string Parameter::tostring()
{
	return mytoken->gettext();
}