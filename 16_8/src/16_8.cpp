//============================================================================
// Name        : 16_8.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<string> first, second, third;

	string temp;
	cout << "Enter first name or enter f to finish:";
	while(getline(cin, temp) && temp!="f")
	{
		first.push_back(temp);
		cout << "Enter first name or enter f to finish:";
	}
	cout << "Enter second name or enter f to finish:";
	while(getline(cin, temp) && temp!="f")
	{
		second.push_back(temp);
		cout << "Enter second name or enter f to finish:";
	}
	first.sort();
	second.sort();
	third.merge(first);
	third.merge(second);
	third.sort();
	third.unique();
	cout << "Show the third list:" << endl;

	for (auto p=third.begin(); p!=third.end(); p++)
	{
		cout << *p << endl;
	}

	return 0;
}
