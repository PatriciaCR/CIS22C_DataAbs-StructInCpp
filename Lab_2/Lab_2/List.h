#ifndef _LIST_
#define _LIST_

#include<iostream>
#include "Node.h"
using namespace std;

template< class ItemType >
class List
{
private:
	Node< ItemType > *firstPtr; // pointer to first node
	Node< ItemType > *lastPtr; // pointer to last node (Not needed but simplifies some functions and saves processing)

	int length; // counter for length

	// utility function to allocate new node
	Node< ItemType > *getNewEntry(const ItemType &);

public:
	List(); // constructor
	~List(); // destructor
	bool insert(const ItemType &, const int);
	bool remove(ItemType &, const int);
	void clear();
	Node< ItemType > *getEntry(const int);
	bool setEntry(ItemType &, int);
	bool isEmpty() const;
	int getLength() const;
	void print() const;

}; // end class List

// default constructor
template< class ItemType >
List< ItemType >::List()
: firstPtr(0), lastPtr(0), length(0)
{
	// empty body
} // end List constructor

// destructor
template< class ItemType >
List< ItemType >::~List()
{
	clear();
} // end List destructor

// insert node at a specified position in the list
template< class ItemType >
bool List< ItemType >::insert(const ItemType &value, const int pos)
{
	Node< ItemType > *newPtr = getNewEntry(value); // new node

	if (isEmpty()) //If List is empty
	{
		firstPtr = lastPtr = newPtr; // new list has only one node
		length++; // Update the length counter
		return true;
	}
	else
	{
		if (pos == 0) // If the position is the front
		{
			newPtr->setNext(firstPtr); // point new node to previous 1st node
			firstPtr = newPtr; // aim firstPtr at new node
			length++; // Update the length counter
			return true;
		}
		else if (0 < pos && pos < length - 1) // If the position is in the middle
		{
			Node< ItemType > *prevPtr = getEntry(pos - 1);
			Node< ItemType > *currentPtr = prevPtr->getNext();
			prevPtr->setNext(newPtr); // Update previous node
			newPtr->setNext(currentPtr); // Update new node
			length++; // Update the length counter
			return true;
		}
		else if (pos == length - 1) // If the position is the end
		{
			lastPtr->setNext(newPtr); // update previous last node
			lastPtr = newPtr; // new last node

			length++; // Update the length counter
			return true;
		}
		else
			return false; // The position is out of range
	}
} // end function insert

// delete node from a specified position in the list
template< class ItemType >
bool List< ItemType >::remove(ItemType &value, const int pos)
{
	if (isEmpty())
		return false;
	else
	{
		if (pos == 0) // If the position is the front
		{
			Node< ItemType > *tempPtr = firstPtr; // hold tempPtr to delete

			if (firstPtr == lastPtr) // If the list has only one node
				firstPtr = lastPtr = 0; // no nodes remain after removal
			else
				firstPtr = firstPtr->getNext(); // point to previous 2nd node

			value = tempPtr->data; // return data being removed
			delete tempPtr; // reclaim previous front node
			length--; // Update the length counter
			return true; // delete successful
		}
		else if (0 < pos && pos < length - 1) // If the position is in the middle or the end
		{
			Node< ItemType > *prevPtr = getEntry(pos - 1);
			Node< ItemType > *currentPtr = prevPtr->getNext();
			prevPtr->setNext(currentPtr->getNext()); // Update the previous node
			if (pos == length - 1)
				lastPtr = prevPtr; // this is now the last node

			value = currentPtr->data; // return data being removed
			delete currentPtr; // reclaim the current node
			length--; // Update the length counter
			return true; // delete successful
		}
		else
			return false; // position is out of range
	}
} // end function remove

// delete all nodes
template< typename ItemType >
void List< ItemType >::clear()
{
	if (!isEmpty()) // List is not empty
	{
		Node< ItemType > *currentPtr = firstPtr;
		Node< ItemType > *tempPtr;

		while (currentPtr != 0) // delete remaining nodes
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->getNext();
			delete tempPtr;
		} // end while
	} // end if
}

// return node from a specified position in the list. If out of range, return last node
template< typename ItemType >
Node< ItemType >* List< ItemType >::getEntry(int pos)
{
	Node< ItemType > *ptr = firstPtr;
	for (int i = 0; i<pos; i++) // Loop through list to find node
	if (ptr->getNext() != 0)
		ptr = ptr->getNext();
	return ptr;
} // end function getEntry

// replace node from a specified position in the list
template< typename ItemType >
bool List< ItemType >::setEntry(ItemType &value, int pos)
{
	Node< ItemType > *newPtr = getNewEntry(value); // new node
	if (remove(value,pos))
	{
		insert(newPtr, pos);
		return true; // If remove is successful, insert and return true
	}
	else
	{
		return false; // position out of range
	}
} // end function setNode


// is List empty?
template< typename ItemType >
bool List< ItemType >::isEmpty() const
{
	return (length == 0);
} // end function isEmpty


// return the length of the List
template< typename ItemType >
int List< ItemType >::getLength() const
{
	return length;
} // end function getLength()

// return pointer to newly allocated node
template< typename ItemType >
Node< ItemType > *List< ItemType >::getNewEntry(const ItemType &value)
{
	return new Node< ItemType >(value);
} // end function getNewEntry

// display contents of List
template< typename ItemType >
void List< ItemType >::print() const
{
	if (isEmpty()) // List is empty
	{
		cout << " The list is empty\n\n";
		return;
	} // end if

	Node< ItemType > *currentPtr = firstPtr;

	cout << " The list is: ";

	while (currentPtr != 0) // get element data
	{
		cout << currentPtr->getItem() << ' ';
		currentPtr = currentPtr->getNext();
	} // end while

	cout << "\n\n";
} // end function print

#endif
