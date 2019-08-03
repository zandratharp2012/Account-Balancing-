/*
***************************************************************
Program Description: ArraySet Driver 
*****************************************************************
*/

#include "ArraySet.h"
#include <iostream>
#include <string>


using namespace std;

void display(ArraySet<string>& set)									//Displays Elements In Array
{
	cout << "The Set Contains The Following Number Of Items: " 
		 << set.getCurrentSize() << endl;
	vector<string> setItems = set.toVector();
	int numberOfEntries = static_cast<int>(setItems.size());
	cout << "\nNow Displaying The Items In Array Set: " << endl;
	for (int index = 0; index < numberOfEntries; index++)
	{
		cout << setItems[index] << " ";
	}
	cout << endl;
}

int main()
{
	ArraySet<string> set;										//Class Object 
	int index;
	cout << "Testing Array Set:" << endl;
	cout << "\nThe Initial Set Is Empty."	<< endl;
	cout << "isEmtpy = " << set.isEmpty() << endl;				//Calling Function To See If Array Is Emtpy 
	cout << "This Should Return 1, Which Is True." << endl;
	
	display(set);												//Displays Empty Array 
	
	string items[] = {"One", "Two", "Three", "Four", "One"};	//Elements We Want To Add To Array
	cout << "Adding 5 Items To Array Set..." << endl;
	for(index = 0; index < 5; index++)							//Loop To Add Elements To Array 
	{
		set.add(items[index]);
	}
	
	display(set);												//Display New Elements In Array 
															
																//Following Functions Test Elements In Array
	
	cout << "\nisEmtpy = " <<set.isEmpty() << endl;
	cout << "This Should Return 0, Which Is False." << endl;		
	cout << "getCurrentSize = " << set.getCurrentSize() << endl;
	cout << "This Should Be The Number 4 After Removing Duplicate Items." << endl;		 
	cout << "contains (\"Three\")=  " << set.contains("Three") << endl;	
	cout << "This Should Return 1, Which Is True." << endl;	
	cout << "remove(\"Two\")= " << set.remove("Two") << endl;
    cout << "This Should Return 1, Which Is True." << endl; 
    cout << "remove(\"Two\")= " << set.remove("Two") << endl;
    cout << "This Should Return 0, Which Is False." << endl;

    display(set);											 	//Display Elements With Modifications Made 
   
    cout << "\nNow Clearing Array Set..." << endl;
    
    set.clear();												//Clearing Array 
    
    cout << "\nisEmpty = " << set.isEmpty() << endl;
    cout << "This Should Return 1, Which Is True." << endl;
    
	return 0;
}  // end main

