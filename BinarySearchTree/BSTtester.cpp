/*
***************************************************************
Program Description: Binary Search Tree Driver
*****************************************************************
*/

#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
   // Testing Constructor and empty()
   BST<int> firstBST;    
   
   //Testing isEmpty(), getHeight(), getNumberOfNodes(), and getNumberOfLeaves()      
   cout << "Constructing empty BST..." << endl;
   cout << "BST " << (firstBST.isEmpty() ? "is" : "is not") << " empty\n";
   cout << "Height of the BST: " << firstBST.getHeight() << endl;	
   cout << "This should be 0 as the BST is empty.\n";
   cout << "Number of nodes in BST: " << firstBST.getNumberOfNodes() << endl;
   cout << "This should be 0 as the BST is empty.\n";
   cout << "Number of leaves in BST: " << firstBST.getNumberOfLeaves() << endl;
   cout << "This should be 0 as the BST is empty.\n";

   // Testing inorder
   cout << "Traversal of BST in order: \n";
   firstBST.inorder(cout);
   cout << endl;

   // Testing insert
   cout << "\nNow insert integers into the BST."
           "\nTry items that are and are not in the BST:\n";
   int number;
   for (;;)
   {
      cout << "\nItem to insert (0 to stop): ";
      cin >> number;
      if (number == 0) break;
      firstBST.add(number);
   }
   cout << '\n';
   firstBST.graph(cout);
   cout << endl;

   cout << "BST " << (firstBST.isEmpty() ? "is" : "is not") << " empty\n";
   cout << "Traversal of BST in order: \n";
   firstBST.inorder(cout);
   cout << endl;

   // Testing search()
   cout << "\n\nNow testing the contains() operation."
           "\nTry items that are and are not in the BST:\n";
   for (;;)
   {
      cout << "Item to find (0 to stop): ";
      cin >> number;
      if (number == 0) break;
      cout << (firstBST.contains(number) ? "Found\n" : "Not found\n") << endl;
   }

   // Testing getHeight(), getNumberOfNodes(), getNumberOfLeaves()
   cout << "Height of the BST: ";
   cout << firstBST.getHeight();
   cout << endl;
   cout << "Number of nodes in BST: ";
   cout << firstBST.getNumberOfNodes();
   cout << endl;
   cout << "Number of leaves in BST: ";
   cout << firstBST.getNumberOfLeaves();
   cout << endl;
   
   // Testing remove()
   cout << "\nNow testing the remove() operation."
           "\nTry items that are and are not in the BST:\n";
   for (;;)
   {
      cout << "\nItem to remove (0 to stop): ";
      cin >> number;
      if (number == 0) break;
      firstBST.remove(number);
      cout << endl;
      firstBST.graph(cout);
      cout << endl;
   }
   cout << "\nTraversal of BST in order: \n";
   firstBST.inorder(cout);
   cout << endl << "End of program...";
}//End of main 
