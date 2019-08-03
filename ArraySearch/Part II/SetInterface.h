 /*
***************************************************************
Program Description: SetInterface File
*****************************************************************
*/

/** Listing 1
	@file SetInterface.h */
	
#ifndef SET_INTERFACE_
#define SET_INTERFACE_

#include <vector>

template <class ItemType>
class SetInterface
{
	public:
		/** Gets current number of entries in the set.
		 @return The integer number of entries currently in the set. */
		virtual int getCurrentSize() const = 0;
		
		/** Sees whether the set is empty.
		 @return  True if the set is empty, or false if not. */
		virtual bool isEmpty() const = 0;
		
		/** Adds a new entry to this set but does not allow duplicate entries.
		 @post    If successful, newEntry is stored in the set and
		 		  the count of items in the set increase by 1.
		 @param   newEntry  The object to be added as a new entry.
		 @return  True if addition was successful, or false it not. */
		virtual bool add(const ItemType& newEntry)= 0;
		
		/** Removes one entry from the set.
		 @post	  If successful, anEntry has been removed from the set
		 		  and the count of the items in the set decreases by 1.
		 @param   anEntry  The entry to be removed
		 @return  True if removal is successful, false if not. */
		virtual bool remove(const ItemType& anEntry) =0;
		
		
		/** Remove all entries from the set.
		 @post    Set is cleared and the count of items is 0. */
		virtual void clear() =0;

		/** Tests whether the set contains a particular entry.
		 @param   anEntry   The entry being located.
		 @retur   True if set contains anEntry, or else false. */
		virtual bool contains(const ItemType& anEntry) const =0;
		 
		/** Empties and then fills vector with all entries in the set
		 @return   A vector containing all entries in the set. */
		virtual std::vector<ItemType> toVector() const =0;
		
		/** Destroys object ad frees memory allocated by the object. */		
		virtual ~SetInterface() {};
		
}; //End SetInterface
#endif	
	
