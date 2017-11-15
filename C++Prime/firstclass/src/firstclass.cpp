//============================================================================
// Name        : firstclass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "showyou.h"
#include "windows.h"
using namespace std;

int main() {
	showyou w(NULL, "");
	char name[20];
	int temp;
	char *name_get;

	cout << "Please enter your name:";
	cin.getline(name, 20);
	w.setname(name);
	cout << "Please enter your num:";
	cin >> temp;
	w.setnum(temp);
	name_get = w.showname();
	cout << name_get;
	cout << endl;
	w.getnum();
	system("ping 127.0.0.1");
	return 0;
}
