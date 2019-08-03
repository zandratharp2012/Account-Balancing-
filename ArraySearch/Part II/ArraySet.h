/*
***************************************************************
Program Description: ArraySet Class and Implementation File 
*****************************************************************
*/

/** Listing 2 - Header File For Array-Based Implementation File Of ADT Set.
	@file ArraySet.h */
	
#ifndef ARRAY_SET_
#define ARRAY_SET_

#include "SetInterface.h"

template<class ItemType>
class ArraySet : public SetInterface<ItemType>
{
	private:
		static const int DEFAULT_CAPACITY = 6;	//Size To Test Full Set 
		ItemType items[DEFAULT_CAPACITY];		//Array Of Set Items
		int itemCount;							//Current Count Of Set Items
		int maxItems;							//Max Capacity Of Set 						
		
		/* 
		Returns Either Index Of The Element In Array Items That 
		Contains The Given Target Or -1 If Array Doesn't Contain Target. 
		*/
		int getIndexOf(const ItemType& target) const;
	
	public:
		ArraySet();										//Constructor
		ArraySet(const ItemType& numElements);			//Second Constructor
		int getCurrentSize() const;						//Get Size
		bool isEmpty() const;							//Determine If Empty
		bool add(const ItemType& newEntry);				//Determine If Adding Elements
		bool remove(const ItemType& anEntry);			//Determine If Removing Elements
		void clear();									//Clear Array 
		bool contains(const ItemType& anEntry) const;	//See If Elements Are In Array
		std::vector<ItemType> toVector() const;			//Sets Items 
}; //End ArraySet

/** Implementation File For Class ArraySet.
 @file ArraySet.cpp */
 
#include <cstddef>

template<class ItemType>
ArraySet<ItemType>::ArraySet(): itemCount(0), maxItems(DEFAULT_CAPACITY)	//Default Constructor 
{
} 

template<class ItemType>
ArraySet<ItemType>::ArraySet(const ItemType& newEntry)						//Initializes Array And ItemCount
{
	int index = 0;
	while(items[index] != NULL)
	{
		index++;
	}
}

template<class ItemType>
int ArraySet<ItemType>::getCurrentSize() const								//Get Current Size Of Array
{
	return itemCount;
}

template<class ItemType>
bool ArraySet<ItemType>::isEmpty() const 								 	//Returns Empty If Empty
{
	return itemCount == 0;
}

template<class ItemType>
bool ArraySet<ItemType>::add(const ItemType& newEntry)						//Returns True If Can Add Elements And Removes Duplcates Before Adding To Array
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
		for (int index = 0; index < itemCount; index++)        				//Loop Will Remove Duplicates From Array 
		{
			for(int j = index+1; j < itemCount; j++)
			{
				if(items[index] == items[j])
				{
					for(int k = j; k < itemCount; k++)
					{
						items[k] = items[k+1];
						k++;
					}
					itemCount--;
					j--;
				}
			}	
		}
	}
	return hasRoomToAdd;
}

template<class ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anEntry)        			//Returns True If Can Remove And Removes Elements From Array 
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
	return canRemoveItem;
}
	
template<class ItemType>
void ArraySet<ItemType>::clear()											//Clears Array
{
	itemCount = 0;
}

template<class ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anEntry) const			//Returns True If Entry If Found In Array 
{
	return getIndexOf(anEntry) > -1;
}

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const					//Sets Elements In Array
{
	std::vector<ItemType> set;
	for(int index = 0; index < itemCount; index++)
		set.push_back(items[index]);
	return set;
}

template<class ItemType>
int ArraySet<ItemType>::getIndexOf(const ItemType& target) const			//Gets Index And If Set Is Empty, Loop Is Skipped, Item Count = 0
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}
	}
	return result;
}
#endif
	
