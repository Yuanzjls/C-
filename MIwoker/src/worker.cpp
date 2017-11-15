/*
 * worker.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: scott
 */

#include "worker.h"
#include <iostream>
using namespace std;
Worker::Worker() : fullname("no one"), id(0)
{

}

Worker::Worker(const std::string & s, long n):fullname(s), id(n)
{

}

Worker::~Worker()
{

}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n');
}

void Worker::Show() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

Waiter::Waiter() : Worker(), panache(0)
{

}

Waiter::Waiter(const std::string & s, long n, int p): Worker(s, n), panache(p)
{

}

Waiter::Waiter(const Worker & wk, int p): Worker(wk), panache(p)
{

}

void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while(cin.get()!='\n');
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << endl;
}

const char * Singer::pv[] = {"other", "alto", "contralto",
		"soprano", "bass", "baritone", "tenor"};

Singer::Singer() : Worker(), voice(other)
{

}

Singer::Singer(const std::string &s, long n, int v) : Worker(s, n), voice(v)
{

}

Singer::Singer(const Worker & wk, int v) : Worker(wk), voice(v)
{

}

void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i=0; i<Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i%4==3)
		{
			cout << endl;
		}
	}
	if (i % 4 != 0)
	{
		cout << endl;
	}
	while(cin >> voice && (voice < 0 || voice >= Vtypes))
	{
		cout << "Please enter a value >= 0 and < " << Vtypes << endl;
	}
	while(cin.get() != '\n')
	{
		cin.ignore();
		cin.clear();
	}
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}
