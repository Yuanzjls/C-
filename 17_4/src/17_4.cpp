//============================================================================
// Name        : 17_4.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string name;
	cout << "Enter the original file1's name:" << endl; // prints !!!Hello World!!!
	cin >> name;
	ifstream fin1(name.c_str());
	if (!fin1.is_open())
	{
		cout << "Sorry, cannot open the file" << endl;
		cout << "Bye";
		return -1;
	}
	cout << "Enter the original file2's name:" << endl; // prints !!!Hello World!!!
	cin >> name;
	ifstream fin2(name.c_str());
	if (!fin2.is_open())
	{
		cout << "Sorry, cannot open the file" << endl;
		cout << "Bye";
		return -1;
	}
	cout << "Enter the destination file's name:" << endl;
	cin >> name;
	ofstream fout(name.c_str());
	if (!fout.is_open())
	{
		cout << "Sorry, cannot open the file" << endl;
		cout << "Bye";
		return -1;
	}
	while (fin1 || fin2)
	{
		char ch;
		fin1.get(ch);
		while(ch != '\n' && fin1)
		{
			fout.put(ch);
			fin1.get(ch);
		}
		fin2.get(ch);
		while(ch != '\n' && fin2)
		{
			fout.put(ch);
			fin2.get(ch);
		}
		fout.put('\n');
	}
	if (!(fin1.eof() && fin2.eof()))
	{
		cout << "Error happened!" << endl;
		cout << "Bye";
		return -1;
	}
	cout << "Finish copy, and reach the eof" << endl;
	cout << "Bye!";
	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}
