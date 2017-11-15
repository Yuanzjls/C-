//============================================================================
// Name        : 17_3.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		cout << "Sorry you did not enter the original file's name.\n";
		cout << "Bye";
		return -1;
	}
	else if (argc == 2)
	{
		cout << "Sorry you did not enter the destination file's name.\n";
		cout << "Bye";
		return -1;
	}
	else if (argc == 3)
	{
		ifstream fin(argv[1]);
		ofstream fout(argv[2]);
		char ch;

		if (!fin.is_open())
		{
			cout << "Cannot open the file\n";
			cout << "Bye\n";
			fin.close();
			return -1;
		}
		fin.get(ch);
		while(fin)
		{
			fout.put(ch);
			fin.get(ch);
		}
		if (!fin.eof())
		{
			cout << "Some error happen.";
			cout << "Bye!";
			fout.close();
			fin.close();
			return -1;
		}
		cout << "Reach the eof, copying succeed!";
		cout << "Bye!";
		fout.close();
		fin.close();
		return 0;
	}
	else
	{
		cout << "Sorry, you write wrong argument";
		return -1;
	}
	return 0;
}
