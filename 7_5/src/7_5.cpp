//============================================================================
// Name        : 7_5.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
long long unsigned int factorial(long long unsigned int N);
int main() {
	int n;
	cout << "Enter a number:";
	cin >> n;
	cout << "The result is " << factorial(n);
	return 0;
}
long long unsigned int factorial(long long unsigned int N)
{
	if (N==0)
		return 1;
	else
	{
		return N*factorial(N-1);
	}
}
