#ifndef _WALLET_
#define _WALLET_
#include"Currency.h"
#include"Interface.h"


class Wallet : public Interface
{
private:
	int used;//Integer data type that holds how much of the array is used
	static const int CAPACITY = 10; //Capacity is the maximum number of currencies that the wallet can hold
	Currency * Money;  //Dinamically allocated array to store currencies

	//Minimum and maximum value for the random number 
	const int MIN_VALUE = 0;
	const int MAX_VALUE = 99;
	
public:
	Wallet();
	~Wallet();
	int numberofc()const; //Returns how many currencies are in the wallet 
	void add(int,int,int,int); //Add money to the wallet by currency
	void remove(int,int,int,int); //Remove money to the wallet by currency
	void clear(int,int,int); //Erase all or one of the currencies from the wallet
	bool checkempty(int) const; //Check if the wallet is empty
	bool checkE(const int& target)const; //Check if an specific currency is in the wallet
	void print();
};
#endif