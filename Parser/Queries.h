#pragma once
#include "List.h"
#include "Lexicon.h"
class Queries
{
public:
	Queries(Lexicon* Lex);
	~Queries();
	string tostring();
protected:
	Lexicon* mylex;
	List mylist;
};

