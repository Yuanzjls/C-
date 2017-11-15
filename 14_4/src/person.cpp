/*
 * person.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#include "person.h"
#include <iostream>
#include <ctime>

using namespace std;
Person::Person(const std::string & ln, const std::string & fn)
{
	lname = ln;
	fname = fn;
}

void Person::Show() const
{
	cout << "The person's last name is " << lname << endl;
	cout << "The person's first name is " << fname << endl;
}

void Person::Set()
{
	cout << "Enter the person's last name: ";
	cin >> lname;
	cout << "Enter the person's first name: ";
	cin >> fname;
}

Person::~Person()
{

}

Gunslinger::Gunslinger(const std::string & ln, const std::string & fn,
		double d, int n):Person(ln, fn)
{
	draw = d;
	numbernotches = n;
}

Gunslinger::Gunslinger(const Person &p, double d, int n):Person(p)
{
	draw = d;
	numbernotches = n;
}

void Gunslinger::Set()
{
	Person::Set();
	cout << "Enter the draw: ";
	cin >> draw;
	cout << "Enter the number of notches remained: ";
	cin >> numbernotches;
}

void Gunslinger::Show() const
{
	Person::Show();
	cout << "The draw is " << draw;
	cout << "The number of notches remained is " << numbernotches;
}

PokerPlayer::PokerPlayer(const std::string & ln, const std::string & fn):Person(ln, fn)
{
	std::srand((std::time(0)));
}

PokerPlayer::PokerPlayer(const Person &p) : Person(p)
{
	std::srand((std::time(0)));
}

void PokerPlayer::Show() const
{
	Person::Show();
}

void PokerPlayer::Set()
{
	Person::Set();
}

BadDude::BadDude(const std::string & ln, const std::string & fn,
		double d, int n):Person(ln, fn), Gunslinger(ln, fn, d, n), PokerPlayer(ln, fn)
{

}

BadDude::BadDude(const Person &p, double d, int n):Person(p ), Gunslinger(p, d, n), PokerPlayer(p)
{

}

void BadDude::Show() const
{
	Gunslinger::Show();
	cout << endl <<"The next card drawn is " << Cdraw() << endl;
}

void BadDude::Set()
{
	Gunslinger::Set();
}
