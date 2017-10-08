#pragma once
#include <string>
#include <iostream>

using namespace std;



class List
{
public:
	List();
	~List();
	void additem(string input);
	string getList();
protected:
	string full_list;
};

