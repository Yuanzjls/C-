//============================================================================
// Name        : 7_10.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
double add(double , double);
double sub(double , double);
double mul(double , double);
double div(double , double);

double  (*pf[4])(double, double)={add, sub, mul, div};
const char *str[] = {"The add result is ", "The sub result is ",
"The mul result is ", "The div result is "} ;
int main() {

	double x, y;

	cout << "Please enter number1:"; // prints !!!Hello World!!!
	cin >> x;
	cout << "Please enter number2:";
	cin >> y;
	for (int i=0; i<4; i++)
	{
		cout  << str[i] << (*pf[i])(x,y)<< endl;
	}
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}
double mul(double x, double y)
{
	return x * y;
}
double div(double x, double y)
{
	return x / y;
}
