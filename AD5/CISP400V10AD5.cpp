// Jianan Cai
// CISP400
// Processing Account derived-class objects individually 
// and polymorphically using dynamic binding.
#include <iostream>
#include "Account.h"
#include "Date.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iomanip>
using namespace std;

int main()
{

	// Create Date object for each derive-class object
   //  Date object for opening date;   Date object for updating date
	Date date0_S(1, 1, 2015);       Date date0_U(2, 19, 2016);
	Date date1_S(2, 29, 2017);      Date date1_U(3, 19, 2017);
	Date date2_S(5, 31, 2016);      Date date2_U(2, 14, 2017);
	Date date3_S(6, 6, 2016);       Date date3_U(1, 12, 2017);
	Date date4_S(11, 30, 2016);     Date date4_U(2, 24, 2017);
	Date date5_S(2, 27, 2017);      Date date5_U(3, 19, 2017);
	Date date6_S(11, 19, 2016);     Date date6_U(1, 19, 2017);
	Date date7_S(7, 32, 2016);      Date date7_U(7, 32, 2016);
	Date date8_S(10, 10, 2016);     Date date8_U(2, 6, 2017);
	Date date9_S(11, 16, 2016);     Date date9_U(2, 4, 2017);
	

	// create derived-class objects
	SavingsAccount savingsAccount0(25.0, .03, "Susan", "Baker", date0_S, date0_U);
	CheckingAccount checkingAccount1(80.0, 1.0, "Robert", "Jones", date1_S, date1_U);
	SavingsAccount savingsAccount2(100, .04, "Chao", "Zulueta", date2_S, date2_U);
	CheckingAccount checkingAccount3(250.0, 2.0, "Kenneth", "Ramirez", date3_S, date3_U);
	SavingsAccount savingsAccount4(125, .02, "Vue", "Thomas", date4_S, date4_U);
	CheckingAccount checkingAccount5(180.0, 3.0, "Angela", "Wilma", date5_S, date5_U);
	SavingsAccount savingsAccount6(600, .04, "Romeo", "Turner", date6_S, date6_U);
	CheckingAccount checkingAccount7(255.0, 3.0, "Jimmy ", "Untalasco", date7_S, date7_U);
	SavingsAccount savingsAccount8(95, .02, "Oscar ", "Udonkanga", date8_S, date8_U);
	CheckingAccount checkingAccount9(80.0, 1.0, "Terrence", "Trocino", date9_S, date9_U);
	
	
	// set floating-point output formatting
	cout << setprecision(2) << fixed;
	
	
	// create array of ten Account pointers
	// and assignment the adress of each derived-class objects
	Account* account[10];
	account[0] = &savingsAccount0;
	account[1] = &checkingAccount1;
	account[2] = &savingsAccount2;
	account[3] = &checkingAccount3;
	account[4] = &savingsAccount4;
	account[5] = &checkingAccount5;
	account[6] = &savingsAccount6;
	account[7] = &checkingAccount7;
	account[8] = &savingsAccount8;
	account[9] = &checkingAccount9;

	
	// display initial Accounts information
	cout << "\n\n***Initial Accounts information***\n\n";
	
	// polymorphically process each element in array account
	for (int i = 0; i < 10; i++)
	{
		account[i]->print(); // output account information
		cout << endl;
	}
	
	
	// display updating information
	cout << "\nOn 3/25/2017 accounts adjusted based on the following schedule:\n";

	// updat each account information
	cout << "1. Susan Baker had a $40 debit.\n"
		<< "2. Robert Jones had a $40 debit.\n"
		<< "3. Chao Zulueta had a $30 credit.\n"
		<< "4. Kenneth Ramirez had a $50 credit.\n"
		<< "5. Vue Thomas had a accruled interest for a period.\n"
		<< "6. Angela Wilma had a transaction fee charge.\n"
		<< "7. Romeo Turner had a accruled interest for a period.\n"
		<< "8. Jimmy  Untalasco had a transaction fee charge.\n"
		<< "9. Oscar Udonkanga had a $60 debit.\n"
		<< "10. Trocino Terrence had a $100 debit.\n";
	
	
	// create a Data object to update the last changing date
	Date lastUpdate(3, 25, 2017);
	
	savingsAccount0.debit(40, lastUpdate);// call the debit function and change the date
	
	checkingAccount1.debit(40, lastUpdate);// call the debit function and change the date
	
	savingsAccount2.credit(30, lastUpdate);// call the credit function and change the date

	checkingAccount3.credit(50, lastUpdate);// call the credit function and change the date

	savingsAccount4.addInterest(lastUpdate);// call the addInterest function and change the date
	
	checkingAccount5.chargeFee(lastUpdate);// call the chargeFee function and change the date

	savingsAccount6.addInterest(lastUpdate); // call the addInterest function and change the date

	checkingAccount7.chargeFee(lastUpdate);// call the chargeFee function and change the date

	savingsAccount8.debit(60, lastUpdate);// call the debit function and change the date

	checkingAccount9.debit(100, lastUpdate);// call the debit function and change the date


	// display updating information
	cout << "\n\n***After the 3 / 25 / 2017 update, the Accounts information*** \n\n";
	
	// polymorphically process each element in array account
	for (int i = 0; i < 10; i++)
	{
		account[i]->print(); // output account information
		cout << endl;
	}
	
	
	// display updating information
	cout << "\nOn 4/8/2017 all the saving used the same interest rate(0.05) and\n"
		<< "all the checking used the same transaction fee($5)\n";
	cout << "\n\n***After the 4/8/2017 update, the Accounts information***\n\n";

	// create a Data object to update the last changing date
	Date U_Date(4, 8, 2017);
	
	savingsAccount0.setInterestRate(0.05, U_Date); // set interest rate to 0.05 and change the date
	checkingAccount1.setTransactionFee(5, U_Date);// set transactional fee to 5 and change the date
	savingsAccount2.setInterestRate(0.05, U_Date);// set interest rate to 0.05 and change the date
	checkingAccount3.setTransactionFee(5, U_Date);// set transactional fee to 5 and change the date
	savingsAccount4.setInterestRate(0.05, U_Date);// set interest rate to 0.05 and change the date
	checkingAccount5.setTransactionFee(5, U_Date);// set transactional fee to 5 and change the date
	savingsAccount6.setInterestRate(0.05, U_Date);// set interest rate to 0.05 and change the date
	checkingAccount7.setTransactionFee(5, U_Date);// set transactional fee to 5 and change the date
	savingsAccount8.setInterestRate(0.05, U_Date);// set interest rate to 0.05 and change the date
	checkingAccount9.setTransactionFee(5, U_Date);// set transactional fee to 5 and change the date

	// polymorphically process each element in array account
	for (int i = 0; i < 10; i++)
	{
		account[i]->print(); // output account information
		cout << endl;
	}

	return 0;
}