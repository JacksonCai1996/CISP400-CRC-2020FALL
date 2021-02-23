// Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
#include "Time.h"
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr, Time t)
    :time(t)
{
    if (mn > 0 && mn <= monthsPerYear) // validate the month
        month = mn;
    else
        throw invalid_argument("month must be 1-12");

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date ";
   print();                   
   cout << endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   cout << month << '/' << day << '/' << year; 
   cout << "\t";
   time.printStandard();
   cout << "\t";
   time.printUniversal();

} // end function print


void Date::increaseDay()
{
    day = checkDay(++day);
    if (day == 1)
    {
        if (month < 12)
        {
            month++;
        }
        else
        {
            year++;
            month = 1;
        }
    }
}

void Date::tick()
{
    if (time.getSecond() < 59)
    {
        int s = time.getSecond();
        time.setSecond(++s);
    }
    else
    {
        if (time.getMinute() < 59)
        {
            int m = time.getMinute();
            time.setMinute(++m);
            time.setSecond(0);
        }
        else
        {
            if (time.getHour() < 23)
            {
                int h = time.getHour();
                time.setHour(++h);
            }
            else
            {
                increaseDay();
                time.setHour(0);      
            }
            
            time.setMinute(0);
            time.setSecond(0);
        }
    }
}


// output Date object to show when its destructor is called
Date::~Date()
{ 
   cout << "Date object destructor is called\n";
   print();
   cout << endl;
} // end ~Date destructor

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

   cout << "day (" << testDay << ") set to 1" << endl;
   return 1;
} // end function checkDay