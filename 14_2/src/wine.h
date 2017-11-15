/*
 * wine.h
 *
 *  Created on: Jul 21, 2017
 *      Author: scott
 */

#ifndef WINE_H_
#define WINE_H_
#include <valarray>
#include <string>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first(){return a;}
	T2 & second(){return b;}
	T1 first()const {return a;}
	T2 second()const {return b;}
	Pair(const T1 & x1, const T2 & x2) {a=x1; b=x2;}
	Pair(){}
};
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;


class Wine: private std::string, private PairArray
{
//private:
//	std::string label;
//	PairArray information;
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	std::string & Label() ;
	void GetBottles();
	int sum();
	void Show();
	~Wine();
};

#endif /* WINE_H_ */
