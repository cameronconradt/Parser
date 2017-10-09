#pragma once
#include "Parameter.h"
class String :
	public Parameter
{
public:
	String(Token* token);
	~String();
};

