#include <iostream>
#include <cstdlib>     // include definition for rand()
using namespace std;

     int main ()
     {
         string items[] = {"one", "two", "three", "four", "one"};
		 int number;

         cout << "Printing a list of 4 random integers in the range 0 through 99" << endl;

         for (int i=0; i<1; i++)
         {
             number = rand() % 4;
             cout << number << "  ";
         }
         cout << items[number];
         cout << endl;

         return 0;
     }
