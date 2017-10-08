#include "Facts.h"



Facts::Facts(Lexicon* Lex)
{
	mylex = Lex;
}


Facts::~Facts()
{
}
string Facts::tostring()
{
	return mylist.getList();
}
