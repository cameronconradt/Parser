#include "Rule.h"



Rule::Rule(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillpredicates();
}


Rule::~Rule()
{
}

string Rule::tostring()
{

}

void Rule::fillpredicates()
{

}