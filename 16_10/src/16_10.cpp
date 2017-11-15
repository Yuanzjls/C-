//============================================================================
// Name        : 16_10.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
	std::string title;
	int rating;
	double price;
};
using namespace std;
bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool rate_sort(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool price_sort(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(shared_ptr<Review>  & rr);
void ShowReview(const shared_ptr<Review> & rr);
int main()
{

	vector<shared_ptr<Review> > books;
	shared_ptr<Review> temp;
	while (FillReview(temp))
	{
		books.push_back(temp);
	}
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
		<< books.size() << " ratings:\n"
		<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end());
		cout << "Sorted by title:\nRating\tBook\tprice\n";
		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end(), rate_sort);
		cout << "Sorted by rating increasing:\nRating\tBook\tprice\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << "Sorted by rating decreasing:\nRating\tBook\tprice\n";
		for_each(books.rbegin(), books.rend(), ShowReview);

		sort(books.begin(), books.end(), price_sort);
		cout << "Sorted by price increasing:\nRating\tBook\tprice\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << "Sorted by price decreasing:\nRating\tBook\tprice\n";
		for_each(books.rbegin(), books.rend(), ShowReview);

	}
	else
	cout << "No entries. ";
	cout << "Bye.\n";
	return 0;
}
bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
	{
		return true;
	}
	else if (r1->title == r2->title && r1->rating < r2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool rate_sort(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	return r1->rating < r2->rating;
}

bool price_sort(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	return r1->price < r2->price;
}

bool FillReview(shared_ptr<Review>  & rr)
{
	string str_temp;
	int rate_temp;
	double price_temp;
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, str_temp);
	if (str_temp == "quit")
	{
		return false;
	}
	std::cout << "Enter book rating: ";
	std::cin >> rate_temp;
	if (!std::cin)
	{
		return false;
	}
	// get rid of rest of input line
	while (std::cin.get() != '\n');
	std::cout << "Enter book price: ";
	std::cin >> price_temp;
	if (!std::cin)
	{
		return false;
	}
	while (std::cin.get() != '\n');
	rr = shared_ptr<Review>(new Review);
	rr->title = str_temp;
	rr->rating = rate_temp;
	rr->price = price_temp;
	return true;
}
void ShowReview(const shared_ptr<Review> & rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t"<< rr->price<< std::endl;
}
