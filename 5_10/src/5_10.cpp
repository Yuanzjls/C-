//============================================================================
// Name        : 5_10.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int rows;
	cout << "Enter number of rows:"; // prints !!!Hello World!!!
	cin >> rows;
	for (int i=0, j; i<rows; i++)
	{
		for (j=0; j<rows-1-i; j++)
		{
			cout << ".";
		}
		for (; j<rows; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
