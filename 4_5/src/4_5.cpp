//============================================================================
// Name        : 4_5.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct candybar
{
	string branch;
	double weight;
	int calorie;
};


int main() {

	candybar * snack = new candybar;

	*snack = {"Mocha Much", 2.3, 350};

	cout << "Branch is " << snack->branch << endl;
	cout << "The weight is " << snack->weight << endl;
	cout << "The calorie is " << snack->calorie << endl;

	return 0;
}
