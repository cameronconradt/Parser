#pragma once
#include "Parameter.h"
class Id :
	public Parameter
{
public:
	Id(Token* token);
	~Id();
};