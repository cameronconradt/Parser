#include "Id.h"



Id::Id(Token* token)
{
	mytoken = token;
}


Id::~Id()
{
}

string Id::tostring()
{
	return mytoken->gettext();
}