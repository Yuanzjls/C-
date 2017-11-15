/*
 * Queue.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: scott
 */

#include "Queue.h"
#include <cstdlib>


void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
