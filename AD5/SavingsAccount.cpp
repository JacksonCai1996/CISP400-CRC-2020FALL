#include "SavingsAccount.h"
#include <iostream>
using namespace std;

// constructor
SavingsAccount::SavingsAccount(double balance, double interest, string first, 
	string last, Date &sDate, Date &uDate)
	: Account(balance, first, last, sDate, uDate) // initialize constructor of Account
{
	// validate if interest is < 0.0
	if (interest < 0)
	{
		interestRate = 0.0; // set interestRate to 0.0
		Account::print(); // print customer’s information
		cout << "\nInterest Rate: " << interestRate;
	}
	else
		interestRate = interest; // initialize interest
}// end constructor

// set interest rate and update the date
void SavingsAccount::setInterestRate(double interest, Date &U_Date)
{
	// validate if interest is < 0.0
	if (interest < 0)
	{
		interestRate = 0.0;// set interestRate to 0.0
		Account::print();// print customer’s information
		cout << "\nInterest Rate: " << interestRate;
	}
	else
	{
		interestRate = interest; // assign the value to interestRate
	}

	Account::updateDate(U_Date); //updates the last update date
} // end setInterestRate function


// add interest to account balance and display information
void SavingsAccount::addInterest(Date& U_Date)
{
	Account::updateDate(U_Date); //updates the last update date

	cout << endl;
	cout << getFirstName() << ' ' << getFirstName() << endl;
	
	cout << "Balance " << getBalance() << ' ' << "Interest Rate " << interestRate << endl
			<< "Interest $" << calculateInterest() << "added to into balance." << endl;
		
	setBalance(getBalance() + calculateInterest());// add the interest account balance
	cout << "The new balance is $" << getBalance() << endl;
				
}// end addInterest function

// get interest
double SavingsAccount::calculateInterest()
{
	return interestRate * getBalance(); // return interest
}// end calculateInterest function


// override virtual function print in Account
void SavingsAccount::print() const
{
	cout << "Savings Account:" << endl;
	Account::print();// invoke print in Account
	cout << "Interest Rate: " << interestRate << endl;
}// end print function
