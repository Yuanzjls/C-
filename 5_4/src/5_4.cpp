//============================================================================
// Name        : 5_4.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int initialmoney = 100;

int main() {
	int years=0;
	double money_daphne, money_cleo;

	money_daphne = initialmoney;
	money_cleo = initialmoney;
	while (money_daphne>=money_cleo)
	{
		years++;
		money_daphne+=initialmoney*0.1;
		money_cleo+=money_cleo*0.05;
	}
	cout << "After " << years << " year, Cleo's investment exceed Daphne's" << endl;
	cout << "Daphne's investment is " << money_daphne << endl;
	cout << "Cleo's investment is " << money_cleo << endl;
	return 0;
}
