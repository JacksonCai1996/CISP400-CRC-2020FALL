#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>// class Employee uses C++ standard string class

class Employee
{
public:
	Employee(std::string, std::string, int);// constructor that initializes courseName
	void setFirstName(std::string);// function that sets the first name
	std::string getFirstName() const; // function that gets the first name
	void setLastName(std::string);// function that sets the last name
	std::string getLastName()const;// function that gets the last name
	void setMonthlySalary(int);// function that sets the monthly salary
	int getMonthlySalary()const;// function that gets the monthly salary
	void increaseMonthlySalary(int); // function that increases the monthly salary

private:
	std::string firstName; // Employee's first name
	std::string lastName; // Employee's last name
	int monthlySalary;   // Employee's monthly salary
}; // end class Employee

#endif // !EMPLOYEE_H