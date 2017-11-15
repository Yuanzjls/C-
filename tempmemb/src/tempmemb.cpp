//============================================================================
// Name        : tempmemb.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<typename T>
class beta
{
private:
	template <typename V>
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) {}
		void show() const {cout << val << endl;}
		V Value() const {return val;}
	};
	hold<T> q;
	hold<int> n;
public:
	beta(T t, int i) : q(t), n(i) {}
	template<typename U>
	U blab(U u, T t) {return (n.Value() + q.Value()) * u / t;}
	void Show() const {q.show(); n.show();}
};
//template class beta<double>;
//template double beta<double>::blab(double, double);
//typedef beta<double> dd;
int main()
{
	beta<double> guy(3.5, 3);

	cout << "T was set to double";
	guy.Show();
	cout << "V was set to T, which is double, then V was set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done\n";

	return 0;
}
