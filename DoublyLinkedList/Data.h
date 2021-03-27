#pragma once
#pragma once

#include "DataInterface.h"
#include <iostream>
#include <string>

inline data::data()
{
	toolname;
	quantity = 0;
	cost = 00.00;
}

inline data::data(std::string tn, int qty, double _cost)
{
	int len = tn.length();
	tn.copy (toolname, tn.size()+1);
	quantity  = qty;
	cost = _cost;
}

inline std::string data::getToolName() const
{
	return toolname;
}

inline int data::getQuantity() const
{
	return quantity;
}

inline double data::getCost() const
{
	return cost;
}

inline void data::displayData()
{
	printf("\ntool name: %s \nqty: %d \nBalance: %.2f\n",
		toolname,
		quantity,
		cost);
}


