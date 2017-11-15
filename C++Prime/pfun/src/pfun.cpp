//============================================================================
// Name        : pfun.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <thread>
#include "func.h"
using namespace std;

void (*f)(string, int);
int main() {
	string str;
	int select;
	cout << "Please enter the words:"; // prints !!!Hello World!!!
	getline(cin, str);
	cout << "please select the fun:";
	if (!(cin >> select))
	{
		select = 0;
		cout << "enter wrong" << endl;
	}
	else if (select > 3 || select < 1)
	{
		select = 0;
		cout << "enter wrong" << endl;
	}
	switch (select)
	{
	case 1:
	{
		f = fun1;
		break;
	}
	case 2:
	{
		f = fun2;
		break;
	}
	case 3:
	{
		f = fun3;
		break;
	}
	default:
	{
		f = fun1;
	}
	}
	f(str, 1);
	return 0;
}

