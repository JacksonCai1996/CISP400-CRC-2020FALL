#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Employee
{
	friend ostream& operator<<(ostream&, const Employee&);

public:
	Employee(string = string(), string = string(), Date = Date());
	bool operator==(const Employee&);

private:
	string firstName;
	string lastName;
	Date date;
};

#endif // !EMPLOYEE_H