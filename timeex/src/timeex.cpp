//============================================================================
// Name        : timeex.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Mytime.h"
using namespace std;

int main() {

	ofstream fout;

	fout.open("Time.txt");

	time weeding(4, 35), waxing(2, 47), total, diff, adjusted;

	cout << "weeding time = ";
	fout << "weeding time = ";
	cout << weeding;
	fout << weeding;
	cout << endl;
	fout << endl;


	cout << "waxing time =";
	fout << "waxing time =";
	cout << waxing;
	fout << waxing;
	cout << endl;
	fout << endl;


	cout << "total work time = ";
	fout << "total work time = ";
	total = weeding + waxing;
	cout << total;
	fout << total;
	cout << endl;
	fout << endl;

	diff = weeding - waxing;
	cout << "weeding time - waxing time = ";
	cout << diff;
	cout << endl;
	fout << "weeding time - waxing time = ";
	fout << diff;
	fout << endl;


	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	cout << adjusted;
	cout << endl;
	fout << "adjusted work time = ";
	fout << adjusted;
	fout << endl;
	return 0;
}
