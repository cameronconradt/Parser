#include "Queries.h"



Queries::Queries(Lexicon* Lex)
{
	mylex = Lex;
}


Queries::~Queries()
{
}
string Queries::tostring()
{
	return mylist.getList();
}
