//============================================================================
// Name        : sum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int start, end;

	cout << "Please enter start: ";
	cin >> start;
	cout << "Please enter end: ";
	cin >> end;
	if (start >= end)
	{
		for (; start >= end ; end++)
		{
			sum+=end;
		}
		cout << "the result is " << sum;
	}
	else
	{
		for (; start <= end ; start++)
		{
			sum+=start;
		}
		cout << "the result is " << sum;
	}
	return 0;
}
