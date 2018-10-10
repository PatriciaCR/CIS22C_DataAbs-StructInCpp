#include"Currency.h"
#include<iostream>
using namespace std;

//Constructor
Currency::Currency(Currencies wna, int wn, int fn, string fna)
{
	Wname = wna;
	Wnum = wn;
	Fnum = fn;
	Fname = fna;
}

//Operator overloading for addition
Currency operator + (const Currency &arr, const Currency & obj)
{
	Currency temp;

	temp.setWname(arr.getWname());
	temp.setFname(arr.getFname());
	temp.setWnum(arr.getWnum() + obj.getWnum()); //Set the whole value of the number
	int sum = arr.getFnum() + obj.getFnum(); //Add the fractional part of the number entered by the user with the one that already existed in the array

	//If the fractional part is more than 100 then substract 100 and set that result in the fractional part of the number, then add 1 to the whole part 
	if (sum >= 100)
	{
		sum = sum - 100;
		temp.setFnum(sum);
		temp.setWnum(temp.getWnum() + 1);
	}

	//If the addition of the fractional part that existed in the array and the one entered by the user is less than 100 set that value in the fractional part of the number.
	else
		temp.setFnum(sum);


	return temp;
}

//Operator overloading for substraction
Currency operator - (const Currency &arr, const Currency & obj)
{
	Currency temp;

	temp.setWname(arr.getWname());
	temp.setFname(arr.getFname());

	//If the substraction of the whole and the fractional part that existed in the array and the one entered by the user is less than 0, tell the user that 
	//it is not posible to substract the number he wanted, because that will make the result of the substraction negative.
	if ((arr.getWnum() - obj.getWnum() < 0) && (arr.getFnum() - obj.getFnum()<0))
	{
		temp.setWnum(arr.getWnum());
		temp.setFnum(arr.getFnum());
		cout << " You cannot substract this amount of money from this currency, It will make the result negative\n\n";
	}


	else
	{
		temp.setWnum(arr.getWnum() - obj.getWnum()); //Substract the whole part of the number (the result will not be negative)
		int res = arr.getFnum() - obj.getFnum();

		//If the result of the substraction of the fractional part is less than 0 then add 100, set that result in the fractional part and substract 1 of the whole part.
		if (res < 0)
		{
			res = 100 + res;
			temp.setFnum(res);
			temp.setWnum(temp.getWnum() - 1);
		}

		//If the result is greater than 0 set that value to the fractional part
		else
			temp.setFnum(res);
	}

	return temp;
}

//Operator overloading for assignment 
Currency&Currency::operator=(const Currency &obj)
{
	//Do the copy
	Wname = obj.getWname();
	Wnum = obj.getWnum();
	Fnum = obj.getFnum();
	Fname = obj.getFname();

	//Return the existing object
	return *this;
}
//Output stream overloading 
ostream &operator << (ostream &strm, const Currency &obj)
{
	switch (obj.getWname())
	{
	case DOLLAR:
		strm << " Dollar " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case BOLIVAR:
		strm << " Bolivar " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case YEN:
		strm << " Yen " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case FRANC:
		strm << " Franc " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case PESO:
		strm << " Peso " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case RUPEE:
		strm << " Rupee " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case POUND:
		strm << " Pound " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case REAL:
		strm << " Real " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case EURO:
		strm << " Euro " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	case RUBLE:
		strm << " Ruble " << obj.getWnum() << "," << obj.getFnum() << " " << obj.getFname();
		break;
	}
	return strm;
}

