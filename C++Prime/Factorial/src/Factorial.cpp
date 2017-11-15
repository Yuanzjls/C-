//============================================================================
// Name        : Factorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include "stdio.h"
using namespace std;
const int arsize = 101;
int main() {
	array<long double, 101> Factorial;
	Factorial[0] = Factorial[1] = 1;
	for (int i=2; i<arsize; i++)
	{
		Factorial[i] = i *	Factorial[i-1];
	}
	for (int i=0; i<arsize; i++)
	{
		printf("%d ! = %.0lf", i, Factorial[i]);
		cout << endl;
	}
	return 0;
}
