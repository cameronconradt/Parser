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
	stringstream toreturn("Facts(");
	toreturn << facts.size() << ")\n";
	for (int i = 0; i < facts.size(); i++)
	{
		toreturn << facts[i]->tostring() << "\n";
	}
	return toreturn.str();
}
void Facts::add()
{
	int foundfirst = 0;
	for (int i = 0; !foundfirst; i++)
	{
		if (mylex->gettoken(i) == FACTS)
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
		if (mylex->gettoken(i) == ID)
		{
			if (mylex->gettoken(i + 1) == LEFT_PAREN)
			{
				try {
					Fact* myscheme = new Fact(mylex, i);
					facts.push_back(myscheme);
				}
				catch (int)
				{
					done = true;
				}
			}
		}
	}
}
