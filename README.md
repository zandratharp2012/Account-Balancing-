 /*
***************************************************************
Program: Account Balancing 
The following program will help balance a checkbook with user input
*****************************************************************
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{

	//Declarations, constants, accumulator and set decimal places 
	
    char choice = ' '; 
    double balance;	  
    double amount;
    double totalSERVICE_CHARGE; 
    const double SERVICE_CHARGE = .35;
    double numService = 0; 
    
	cout<<fixed<<showpoint<<setprecision(2); 
	
	//Get user input and commence loop
	
    cout<<"Checkbook Balancing program"<<endl;
    cout<<"Please enter your initial balance: "; 
    cin>>balance;
    cout<<endl;
    
	while (choice != 'e' || choice != 'E') 
     {
        cout<<"Please enter a letter corresponding to your type of transaction."<<endl;
        cout<<"C - Process a Check."<<endl;
        cout<<"D - Process a Deposit."<<endl;
        cout<<"E - Do end of month processing and exit program."<<endl;
        cin>>choice;
        
        //Commence if statements based on the choice entered
		//statements will either process a check, deposit into the balance or exit the program
		//if the choice is to deposit a check, there will be a service charge and accumulators will determine balance at the end of the program
    	
        if (choice == 'c' || choice == 'C' )  
        {
            cout<<"Enter transaction amount: ";
            cin>>amount;
            cout<<"Processing check for "<<amount<<endl;
            balance = balance - amount; 
            cout<<"Balance: "<<balance<<endl;
            cout<<"Service charge: $"<<SERVICE_CHARGE<<" for a check"<<endl;
            numService++; 
            totalSERVICE_CHARGE = numService * SERVICE_CHARGE; 
            cout<<"Total service charges: $"<<totalSERVICE_CHARGE<<endl;
        }
        else if (choice == 'd'|| choice == 'D' )  
       
        {
            cout<<"Enter transaction amount: ";
            cin>>amount;
            cout<<"Processing deposit for "<<amount<<endl;
            balance = balance + amount;
            cout<<"Balance: "<<balance<<endl;
            totalSERVICE_CHARGE = numService * SERVICE_CHARGE;
            cout<<"Total service charges: $"<<totalSERVICE_CHARGE<<endl;
        }
        
        //Choice E will add all transactions and add service charges to deliver final balance
        
        else if (choice == 'e'|| choice == 'E')  
         {
            cout<<"Processing end of the month "<<endl;
            totalSERVICE_CHARGE = numService * SERVICE_CHARGE; 
            cout <<"Final Balance: "<<balance - totalSERVICE_CHARGE<<endl; 
            
        }
        else
        {
            cout<<"Please enter a valid transaction type"<<endl; 
            
        }
    }
    return 0;
}	//end of program
