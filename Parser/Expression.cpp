#include "Expression.h"



Expression::Expression(Lexicon* lex, int inpos)
{
	mylex = lex;
	pos = inpos;
	fillexpr();
}


Expression::~Expression()
{
}

string Expression::tostring()
{
	stringstream toreturn;
	toreturn << parameters[0]->tostring();
	toreturn << myoperator->gettext();
	toreturn << parameters[1]->tostring();
	return toreturn.str();
}

void Expression::fillexpr()
{
	addtoparameters();
	for (int i = pos; mylex->gettoken(i - 1) != (ADD || MULTIPLY); i++)
	{
		pos = i;
	}
	myoperator = mylex->returnToken(pos);
	pos++;
	addtoparameters();
}

void Expression::addtoparameters()
{
	Parameter* temp;
	if (mylex->gettoken(pos) == STRING)
	{
		if (mylex->gettoken(pos) == STRING)
		{
			temp = new String(mylex->returnToken(pos));
		}
		else if (mylex->gettoken(pos) == ID)
		{
			temp = new Id(mylex->returnToken(pos));
		}
		else
		{
			temp = new Expression(mylex, pos);
		}
	}
}
