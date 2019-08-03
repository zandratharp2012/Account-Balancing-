 /*
*****************************************************************
Program Description: Stack Driver
*****************************************************************
*/

#include <iostream>
#include <string>
#include "ArrayStack.h"

//Declaration of methods 

bool isOperator(char C);					
bool isDigit(char C);
bool correctForm(char arr[]);
int performOp(char op, int op1, int op2);

int main()
{
    
		ArrayStack<int> Stack;	//Declaring class object 
		int result, op1, op2;
	    char items[MAX_STACK];
	    char decision = 'y';
		while (decision == 'y' || decision == 'Y') 	//Loop based on decision to continue or end
		{
			int index;
			cout << "Enter an expression: ";
			cin.getline(items, 32);
			cout << "Items entered are: " << items << endl;
			
			if(correctForm(items))      //If postfix expression is valid, continue program
			{
				for(int i = 0; i < items[i]; i++)
				{	
					if(isOperator(items[i])) 			//If is +,-,*, or /, will perform operation 
					{
						int op2 = Stack.peek();
						Stack.pop();
						int op1 = Stack.peek();
						Stack.pop();
						int result = performOp(items[i], op1, op2);
						
						Stack.push(result);				//Pushing result to top of stack 
					}
					else if(isDigit(items[i])) 
					{
						cout<<"Reading items and pushing " << items[i] << std::endl;
						
						Stack.push(items[i] - '0'); 	//Pushing and converting to digits 
					}	
					else if(items[i] == ' ')
					{
						continue;
					}
					else if (isalpha(items[i]))			//If alphabet, will disregard value
					{
						cout << "Invalid entry, not added to stack." << endl;
					}
				}
				while (!Stack.isEmpty())
				{
					cout << "Result is \"" << Stack.peek() << "\"" << endl; //Calling top of stack
					break;
				}
				cout << endl;
			}
			else
			{
				cout << "Program will restart." << endl;
			}
			cout << "Empty: " << Stack.isEmpty() << endl;
			cout << "If you have more expressions, enter y to continue..." << endl;
			cin >> decision;
			cin.getline(items, 32);
		}
	return Stack.peek();
	cout << "You have chosen to exit the program.";
}  // end driver

bool isOperator(char C) 		//Determines if character is +, -, *, or /
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
	{
		return true;
	}
	return false;
}  

bool isDigit(char C)           //Determinds if character is number and error checking 
{
	if(C >= '0' && C <= '9')
	{
		return true;
	}
	return false;
}

bool correctForm(char items[])	//Determinds if postfix expression is valid 
{
	int digitCount = 0;
	int opCount = 0;
	for(int i = 0; i < items[i]; i++)
	{
		if(isDigit(items[i]))
		{
			digitCount++;					//Counting digits
		}
		else if(isOperator(items[i]))
		{
			opCount++;						//Counting operators
		}
	}
	if(digitCount == opCount || digitCount < opCount)
	{
		cout << "Invalid Postfix Expression." << endl;
		return false;
	}
	else
	{
		return true;
	}
	
}

int performOp(char op, int op1, int op2)	//Performs operation 
{
	if(op == '+')
	{
		return op1 + op2;
	}
	else if(op == '-')
	{
		return op1 - op2;
	}
	else if(op == '*')
	{
		return op1 * op2;
	}
	else if(op == '/')
	{
		return op1 / op2;
	}
	else
	{
		cout << "Unexpected Error" << endl;
	}
	return -1;
}
