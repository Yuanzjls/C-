/*
 * RatePlayer.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: scott
 */

#include "RatePlayer.h"
#include <iostream>

using namespace std;

TableTennisPlayer::TableTennisPlayer(const string & fn,
		const string &ln, bool ht)
{
	firstname = fn;
	lastname = ln;
	hasTable = ht;
}

void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

RatePlayer::RatePlayer(unsigned int r, const string & fn,
			const string & ln, bool ht)
{
	TableTennisPlayer(fn, ln, ht);
	rating = r;
}

RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer & tp):TableTennisPlayer(tp)
{
	rating = r;
}


//
//RatePlayer::RatePlayer() {
//	// TODO Auto-generated constructor stub
//
//}
//
//RatePlayer::~RatePlayer() {
//	// TODO Auto-generated destructor stub
//}

