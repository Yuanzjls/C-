//============================================================================
// Name        : 14_5.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "abstremp.h"

using namespace std;

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();

    highfink hf(ma, "Cury Kew");
    hf.ShowAll();

    cout << "Press a key for next phase:" << endl;
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer: \n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for(int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    return 0;
}
