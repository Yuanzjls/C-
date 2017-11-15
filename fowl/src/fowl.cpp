//============================================================================
// Name        : fowl.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// fowl.cpp -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

int main()
{
	using namespace std;
	shared_ptr<string> films[5] =
	{
		shared_ptr<string> (new string("Fowl Balls")),
		shared_ptr<string> (new string("Duck Walks")),
		shared_ptr<string> (new string("Chicken Runs")),
		shared_ptr<string> (new string("Turkey Errors")),
		shared_ptr<string> (new string("Goose Eggs"))
	};
	shared_ptr<string> pwin;
	pwin = films[2]; // films[2] loses ownership
	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	cin.get();
	return 0;
}
