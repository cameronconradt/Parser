#pragma once
#include <fstream>
#include "Lexicon.h"
#include "DatalogProgram.h"

class parser
{
public:
	parser(char* infilename);
	~parser();
	string simpletostring();
	string tostring();
protected:
	DatalogProgram* mydata;
	char* filename;
	int pos;
	int furthestfail;
	Lexicon* mylex;
	void start();
	void match(int in);
	void parse(int token);
	enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

