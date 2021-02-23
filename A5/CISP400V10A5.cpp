// V10A5.cpp
// Complex class test program.
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	Complex x;
	Complex y(4.3, 8.2);
	Complex z(3.3, 1.1);
	Complex l(0, 0);
	Complex m(0, 0.1);
	Complex k;

	cout << "Enter a complex number in the form: (a, b) for Complex object k.\n"
		<< "(Performing >> operator overloading.)\n"
		<< "? ";
	cin >> k;

	cout << "\nThe existing Complex objects are:\n"
		<< "(Performing << operator overloading.)";
	cout << "\nx: " << x
		<< "\ny: " << y
		<< "\nz: " << z
		<< "\nk: " << k
		<< "\nl: " << l
		<< "\nm: " << m << '\n';



	x = y + z;
	cout << "\nPerforming +, = and << operators overloading.\nx = y + z:" << endl;
	cout << x << " = " << y << " + " << z << endl;

	x = y - z;
	cout << "\nPerforming -, = and << operators overloading.\nx = y - z:" << endl;
	cout << x << " = " << y << " - " << z << endl;

	x = y * z;
	cout << "\nPerforming *, = and << operators overloading.\nx = y * z:" << endl;
	cout << x << " = " << y << " * " << z << endl;

	x = y / z;
	cout << "\nPerforming /, = and << operators overloading.\nx = y / z:" << endl;
	cout << x << " = " << y << " / " << z << endl;

	x = y / l;
	cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0).\nx = y / l:" << endl;
	cout << x << " = " << y << " / " << l << endl;

	x = y / m;
	cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0.1).\nx = y / m:" << endl;
	cout << x << " = " << y << " / " << m << endl;

	cout << "\nPerforming != and << operators overloading.\ncheck x != k" << endl;
	if (x != k)
		cout << x << " != " << k << endl;

	cout << "\nPerforming =, == and << operators overloading."
		<< "\nassign k to x by using x = k statement." 
		<< "\ncheck x == k"<< endl;
	x = k;
	if(x == k)
		cout << x << " == " << k << endl;

	system("pause");

} // end main