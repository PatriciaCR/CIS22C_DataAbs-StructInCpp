/***********************************************************************************************/
/* De Anza College, Fall 2015. CIS 22C                                                         */
/*                                                                                             */
/* Lab 3:										                                               */
/*                                                                                             */
/* Team: Calvin Rong, Jason Do, Patricia Caceres.                                              */
/***********************************************************************************************/

#include<iostream>
#include<string>
#include"Stack.h"

using namespace std;


bool isoperand(char); //Function that checks if the character is a operand
bool isoperator(char); //Function that checks if the character is a operator
int precedence(char);
void Execute(Stack<char>&,Stack<int>&);

int main()
{
	cout << string(60,'=')<<endl<<endl;
	cout << "\t\t\tInfix Calculator\n\n";
	cout << string(60, '=')<<endl<<endl;

	string infix;
	cout << " Please insert your infix expression:\n\n";
	getline(cin, infix);

	Stack<int> valStack;
	Stack<char> opStack;
	int val = 0;
	int checksum1 = 0;
	int checksum2 = 0;
	int checksum3 = 0;
	int checksum4 = 0;
	int checksum5 = 0;

	int result=0;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isoperand(infix[i]) == true) //If character is an operand push it into the operand's stack
		{
			val = infix[i] - '0';
			valStack.push(val);
			val = 0;
			checksum1++;
			if (checksum5 == 0)
			{
				checksum5++;
			}
			else
			{
				cout << "Syntax error.  This calculator only accepts single digit operands." << endl;
				system("pause");
				return 0;
			}
		}
		else if (infix[i] == '(') //If the character is a ( push it into the operator's stack 
		{
			opStack.push(infix[i]);
			checksum3++;
		}
		else if (isoperator(infix[i]) == true) //If the character is an operator 
		{
			if (checksum5 == 1)
			{
				checksum5--;
			}
			else
			{
				cout << "Syntax error.  Unrecognized operator pairing." << endl;
				system("pause");
				return 0;
			}
			if (opStack.isStackEmpty()) //if the stack is empty push the character into the operator's stack
			{
				opStack.push(infix[i]);
			}
			
			//if the stack is not empty: check if the precedence of the current character is greater than that of the character that is on the top of the operator's stack
			else if (precedence(infix[i]) > precedence(opStack.peek()))
			{
				opStack.push(infix[i]);
			}
			else
			{
				while ((!opStack.isStackEmpty()) && (precedence(infix[i]) <= precedence(opStack.peek())))
				{
					Execute(opStack, valStack);
				}
				opStack.push(infix[i]);
			}
			checksum2++;
		}
		else if (infix[i] == ')')
		{
			while (opStack.peek() != '(')
			{
				Execute(opStack, valStack);
			}
			opStack.pop();
			checksum4++;
		}
	}
	if (checksum1 != (checksum2 + 1))
	{
		cout << "Syntax error.  Invalid ratio of operands to operators." << endl;
		system("pause");
		return 0;
	}
	if (checksum3 != checksum4)
	{
		cout << "Syntax error.  Unequal amounts of opening and closing parentheses." << endl;
		system("pause");
		return 0;
	}
	while (!opStack.isStackEmpty())
	{
		Execute(opStack, valStack);
	}
	result = valStack.peek();
	
	cout << "The result of your expression is: ";
	cout << result << endl << endl;
	system("pause");
	return 0;
}

void Execute(Stack<char>& opStack,Stack<int>& valStack)
{
	char op;
	int operand1, operand2;
	int result = 0;

	operand2 = valStack.peek();
	valStack.pop();

	operand1 = valStack.peek();
	valStack.pop();
	
	op = opStack.peek();
	opStack.pop();


	//result = operand1 op operand2; =================WON'T WORK(Obviously)=================================================================
	switch (op){
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	}

	valStack.push(result);
}
int precedence(char a)
{
	int temp;

	if (a == '*' || a == '/')
		temp = 3;
	else  if (a == '+' || a == '-')
		temp = 2;
	else
		temp = 1;

	return temp;
}

bool isoperand(char data) 
{
	if ((data >= '0') && (data <= '9')) //If the data is a digit return true
		return true;
	else if ((data >= 'a') && (data <= 'z')) //If the data is a lower case letter return true
		return true;
	else if ((data >= 'A') && (data <= 'Z'))//if the data is a upper case letter return true
		return true;
	else
		return false;
}

bool isoperator(char data)
{
	if ((data == '+') || (data == '-') || (data == '*')|| (data == '/'))
		return true;
	else
		return false;
}


