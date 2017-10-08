#include "Schemes.h"



Schemes::Schemes(Lexicon* Lex)
{
	mylex = Lex;
}


Schemes::~Schemes()
{
}
string Schemes::tostring()
{
	return mylist.getList();
}
