#include "Decrypt.h"
#include <iostream>
using namespace std;

Decrypt::Decrypt(int num)
{
	cout << "\n*D* The Decrypt constructor is called\n"
		<< "   and the passed in number is " << num << ".**\n\n";

	storeData(num);
	displayOriginalData();
	displayDecryptedData();
}

Decrypt::Decrypt(int const* arrPtr)
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

	cout << "\n*D* The Decrypt array constructor is called\n"
		<< "   and the passed in number is " << num << ".**\n\n";

	storeData(num / 10000);
	displayOriginalData();
	displayDecryptedData();

}




void Decrypt::storeData(int number)
{
	if (number <= 0)
	{
		cout << "  XXXXX The inputted number is less than or equal to 0.\n"
			<< "     The number is reset to 1234. XXXXX\n";
		number = 1234;
	}

	int temp;
	for (int i = 3; i >= 0; i--)
	{
		temp = number % 10;
		number /= 10;
		digits[i] = temp;
		digits[i + 4] = (digits[i] + 13) % 10;
	}

	swap(digits[4], digits[6]);
	swap(digits[5], digits[7]);
}

void Decrypt::displayOriginalData() const
{
	cout << "\n     The original data is ";
	for (int i = 0; i < 4; i++)
		cout << ' ' << digits[i];
	cout << ".\n";
}

void Decrypt::displayDecryptedData() const
{
	cout << "     The encrypted data is ";
	for (int i = 4; i < 8; i++)
		cout << ' ' << digits[i];
	cout << ".\n\n";
}

int Decrypt::getDecryptedData() const
{
	int number = 0;
	for (int i = 4; i < 8; i++)
		number = number * 10 + digits[i];

	return number;
}