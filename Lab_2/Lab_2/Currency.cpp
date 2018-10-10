#include"Currency.h"
#include<iostream>
using namespace std;

//Constructor
Currency::Currency(int wn, int fn)
{
	Wnum = wn;
	Fnum = fn;
}

//Output stream overloading 
ostream &operator << (ostream &strm, const Currency &obj)
{
	strm << obj.getWname() << " " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
	return strm;
}

// Operator Overloading

//Compares two currency objects to know which one is the smallest
bool Currency::operator<(const Currency& other)
{
	if (this->getWnum() <= other.getWnum()) 
	{
		if (this->getWnum() == other.getWnum())
		{
			if (this->getFnum() < other.getFnum())
				return true;
			else
				return false;
		}
		return true;
	}
	else
		return false;

}

//Compares two currency objects to know which one is the biggest
bool Currency::operator>(const Currency& other)
{
	if (this->getWnum() >= other.getWnum())
	{
		if (this->getWnum() == other.getWnum())
		{
			if (this->getFnum() > other.getFnum())
				return true;
			else
				return false;
		}
		return true;
	}
	else
		return false;
}

//Check if two currency objects are the same. If they are the same return true, else false
bool Currency::operator==(const Currency& other)
{
	if ((this->getWnum() == other.getWnum()) && (this->getFnum() == other.getFnum()))
		return true;
	else
		return false;
}

//Operator overloading for assignment 
Currency&Currency::operator=(const Currency &obj)
{
	//Do the copy
	Wnum = obj.getWnum();
	Fnum = obj.getFnum();

	//Return the existing object
	return *this;
}
