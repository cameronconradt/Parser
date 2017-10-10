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
	stringstream toreturn("Rules(");
	toreturn << rules.size() << ")\n";
	for (int i = 0; i < rules.size(); i++)
	{
		toreturn << rules[i]->tostring() << "\n";
	}
	return toreturn.str();
}

void Rules::add()
{
	int foundfirst = 0;
	for (int i = 0; !foundfirst; i++)
	{
		if (mylex->gettoken(i) == RULES)
		{
			if (mylex->gettoken(i++) == COLON)
			{
				foundfirst = i;
			}
		}
	}
	bool done = false;
	for (int i = foundfirst; !done; i++)
	{
		if (mylex->gettoken(i - 1) !=( COLON_DASH || COMMA))
		{
			if (mylex->gettoken(i) == ID)
			{
				if (mylex->gettoken(i + 1) == LEFT_PAREN)
				{
					try {
						Rule* myrule = new Rule(mylex, i);
						rules.push_back(myrule);
					}
					catch (int)
					{
						done = true;
					}
				}
			}
		}
	}
}