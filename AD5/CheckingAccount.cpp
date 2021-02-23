#include "CheckingAccount.h"
#include <iostream>
using namespace std;

// constructor
CheckingAccount::CheckingAccount(double balance, double fee, 
	string first, string last,  Date& sDate, Date& uDate )
	:Account(balance, first, last, sDate, uDate)// initialize constructor of Account
{
	// validate if fee is < 0.0
	if (fee <= 0)
	{
		transactionFee = 0.0; // set transactionFee to 0.0
		Account::print();// print customer’s information
		cout << "\nTransaction Fee: " << transactionFee;
	}

	else
	{
		transactionFee = fee; // initialize interest
	}
}// end constructor


// set transactional fee and update the date
void CheckingAccount::setTransactionFee(double fee, Date& U_Date)
{
	// validate if fee is < 0.0
	if (fee <= 0)
	{
		transactionFee = 0.0; // set transactionFee to 0.0
		Account::print();// print customer’s information
	}
		
	else
	{
		transactionFee = fee;// assign the value to interestRate
		
	}
	
	Account::updateDate(U_Date); //updates the last update date	
}// end setTransactionFee function


// subtracts fee from the account balance
// displays the fee charge information
void CheckingAccount::chargeFee(Date& U_Date)
{
	cout << endl;
	cout << Account::getFirstName() << ' ' << Account::getLastName() << endl;
	cout << "$" << transactionFee << " transaction fee charged" << endl;

	Account::setBalance(getBalance() - transactionFee); // subtracts fee from accountBalance
	Account::updateDate(U_Date); //updates the last update date

}// end chargeFee function

// override virtual function print in Account
void CheckingAccount::print() const
{
	cout << "Checking Account:" << endl;
	Account::print();// invoke print in Account
	cout << "Transaction Fee: $" << transactionFee << endl;
}// end print function


// override virtual function debit in Account
void CheckingAccount::debit(double debit, Date& U_Date)
{
	if (Account::getBalance() < debit)
	{
		Account::debit(debit, U_Date); // invoke debit in Account 
	}
	else 
	{
		Account::setBalance(Account::getBalance() - debit) ; // subtract the amount from current balance
		chargeFee(U_Date); // call function chargeFee
	}
		
	
}// end debit function





