// Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
#include <cmath>
using namespace std;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart),
    imaginary(imaginaryPart)
{
    // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+(const Complex& operand2) const
{
    return Complex(real + operand2.real,
        imaginary + operand2.imaginary);
} // end function operator+

// subtraction operator
Complex Complex::operator-(const Complex& operand2) const
{
    return Complex(real - operand2.real,
        imaginary - operand2.imaginary);
} // end function operator-


Complex Complex::operator*(const Complex& operand2) const
{
    return Complex((real * operand2.real) - (imaginary * operand2.real),
        (real * operand2.imaginary) + (imaginary * operand2.real));
}

Complex Complex::operator/(const Complex& operand2) const
{
    if (operand2.real == 0 && operand2.imaginary == 0)
    {
        return Complex(INFINITY, INFINITY);
    }
    else
    {
        return Complex(
            (((real * operand2.real) + (imaginary * operand2.imaginary)) / ((operand2.real * operand2.real) + (operand2.imaginary * operand2.imaginary))),

            ((imaginary * operand2.real) - (real * operand2.imaginary)) / ((operand2.real * operand2.real) + (operand2.imaginary * operand2.imaginary)));
    }
}


bool Complex::operator==(const Complex& operand2)const
{
    if (real != operand2.real)
        return false;

    return true;
}

bool Complex::operator!=(const Complex& operand2)const
{
    return !(*this == operand2);
}



const Complex& Complex::operator=(const Complex& operand2)
{
    if (&operand2 != this)
    {
        real = operand2.real;
        imaginary = operand2.imaginary;
    }
    return *this;
}

istream& operator>>(istream& input, Complex& c)
{
    input.ignore(); // skip (
    input >> c.real;
    input.ignore(2); // skip , and space
    input >> c.imaginary;
    input.ignore(); // skip )

    return input;
}

ostream& operator<<(ostream& output, const Complex& c)
{
    if (c.real != INFINITY && c.imaginary != INFINITY)
    {
        output << '(' << c.real << ", " << c.imaginary << ')';
        return output;
    }
    else
    {
        output << "infinite";
        return output;
    }

}


