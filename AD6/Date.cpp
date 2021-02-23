#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

Date::Date(int m, int d, int y)
{
	if (m < 0)
		month = 1;
	else
		month = m;
	year = y;

	day = checkDay(d);
}

bool Date::operator==(const Date& d)
{
	if (month == d.month && day == d.day && year == d.year)
		return true;

	return false;
}

int Date::checkDay(int testDay)
{
	int dayPerMonth[13] = { 0, 31, 28, 31, 30, 31,30, 31,31 ,30, 31, 30,31 };

	if (testDay <= dayPerMonth[month])
		return testDay;

	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return testDay;

	return 1;
}

ostream& operator<<(ostream& output, const Date& d)
{
	string monthPerYear[13] = { "", "January", "February" ,"March" ,"April" ,"May" ,"June" ,"July" ,"August" ,
							   "September" ,"October" ,"November" ,"December" };

	output << monthPerYear[d.month] << ' ' << d.day << ", " << d.year;

	return output;
}