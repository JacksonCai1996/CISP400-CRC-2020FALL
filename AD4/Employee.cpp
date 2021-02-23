//  Employee.cpp
// Employee class member-function definitions.  
#include <iostream>
#include "Employee.h" // Employee class definition
#include "DateTime.h"
using namespace std;
int Employee::count = 0;


// constructor uses member initializer list to pass initializer 
// values to constructors of member objects  
Employee::Employee( const string &first, const string &last,const Date & dateOfHire,
    const Date & dateOfBirth, const DateTime& dateOfStart, const DateTime& dateOfEnd)
   : firstName( first ), // initialize firstName
     lastName( last ), // initialize lastName
     birthDate( dateOfBirth ), // initialize birthDate
     hireDate( dateOfHire ), // initialize hireDate
     startDateTime(dateOfStart),
     endDateTime(dateOfEnd)
{
    count++;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
   
    cout << "\n\nEmployee: " << getFirstName() << ' ' << getLastName() << "   ";
    getbirthDate();
    cout << "\t\t";
    gethireDate();
    cout << "    ";
    getstartDateTime();
    getendDateTime();

} // end function print

string Employee::getFirstName()const
{
    return firstName;
}

string Employee::getLastName()const
{
    return lastName;
}

void Employee::gethireDate()const
{
    cout << "hire date: ";
    hireDate.print();
}

void Employee::getbirthDate()const
{
    cout << "birth date: ";
    birthDate.print();
}

void Employee::getstartDateTime()const
{
    cout << "Training starts at ";
    startDateTime.print();
}

void Employee::getendDateTime()const
{
    cout << endl;
    bool check = testZeroDateTime(endDateTime);
    if (check)
    {
        cout << "No specified end training date and time.";
        cout << endl;
    }
    else
    {
        cout << "Training ends at ";
        endDateTime.print(); 
        cout << endl << endl;
    }
}

bool Employee::testZeroDateTime(const DateTime& dT) const
{
    if (dT.getHour() == 0 && dT.getMinute() == 0 && dT.getSecond() == 0)
        return true;
    else
        return false;
}

void Employee::setendDateTime(int h, int m, int s)
{
    int d = h / 8;
    int remainScond = (h - d * 8) * 3600 + m * 60 + s;
    endDateTime = startDateTime;

    cout << "\n\n ***" << getFirstName() << ' ' << getLastName() << " needs "
        << h << " hours " << m << " minutes " << "and " << s 
        << " seconds to finish a trianing.***\n";

    for (int i = 0; i < d; i++)
    {
        endDateTime.increaseADay();
    }
    
    for (int i = 0; i < remainScond; i++)
    {
        endDateTime.tick();
    }
}


int Employee::getCount()
{
    return count;
}

Employee::~Employee()
{
    --count;
}