#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);

public:
	Date(int = 1, int = 1, int = 1900);
	bool operator==(const Date&);

private:
	int month;
	int day;
	int year;

	int checkDay(int);
};

#endif // !DATE_H
