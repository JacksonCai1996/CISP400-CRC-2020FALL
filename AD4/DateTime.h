#ifndef DATETIME_H
#define DATETIME_H
#include "Time.h"

class DateTime
{

public:
	static const int monthsPerYear = 12;
	
	DateTime(int = 0, int = 0, int = 0, Time = Time(0,0,0));
	void print()const;
	void increaseADay();
	void tick();
	
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	unsigned int getMonth()const;
	unsigned int getYear()const;
	unsigned int getDay()const;

	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	unsigned int getHour()const;
	unsigned int getMinute()const;
	unsigned int getSecond()const;

private:
	unsigned int month; // 1-12 (January-December)
	unsigned int day; // 1-31 based on month
	unsigned int year; // any year
	Time time;
	
	// utility function to check if day is proper for month and year
	unsigned int checkDay(int) const;
};
#endif // !DATETIME_H
