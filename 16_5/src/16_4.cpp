//============================================================================
// Name        : 16_4.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
int reduce(T ar[], int n);

int main()
{
	const int init_size = 9;
	srand(time(0));
	string data_in[init_size] = { "insult", "danger", "danger", "beetle",
			"insult", "beetle", "garage", "apiary", "health"};
	cout << "The original data is:" << endl;

	random_shuffle(data_in, data_in+init_size);
	for (int i=0; i<init_size; i++)
	{
		//data_in[i] = char((double)rand() / RAND_MAX * (init_size/2)) + 'a';
		cout << data_in[i] << "\t";
		if (i%5==4)
		{
			cout << endl;
		}
	}
	int size = reduce(data_in, init_size);
	cout << endl << "After operation data is:" << endl;
	for (int i=0; i<size; i++)
	{
		//data_in[i] = rand() % (init_size/2);
		cout << data_in[i] << "\t";
		if (i%5==4)
		{
			cout << endl;
		}
	}

	return 0;
}

template<class T>
int reduce(T ar[], int n)
{
	sort(ar, ar+n);
	T * end = unique(ar, ar+n);
	return end - ar;
}
