//============================================================================
// Name        : 14_4.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include "person.h"
#include <cstring>
using namespace std;
const int SIZE = 4;
int main()
{
	Person * lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the Person category:\n"
			<< "g: gunslinger p: pokerplayer "
			<<"b: baddude: singing waiter q: quit\n";
		cin >> choice;
		while(strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
		{
			break;
		}
		switch(choice)
		{
			case 'g':
				lolas[ct] = new Gunslinger;
				break;
			case 'p':
				lolas[ct] = new PokerPlayer;
				break;
			case 'b':
				lolas[ct] = new BadDude;
				break;
		}
		while(cin.get() != '\n');
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for(i=0; i<ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i=0; i<ct; i++)
	{
		delete lolas[i];
	}
	cout << "Bye.\n";

	return 0;
}
