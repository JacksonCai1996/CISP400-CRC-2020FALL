#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
Account::Account(double balance, string first, string last,
		Date& sDate, Date& uDate)
	:startingDate(sDate), // intialize startingDate
	 lastUpdateDate(uDate) // intialize lastUpdateDate
{
	setFirstName(first);
	setLastName(last);
	setBalance(balance);
	
}// end Account constructor

void Account::setFirstName(string first)
{
	firstName = first;
}

void Account::setLastName(string last)
{
	lastName = last;
}

void Account::setBalance(double balance)
{
	// validate account balance
	if (balance < 0.0)
	{
		cout << "The initial balance was invalid." << endl;
		accountBalance = 0.0; // set accountBalance to 0
	}
	else
		accountBalance = balance;
} // end

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

// return account balance
double Account::getBalance() const
{
	return accountBalance;
}// end getBalance function


// add an amount to the current balance.
void Account::credit(double amount, Date& U_Date)
{
	accountBalance += amount; // add amount to current balance
	lastUpdateDate.setDate(U_Date); //updates the last update date
}// end credit function


// withdraw money from the current balance
void Account::debit(double amount, Date &U_Date)
{
	// validate if amount > account balace
	if (amount > getBalance())
	{
		// display customer's information
		cout << endl;
		cout << firstName << ' ' << lastName << endl;
		cout << "Balance is $" << accountBalance << " and debit amount is $" << amount << endl;
		cout << "Debit amount exceeded account balance.  The request is returned."
			<< endl;
	}
	else
	{
		accountBalance -= amount;  // subtract the amount from current balance
	}
	
	lastUpdateDate.setDate(U_Date);//updates the last update date	
}// end debit function

// display customer's information
void Account::print() const
{
	cout << firstName << ' ' << lastName << endl
		<< "A/C Open ";
	startingDate.print();
	cout << "\nA/C updated ";
	lastUpdateDate.print();
	cout << "\nA/C Balance " << getBalance() << endl;
}// end print function


// update the transactioal date when customer manipulate the account
void Account::updateDate(Date& U_Date)
{
	lastUpdateDate.setDate(U_Date); //updates the last update date
}// end updateDate function