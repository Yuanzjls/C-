//============================================================================
// Name        : stdmove.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
using namespace std;

class Useless
{
private:
	int n;
	char *pc;
	static int ct;
	void ShowObject() const;
public:
	Useless()
	{
		ct++;
		n = 0;
		pc = nullptr;
	}
	explicit Useless(int k) : n(k)
	{
		ct++;
		pc = new char [n];
	}
	Useless(int k, char ch) : n(k)
	{
		ct++;
		pc = new char[n];
		for (int i=0; i<n; i++)
		{
			pc[i] = ch;
		}
	}
	Useless(const Useless & f) : n(f.n)
	{
		ct++;
		pc = new char[n];
		for (int i=0; i<n; i++)
		{
			pc[i] = f.pc[i];
		}
	}
	Useless(Useless && f)
	{
		ct++;
		pc = f.pc;
		n = f.n;
		f.pc = nullptr;
		f.n = 0;
	}
	~Useless()
	{
		delete [] pc;
		ct--;
	}
	Useless operator+(const Useless & f)const
	{
		Useless temp = Useless(n + f.n);
		for (int i=0; i<n; i++)
		{
			temp.pc[i] = pc[i];
		}
		for (int i=n; i<temp.n; i++)
		{
			temp.pc[i] = f.pc[i-n];
		}
		return temp;
	}
	Useless & operator=(const Useless &f)
	{
		cout << "copy assignment operator called:\n";
		if (this == &f)
		{
			return *this;
		}
		delete [] pc;
		n = f.n;
		pc = new char[n];
		for (int i = 0; i<n; i++)
		{
			pc[i] = f.pc[i];
		}
		return *this;
	}
	Useless & operator=(Useless &&f)
	{
		cout << "move assignment operator called:\n";
		if (this == &f)
		{
			return *this;
		}
		delete [] pc;
		n = f.n;
		pc = f.pc;
		f.n = 0;
		f.pc = nullptr;
		return *this;
	}
	void ShowData() const
	{
		if (n == 0)
		{
			cout << "(object empty)";
		}
		else
		{
			for (int i=0; i<n; i++)
			{
				cout << pc[i];
			}
		}
		cout << endl;
	}
};

int Useless::ct = 0;
int main()
{
	Useless one(10, 'x');
	Useless two = one+one;
	cout << "object one: ";
	one.ShowData();
	cout << "object two: ";
	two.ShowData();
	Useless three, four;
	cout << "three = one \n";
	three = one;
	cout << "now object three = ";
	three.ShowData();
	cout << "four = one + two\n";
	four = one + two;
	cout << "now object four = ";
	four.ShowData();
	cout << "four = move(one)\n";
	four = move(one);
	cout << "now object four = ";
	four.ShowData();
	cout << "and object one = ";
	one.ShowData();

	return 0;
}
