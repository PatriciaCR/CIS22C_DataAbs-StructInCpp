/******************************************************************************************************************/
/* CIS 22C. DeAnza College, Fall Quarter 2015                                                                     */
/*                                                                                                                */
/* Lab 1: This program has Wallet ADT with this interfaces: number of currencies, add money by currency, remove   */
/* money by currency, remove all currencies, and check if wallet is empty. We also created a Currency ADT with    */
/* four attributes: currency name, whole parts and fractional parts and fractional's name. We do not let the user */
/* remove any money if there is not enough in the wallet. Also, we let the user add or remove money manually, and */
/* with the random number generator. The wallet is initialized with 10 currencies, so the user can remove or add  */
/* any of the currencies.                                                                                         */
/*                                                                                                                */
/* Team: Patricia Caceres, Cathleen Carroll                                                                       */
/******************************************************************************************************************/

#include<iostream>
#include<string>
#include"Currency.h"
#include"Wallet.h"
using namespace std;


int main()
{
	Interface *interfaceptr = new Wallet(); 

	int choice = 0;


	//Main Menu: Ask the user if he/she wants to add, remove or see the currencies that exists on the wallet.
	do{
		cout << string(60, '=') << endl << endl;
		cout << "\t\t\t MY WALLET\n\n";
		cout << string(60, '-') << endl << endl;

		cout << "\t0)How many currencies are in the wallet?\n";
		cout << "\t1)Add a Currency\n";
		cout << "\t2)Remove a Currency\n";
		cout << "\t3)Remove all or some of the Currencies\n";
		cout << "\t4)See my Currencies\n";
		cout << "\t5)Exit the program\n\n";

		cout << string(60, '-') << endl << endl;
		int count = 0;

		//Validate the choice the user makes.
		do
		{
			if (count > 0)
			{
				cout << "\n You did not enter a correct value for your choice, try again\n\n";
				cout << string(60, '-') << endl << endl;
			}
			cout << " Please enter the number of your choice: ";
			cin >> choice;
			count++;
		} while ((choice > 5) || (choice < 0));

		//Prompts the user the selection he/she made
		cout << "\n\n You selected item " << choice << endl << endl;
		cout << string(60, '-') << endl << endl;






		//Redirects the user to the respective function according to the selection he/she made
		switch (choice)
		{
		case 0: //Number of currencies
		{
					cout << " There are " << interfaceptr->numberofc() << " currencies in the Wallet\n\n\n\n"; //Call the function for the number of currencies and print the result 
					break;
		}
		case 1: //Add a currency 
		{
					cout << " Redirecting to Add a currency.\n\n";
					system("pause");
					system("CLS");
					string chc;

					cout << string(90, '=') << endl << endl;
					cout << "\t\t\t    * * *  A D D   M O N E Y  * * *\n\n";
					cout << string(90, '=') << endl << endl;

					do{

						//Ask the user which currency he/she would like to add
						int choice, cont = 0;
						cout << " Please select the number of the currency to which you would like to add money\n\n";
						cout << " Dollar=0, Bolivar=1, Yen=2, Franc=3,Peso=4, Rupee=5, Pound=6, Real=7, Euro=8, Ruble=9\n\n";

						do //Validate the choice
						{
							if (cont > 0)
							{
								cout<<endl<< string(90, '-') << endl;
								cout << "\n You did not insert a correct value for your choice,try again\n";
							}
							cout << "\n Please enter the number of your choice: ";
							cin >> choice;
							cont++;
						} while ((choice > 9) || (choice < 0));
						cout << endl << string(90, '-') << endl;


						//Check if the currency that the user chose exist in the wallet. If it exists continue if not tell the user that the currency does not exist
						if (interfaceptr->checkE(choice) == true)
						{
							//Ask the user how would he/she prefer to add the currency to the wallet 
							cont = 0;
							int chch;
							do //Validate the choice
							{
								if (cont > 0)
								{
									cout << "\n You did not insert a correct value for your choice,try again\n\n";
									cout << string(90, '-') << endl;
								}
								cout << "\n Would you like to add this currency:\n\n\t1)Manually\n\t2)Random Number Generator\n";
								cout << "\n Please enter the number of your choice: ";
								cin >> chch;
								cont++;
							} while ((chch != 1) && (chch != 2));
							cout << endl << string(90, '-') << endl;




							cont = 0;
							//Add the number manually 
							if (chch == 1)
							{
								//Ask the user the number he/she woud like to add 
								int a, b;
								do
								{
									if (cont > 0)
									{
										cout << "\n The numbers you chose are out of range,try again\n\n";
										cout << string(90, '-') << endl;
									}
									cout << "\n Please insert two numbers from 0 to 99 separated by a space. The first number will be the\n Whole part and the second number will be the fractional part of the number you want to add\n\n ";
									cin >> a >> b;
									cont++;
								} while ((a < 0) || (a > 99) || (b < 0) || (b > 99));

								interfaceptr->add(choice, 1, a, b); //Add the currency entered by the user
							}


							//Add the number using the random number generator 
							if (chch == 2)
							{
								interfaceptr->add(choice, 2, 0, 0);
							}
						}
						else
							cout << "\n That currency does not exist in the Wallet.\n\n";

						cout << string(90, '-') << endl;
						//Ask the user if he/she wants to add more currencies 
						cont = 0;
						do
						{
							if (cont > 0)
							{
								cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
								cout << string(90, '-') << endl;
							}
							cout << "\n Do you want to add more currencies. Enter 'Yes' or 'No'\n\n ";
							cin >> chc;
							cont++;
						} while ((chc != "Yes") && (chc != "No")); //If ther user does not want to add more currencies: Go to main menu 
						cout << endl;
						cout << string(90, '=') << endl << endl;

					} while (chc == "Yes"); //If the user wants to add more currencies, repeat.


					cout << "\n Redirecting to Main Menu\n\n";
					system("pause");
					system("CLS");
					break;
		
		}

		case 2://Substract a currency
		{
				   system("pause");
				   system("CLS");

				   cout << string(90, '=') << endl << endl;
				   cout << "\t\t\t * * *  R E M O V E   M O N E Y  * * *\n\n";
				   cout << string(90, '=') << endl << endl;
				   string chc;

				   //Ask the user what currency he/she would like to remove money from 
				   do{
					   int choice, cont = 0;
					   cout << " Please select the number of the currency from which you would like to remove money\n\n";
					   cout << " Dollar=0, Bolivar=1, Yen=2, Franc=3,Peso=4, Rupee=5, Pound=6, Real=7, Euro=8, Ruble=9\n\n";


					   //Validate the choice
					   do
					   {
						   if (cont > 0)
						   {
							   cout << endl << string(90, '-') << endl;
							   cout << "\n You did not insert a correct value for your choice,try again\n";
						   }
						   cout << "\n Please enter the number of your choice: ";
						   cin >> choice;
						   cont++;
					   } while ((choice > 9) || (choice < 0));
					   cout << endl << string(90, '-') << endl;

					   //if the wallet is not empty and the currency that the user selected exists in the wallet continue, else tell the user wether the wallet is empty 
					   //or the currency does not exist.
					   if (interfaceptr->checkempty(choice)== false)
					   {
						   if (interfaceptr->checkE(choice)== true)
						   {
							   //Ask the user how he/she would like to remove the money(manually or by the random number generator)
							   cont = 0;
							   int chch;
							   //Validate the choice
							   do
							   {
								   if (cont > 0)
								   {
									   cout << "\n You did not insert a correct value for your choice,try again\n\n";
									   cout << string(90, '-') << endl;
								   }
								   cout << "\n Would you like to remove this currency:\n\n\t1)Manually\n\t2)Random Number Generator\n ";
								   cout << "\n Please enter the number of your choice: ";
								   cin >> chch;
								   cont++;
							   } while ((chch != 1) && (chch != 2));
							   cout << endl << string(90, '-') << endl << endl;


							   cont = 0;
							   //Remove manually
							   if (chch == 1)
							   {
								   // Ask the user the number he / she woud like to add
								   int a, b;
								   do
								   {
									   if (cont > 0)
									   {
										   cout << "\n The numbers you chose are out of range,try again\n\n";
										   cout << string(90, '-') << endl << endl;
									   }
									   cout << " Please insert two numbers from 0 to 99 separated with a space. The first number will be\n the Whole part and the second number will be the fractional part of the number you want\n to remove\n\n ";
									   cin >> a >> b;
									   cont++;
								   } while ((a < 0) || (a > 99) || (b < 0) || (b > 99));
								   cout << endl << string(90, '-') << endl << endl;
								 
								   interfaceptr->remove(choice, 1, a, b); //Call the remove function for  remove currencies manually and passes the values the user wants to erase
						
							   }

							   //Call the remove function for the random number generator choice
							   if (chch == 2)
							   {
								   interfaceptr->remove(choice,2,0,0);
							   }
						   }
						   else
							   cout << "\n That currency does not exist in the Wallet.\n";
					   }
					   else
						   cout << "\n You cannot remove money from this currency because the wallet is empty.\n";


					   cout << endl << string(90, '-') << endl;
					   //Ask the user if he/she wants to remove more money from currencies 
					   cont = 0;
					   do
					   {
						   if (cont > 0)
						   {
							   cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
							   cout << string(90, '-') << endl;
						   }
						   cout << "\n Do you want to remove more money from your currencies. Enter 'Yes' or 'No'\n\n ";
						   cin >> chc;
						   cont++;
					   } while ((chc != "Yes") && (chc != "No")); //If ther user does not want to remove more currencies: Go to main menu
					   cout << endl;
					   cout << string(90, '=') << endl << endl;

				   } while (chc == "Yes"); //If the user wants to remove more money, repeat 


				   cout << "\n Redirecting to Main Menu\n\n";
				   system("pause");
				   system("CLS");
		
				   break;
		}

		case 3://Erase all or one of the currencies from the wallet, the parameter can be just 3 or 5: 3 if the user selects the option number 3 of the main menu
			//and 5 if the user wants to exit the program
		{
				   system("pause");
				   system("CLS");

				   cout << string(90, '=') << endl << endl;
				   cout << "\t\t\t* * *  E R A S E   C U R R E N C I E S  * * *\n\n";
				   cout << string(90, '=') << endl << endl;

					   //Ask the user if he/she wants to eliminate a specific currency or all of them 
					   int cont = 0;
					   string chc;
					   int select;
					   do
					   {
						   if (cont > 0)
						   {
							   cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
							   cout << string(90, '-') << endl << endl;
						   }

						   cout << " Would you like to:\n\n \t1)Remove an specific currency\n \t2)Remove all the currencies\n\n";
						   cout << " Please enter the number of your choice:  ";
						   cin >> select;
						   cont++;
					   } while ((select != 1) && (select != 2));


					   cout << endl << string(90, '-') << endl;
					   switch (select)
					   {
					   case 1: // If the user wants to erase an specific currency: Ask the user which currency he/she would like to erase 
						   cont = 0;
						   int choice;
						   cout << "\n Please select the number of the currency that you would like to erase\n\n";
						   cout << " Dollar=0, Bolivar=1, Yen=2, Franc=3,Peso=4, Rupee=5, Pound=6, Real=7, Euro=8, Ruble=9\n\n\n";

						   //Validate the choice
						   do
						   {
							   if (cont > 0)
							   {
								   cout << "\n You did not insert a correct value for your choice,try again\n\n";
								   cout << string(90, '-') << endl << endl;
							   }
							   cout << " Please enter the number of your choice: ";
							   cin >> choice;
							   cont++;
						   } while ((choice > 9) || (choice < 0));

						   interfaceptr->clear(3, select, choice); //Call the erase function to erase an specific currency

						   break;


					   case 2: //If the user wants to erase all the currencies from the wallet 
					   {
								   //Ask the user if he/she really wants to erase the all the currencies
								   cont = 0;
								   do
								   {
									   if (cont > 0)
									   {
										   cout << "\n You did not insert a correct value for your choice. Please try again\n\n";
										   cout << string(90, '-') << endl << endl;
									   }
									   cout << "\n Do you really want to erase ALL THE CURRENCIES from the wallet?. Enter 'Yes' or 'No'\n\n ";
									   cin >> chc;
									   cont++;
								   } while ((chc != "Yes") && (chc != "No"));
								   cout << endl << endl;

								   //If the user wants to erase all the currencies... Delete them (set all the currencies to the values of the default constructor )
								   if (chc == "Yes")
								   {
									   cout << " ERASING ALL THE CURRENCIES FROM THE WALLET...\n\n";
									   interfaceptr->clear(3, select, 10); //Call the erase function to erase all the currencies
								   }
								   //No: Continue the program
								   cout << string(90, '=') << endl;
								   break;
					   }
					   }
				   
				   cout << "\n\n Redirecting to main menu...\n\n";
				   system("pause");
				   system("CLS");

				   break;
		}

		case 4://Print the Wallet
			cout << " Redirecting to print the wallet\n\n";
			interfaceptr->print();
			break;
		case 5: //EXIT the program
			interfaceptr->clear(5,0,0); //Erase all the currencies from the wallet 
			interfaceptr->print();//Print the wallet again.

		}

	} while (choice != 5); //If the choice if 5: Exit the program.


	delete interfaceptr;
	return 0;
}