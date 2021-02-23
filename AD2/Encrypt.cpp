#include "Encrypt.h"
#include <iostream>
using namespace std;

Encrypt::Encrypt(int num)
{
	cout << "\n*E* The Encrypt constructor is called\n"
		<< "   and the passed in number is " << num << ".**\n\n";

	storeData(num);
	displayOriginalData();
	displayEncryptedData();
}

Encrypt::Encrypt(int const *arrPtr)
{
	int num = 0;

	if (*arrPtr <= 0)
	{
		num = arrPtr[0];
		for (int i = 1; i < 8; i++)
			num = num * 10 - arrPtr[i];
	}
	else
		for (int i = 0; i < 8; i++)
			num = num * 10 + arrPtr[i];

	cout << "\n*E* The Encrypt array constructor is called\n"
		<< "   and the passed in number is " << num << ".**\n\n";

	storeData(num / 10000);
	displayOriginalData();
	displayEncryptedData();

}


void Encrypt::storeData(int number)
{
	if (number <= 0)
	{
		cout << "  XXXXX The inputted number is less than or equal to 0.\n"
			<< "     The number is reset to 9436. XXXXX\n";
		number = 9436;
	}
	
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
		cout << ' ' << digits[i];
	cout << ".\n\n";
}

int Encrypt::getEncryptedData() const
{
	int number = 0;
	for (int i = 4; i < 8; i++)
		number = number * 10 + digits[i];

	return number;
}