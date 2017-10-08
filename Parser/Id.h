#pragma once
#include "Parameter.h"
#include "Lexicon.h"
class Id :
	protected Parameter
{
public:
	Id(Token* token);
	~Id();
protected:
	Token* id;
};

