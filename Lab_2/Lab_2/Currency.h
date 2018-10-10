#ifndef _CURRENCY_
#define _CURRENCY_
#include<string>
#include<iostream>
using namespace std;

class Currency
{
private:

	//Attributes of the Currencies
	const string Wname = "Dollar";
	int Wnum;
	int Fnum;
	const string Fname = "cents";

public:
	//Constructors
	Currency(int, int);
	Currency(){ Wnum = 0; Fnum = 0; } //Default Constructor

	//Mutators
	void setWnum(int w){ Wnum = w; };
	void setFnum(int fr){ Fnum = fr; };

	//Accesors 
	string getWname() const
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
	bool operator<(const Currency& other);
	bool operator>(const Currency& other);
	bool operator==(const Currency& other);
	Currency& operator=(const Currency &);

	// Friends (Output operator overloading)
	friend ostream &operator << (ostream &, const Currency &);
};
#endif