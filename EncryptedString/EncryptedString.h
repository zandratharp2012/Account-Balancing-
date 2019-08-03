 /*
***************************************************************
Program Description: EncryptedString Class
*****************************************************************
*/

#ifndef ENCRYPTEDSTRING_H
#define ENCRYPTEDSTRING_H
#include<string>

using namespace std;

// Encrypted class declaration
class EncryptedString
{
	private:
		string sentence; 			//Declaring Variable
	public:	
	
		//Function Prototypes 
													
		EncryptedString();			//Constructor
    	EncryptedString(string);	//Constructor with argument
    	void setSentence(string);	//Set And Encrypt String						
    	string getDecrypted();		//Get Original String
		string getEncrypted();		//Get Encrypted String
};
#endif

