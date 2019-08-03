 /*
***************************************************************
Program Description: EncryptedString Implementation File 
*****************************************************************
*/

#include "EncryptedString.h"
#include <iostream>

using namespace std;

EncryptedString::EncryptedString()						//Constructor
{
	sentence = "";
}
EncryptedString::EncryptedString(string s)				//Constructor Calling Set Function 
{
	setSentence(s);	 
}
void EncryptedString::setSentence(string str)			//Set And Encrypt String 
{
	string temp;										//Declare Temporary String Variable 
	for (int index=0; index <= str.length(); index++)
	{	
		if (str[index] == 32)							//Does Not Encrypt Space
			temp += str[index];							
		else if (str[index] > 64 && str[index] < 90) 
			temp += (str[index]+1);						
		else if (str[index] > 96 && str[index] < 122) 	
			temp += (str[index] +1);					
		else if (str[index] == 90 || str[index] == 122) 
			temp += (str[index] -25);						//Allows 'z' & 'Z' To Wrap Around 
	}
	sentence = temp;										//Stores Encrypted String
}
string EncryptedString::getDecrypted() 						//Get Original String
{
	for (int index=0; index <= sentence.length(); index++)
	{
		if (sentence[index] == 32)							//Keeps Spaces 
			sentence[index] = sentence[index];
		else 
			sentence[index] = sentence[index] -1;			//Shifts String -1
	}
	return sentence;
}
string EncryptedString::getEncrypted()
{
	return sentence;										//Gets Encrypted String 
}

