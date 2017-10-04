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
	void match(int in);
	void parse(int token);
	const enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};
