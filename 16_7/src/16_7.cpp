//============================================================================
// Name        : 16_7.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> Lotto(unsigned int range, unsigned int count);

int main()
{
	srand(time(0));

	unsigned int range, count;

	cout << "Enter the range: ";
	cin >> range;
	cout << "Enter the count: ";
	cin >> count;

	vector<int> winner = Lotto(range, count);

	cout << "The winner is:" << endl;
	for (auto p=winner.begin(); p<winner.end(); p++)
	{
		cout << *p<< "\t";
	}
	return 0;
}

vector<int> Lotto(unsigned int range, unsigned int count)
{
	vector<int> all;

	for (unsigned int i=0; i<range; i++)
	{
		all.push_back(i+1);
	}
	for (int i=0; i<rand(); i++)
	{
		random_shuffle(all.begin(), all.end());
	}
	return vector<int>(all.begin(), all.begin()+count);
}
