//============================================================================
// Name        : 17_5.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main()
{
	list<string> first, second, third;

	string temp;
	ifstream fin1("mat.dat"), fin2("pat.dat");

	if ((!fin1.is_open()) || (!fin2.is_open()))
	{
		cout << "Sorry, cannot open file\n";
		cout << "Bye!";
		return -1;
	}

	cout << "The mat's friends name list:" << endl;
	fin1 >> temp;
	while(fin1)
	{
		first.push_back(temp);
		cout << temp << endl;
		fin1 >> temp;
	}

	cout << "The pat's friends name list:" << endl;
	fin2 >> temp;
	while(fin2)
	{
		second.push_back(temp);
		cout << temp << endl;
		fin2 >> temp;
	}
	first.sort();
	second.sort();
	third.merge(first);
	third.merge(second);
	third.sort();
	third.unique();
	cout << "Show the third list:" << endl;

	ofstream fout("matnpat.dat");
	for (auto p=third.begin(); p!=third.end(); p++)
	{
		cout << *p << endl;
		fout << *p << " ";
	}
	fout.close();
	fin1.close();
	fin2.close();

	return 0;
}
