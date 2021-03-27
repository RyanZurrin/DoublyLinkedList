#pragma once
#include "Node.h"
#include <iostream>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(int maxSize);
	bool addItem(int val, data& _d);
	bool deleteItem(int val);
	bool findItem(int val, data& _d);
	bool isEmpty()const;
	bool isFull()const;
	int getQty()const;
	bool makeEmpty();
	void displayKeys()const;
	void displayAll(std::ostream&);
	~DoublyLinkedList();


private:
	int qty;
	int max;
	node* head;
	node* curr;
};

