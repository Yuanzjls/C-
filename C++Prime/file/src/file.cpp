//============================================================================
// Name        : file.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream outfile("1.txt");

	outfile<<"hello world"<<endl<<"nice to meet you";
	return 0;
}
