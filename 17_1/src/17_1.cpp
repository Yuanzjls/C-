//============================================================================
// Name        : 17_1.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch;
	unsigned int count = 0;

	cout << "Enter a sentence with #:";
	cin.get(ch);
	while (ch != '#')
	{
		cin.get(ch);
	}
	cin.get(ch);
	while (ch != '#')
	{
		if (isalpha(ch))
		{
			count++;
		}
		cin.get(ch);
	}
	cout << "The characters you enter is " << count << endl;
	while (cin.get() != '\n');
}
