//============================================================================
// Name        : funtemp.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T a[], T b[], int n);

template <typename T>
void Show(T a[], int n);
const int Lim = 8;

using namespace std;

int main()
{
	int i = 10, j = 20;

	cout << "i, j =" << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i, j =" << i << ", " << j << ".\n";

	int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
	int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};

	cout << "Original arrays:\n";
	Show(d1, Lim);
	Show(d2, Lim);
	Swap(d1, d2, Lim);
	cout << "Swapped arrays:\n";
	Show(d1, Lim);
	Show(d2, Lim);


	return 0;
}
template <typename T>
void Swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}
template <typename T>
void Swap(T a[], T b[], int n)
{
	T temp;

	for (int i=0; i<n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
template <typename T>
void Show(T a[], int n)
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";

	for (int i=4; i<n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
