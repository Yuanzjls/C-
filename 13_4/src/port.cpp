/*
 * port.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: scott
 */

#include "port.h"
#include <cstring>
using namespace std;

Port::Port(const char * br, const char * st, int b)
{
	brand = new char [strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}
Port::Port(const Port &p)
{
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port::~Port()
{
	delete [] brand;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
	{
		return *this;
	}
	else
	{
		delete [] brand;
		brand = new char [strlen(p.brand) + 1];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
		bottles = p.bottles;

		return * this;
	}
}

Port & Port::operator+=(int b)
{
	bottles += b;

	return *this;
}

Port & Port::operator-=(int b)
{
	bottles -= b;

	return *this;
}

int Port::BottleCount() const
{
	return bottles;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	cout << p.brand << ", " << p.style << ", " << p.bottles;

	return os;
}

VintagePort::VintagePort() : Port("none", "vintage", 0)
{
	nickname = new char [strlen("Null") + 1];
	strcpy(nickname, "Null");
	year = 1979;
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :Port(br, "vintage", b)
{
	nickname = new char [strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
//	brand = new char [strlen(vp.brand) + 1];
//	strcpy(brand, brand);
//
//	strcpy(style, vp.style);
//	bottles = vp.bottles;

	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
VintagePort::~VintagePort()
{
	delete [] nickname;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
	{
		return *this;
	}
	else
	{
		this->Port::operator =(vp);

		nickname = new char [strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
		return *this;
	}
}
void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
	cout << (const VintagePort &)vp;
	cout << vp.nickname << ", " << vp.year;
	return os;
}
