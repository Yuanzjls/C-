//============================================================================
// Name        : 14_5.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "abstremp.h"
#include <vector>
#include <cctype>

using namespace std;

int main()
{
	enum classkind{Employee =0, Manager, Fink, Highfink};
	vector<employee *> pc;
	employee * pc_temp;
	fstream finout("test.txt", ios_base::in);

	if (!finout.is_open())
	{
		cout << "Sorry, cannot open the file.";
		cout << "Bye!";
		return -1;
	}
	char ch;
	int classtype;
	cout << "The content of file is" << endl;
	finout.seekg(0);
	while((finout >> classtype).get(ch))
	{
		switch (classtype)
		{
			case Employee:
				pc_temp = new employee;
				break;
			case Manager:
				pc_temp = new manager;
				break;
			case Fink:
				pc_temp = new fink;
				break;
			case Highfink:
				pc_temp = new highfink;
				break;
		}
		pc_temp->Readall(finout);
		pc_temp->ShowAll();
		pc.push_back(pc_temp);
		cout << endl;
	}

	cout << "Enter a to add data, and enter m to modify data:";
	cin >> ch;
	ch = tolower(ch);
	if (ch == 'a')
	{
		cout << "Enter e, m, f, h to add different type of data:";
		cin >> ch;
		ch = tolower(ch);
		pc_temp = NULL;
		switch (ch)
		{
			case 'e':
				pc_temp = new employee;
				break;
			case 'm':
				pc_temp = new manager;
				break;
			case 'f':
				pc_temp = new fink;
				break;
			case 'h':
				pc_temp = new highfink;
				break;
		}
		if (pc_temp != NULL)
		{
			pc_temp->SetAll();
			pc.push_back(pc_temp);
		}
	}
	else if (ch == 'm')
	{
		cout << "Enter the number of data you want to change:" ;
		int number;
		cin >> number;
		pc[number]->SetAll();
	}
	finout.clear();
	finout.close();
	finout.open("test.txt", ios_base::out | ios_base::trunc);
	finout.seekg(0);
	for (unsigned int i=0; i<pc.size(); i++)
	{
		pc[i]->Writeall(finout);
		pc[i]->ShowAll();
		finout << endl;
		cout << endl;
		delete pc[i];
	}



	finout.close();



    return 0;
}
