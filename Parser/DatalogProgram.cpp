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
	return schemes->tostring() + '\n' +
		facts->tostring() + '\n' +
		rules->tostring() + '\n' +
		queries->tostring();

}
