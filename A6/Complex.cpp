#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

ostream &operator<<(ostream& output, const Complex& c)
{
	output << c.real << (c.imaginary > 0 ? " + " : " - ") << abs(c.imaginary) << "i";
	return output;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

bool Complex::operator==(const Complex& c)
{
	if (real == c.real && imaginary == c.imaginary)
		return true;
	
	return false;
}