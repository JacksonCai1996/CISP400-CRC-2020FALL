#include "Encrypt.h"
#include <iostream>
using namespace std;

Encrypt::Encrypt(int num)
{
	cout << "\n\n** The default constructor is called\n"
		<< "   and the passed in number is " << num << ".**\n\n";
	if (num <= 0)
	{
		cout << " XXX The inputted number is less than or equal to 0.\n"
			<< "     The number is reset to 9436. XXX\n";
		num = 9436;
	}

	storeData(num);
	displayOriginalData();
	displayEncryptedData();
}


void Encrypt::storeData(int number)
{
	int temp;
	for (int i = 3; i >= 0; i--)
	{
		temp = number % 10;
		number /= 10;
		digits[i] = temp;
		digits[i + 4] = (digits[i] + 7) % 10;
	}

	swap(digits[4], digits[6]);
	swap(digits[5], digits[7]);
}

void Encrypt::displayOriginalData() const
{
	cout << "\n     The original data is ";
	for (int i = 0; i < 4; i++)
		cout << ' ' << digits[i];
	cout << ".\n";
}

void Encrypt::displayEncryptedData() const
{
	cout << "     The encrypted data is ";
	for (int i = 4; i < 8; i++)
		cout << ' '  << digits[i] ;
	cout << ".\n";
}