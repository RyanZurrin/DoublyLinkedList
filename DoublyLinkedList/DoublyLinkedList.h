#pragma once
#include "DoublyLinkedInterface.h"
#include <iostream>

inline DoublyLinkedList::DoublyLinkedList()
{
	qty = 0;
	max = INT_MAX;
	head = NULL;
	curr = NULL;
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
	curr = NULL;
}


inline bool DoublyLinkedList::addItem(int _key, data& _d)
{
	node* temp;
	if (isFull())
	{
		std::cout << "cant add item list is full" << std::endl;
		return false;
	}
	temp = new node;
	temp->key = _key;
	temp->d = _d;
	if(isEmpty())//first node being added to list
	{
		std::cout << "adding first node to list: "<< _key << std::endl;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		curr = head;
		qty++;
		return true;
	}
	//only one node in list adding the second node
	else if (head->next == NULL)
	{
		if (head->key == _key)//duplicate, don't add;
		{
			std::cout << "duplicate item didn't add: "<<_key<<std::endl;
			return false;
		}
		else if (_key < head->key)//adding new first node
		{
			std::cout << "adding new node to beginning2: "<< _key<<std::endl;
			temp->next = head;
			head->prev = temp;
			temp->prev = NULL;
			head = temp;
			qty++;
			return true;
		}
		else//adding second node
		{
			std::cout << "adding second node to list: "<<_key<<std::endl;
			temp->prev = head;
			head->next = temp;
			temp->next = NULL;
			curr = temp;
			qty++;
			return true;
		}
	}
	else//every other case
	{
		if (head->key == _key)//duplicate
		{
			std::cout << "duplicate item didn't add: "<<_key<<std::endl;
			return false;
		}
		if (head->key > _key)//adding new first node with list of many nodes
		{
			std::cout << "adding new node to beginning3+: "<< _key<<std::endl;
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
			qty++;
			return true;
		}
		if (curr->key > _key)
		{
			curr = head;
		}
		for (;curr->next != NULL; curr = curr->next)
		{
			if (curr->key == _key)//duplicate
			{
				std::cout << "duplicate item didn't add: "<<_key<<std::endl;
				return false;
			}
			if (curr->key > _key)//adding node to middle of list
			{
				std::cout << "adding node to middle of list: " <<_key << std::endl;
				temp->next = curr;
				temp->prev = curr->prev;
				curr->prev->next = temp;
				curr->prev = temp;
				qty++;
				return true;
			}

		}//end for loop
		if (curr->next == NULL && curr->key < _key)//adding node to end of list
		{
			std::cout << "adding node to end of list: "<<_key << std::endl;
			temp->next = NULL;
			curr->next = temp;
			temp->prev = curr;
			qty++;
			return true;
		}
	}
	std::cout << "something went wrong and no node added: "<<_key<<std::endl;
	return false;
}

inline bool DoublyLinkedList::deleteItem(int _key)
{
	node* temp;
	data junk;
	if(isEmpty()) {
		std::cout <<" list not initialized." << std::endl;
		return false;
	}
	bool found = findItem(_key, junk);
	if (found)
	{
		temp = curr;
		if (curr == head)
		{
			std::cout << "deleting start key"<<std::endl;
			head = head->next;
			head->prev = NULL;
			curr = head;
		}
		else if (curr->next == NULL)
		{
			std::cout << "deleting last key"<<std::endl;
			curr = curr->prev;
			curr->next = NULL;
		}
		else
		{
			std::cout << "deleting middle key"<<std::endl;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
		delete temp;
		qty--;
		return true;
	}//end if
	return false; // not found
}//end deleteItem


inline bool DoublyLinkedList::findItem(int _key, data& _d)
{
	if (isEmpty())
	{
		std::cout << "in getItem and is empty list" << std::endl;
		return false;
	}
	if (head->key == _key)
	{
		std::cout << "item found at start of list: "<<_key <<std::endl;
		_d = head->d;
		return true;
	}

	curr = head->next;
	if (curr->key == _key)
	{
		std::cout << "item found second slot: "<<_key<<std::endl;
		_d = curr->d;
		return true;
	}
	else
	{
		std::cout << "in getItem else statement now"<<std::endl;
		while (curr->next != head)
		{
			std::cout<< "key: "<< _key << " in while loop checking curr: "<< curr->key<<std::endl;
			if (_key == curr->key)
			{
				std::cout << "getItem found: " << _key << std::endl;
				_d = curr->d;
				std::cout << "curr at: "<< curr->key <<std::endl;
				return true;
			}
			curr = curr->next;
		}
		std::cout << "leaving getItem else statement now"<<std::endl;
	}
	std::cout << "in getItem and item was not found: "<< _key << std::endl;
	return false;



	/*
	if (isEmpty())
	{
		std::cout << "list empty cant find: "<< _key <<std::endl;
		return false;
	}
	if (_key < curr->key)
	{
		curr = head;
	}
	do
	{
		if (_key == curr->key)
		{
			std::cout << "found: "<< _key <<std::endl;
			_d = curr->d;
			return true;
		}
		if (curr->key > _key)
		{
			std::cout << "found: "<< _key <<std::endl;
			return false;
		}
		curr = curr->next;
	}
	while (curr != NULL);
	std::cout << "curr at: "<< curr->key <<std::endl;
	//curr = head;
	return false;
	*/
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
	node* temp;
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

inline void DoublyLinkedList::displayKeys() const
{
	node* printer;
	int count = qty;

	if (head != NULL)
	{
		printer = head;
		std::cout << std::endl;
		do {
			std::cout << printer->key << "->";
			printer = printer->next;
			count--;
		} while (count!=0);
	}
	std::cout << std::endl;
}

inline void DoublyLinkedList::displayAll(std::ostream& out)
{
}

inline DoublyLinkedList::~DoublyLinkedList()
{
	makeEmpty();
}
