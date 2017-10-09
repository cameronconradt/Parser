#pragma once
#include "Token.h"
#include <string>
class Parameter
{
public:
	Parameter(Token* token);
	~Parameter();
	string tostring();
protected:
	Token* mytoken;

};

