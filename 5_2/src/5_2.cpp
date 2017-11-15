//============================================================================
// Name        : 5_2.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
const int ArSize = 16;
int main() {
	array<long long, ArSize> factorials;

	factorials[0] = factorials[1] = 1;

	for(int i = 2; i < ArSize; i++)
	      factorials[i] = i * factorials[i-1];

	for(int i = 0; i < ArSize; ++i)
	     cout << i << "! = " << factorials[i] << "\n";

	    return 0;
}
