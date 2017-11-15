//============================================================================
// Name        : cinsum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	long long sum = 0, a;

	while(1)
	{
		cout << "Please enter a value:";
		cin >> a;
		if (a == 0)
		{
			cout << "\a";
			break;

		}
		sum += a;

		cout << sum << endl;
	}
	return 0;
}
