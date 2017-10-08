#include "Id.h"



Id::Id(Token* token)
{
	id = token;
}


Id::~Id()
{
}

string Id::tostring()
{
	return id->gettext();
}