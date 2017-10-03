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
	}

}
void parser::match(string in)
{
	if (mylex->gettoken(pos + 1) != in)
	{
		throw pos;
	}
}
