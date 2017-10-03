#pragma once
#include <fstream>
#include "Lexicon.h"
#include "scan.h"

class parser
{
public:
	parser(char* infilename);
	~parser();
protected:
	char* filename;
	int pos;
	int furthestfail;
	Lexicon* mylex;
	void start();
	void match(string in);
};

