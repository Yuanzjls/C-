/*
 * tv.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#include "tv.h"
#include <iostream>

using namespace std;
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}

void Tv::chanup()
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 0;
	}
}

void Tv::chandown()
{
	if (channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}

void Tv::settings() const
{

	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = "
				<< (mode == Antenna? "antenna":"cable") << endl;
		cout << "Input = "
				<< (input == TV? "TV": "DVD") << endl;
	}
}

void Remote::show_controlmode()
{
	cout << "The control mode is " << (controlmode == interactive? "interactive" : "normal") << endl;
}

void Tv::toggle_controlmode(Remote & R)
{
	R.controlmode = (R.controlmode == R.interactive )? R.normal : R.interactive;
}
