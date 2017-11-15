//============================================================================
// Name        : MIwoker.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "worker.h"
#include <cstring>
#include "queuetp.h"
using namespace std;
const int SIZE = 4;
int main()
{
	QueueTP<Worker*> lolas(SIZE);
	Worker *add;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{


		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<<"t: singing waiter q: quit\n";
		cin >> choice;
		while(strchr("wstq", choice) == NULL)
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
			case 'w':
				add = new Waiter;
				break;
			case 's':
				add = new Singer;
				break;
			case 't':
				add = new SingingWaiter;
				break;
		}
		while(cin.get() != '\n');
		add->Set();
		lolas.enqueue(add);
	}

	cout << "\nHere is your staff:\n";
	int i;
	Worker *temp;
	for(i=0; i<ct; i++)
	{

		cout << endl;
		lolas.dequeue(temp);
		temp->Show();
		delete temp;
	}
	cout << "Bye.\n";

	return 0;
}
