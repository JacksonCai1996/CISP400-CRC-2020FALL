#ifndef ENCRYPT_H
#define ENCRYPT_H


class Encrypt
{
public:
	Encrypt(int);// constructor
	void storeData(int); // stores  eight elements into the array
	void displayOriginalData() const; // display first four elements of the array
	void displayEncryptedData() const; // display last four elements of the array

private:
	int digits[8]; // array that stores original data and encrypted data

};

#endif // !ENCRYPT-H