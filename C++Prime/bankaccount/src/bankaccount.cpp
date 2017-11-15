//============================================================================
// Name        : bankaccount.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "account.h"
using namespace std;

int main() {
	string id;
	string name;
	long unsigned int num;
	cout << "Please Enter your account's name:";
	getline(cin, name);
	cout << "Please Enter you account's ID:";
	getline(cin, id);
	cout << "Please Enter you account's num:";
	cin >> num;
	account a(name, id, num);
	while(1)
	{
		cout << "choose: 1.save 2.out:";
		cin >> num;
		if (num == 1)
		{
			cout << "save into your account:";
			cin >> num;
			a.save(num);
		}
		else if (num == 2)
		{
			cout << "get from you account:";
			cin >> num;
			a.out(num);
		}
		cin.clear();
		a.show();
	}
	return 0;
}
