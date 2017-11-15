/*
 * sales.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: scott
 */

#include "sales.h"
using namespace std;

Sales::bad_index::bad_index(int ix, const std::string &s):logic_error(s), bi(ix)
{

}

Sales::Sales(int yy)
{
	year = yy;
	for (int i=0; i<MONTHS; i++)
	{
		gross[i] = 0;
	}
}

Sales::Sales(int yy, const double * gr, int n)
{
	year = yy;

	int lim;

	if (n>=0 && n <= MONTHS)
	{
		int i;
		lim = n;
		for (i=0; i<lim; i++)
		{
			gross[i] = gr[i];
		}
		for (; i<MONTHS; i++)
		{
			gross[i] = 0;
		}
	}
	else if (n > MONTHS)
	{
		for (int i=0; i<MONTHS; i++)
		{
			gross[i] = MONTHS;
		}
	}
	else
	{
		for (int i=0; i<MONTHS; i++)
		{
			gross[i] = 0;
		}
	}
}

double Sales::operator[](int i) const
{
	if (i<0 || i>=MONTHS)
	{
		throw bad_index(i);
	}
	return gross[i];
}

double & Sales::operator[](int i)
{
	if (i<0 || i>=MONTHS)
	{
		throw bad_index(i);
	}
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string & lb, int ix,
		const string & s) : Sales::bad_index(ix, s)
{
	lbl = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy) : Sales(yy)
{
	label = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy,
		const double * dr, int n):Sales(yy, dr, n)
{
	label = lb;
}

double LabeledSales::operator[](int i) const
{
	if(i < 0 || i >= MONTHS)
	{
		throw nbad_index(Label(), i);
	}
	return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
	if(i < 0 || i >= MONTHS)
	{
		throw nbad_index(Label(), i);
	}
	return Sales::operator[](i);
}
