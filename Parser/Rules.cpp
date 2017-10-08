#include "Rules.h"



Rules::Rules(Lexicon* Lex)
{
	mylex = Lex;
}


Rules::~Rules()
{
}
string Rules::tostring()
{
	return mylist.getList();
}
