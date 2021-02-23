#include "Complex.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

template<typename T>
bool isEqualTo(T value1, T value2)
{
    if (value1 == value2)
        return true;
    
    return false;
}


int main()
{
    cout << "***  Integers Tests  ***\n"
        << "Integers: 1 and 1 are " << (isEqualTo(1, 1) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: 2 and 4 are " << (isEqualTo(2, 4) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -1 and 1 are " << (isEqualTo(-1, 1) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -1 and -1 are " << (isEqualTo(-1, -1) ? "" : "\"NOT\" ") << "equal\n\n";

    cout << "\n***  Chars Tests  ***\n"
        << "Integers: a and a are " << (isEqualTo('a', 'a') ? "equal" : "\"NOT\" equal") << endl
        << "Integers: a and c are " << (isEqualTo('a', 'c') ? "equal" : "\"NOT\" equal") << endl
        << "Integers: c and a are " << (isEqualTo('c', 'a') ? "equal" : "\"NOT\" equal") << endl
        << "Integers: c and c are " << (isEqualTo('c', 'c') ? "" : "\"NOT\" ") << "equal\n\n";

    cout << "\n***  Double Tests  ***\n"
        << "Integers: 2.2 and 2.2 are " << (isEqualTo(2.2, 2.2) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: 2.2 and 2.3 are " << (isEqualTo(2.2, 2.3) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -2.2 and 2.2 are " << (isEqualTo(-2.2, 2.2) ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -2.2 and -2.2 are " << (isEqualTo(-2.2, -2.2) ? "" : "\"NOT\" ") << "equal\n\n";


    Complex c1(10, 5);
    Complex c2(10, 54);
    Complex c3(10, -5);
    Complex c4(-10, -5);
    cout << "\n***  Complex Tests  ***\n"
        << "Class objects: " << c1 << " and " << c1 << " are" << (isEqualTo(c1, c1) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << c1 << " and " << c2 << " are" << (isEqualTo(c1, c2) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << c3 << " and " << c1 << " are" << (isEqualTo(c3, c1) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << c4 << " and " << c4 << " are" << (isEqualTo(c4, c4) ? " " : " \"NOT\" ") << "equal\n\n";

    
    cout << "\n***  string Tests  ***\n"
        << "Integers: abcdefg and abcdefg are " << (isEqualTo("abcdefg", "abcdefg") ? "equal" : "\"NOT\" equal") << endl
        << "Integers: abcdefg and abcdefh are " << (isEqualTo("abcdefg", "abcdefh") ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -abcdefg and abcdefg are " << (isEqualTo("-abcdefg", "abcdefg") ? "equal" : "\"NOT\" equal") << endl
        << "Integers: -abcdefg and -abcdefg are " << (isEqualTo("-abcdefg", "-abcdefg") ? "" : "\"NOT\" ") << "equal\n\n";


    Date d1(2, 31, 2017);
    Date d2(2, 13, 2017);
    Date d3(2, 14, 2017);
    Date d4(-2, 13, 2017);
    cout << "\n***  Date Tests  ***\n"
        << "Class objects: " << d1 << " and " << d1 << " are" <<(isEqualTo(d1, d1) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << d2 << " and " << d3 << " are" << (isEqualTo(d2, d3) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << d4 << " and " << d2 << " are" << (isEqualTo(d4, d2) ? " equal" : " \"NOT\" equal") << endl
        << "Class objects: " << d4 << " and " << d4 << " are" << (isEqualTo(d4, d4) ? " " : " \"NOT\" ") << "equal\n\n";

    system("pause");

}

