#include "DateTime.h"
#include <array>
#include <iostream>
#include <stdexcept>
using namespace std;


DateTime::DateTime(int mn, int dy, int yr, Time t)
	:time(t)
{
	setMonth(mn);
    setYear(yr);
    setDay(dy);
	
}

void DateTime::print()const
{
	cout << month << '/' << day << '/' << year;
	cout << "    ";
	time.printStandard();
}

void DateTime::increaseADay()
{
	day = checkDay(++day);
	if (day == 1)
	{
		if (month < 12)
			++month;
		else
		{
			setYear(++year);
			month = 1;
		}
	}
}

void DateTime::tick()
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
                increaseADay();
                time.setHour(0);
            }

            time.setMinute(0);
            time.setSecond(0);
        }
    }
}

void DateTime::setDay(int d)
{
    day = checkDay(d);
}

void DateTime::setMonth(int m)
{
    if (m > 0 && m <= monthsPerYear) // validate the month
        month = m;
    else
    {
        cout << "Invalid month (" << m << ") set to 1\n";
        month = 1;
    }
}

void DateTime::setYear(int y)
{
    if (y >= 1920 && y < 2020) // validate the month
        year = y;
    else
    {
        cout << "Invalid year (" << y << ") set to 2011\n";
        year = 2011;
    }
}

unsigned int DateTime::getMonth()const
{
    return month;
}

unsigned int DateTime::getYear()const
{
    return year;
}

unsigned int DateTime::getDay()const
{
    return day;
}



void DateTime::setHour(int h)
{
    time.setHour(h);
}

void DateTime::setMinute(int m)
{
    time.setMinute(m);
}

void DateTime::setSecond(int s)
{
    time.setSecond(s);
}

unsigned int DateTime::getHour()const
{
    return time.getHour();
}

unsigned int DateTime::getMinute()const
{
    return time.getMinute();
}

unsigned int DateTime::getSecond()const
{
    return time.getSecond();
}


unsigned int DateTime::checkDay(int testDay)const
{
    static const array< int, monthsPerYear + 1 > daysPerMonth =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // February 29 check for leap year 
    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    cout << "day (" << testDay << ") set to 1\n";
    return 1;
}