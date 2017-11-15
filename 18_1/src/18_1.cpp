//============================================================================
// Name        : 18_1.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <initializer_list>

using namespace std;

template <class T>
T average_list(initializer_list<T> il)
{
	T average=0;
	for (auto p = il.begin(); p < il.end(); p++)
	{
		average += *p;
	}
	return average / il.size();
}

int main()
{
	using namespace std;
	// list of double deduced from list contents
	auto q = average_list({15.4, 10.7, 9.0});
	cout << q << endl;
	// list of int deduced from list contents
	cout << average_list({20, 30, 19, 17, 45, 38} ) << endl;
	// forced list of double
	auto ad = average_list<double>({'A', 70, 65.33});
	cout << ad << endl;
	return 0;
}

