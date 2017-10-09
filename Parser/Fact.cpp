#include "Fact.h"



Fact::Fact(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillstrings();
}


Fact::~Fact()
{
}

string Fact::tostring()
{
	string toreturn = factId->tostring();
	for (int i = 0; i < strings.size(); i++)
	{
		toreturn += strings[i]->tostring();
	}
	return toreturn;

}
void Fact::fillstrings()
{
	factId = new Id(mylex->returnToken(pos));
	String* tempstring;
	for (int i = pos + 1; mylex->gettoken(i - 1) != PERIOD; i++)
	{
		tempstring = new String(mylex->returnToken(i));
		strings.push_back(tempstring);
	}
}