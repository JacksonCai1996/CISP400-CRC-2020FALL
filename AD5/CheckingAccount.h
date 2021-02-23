#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include "Account.h"
using namespace std;

// CheckingAccount class derived from Account class
class CheckingAccount : public Account
{
private:
	double transactionFee; // customer's transactional fee
public:
	CheckingAccount(double, double, string, string, Date&, Date& );// constructor initialization

	void chargeFee(Date&); // subtracts fee from the account balance

	void setTransactionFee(double, Date&); // set transactional fee

	void print() const; // override print function in Account


	virtual void debit(double, Date& U_Date); // override debit function in Account
};

#endif // !CHECKINGACCOUNT_H