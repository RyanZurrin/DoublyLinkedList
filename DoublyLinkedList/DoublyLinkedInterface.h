#pragma once
#include "Node.h"
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(int maxSize);
	DoublyLinkedList(const DoublyLinkedList& dll);
	bool addItem(int val, Data& _d);
	bool deleteItem(int val, Data& _d);
	bool findItem(int val, Data& _d);
	bool isEmpty()const;
	bool isFull()const;
	int getQty()const;
	bool makeEmpty();
	void printList();
	void printReverse();
	~DoublyLinkedList();


private:
	int qty;
	int max;
	Node* head;
	Node* tail;

};

