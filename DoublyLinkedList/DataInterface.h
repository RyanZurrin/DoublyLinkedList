#pragma once

#pragma once
#include <string>

struct  data
{
public:
	char toolname[35];
	int quantity;
	double cost;
	data();
	data(std::string tn, int qty, double _cost);
	std::string getToolName()const;
	int getQuantity()const;
	double getCost()const;
	void displayData();


};
