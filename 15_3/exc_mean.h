/*
 * exc_mean.h
 *
 *  Created on: Jul 25, 2017
 *      Author: scott
 */

#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
class base_error: public std::logic_error
{
protected:
	double v1;
	double v2;
public:
	base_error(const std::string &s="none", double a=0, double b=0):
		 std::logic_error(s)
	{
		v1 = a;
		v2 = b;
	}
	 virtual std::string what()
	{
		return std::logic_error::what();
	}
};



class bad_hmean:public base_error
{
public:
	bad_hmean(double a = 0, double b = 0) :
		base_error("hmean(",a, b){}
	virtual std::string what()
	{
		std::ostringstream sstream;

		sstream << (base_error::what()) << v1 << ", " << v2
				<< "): invalid arguments a = -b\n";
		return sstream.str();
//		base_error.what() + std::string(v1) << ", " << std::string(v2) << "): invalid arguments a = -b\n";
	}


};

class bad_gmean:public base_error
{
public:
	bad_gmean(double a = 0, double b = 0) :
		base_error("gmean(", a, b ){}
	virtual std::string what()
	{

		std::ostringstream sstream;

		sstream << (base_error::what()) << v1 << ", " << v2
				<< "): arguments should be >= 0\n";
		return sstream.str();

	}
};



#endif /* EXC_MEAN_H_ */
