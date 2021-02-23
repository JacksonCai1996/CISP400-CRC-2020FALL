#ifndef ENCRYPT_H
#define ENCRYPT_H

class Encrypt
{
public:
	Encrypt(int);
	Encrypt( int const*);
	void storeData(int);
	void displayOriginalData() const;
	void displayEncryptedData() const;
	int getEncryptedData() const;

private:
	int digits[8];
};

#endif // !ENCRYPT_H