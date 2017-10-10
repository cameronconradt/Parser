#include "Predicate.h"



Predicate::Predicate(Lexicon* lex, int inpos)
{
	mylex = lex;
	pos = inpos;
	fillparameters();
}


Predicate::~Predicate()
{
}
string Predicate::tostring()
{
	string toreturn = predicateId->tostring();
	for (int i = 0; i < parameters.size(); i++)
	{
		toreturn += parameters[i]->tostring();
	}
	return toreturn;
}
void Predicate::fillparameters()
{
	predicateId = new Id(mylex->returnToken(pos));
	for (int i = pos; mylex->gettoken(i - 1) != RIGHT_PAREN; i++)
	{
		if (mylex->gettoken(i) == STRING)
		{
			String* tempstring;
			tempstring = new String(mylex->returnToken(i));
			parameters.push_back(tempstring);
		}
		else if (mylex->gettoken(i) == ID)
		{
			Id* tempid;
			tempid = new Id(mylex->returnToken(i));
			parameters.push_back(tempid);
		}
		else
		{
			Expression* tempexp;
			tempexp = new Expression(mylex, i);
			parameters.push_back(tempexp);
		}
	}

}
