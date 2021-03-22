#pragma once
#include "DoublyLinkedInterface.h"

inline DoublyLinkedList::DoublyLinkedList()
{
	qty = 0;
	max = INT_MAX;
	head = NULL;
	tail = NULL;
}

inline DoublyLinkedList::DoublyLinkedList(int maxSize)
{
	qty = 0;
	if (maxSize > 0)
	{
		max = maxSize;
	}
	else
		max = INT_MAX;
	head = NULL;
	tail = NULL;
}

inline DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
	qty = dll.qty;
	max = dll.max;
	head = dll.head;
	tail = dll.tail;

}

inline bool DoublyLinkedList::addItem(int val, Data& _d)
{
	Node* temp;
	if (isFull())
	{
		return false;
	}
	temp = new Node;
	temp->key = val;
	temp->d = _d;
	if(isEmpty())//first node being added to list
	{
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		qty++;
		return true;
	}
	//only one node in list adding the second node
	else if (head->next == NULL && tail == head)
	{
		if (head->key == val)//duplicate, don't add;
		{
			return false;
		}
		else if (val < head->key)//adding new first node
		{
			temp->next = head;
			head->prev = temp;
			temp->prev = NULL;
			head = temp;
			qty++;
			return true;
		}
		else//adding second node
		{
			temp->prev = head;
			head->next = temp;
			temp->next = NULL;
			tail = temp;
			qty++;
			return true;
		}
	}
	else
	{

	}
	return false;
}

inline bool DoublyLinkedList::deleteItem(int val, Data& _d)
{

	return false;
}

inline bool DoublyLinkedList::findItem(int val, Data& _d)
{
	return false;
}

inline bool DoublyLinkedList::isEmpty() const
{
	return qty==0;
}

inline bool DoublyLinkedList::isFull() const
{
	return qty>=max;
}

inline int DoublyLinkedList::getQty() const
{
	return qty;
}

inline bool DoublyLinkedList::makeEmpty()
{
	Node* temp;
	if (isEmpty())
	{
		return false;
	}
	while (qty!=0)
	{
		temp = head;
		head = head->next;
		delete temp;
		qty--;
	}
	return true;
}

inline void DoublyLinkedList::printList()
{
}

inline void DoublyLinkedList::printReverse()
{
}

inline DoublyLinkedList::~DoublyLinkedList()
{
	makeEmpty();
}
