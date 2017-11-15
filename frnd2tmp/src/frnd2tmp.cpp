
//============================================================================
// Name        : frnd2tmp.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <typename T> void counts();
template <typename T> void report(T &);

template <typename TT>
class HasFriend
{
private:
	TT item;
	static int ct;
public:
	HasFriend(const TT & i) : item(i) {ct++;}
	~HasFriend(){ct--;}
	friend void counts<TT>();
	friend void report<>(HasFriend<TT> & hf);
};

template <typename T>
int HasFriend<T>::ct = 0;

template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriend<T>)<< "; ";
	cout << "template counts(): " << HasFriend<T>::ct << endl;
}
template <typename T>
void report(T & hf)
{
	cout  << hf.item << endl;
}

int main()
{

	counts<int>();
	HasFriend<int> hfi1(10);
	HasFriend<int> hfi2(20);
	HasFriend<double> hfdb(10.5);
	report(hfi1); // generate report(HasFriendT<int> &)
	report(hfi2); // generate report(HasFriendT<int> &)
	report(hfdb); // generate report(HasFriendT<double> &)
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();

	return 0;
}

