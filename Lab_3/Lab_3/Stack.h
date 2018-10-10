#ifndef _STACK_
#define _STACK_

#include "List.h" // List class definition

template< class STACKTYPE >
class Stack : private List<STACKTYPE>
{
public:
	//Stack size
	int size() const
	{
		return this->getLength();
	}

	// push calls List's insert at pos 0
	void push(const STACKTYPE &data)
	{
		this->insert(data, 0);
	} // end function push

	// pop calls List's remove at pos 0
	bool pop()
	{
		return this->remove(0);
	} // end function pop

	// isStackEmpty calls List's isEmpty
	bool isStackEmpty() const
	{
		return this->isEmpty();
	} // end function isStackEmpty

	// printStack calls List's print
	void printStack() const
	{
		this->print();
	} // end function printStack

	//Peek return the top of the Stack, it calls List's getEntry of the last element 
	STACKTYPE peek() const
	{
		return this->getLast();
	} //end function peek 

}; // end class Stack


#endif
