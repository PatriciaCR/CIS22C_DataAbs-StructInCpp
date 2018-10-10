#ifndef _CURRENCY_
#define _CURRENCY_
#include<string>
#include<iostream>
using namespace std;

enum Currencies //Enumerator for the different currencies that the wallet will hold
{
	DOLLAR,
	BOLIVAR,
	YEN,
	FRANC,
	PESO,
	RUPEE,
	POUND,
	REAL,
	EURO,
	RUBLE,
	DEFAULT //Just to initialize 
};

class Currency
{
private:

	//Attributes of the Currencies
	Currencies Wname;
	int Wnum;
	int Fnum;
	string Fname;

public:
	//Constructors
	Currency(Currencies, int, int, string);
	Currency(){ Wname = DEFAULT; Wnum = 0; Fnum = 0; Fname = " "; } //Default Constructor

	//Mutators
	void setWname(Currencies c){ Wname = c; };
	void setWnum(int w){ Wnum = w; };
	void setFnum(int fr){ Fnum = fr; };
	void setFname(string f){ Fname = f; };

	//Accesors 
	Currencies getWname() const
	{
		return Wname;
	}
	int getWnum() const
	{
		return Wnum;
	}
	int getFnum() const
	{
		return Fnum;
	}
	string getFname() const
	{
		return Fname;
	}

	// Overloaded operator functions
	friend Currency operator + (const Currency &, const Currency &); // Overloaded +
	friend Currency operator - (const Currency &, const Currency &); // Overloaded −
	Currency& operator=(const Currency &);
	// Friends (Output operator overloading)
	friend ostream &operator << (ostream &, const Currency &);
};
#endif