 /*
***************************************************************
Program Description: EncryptedString Program 
*****************************************************************
*/

#include "EncryptedString.h"
#include "EncryptedString.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	EncryptedString data;									//Create Object
	string input;
	cout << "Enter a string: " << endl;		
	getline(cin,input);
	data.setSentence(input);								//Pass User Input Into Function 
	cout << "Here is your encrypted message" << endl;
	cout << data.getEncrypted() << endl;					//Get Encrypted String
	cout << "Here is your original message" << endl;
	cout << data.getDecrypted() << endl;					//Get Original String 
	return 0;
}															//End Of Program 

