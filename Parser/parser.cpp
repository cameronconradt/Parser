#include "parser.h"



parser::parser(char* infilename)
{
	filename = infilename;
	furthestfail = 0;
	start();
}


parser::~parser()
{
}

void parser::start()
{
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		char temp;
		while (!myfile.eof())
		{
			myfile.get(temp);
			mylex->readin(temp);
		}
		mylex->filter();
		tokens start = datalogProgram;
		try {
			parse(start);
		}
		catch(int error){
			if (error > furthestfail)
				furthestfail = error;

		}
	}

}
void parser::match(int in)
{
	if (mylex->gettoken(pos) != in)
	{
		throw pos;
	}
	else
		pos++;

}
void parser::parse(int token)
{
	int temppos = pos;
		switch (token)
		{
		case datalogProgram:
			try {
				match(SCHEMES);
				match(COLON);
				parse(scheme);
				parse(schemeList);
				}
			catch (int error)
			{
				pos = temppos;
				if (error > furthestfail)
					furthestfail = error;
				try {
					match(FACTS);
					match(COLON);
					parse(fact);
					parse(factList);
				}
				catch (int errorfacts)
				{
					pos = temppos;
					if (errorfacts > furthestfail)
						furthestfail = errorfacts;
					try {
						match(RULES);
						match(COLON);
						parse(rule);
						parse(ruleList);
					}
					catch (int errorrules)
					{
						pos = temppos;
						if (errorrules > furthestfail)
							furthestfail = errorrules;
						match(QUERIES);
						match(COLON);
						parse(query);
						parse(queryList);
					}
				}
			}
			break;
		case scheme:
				match(ID);
				match(LEFT_PAREN);
				parse(idList);
				match(RIGHT_PAREN);
			break;
		case schemeList:
			try {
				parse(scheme);
				parse(schemeList);
			}
			catch (int error)
			{
				pos++;
			}
			break;
		case idList:
			break;
		case fact:
			match(ID);
			match(LEFT_PAREN);
			match(STRING);
			parse(stringList);
			match(RIGHT_PAREN);
			match(PERIOD);
			break;
		case factList:
			break;
		case rule:
			parse(headPredicate);
			match(COLON_DASH);
			parse(predicate);
			parse(predicateList);
			match(PERIOD);
			break;
		case ruleList:
			break;
		case headPredicate:
			match(ID);
			match(LEFT_PAREN);
			match(ID);
			parse(idList);
			match(RIGHT_PAREN);
			break;
		case predicate:
			match(ID);
			match(LEFT_PAREN);
			parse(parameter);
			parse(parameterList);
			match(RIGHT_PAREN);
			break;
		case predicateList:
			break;
		case parameter:
			try {
				match(STRING);
			}
			catch (int error)
			{
				if (error > furthestfail)
					furthestfail = error;
				try {
					match(ID);
				}
				catch (int error2)
				{
					if (error2 > furthestfail)
						furthestfail = error2;
					parse(expression);
				}
			}

			break;
		case parameterList:
			break;
		case expression:
			match(LEFT_PAREN);
			parse(parameter);
			parse(operators);
			parse(parameter);
			match(RIGHT_PAREN);
			break;
		case operators:
			try {
				match(ADD);
			}
			catch (int error)
			{
				if (error > furthestfail)
					furthestfail = error;
				match(MULTIPLY);
			}
			break;
		case query:
			parse(predicate);
			match(Q_MARK);
			break;
		case queryList:
			break;
		case stringList:
			break;
		}
}
