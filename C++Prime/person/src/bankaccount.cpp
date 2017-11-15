//============================================================================
// Name        : bankaccount.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "person.h"
using namespace std;

int main() {
	person one;
	person two("Smythecraft");
	person three("Dimwiddy", "Sam");
	three.show();
	cout<<endl;
	three.FormalShow();
	return 0;
}
