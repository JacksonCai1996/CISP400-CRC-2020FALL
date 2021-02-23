#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
	friend ostream& operator<<(ostream&, const Complex&);

public:
	Complex(double = 0.0, double = 0.0);
	bool operator==(const Complex&);

private:
	double real;
	double imaginary;
};

#endif // !COMPLEX_H