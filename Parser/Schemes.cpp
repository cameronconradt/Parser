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
	string toreturn = "";
	for (int i = 0; i < schemes.size(); i++)
	{
		toreturn += schemes[i]->tostring();
	}
}
void Schemes::add()
{
	int foundfirst = 0;
	for (int i = 0; !foundfirst; i++)
	{
		if (mylex->gettoken(i) == SCHEMES)
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
					Scheme* myscheme = new Scheme(mylex, i);
					schemes.push_back(myscheme);
				}
				catch (int)
				{
					done = true;
				}
			}
		}
	}

}
