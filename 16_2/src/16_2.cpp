//============================================================================
// Name        : 16_1.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

string & string_modify(string &s);
bool ispalindrome(const string &s);
int main()
{
	string input;
	cout << "Enter a sentence or quit to quit:" << endl;
	while(getline(cin, input) && input != "q" && input != "Q")
	{
		string_modify(input);
		if (ispalindrome(input))
		{
			cout << "The string you input is palindrome." << endl;
		}
		else
		{
			cout << "The string you input is not a palindrome." << endl;
		}
		cout << "Enter a sentence or quit to quit:" << endl;
	}
	cout << "Bye!";
	return 0;
}

string & string_modify(string &s)
{
	for (auto p=s.begin(); p!=s.end(); p++)
	{
		if (isalpha(*p) == false)
		{
			s.erase(p);
		}
		else
		{
			*p = tolower(*p);
		}
	}
	return s;

}

bool ispalindrome(const string &s)
{
	string st(s.rbegin(), s.rend());
	return (st == s);
}
