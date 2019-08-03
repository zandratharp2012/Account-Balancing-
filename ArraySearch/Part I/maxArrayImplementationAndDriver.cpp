 /*
***************************************************************
Program Description: maxArray Implementation File And Driver
*****************************************************************
*/

#include <iostream>

using namespace std;

int maxArray(int arr[], int nElements)				//Find Largest Number In Array
{
	int largestNum = arr[0];
	for (int index = 1; index < nElements; index++)
	{
		if(arr[index] > largestNum)
		{
			largestNum = arr[index];				//Largest Number Will Be Stored In Variable
		}
	}
	return largestNum;								//Largest Number Returned
}

int main()
{
	//Store Number(s) In Array
	
	int Array[] = {32};											
	cout << "The Largest Number In The Array Is:" << endl;
	cout << maxArray(Array, sizeof(Array)/sizeof(Array[0]))<< endl; //Print Max Number In Array
	return 0;
}
