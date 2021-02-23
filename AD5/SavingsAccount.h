#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"
#include <string>// C++ standard string class
using namespace std;

// SavingsAccount class derived from Account class
class SavingsAccount : public Account
{
private:
	double interestRate; // customer's interest rate

public:
	SavingsAccount(double, double, string, string, Date&, Date&); // constructor initialization

	void setInterestRate(double, Date&); // set interest rate

	void addInterest(Date&);// add interest rate to account balance

	double calculateInterest(); // calculate interest rate

	virtual void print() const;// override function print in Account
};

#endif // !SAVINGS_H