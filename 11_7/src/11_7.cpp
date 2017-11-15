//============================================================================
// Name        : 11_7.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Mycomplex.h"
using namespace std;

int main() {
	Mycomplex a(3, 4);
	Mycomplex c(0, 0);
	cout << "Enter a complex number (q to quit):\n";
	while(cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit):" << endl;
	}
	cout << "Done!\n";
	return 0;
}
