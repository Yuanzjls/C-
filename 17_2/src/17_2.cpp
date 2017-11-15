//============================================================================
// Name        : 17_2.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	char ch;

	if (argc == 1)
	{
		cout << "The arguement is not correct" << endl;
		cout << "Bye!";
		return -1;
	}
	ofstream fout(argv[1], std::ios_base::out);
	if (!fout.is_open())
	{
		cout << "Error, cannot open the file " << endl;
		cout << "Bye!";
		return -1;
	}
	cout << "Enter the content: " << endl;

	while(cin.get(ch))
	{
		fout.put(ch);
		cin.get(ch);
	}
	if (cin.eof())
	{
		fout.close();
		cout << endl << "Bye";
	}
	else
	{
		cout << "Something error happened" << endl;
		return -1;
	}
	return 0;
}

