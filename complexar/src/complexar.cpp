//============================================================================
// Name        : complexar.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// complex operators
#include <iostream>     // std::cout
#include <complex>      // std::complex
#include <valarray>
using namespace std;

int main ()
{
  valarray<complex<double>> compvalar = {complex<double>(1,2), complex<double>(3,1), complex<double>(3,2), complex<double>(10,2)};


    cout << "complex value original:" << endl;

    for (unsigned int i=0; i<compvalar.size(); i++)
    {
        cout << "real:\t" << compvalar[i].real() << "\timage:\t" << compvalar[i].imag() << endl;
    }

    complex<double> t = compvalar.sum();
    cout << "after sum";
    cout << "real:\t" << t.real() << "\timage:\t" << t.imag() << endl;
  return 0;
}
