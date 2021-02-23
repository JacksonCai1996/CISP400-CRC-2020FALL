#include "Complex.h"
#include "Date.h"
#include "Employee.h"
#include "Stack.h"
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;


template<typename T>
bool isEqualTo(T value1, T value2)
{
    if (value1 == value2)
        return true;

    return false;
}

template<typename T>
void pushData(T value1, T value2, T value3, T value4, Stack<T> &data, string type, string stackName)
{ 
    cout << "  push " << type << " into the " << stackName << endl;
    cout << "     " << value1 << " is pushed into the stack.\n";
    data.push(value1);
    cout << "     " << value2 << " is pushed into the stack.\n";
    data.push(value2);
    cout << "     " << value3 << " is pushed into the stack.\n";
    data.push(value3);
    cout << "     " << value4 << " is pushed into the stack.\n";
    data.push(value4);
}

template<typename T>
void pushEmployeeData(T value1, T value2, T value3, T value4, T value5, T value6,
              Stack<T>& data, string type, string stackName)
{
    cout << "  push " << type << " into the " << stackName << endl;
    cout << "     " << value1 << " is pushed into the stack.\n";
    data.push(value1);
    cout << "     " << value2 << " is pushed into the stack.\n";
    data.push(value2);
    cout << "     " << value3 << " is pushed into the stack.\n";
    data.push(value3);
    cout << "     " << value4 << " is pushed into the stack.\n";
    data.push(value4);
    cout << "     " << value5 << " is pushed into the stack.\n";
    data.push(value5);
    cout << "     " << value6 << " is pushed into the stack.\n";
    data.push(value6);
}


template<typename T>
void popData(Stack<T>& stack1, Stack<T>& stack2)
{
    T val1;
    T val2;

    while (stack1.pop(val1) && stack2.pop(val2))
    {
        cout << "  Objects of " << typeid(T).name() << " :\n"
            << "    " << val1 << " and\n"
            << "    " << val2
            << "\n    are " << (isEqualTo(val1, val2) ? "" : "\"NOT\" ") << "equal.\n\n";
    }

}


int main()
{
    
    Stack<int> intStack1;
    Stack<int> intStack2;
    cout << "**int-int Testing intgers int-int**\n"
        << "Create two 10-element integer-stacks(int1Stack and int2Stack).\n\n"
        << "Push integers into the integer-stacks.\n";  
    pushData(1, 2, -1, -1, intStack1, "integers", "intStack1");
    pushData(1, 4, 1, -1, intStack2, "integers", "intStack2");

    cout << "\nPop out integers from the integer-stacks to do comparison.\n";
    popData(intStack1, intStack2);
    cout << endl << endl;


    Stack<char> charStack1;
    Stack<char> charStack2;
    cout << "**char-char Testing chars char-char**\n"
        << "Create two 10-element char-stacks(char1Stack and char2Stack).\n\n"
        << "Push chars into the char-stacks.\n";
    pushData('a', 'a', 'A', 'A', charStack1, "chars", "charStack1");
    pushData('a','c','a', 'A', charStack2, "chars", "charStack2");

    cout << "\nPop out chars from the char-stacks to do comparison.\n";
    popData(charStack1, charStack2);
    cout << endl << endl;


    Stack<double> doubleStack1;
    Stack<double> doubleStack2;
    cout << "**double-double Testing doubles double-double**\n"
        << "Create two 10-element double-stacks(double1Stack and double2Stack).\n\n"
        << "Push doubles into the double-stacks.\n";
    pushData(2.2, 2.2, -2.2, -2.2, doubleStack1, "doubles", "doubleStack1");
    pushData(2.2, 2.3, 2.2, -2.2, doubleStack2, "doubles", "doubleStack2");

    cout << "\nPop out doubles from the double-stacks to do comparison.\n";
    popData(doubleStack1, doubleStack2);
    cout << endl << endl;

    
    
    
    Stack<Complex> complex1Stack;
    Stack<Complex> complex2Stack;
    cout << "**Complex-Complex Testing Complex objects Complex-Complex**\n"
        << "Create two 10-element Complex-stacks(Complex1Stack and Complex2Stack).\n\n"
        << "Push Complex objects into the Complex-stacks.\n";

    Complex c1(10, 5);
    Complex c2(10, -5);
    Complex c3(10, 54);
    pushData(c1, c1, c2, c2, complex1Stack, "Complex objects", "complex1Stack");
    pushData(c1, c3, c1, c2, complex2Stack, "Complex objects", "complex1Stack");

    cout << "\nPop out Complex objects from the Complex-stacks to do comparison.\n";
    popData(complex1Stack, complex2Stack);
    cout << endl << endl;


    Stack<string> stringStack1;
    Stack<string> stringStack2;
    string s1 = "abcdefg";
    string s2 = "-abcdefg";
    string s3 = "abcdefh";
    cout << "**string-string Testing strings string-string**\n"
        << "Create two 10-element string-stacks(string1Stack and string2Stack).\n\n"
        << "Push strings into the string-stacks.\n";
    pushData(s1, s1, s2, s2, stringStack1, "strings", "stringStack1");
    pushData(s1, s3, s1, s2, stringStack2, "strings", "stringStack2");

    cout << "\nPop out strings from the string-stacks to do comparison.\n";
    popData(stringStack1, stringStack2);
    cout << endl << endl;

    
    Stack<Date> date1Stack;
    Stack<Date> date2Stack;
    cout << "**Date-Date Testing Date objects Date-Date**\n"
        << "Create two 10-element Date-stacks(Date1Stack and Date2Stack).\n\n"
        << "Push Date objects into the Date-stacks.\n";
    
    Date d1(2, 31, 2014);
    Date d2(2, 13, 2014);
    Date d3(-2, 13, 2014);
    Date d4(-2, 14, 2014);
    pushData(d1, d2, d3, d3, date1Stack, "Date objects", "date1Stack");
    pushData(d1, d4, d2, d3, date2Stack, "Date objects", "date2Stack");

    cout << "\nPop out Date objects from the Date-stacks to do comparison.\n";
    popData(date1Stack, date2Stack);
    cout << endl << endl;

    
    Stack<Employee> employee1Stack;
    Stack<Employee> employee2Stack;
    cout << "**Employee-Employee Testing Employee objects Employee-Employee**\n"
        << "Create two 10-element Employee-stacks(Employee1Stack and Employee2Stack).\n\n"
        << "Push Employee objects into the Employee-stacks.\n";  

    Date ed1(3, 1, 2014);
    Date ed2(3, 2, 2014);
    Employee e0("John", "Lin", ed1);
    Employee e1("1John", "Lin", ed1);
    Employee e2("John", "1Lin", ed1);
    Employee e3("1John", "1Lin", ed2);
    Employee e4("John", "1Lin", ed2);
    Employee e5("John", "Lin", ed2);

    pushEmployeeData(e0, e1, e2, e0, e2, e3, employee1Stack, "Employee objects", "employee1Stack");
    pushEmployeeData(e0, e0, e0, e4, e5, e3, employee2Stack, "Employee objects", "employee2Stack");

    cout << "\nPop out Employee objects from the Employee-stacks to do comparison.\n";
    popData(employee1Stack, employee2Stack);
    cout << endl;


    system("pause");
}

