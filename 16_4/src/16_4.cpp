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

int reduce(long ar[], int n);

int main()
{
	const int init_size = 20;
	srand(time(0));
	long data_in[init_size];
	cout << "The original data is:" << endl;
	for (int i=0; i<init_size; i++)
	{
		data_in[i] = long((double)rand() / RAND_MAX * (init_size/2));
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

int reduce(long ar[], int n)
{
	sort(ar, ar+n);
	long * endx = unique(ar, ar+n);
	return endx - ar;
}
