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
	for (int i = pos; mylex->gettoken(i-1) == COLON_DASH; i++)
		pos = i;
	temppredicate = new Predicate(mylex->returnToken(pos));
	predicates.push_back(temppredicate);
	for (int i = pos; mylex->gettoken(i) != PERIOD; i++)
	{
		if (mylex->gettoken(i - 1) == COMMA)
		{
			temppredicate = new Predicate(mylex->returnToken(i));
			predicates.push_back(temppredicate);
		}
	}

}