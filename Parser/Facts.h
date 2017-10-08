#pragma once
#include "List.h"
#include "Lexicon.h"
class Facts
{
public:
	Facts(Lexicon* Lex);
	~Facts();
	string tostring();
protected:
	Lexicon* mylex;
	List mylist;
};

