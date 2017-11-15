/*
 * classic.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: scott
 */

#include "classic.h"
#include <iostream>
#include <cstring>

using namespace std;
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	performers = new char [strlen(s1) + 1];
	label = new char [strlen(s2) + 1];

	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];

	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
	cout << "Cd Destroyed" << endl;

}

void Cd::Report() const
{
	cout << "This is the information of the CD: " << endl;
	cout << "The performers is " << performers << endl;
	cout << "The label of the CD is " << label << endl;
	cout << "The selection number is " << selections << endl;
	cout << "The play time is " << playtime << endl << endl;
}

Cd & Cd::operator=(const Cd &d)
{
	if (this == &d)
	{
		return *this;
	}
	else
	{
		delete [] performers;
		delete [] label;

		performers = new char [strlen(d.performers) + 1];
		label = new char [strlen(d.label) + 1];

		strcpy(this->performers, d.performers);
		strcpy(this->label, d.label);
		this->selections = d.selections;
		this->playtime = d.playtime;
		return *this;
	}
}

Classic::Classic(const char * s0, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	identity = new char [strlen(s0) + 1];
	strcpy(identity, s0);
}
Classic::Classic(const char * s0, const Cd & d) : Cd(d)
{
	identity = new char [strlen(s0) + 1];
	strcpy(identity, s0);
}

Classic & Classic::operator=(const Classic &cla)
{
	if (this == &cla)
	{
		return *this;
	}
	else
	{
		this->Cd::operator=((const Cd &) cla);
		delete [] identity;
		identity = new char [1];
		this->identity[0] = '\0';
		return *this;
	}
}

void Classic::Report() const
{
	cout << "This is a classical CD: " << identity <<endl;
	Cd::Report();

}

Classic::~Classic()
{
	delete [] identity;
	cout << "Classic destroyed" << endl;
}

