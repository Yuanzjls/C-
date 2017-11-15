/*
 * Mytime.h
 *
 *  Created on: Jul 8, 2017
 *      Author: scott
 */

#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

class time {
private:
	int hours;
	int minutes;
public:
	time();
	time(int h, int m =0);
	void AddMin(int n);
	void AddHr(int h);
	void Reset(int h=0, int n=0);
	time operator+(const time & t) const;
	time operator-(const time & t) const;
	time operator*(double n) const;
	void Show() const;
	friend std::ostream & operator <<(std::ostream & os, const time & t);
	~time();
};

#endif /* MYTIME_H_ */
