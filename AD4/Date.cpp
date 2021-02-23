//  Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
    setMonth(mn);
    setYear(yr);
    setDay(dy);
    
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   cout << month << '/' << day << '/' << year; 
} // end function print

void Date::setDay(int d)
{
    day = checkDay(d);
}

void Date::setMonth(int m)
{
    if (m > 0 && m <= monthsPerYear) // validate the month
        month = m;
    else
    {
        cout << "Invalid month (" << m << ") set to 1\n";
        month = 1;
    }
}

void Date::setYear(int y)
{
    if (y >= 1920 && y < 2020) // validate the month
        year = y;
    else
    {
        cout << "Invalid year (" << y << ") set to 2011\n";
        year = 2011;
    }
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay( int testDay ) const
{
   static const array< int, monthsPerYear + 1 > daysPerMonth = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || 
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   cout << "day (" << testDay << ") set to 1\n";
   return 1;
} // end function checkDay
