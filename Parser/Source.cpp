#include <iostream>
#include "parser.h"
#include "DatalogProgram.h"

using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 1)
	{
		for (int i = 1; i < 11; i++)
		{
			stringstream ss;
			ss << "test";
			ss << i;
			ss << ".txt";
			char* temp = new char();
			ss >> *temp;
			parser* myparse = new parser(temp);
			myparse->simpletostring();
		}
	}
	else
	{
		ifstream myfile(argv[1]);
		if (!myfile.is_open())
		{
			cout << "Bad file name!" << endl;
			return 0;
		}
		else
		{
			parser* myparse = new parser(argv[1]);
			cout << myparse->tostring();
		}
	}
	return 0;
}