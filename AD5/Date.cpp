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
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   cout << month << '/' << day << '/' << year; 
} // end function print


// update a Date object private data member
void Date::setDate(Date& date)
{
	month = date.month;
	day = date.day;
	year = date.year;
}// end setDate print

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[monthsPerYear + 1] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;
	// February 29 check for leap year
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Day (" << testDay << ") set to 1.\n";
	return 1; // leave object in consistent state if bad value
} // end function checkDay
