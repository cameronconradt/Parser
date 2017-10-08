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

}
void Scheme::fillcolumns()
{
	schemeId = new Id(mylex, pos);
	Id* tempid;
	for (int i = pos + 1; mylex->gettoken(i-1) != RIGHT_PAREN; i++)
	{
		tempid = new Id(mylex->returnToken());
		columnNames.push_back(tempid);
	}
}
