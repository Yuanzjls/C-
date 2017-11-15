/*
 * studentc.h
 *
 *  Created on: Jul 18, 2017
 *      Author: scott
 */

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream & arr_pit(std::ostream & os) const;
public:
//	using ArrayDb::max;
//	using ArrayDb::min;
	using ArrayDb::operator[];
	Student();
	explicit Student(const std::string & s);
	explicit Student(int n);
	Student(const std::string &s, int n);
	Student(const std::string &s, const ArrayDb &a);
	Student (const char * str, const double * pd, int n);
	~Student();
	double Average() const;
	const std::string & Name() const;
//	double & operator[](int i);
//	double operator[](int i) const;

	friend std::istream & operator>>(std::istream & is, Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);
	friend std::ostream & operator<<(std::ostream &os, const Student & stu);
};

#endif /* STUDENTC_H_ */
