#include "List.h"



List::List()
{
	full_list = "";
}


List::~List()
{
}

void List::additem(string input)
{
	full_list += input;
}

string List::getList()
{
	return full_list;
}
