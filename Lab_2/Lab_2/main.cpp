/***********************************************************************************************/
/* De Anza College, Fall 2015. CIS 22C                                                         */
/*                                                                                             */
/* Lab 2:  This program demonstrates the capabilities of a Link-based Stack of different data  */
/* types(int,doubles,string,currency objects). The operations that we implemented for the      */
/* Stack are push, pop, isempty, size and print.                                               */
/*                                                                                             */
/* Team: Calvin Rong, Jason Do, Patricia Caceres.                                              */
/***********************************************************************************************/


#include<iostream>
#include<string>
#include"Stack.h"
#include"Currency.h"
using namespace std;

int mainmenu();
void integerStack(); //Function to create an integer stack
void doubleStack(); //Function to create a double stack
void stringStack(); //Function to create a string stack
void currencyStack(); //Function to create a currency stack 

int main()
{
	int choice;
	do
	{
		choice = mainmenu(); //Call the main menu function which returns the choice the user selects from that menu.

		switch (choice)//Redirects the user to the function of its choice 
		{
		case 1://Integer Stack
			integerStack();
			break;
		case 2://Double Stack 
			doubleStack();
			break;
		case 3://String Stack
			stringStack();
			break;
		case 4://Currency Stack 
			currencyStack();
			break;
		}

	} while (choice != 5);
	cout << endl << endl;
	system("pause");
	return 0;
}

int mainmenu() //Main menu 
{
	int choice;

	//Ask the user which type of stack he wants to try 
	cout << string(60, '=') << endl << endl;
	cout << "\t\t    Link-based Stack ADT" << endl << endl;
	cout << " This program demonstrates the capabilities of a Link-based\n Stack of different data types (int,doubles,string, and\n currency objects)\n\n";
	cout << string(60, '=') << endl << endl;
	cout << "\t1) Integer Stack" << endl;
	cout << "\t2) Double Stack" << endl;
	cout << "\t3) String Stack" << endl;
	cout << "\t4) Currency Stack" << endl;
	cout << "\t5) Exit the program" << endl << endl;
	cout << string(60, '=') << endl << endl;


	cout << " Please insert the number of the Stack that you would like\n to try: ";
	cin >> choice;
	
	while (choice < 1 || choice > 5)
	{
		cout << "\n You did not insert a correct value for your choice.\n Please, try again..." << endl << endl;
		cout << string(60, '-') << endl << endl;
		cout << " Please insert the number of the Stack that you would like\n to try: ";
		cin >> choice;
	}
	return choice;
}

void integerStack()
{
	cout << endl;
	system("pause");
	system("CLS");
	cout << string(60, '=') << endl << endl;
	cout << "\t\t    Link-based Stack ADT" << endl << "\t\t\tInteger Stack\n\n";
	cout << string(60, '=') << endl << endl;

	Stack< int > intStack; // create Stack of ints
	cout << " Processing an integer Stack..." << endl << endl;
	cout << " The size of the Stack is " << intStack.size() << endl << endl;

	// push integers onto intStack
	for (int i = 0; i < 7; i++)
	{
		intStack.push(i);
		intStack.printStack();
	} // end for

	cout << "\n The new size of the Stack is " << intStack.size() << endl << endl;
	cout << string(60, '-') << endl << endl;

	int popInteger; // store int popped from stack

	// pop integers from intStack
	while (!intStack.isStackEmpty())
	{
		intStack.pop(popInteger);
		cout << " " << popInteger << " popped from stack" << endl;
		intStack.printStack();
	} // end while
	cout << string(60, '=') << endl << endl;
	cout << " Returning to Main menu" << endl << endl;
	system("pause");
	system("CLS");
}

void doubleStack()
{
	cout << endl;
	system("pause");
	system("CLS");
	cout << string(60, '=') << endl << endl;
	cout << "\t\t    Link-based Stack ADT" << endl << "\t\t\tDouble Stack\n\n";
	cout << string(60, '=') << endl << endl;
	Stack< double > doubleStack; // create Stack of doubles
	double value = 1.1;

	cout << " Processing a double Stack" << endl << endl;
	cout << " The size of the Stack is " << doubleStack.size() << endl << endl;


	// push floating-point values onto doubleStack
	for (int j = 0; j < 5; j++)
	{
		doubleStack.push(value);
		doubleStack.printStack();
		value += 1.1;
	} // end for

	cout << "\n The new size of the Stack is " << doubleStack.size() << endl << endl;
	cout << string(60, '-') << endl << endl;

	double popDouble; // store double popped from stack

	// pop floating-point values from doubleStack
	while (!doubleStack.isStackEmpty())
	{
		doubleStack.pop(popDouble);
		cout << " " << popDouble << " popped from stack" << endl;
		doubleStack.printStack();
	} // end while

	cout << string(60, '=') << endl << endl;
	cout << " Returning to Main menu" << endl << endl;
	system("pause");
	system("CLS");
}

void stringStack()
{
	cout << endl;
	system("pause");
	system("CLS");
	cout << string(60, '=') << endl << endl;
	cout << "\t\t    Link-based Stack ADT" << endl << "\t\t\tString Stack\n\n";
	cout << string(60, '=') << endl << endl;

	Stack< string > strngStack; // create Stack of strings
	cout << " Processing a string Stack" << endl << endl;
	cout << " The size of the Stack is " << strngStack.size() << endl << endl;

	// push strings onto intStack
	strngStack.push("Horse");
	strngStack.printStack();

	strngStack.push("House");
	strngStack.printStack();

	strngStack.push("Boy");
	strngStack.printStack();

	strngStack.push("Girl");
	strngStack.printStack();

	strngStack.push("Human");
	strngStack.printStack();

	cout << "\n The new size of the Stack is " << strngStack.size() << endl << endl;

	cout << string(60, '-') << endl << endl;

	string popstrng; // store string popped from stack

	// pop strings from intStack and print
	while (!strngStack.isStackEmpty())
	{
		strngStack.pop(popstrng);
		cout << " " << popstrng << " popped from stack" << endl;
		strngStack.printStack();
	} // end while
	cout << string(60, '=') << endl << endl;

	cout << " Returning to Main menu" << endl << endl;
	system("pause");
	system("CLS");

}

void currencyStack()
{
	cout << endl;
	system("pause");
	system("CLS");
	cout << string(100, '=') << endl << endl;
	cout << "\t\t\t\t\tLink-based Stack ADT" << endl << "\t\t\t\t\t   Currency Stack\n\n";
	cout << string(100, '=') << endl << endl;

	Stack< Currency > crrStack; // create Stack of Currencies
	cout << " Processing a string Stack" << endl << endl;
	cout << " The size of the Stack is " << crrStack.size() << endl << endl;


	// push currencies onto intStack
	Currency obj(34, 45);
	crrStack.push(obj);
	crrStack.printStack();

	Currency obj1(23, 78);
	crrStack.push(obj1);
	crrStack.printStack();

	Currency obj2(12, 67);
	crrStack.push(obj2);
	crrStack.printStack();

	Currency obj3(23, 54);
	crrStack.push(obj3);
	crrStack.printStack();

	cout << "\n The new size of the Stack is " << crrStack.size() << endl << endl;
	cout << string(100, '-') << endl << endl;

	Currency popcurrency; // store currency popped from stack

	// pop currencies from intStack and print
	while (!crrStack.isStackEmpty())
	{
		crrStack.pop(popcurrency);
		cout << popcurrency << " popped from stack" << endl;
		crrStack.printStack();
	} // end while
	cout << string(100, '=') << endl << endl;
	cout << " Returning to Main menu" << endl << endl;
	system("pause");
	system("CLS");

}

