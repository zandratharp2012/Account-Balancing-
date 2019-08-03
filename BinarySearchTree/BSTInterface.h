/*
***************************************************************
Program Description: Binary Search Tree Interface
*****************************************************************
*/

/** Interface for the ADT BST (Binary Search Tree)
    @file BSTInterface.h */

#ifndef BST_INTERFACE
#define BST_INTERFACE
#include <iostream>
using namespace std;

template<class ItemType>
class BSTInterface
{
public:
   /** Test if the BST is empty
    @return true if this BST is empty; otherwise return false */
   virtual bool isEmpty() const = 0;

   /** Gets the height of this binary tree.
    @return The heigh of the binary tree. */
   virtual int getHeight() const = 0;

   /** Gets the number of nodes in this binary tree.
    @return The number of nodes in the binary tree*/
   virtual int getNumberOfNodes() const = 0;
   
   /** Gets the number of leaves in this binary tree.
    @return The number of leaves in the binary tree. */
   virtual int getNumberOfLeaves() const = 0;
   
   /** Search the BST for an item
    @rturn true if item found, and false otherwise */
   virtual bool contains(const ItemType & item) const = 0; 

   /* Add an item to the BST.
    @return true if item was successfull inserted; otherwise
        returns false (if item was already in the binary search tree) */
   virtual bool add(const ItemType & item) = 0;

   /* Remove an item from the nBST.
    @return true if item was successfully removed;
        otherwise return false. */ 
   virtual bool remove(const ItemType & item) = 0;

  /* Perform an inorder traversal of the BST, displaying each entry */ 
   virtual void inorder(std::ostream & out) const = 0;

  /* Display the BST in graphical format */ 
  virtual void graph(std::ostream & out) const = 0;

 /** Destroys object and frees memory allocated by object. */
   virtual ~BSTInterface() {  }

}; // end of BSTInterface
#endif

