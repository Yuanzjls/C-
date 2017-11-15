/*
 * Mycomplex.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: scott
 */

#include "Mycomplex.h"

using namespace std;

Mycomplex::Mycomplex()
{
	Setxy(0, 0);
	// TODO Auto-generated constructor stub

}

Mycomplex::Mycomplex(double set_x, double set_y)
{
	Setxy(set_x, set_y);
}

void Mycomplex::Setxy(double set_x, double set_y)
{
	x = set_x;
	y = set_y;
}
Mycomplex Mycomplex::operator+(const Mycomplex & b) const
{
	return Mycomplex(this->x+b.x, this->y+b.y);
}
Mycomplex Mycomplex::operator*(const Mycomplex & b) const
{
	return Mycomplex(x*b.x-y*b.y, x*b.y + y*b.x);
}

Mycomplex Mycomplex::operator~(void) const
{
	return Mycomplex(x, -y);
}

Mycomplex Mycomplex::operator-(const Mycomplex & b) const
{
	return Mycomplex(x-b.x, y-b.y);
}
Mycomplex Mycomplex::operator*(const double  b) const
{
	return Mycomplex(x*b, y*b);
}
Mycomplex operator*(const double b, const Mycomplex & v)
{
	return Mycomplex(v.x*b, v.y*b);
}
istream & operator>>(istream & is, Mycomplex & c)
{
	cout << "real: ";
	if (is >> c.x)
	{
		cout << "imaginary: ";
		is >> c.y;
	}
	return is;
}
ostream & operator<<(ostream & os, const Mycomplex  & c)
{
	os << "("<< c.x << "," << c.y << "i)";
	return os;
}
Mycomplex::~Mycomplex() {
	// TODO Auto-generated destructor stub
}

