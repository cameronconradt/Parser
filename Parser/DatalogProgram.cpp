#include "DatalogProgram.h"



DatalogProgram::DatalogProgram(Lexicon* Lex)
{
	schemes = new Schemes(Lex);
	queries = new Queries(Lex);
	rules = new Rules(Lex);
	facts = new Facts(Lex);
}


DatalogProgram::~DatalogProgram()
{
}
string DatalogProgram::tostring()
{
	return schemes->tostring()  +
		facts->tostring()  +
		rules->tostring()  +
		queries->tostring();

}
