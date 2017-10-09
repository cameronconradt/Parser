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
	string toreturn = head->tostring();
	for (int i = 0; i < predicates.size(); i++)
	{
		toreturn += predicates[i]->tostring();
	}
	return toreturn;
}

void Rule::fillpredicates()
{
	head = new HeadPredicate(mylex->returnToken(pos));
	Predicate* temppredicate;
	for (int i = pos; mylex->gettoken(i) == RIGHT_PAREN; i++)
		pos = i;
	for (int i = pos + 1; mylex->gettoken(i - 1) != PERIOD; i++)
	{
		temppredicate = new Predicate(mylex->returnToken(i));
		predicates.push_back(temppredicate);
	}
}