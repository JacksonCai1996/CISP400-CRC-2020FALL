// Employee.h
// Employee class definition showing composition.
// Member functions defined in Employee.cpp.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" // include Date class definition
#include "DateTime.h" // include DateTime class definition

class Employee
{
public:
   Employee( const std::string &, const std::string &, const Date &, const Date &,
				const DateTime&, const DateTime&);
   ~Employee(); // provided to confirm destruction order

   std::string getFirstName() const;
   std::string getLastName() const;
   void gethireDate() const;
   void getbirthDate() const;
   void getstartDateTime() const;
   void getendDateTime()const;
   bool testZeroDateTime(const DateTime&) const;
   void setendDateTime(int, int, int);
   void print() const;
   static int getCount();

private:
	static int count;
	std::string firstName; // composition: member object
	std::string lastName; // composition: member object
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
    const DateTime startDateTime;
    DateTime endDateTime;
}; // end class Employee

#endif