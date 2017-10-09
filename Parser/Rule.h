#pragma once
#include "Lexicon.h"
#include "HeadPredicate.h"
#include "Predicate.h"
#include <string>
class Rule
{
public:
	Rule(Lexicon* Lex, int inpos);
	~Rule();
	string tostring();
protected:
	Lexicon* mylex;
	int pos;
	HeadPredicate* head;
	vector<Predicate*> predicate;
	void fillpredicates();
};

