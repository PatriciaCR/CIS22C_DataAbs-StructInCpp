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
	bool pop(STACKTYPE &data)
	{
		return this->remove(data,0);
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
}; // end class Stack


#endif
