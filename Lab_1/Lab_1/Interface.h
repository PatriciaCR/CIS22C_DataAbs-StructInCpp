#ifndef _INTERFACE_
#define _INTERFACE_

class Interface
{
	public:
		Interface(){}
		virtual ~Interface(){}
		virtual int numberofc()const=0; //Returns how many currencies are in the wallet 
		virtual void add(int, int, int, int) = 0; //Add money to the wallet by currency
		virtual void remove(int, int, int, int) = 0; //Remove money to the wallet by currency
		virtual void clear(int, int, int) = 0; //Erase all or one of the currencies from the wallet
		virtual bool checkempty(int) const = 0; //Check if the wallet is empty
		virtual bool checkE(const int& target)const = 0; //Check if an specific currency is in the wallet
		virtual void print() = 0;
};
#endif