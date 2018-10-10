#ifndef _NODE_
#define _NODE_

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 13
template< typename ItemType > class List;

template<class ItemType>
class Node
{
	friend class List<ItemType>; // make List a friend
private:
	ItemType data; //A data item
	Node <ItemType>* nextPtr; // Pointer to next node 
public:
	Node();
	Node(const ItemType & anItem);
	Node(const ItemType &anItem, Node <ItemType>* nextPtr);
	void setItem(const ItemType & anItem);
	void setNext(Node<ItemType>* nextPtr);
	ItemType getItem() const;
	Node <ItemType>* getNext() const;
}; //End Node

template<class ItemType>
Node<ItemType>::Node() :nextPtr(nullptr)
{

}//end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType & anItem) : data(anItem), nextPtr(nullptr)
{
}//end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node <ItemType>* nextNodePtr) : data(anItem), nextPtr(nextNodePtr)
{
}//end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	data = anItem;
}//end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	nextPtr = nextNodePtr;
}//end setNext

template<class ItemType>
ItemType Node<ItemType> ::getItem() const
{
	return data;
}//end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType> ::getNext() const
{
	return nextPtr;
}//end getNext 

#endif