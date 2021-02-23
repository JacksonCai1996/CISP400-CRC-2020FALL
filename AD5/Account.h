#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Date.h"
#include <string>
using namespace std;

class Account
{
private:
	string firstName; // customer's first name
	string lastName; // customer's last name
	double accountBalance;  // customer's account balance
	Date startingDate;   // date for customer opening account 
	Date lastUpdateDate; // date for customer opening account 

public:
	// constructor initialization
	Account(double, string, string, Date&, Date&);

	void setFirstName(string);
	void setLastName(string);
	void setBalance(double);
	
	string getFirstName() const;
	string getLastName() const;
	double getBalance() const; // return account balance
	
	void updateDate(Date&);  // change the updating date;

	void credit(double, Date&); // add an amount to the current balance.

	virtual void debit(double, Date&);//withdraw money from the account balance

	virtual void print() const; // displays customer’s information

};

#endif // !ACCOUNT_H