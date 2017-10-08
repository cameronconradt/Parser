#include "Scheme.h"



Scheme::Scheme(Lexicon* Lex, int inpos)
{
	mylex = Lex;
	pos = inpos;
	fillcolumns();
}


Scheme::~Scheme()
{
}

string Scheme::tostring()
{
	string toreturn = schemeId->tostring();
	for (int i = 0; i < columnNames.size(); i++)
	{
		toreturn += columnNames[i]->tostring();
	}
	return toreturn;
}
void Scheme::fillcolumns()
{
	schemeId = new Id(mylex->returnToken(pos));
	Id* tempid;
	for (int i = pos + 1; mylex->gettoken(i-1) != RIGHT_PAREN; i++)
	{
		tempid = new Id(mylex->returnToken(i));
		columnNames.push_back(tempid);
	}
}
