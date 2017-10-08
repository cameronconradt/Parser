#pragma once
#include "List.h"
#include "Lexicon.h"
class Schemes
{
public:
	Schemes(Lexicon* Lex);
	~Schemes();
protected:
	Lexicon* mylex;
};

