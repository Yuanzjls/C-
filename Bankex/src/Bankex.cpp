//============================================================================
// Name        : Bankex.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "brass.h"
#include "BrassPlus.h"
#include <string>
using namespace std;
const int CLIENTS = 4;
int main()
{

	Brass * p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin,temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
		<< "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
		{
			cout <<"Enter either 1 or 2: ";
		}
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
			<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
			tmax, trate);
		}
		while (cin.get() != '\n');
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; // free memory
	}
	cout << "Done.\n";
	return 0;
}
