/*
 * Mycomplex.h
 *
 *  Created on: Jul 13, 2017
 *      Author: scott
 */

#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_
#include <iostream>
class Mycomplex {
private:
	double x;
	double y;
public:
	Mycomplex();
	Mycomplex(double set_x, double set_y);
	void Setxy(double set_x, double set_y);
	Mycomplex operator+(const Mycomplex & b) const;
	Mycomplex operator*(const Mycomplex & b) const;
	Mycomplex operator~(void) const;
	Mycomplex operator-(const Mycomplex & b) const;
	Mycomplex operator*(const double  b) const;
	friend Mycomplex operator*(const double b, const Mycomplex & v);
	friend std::istream & operator>>(std::istream & is, Mycomplex & c);
	friend std::ostream & operator<<(std::ostream & os, const Mycomplex  & c);
	~Mycomplex();
};

#endif /* MYCOMPLEX_H_ */
