#ifndef DECRYPT_H
#define DECRYPT_H

class Decrypt
{
public:
	Decrypt(int);
	Decrypt(int const*);
	void storeData(int);
	void displayOriginalData() const;
	void displayDecryptedData() const;
	int getDecryptedData() const;

private:
	int digits[8];
};

#endif // !DECRYPT_H