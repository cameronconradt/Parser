#pragma once
#include "Lexicon.h"
#include "String.h"
#include "Id.h"
class Fact
{
public:
	Fact(Lexicon* Lex, int inpos);
	~Fact();
	string tostring();
protected:
	Lexicon* mylex;
	int pos;
	vector<String*> strings;
	Id* factId;
	void fillstrings();
	const enum tokens {
		datalogProgram, scheme, schemeList, idList, fact, factList, rule, ruleList, headPredicate, predicate, predicateList,
		parameter, parameterList, expression, operators, query, queryList, stringList, COMMA, PERIOD, Q_MARK, LEFT_PAREN,
		RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING
	};
};

