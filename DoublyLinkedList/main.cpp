#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList test;
	data t1("hammer", 5, 19.99);
	data t2("saw", 15, 22.50);
	data t3("level", 12, 15.99);
	data t4("nails", 45, 14.99);
	data t5("tape measure", 45, 12.50);
	data t6("ladder", 2, 215.39);
	data found;

	test.addItem(3, t1);
	test.addItem(2, t2);
	std::cout << "qty: " << test.getQty() << std::endl;
	test.displayKeys();
	test.addItem(5, t3);
	test.displayKeys();
	test.addItem(1, t1);
	test.addItem(6, t2);
	std::cout << "qty: " << test.getQty() << std::endl;
	test.displayKeys();
	test.addItem(4, t3);
	test.displayKeys();
	test.addItem(4, t3);
	test.displayKeys();
	test.deleteItem(4);
	test.findItem(6, found);
	found.displayData();
	test.displayKeys();
	std::cout << "qty: " << test.getQty() << std::endl;

	return 0;
}