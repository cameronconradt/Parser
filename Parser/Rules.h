#pragma once
#include "List.h"
#include "Lexicon.h"
class Rules
{
public:
	Rules(Lexicon* Lex);
	~Rules();
	string tostring();
protected:
	Lexicon* mylex;
	List mylist;
};

