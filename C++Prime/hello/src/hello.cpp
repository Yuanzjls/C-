//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {
	int price[5] = {1,2,3,4};
	for (int x : price)
	{
			cout << x << endl;
	}
	return 0;
}
