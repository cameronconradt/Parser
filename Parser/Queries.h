#pragma once
#include "List.h"
#include "Lexicon.h"
class Queries
{
public:
	Queries(Lexicon* Lex);
	~Queries();
protected:
	Lexicon* mylex;
};

