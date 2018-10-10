#include"Wallet.h"
#include"Currency.h"
#include "Interface.h"
#include<cstdlib>
#include<ctime>

Wallet::~Wallet()
{
	// Deallocate the memory that was previouly reserved for this class
	if (Money)
		delete[] Money;
}
Wallet::Wallet()
{
	// Seed the random number generator.
	srand(time(0));  
	
	//Creates a dynamically allocated array
	Money = new Currency[CAPACITY];

	//Initialize the fractional name for each one of the currencies.
	for (int i = 0; i < 10; i++)
	{
		Currency obj(static_cast<Currencies>(i), 0, 0, " ");
		Money[i] = obj;
		switch (i)
		{
		case DOLLAR:
			Money[DOLLAR].setFname("cents");
			break;
		case BOLIVAR:
			Money[BOLIVAR].setFname("centimos");
			break;
		case YEN:
			Money[YEN].setFname("sen");
			break;
		case FRANC:
			Money[FRANC].setFname("centime");
			break;
		case PESO:
			Money[PESO].setFname("centavos");
			break;
		case RUPEE:
			Money[RUPEE].setFname("pais");
			break;
		case POUND:
			Money[POUND].setFname("penny");
			break;
		case REAL:
			Money[REAL].setFname("centavo");
			break;
		case EURO:
			Money[EURO].setFname("cent");
			break;
		case RUBLE:
			Money[RUBLE].setFname("kopek");
			break;
		}
		used = i + 1;
	}
}
void Wallet::add(int choice, int manran,int Wval,int Frac) //Add money to the wallet by currency (Let the user chose how to add the number: manually or by the random number generator)
{
	Currency obj1; //Creates a currency object that will hold the random numbers or the numbers entered by the user 
	
	
	if (manran == 1)//Add a currency manually
	{
		obj1.setWnum(Wval);
		obj1.setFnum(Frac);

		cout << "\n Adding " << obj1.getWnum() << "," << obj1.getFnum() << " . . . \n\n";
		
		//Add the value that was in the array and the one that the user entered.
		Money[choice] = Money[choice] + obj1;
	}

	if (manran == 2) //Add a currency with the random number generator 
	{
		
		//Get a random number, from 0 to 99 for the whole and fractional value 
		obj1.setWnum((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);
		obj1.setFnum((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);
		
		cout << "\n Adding " << obj1.getWnum() << "," << obj1.getFnum() << " . . . \n\n"; //So the user will know how much he/she is adding to the wallet
		
		//Add the value that was in the array and the random numbers 
		Money[choice] = Money[choice] + obj1;
	}
}


void Wallet::remove(int choice, int manran, int Wval, int Frac) //Remove money from the wallet by currency
{
	Currency obj1; //Creates a currency object that will hold the random numbers or the numbers entered by the user 
	
	
	if (manran == 1) //Manually option
	{
		obj1.setWnum(Wval);
		obj1.setFnum(Frac);

		cout << " Removing " << obj1.getWnum() << "," << obj1.getFnum() << " . . . \n";

		//If the number entered by the user is more than what he/she has in the wallet tell the user he cannot remove that amount 
		if ((Money[choice].getWnum() >= obj1.getWnum()) && (Money[choice].getFnum()>=obj1.getFnum()))
			//Substract the value that was in the array and the one that the user entered.
			Money[choice] = Money[choice] - obj1;
		else
			cout << "\n There is not enough money in the wallet to remove that amount. You only have: " << Money[choice].getWnum() << "," << Money[choice].getFnum()<<endl;
	}

	if (manran == 2) //Random number generator option
	{

		//Get a random number, from 0 to 99 for the whole and fractional value 
		obj1.setWnum((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);
		obj1.setFnum((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);

		cout << " Removing " << obj1.getWnum()<<","<<obj1.getFnum()<<" . . . \n"; //So the user will know how much he/she is removing from the wallet 

		//If the number entered by the user is more than what he/she has in the wallet tell the user he cannot remove that amount 
		if ((Money[choice].getWnum() >= obj1.getWnum()) && (Money[choice].getFnum()>obj1.getFnum()))
			//Substract the value that was in the array and the random numbers
			Money[choice] = Money[choice] - obj1;
		else
			cout << "\n There is not enough money in the wallet to remove that amount. You only have: " << Money[choice].getWnum() << "," << Money[choice].getFnum()<<endl;
	}
}

void Wallet::clear(int s,int preference,int specific)
{
	Currency obj1; //Creates a currency object that will hold the random numbers or the numbers entered by the user 

	//If the user wants to exit the program erase all the currencies (Set to the values of the default constructor)		
	if (s == 5)
		{
			for (int i = 0; i < CAPACITY; i++)
			{
				Currency obj;
				Money[i] = obj;
			}
		}

	//If the user wants to erase some or all of the currencies...
	if (s == 3)
		{
			if (preference == 1) //The user wants to delete just one of the currencies
			{
				//Check if the currency exists in the wallet, if the currency exists set it to the values of the default constructor else tell the user that the currency does not exist
				if (checkE(specific) == true)
				{
					for (int i = 0; i < CAPACITY; i++)
					{
						if (Money[i].getWname() == specific)
						{
							Currency obj;
							Money[i] = obj;
							used--;
							cout << "\n\n\n\t\t*** The Currency that you selected has been erased***\n\n";
						}
					}
				}
				else
					cout << "\n\n That currency does not exist inside the Wallet";
			}


			else // The user wants to delete all the currencies (set each of the currencies to the default values: default constructor)
			{
				for (int i = 0; i < CAPACITY; i++)
				{
					Currency obj;
					Money[i] = obj;
				}
			}
		
		}
}

int Wallet::numberofc() const //Returns how many currencies are in the wallet 
{
	//Goes through the array and counts the currencies that exist in the wallet ignoring the ones that have the default values
	for (int i = 0; i < 10; i++)
	{
		if (Money[i].getWname() == DEFAULT)
		{
			continue;
		}
		(used + 1);
	}

	//Return the number of currencies.
	return used;
}
bool Wallet::checkempty(int) const //Check if the wallet is empty
{
	bool fb;
	//Goes through the array and checks if the values of the currencies are set to the default values. If it founds a currency with valid values (not default) the wallet is not empty
	for (int i = 0; i<CAPACITY; i++)
	{
		if ((Money[i].getWname() == DEFAULT) && (Money[i].getWnum() == 0) && (Money[i].getFnum() == 0) && (Money[i].getFname() == " "))
			fb = true;
		else
		{
			fb = false;
			return fb;
		}

	}
	return fb;
}

bool Wallet::checkE(const int & target)const //Check if an specific currency is in the wallet
{
	bool bf;
	Currencies coin = static_cast<Currencies> (target); 

	//Goes through the array and compares the whole name of the array and the target to see if they are equal. If they are equal return true 
	for (int i = 0; i<CAPACITY; i++)
	{
		if (Money[i].getWname() == coin)
		{
			bf = true;
			return bf;
		}
		else //Else the currency does not exist in the array
			bf = false;
	}
	return bf;
}

void Wallet::print() //Print all the currencies
{
	system("pause");
	system("CLS");

	cout << string(60, '=') << endl << endl;
	cout << "\t\t\t MY WALLET\n\n";
	cout << "\t\t     List of Currencies\n\n";
	cout << string(60, '=') << endl << endl;

	int m = 0;
	//Goes through the array and shows the currencies that are in the wallet.
	for (int i = 0; i < CAPACITY; i++)
	{
		if ((Money[i].getWname()!=DEFAULT)||(Money[i].getWnum() != 0) || (Money[i].getFnum() != 0))
		{
			cout << " " << m + 1 << ") " << Money[i]; //Output operator overloaded
			cout << endl << endl << string(60, '-') << endl << endl;
			m++;
		}
	}
	if (m == 0) //If the wallet is empty tell the user 
		cout << " The Wallet is empty!!!...\n\n";

	system("pause");
	system("CLS");
}



