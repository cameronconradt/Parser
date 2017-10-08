#pragma once
#include "List.h"
#include "Lexicon.h"
class Facts
{
public:
	Facts(Lexicon* Lex);
	~Facts();
protected:
	Lexicon* mylex;
};

