#include "Employee.h"
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


Employee::Employee(string first, string last, Date d)
{
	firstName = first;
	lastName = last;
	date = d;
}


bool Employee::operator==(const Employee& e)
{
	if (firstName == e.firstName && lastName == e.lastName && date == e.date)
		return true;

	return false;
}


ostream& operator<<(ostream& output, const Employee& e)
{
	output << e.firstName << ' ' << e.lastName << " birth date: " << e.date;

	return output;
}