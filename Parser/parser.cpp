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
		parse(start);
	}

}
void parser::match(int in)
{
	if (mylex->gettoken(pos+1) != in)
	{
		throw pos;
	}
}
void parser::parse(int token)
{
	try
	{
		switch (token)
		{
		case datalogProgram:
			if (mylex->gettoken(pos) == SCHEMES)
			{
				
			}
			break;
		case scheme:
			break;
		case schemeList:
			break;
		case idList:
			break;
		case fact:
			break;
		case factList:
			break;
		case rule:
			break;
		case ruleList:
			break;
		case headPredicate:
			break;
		case predicate:
			break;
		case predicateList:
			break;
		case parameter:
			break;
		case parameterList:
			break;
		case expression:
			break;
		case operators:
			break;
		case query:
			break;
		case queryList:
			break;
		case stringList:
			break;
		case COMMA:
			break;
		case PERIOD:
			break;
		case Q_MARK:
			break;
		case LEFT_PAREN:
			break;
		case RIGHT_PAREN:
			break;
		case COLON:
			break;
		case COLON_DASH:
			break;
		case MULTIPLY:
			break;
		case ADD:
			break;
		case SCHEMES:
			break;
		case FACTS:
			break;
		case RULES:
			break;
		case QUERIES: break;
		case ID:
			break;
		case STRING:
			break;
		}
	}
}
