#include "Employee.h" // include definition of class Employee
#include <iostream>
#include <string>
using namespace std;


// constructor initializes firstName, lastName, monthlySalary
Employee::Employee(string first, string last, int salary)
{
	setFirstName(first); // call set function to initialize firstName
	setLastName(last);// call set function to initialize lastName
	setMonthlySalary(salary); // validate and store monthlySalary
} // end Employee constructor

// function to set the first name
void Employee::setFirstName(string first)
{
	firstName = first;  // store the first name in the object
}// end function setFirstName

// function to get the first name
string Employee::getFirstName()const
{
	return firstName;// return object's firstName
}// end function getFirstName

// function to set the last name
void Employee::setLastName(string last)
{
	lastName = last;// store the first name in the object
}// end function setLastName

// function to get the last name
string Employee::getLastName()const
{
	return lastName; // return object's lastName
}// end function getLastName

// function that sets the monthly salary
// ensures that the salary greater than 0
// if not, set monthlySalary to 1000
void Employee:: setMonthlySalary(int salary)
{
	if (salary > 0)// if salary is greater than 0
		monthlySalary = salary;//  store the monthly salary in the object
	else
	{
		// display messages
		cout << "\n XX Employee: " << getFirstName() << " "
			<< getLastName() << "'s inputted monthly salary is " << salary << endl;
		cout << " ** The salary is set to $1000. **\n";
		monthlySalary = 1000;// set monthlySalary to 1000
	}// end if

}// end function setMonthlySalary

// // function that gets the monthly salary
int Employee::getMonthlySalary()const
{
	return monthlySalary; // return object's monthlySalary
}

// function that increses the monthly salary
void Employee::increaseMonthlySalary(int rate)
{
	if (rate >= 0) // if increasing rate is greater or equal to 0
	{
		// display employee's first name, last name and original salary
		cout << "+++ Employee: " << getFirstName() << " " << getLastName()
			<< " has a salary adjustment of " << rate << " %" << endl;
		cout << " The original monthly salary is $" << getMonthlySalary() << endl;

	}
	else // if increasing rate is less than 0
	{
		// display employee's first name, last name and original salary
		cout << "--- Employee: " << getFirstName() << " " << getLastName()
			<< " has a salary adjustment of " << rate << " %" << endl;
		cout << " The original monthly salary is $" << getMonthlySalary() << endl;
	}// end if

	// Increases or decreases the monthly salary
	// display the new monthly salary
	monthlySalary = static_cast<int>(getMonthlySalary() * (1 + (rate / 100.0)));
	cout << " The new monthly salary is $" << getMonthlySalary() << endl << endl; 
}// end function increaseMonthlySalary