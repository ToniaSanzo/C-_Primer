#pragma once
#include <string>
#include <cstdlib>
#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};


/**
* Takes input from the user, in this order [string, unsigned int, double] and creates a Sales_data object from that information
*/
void readData(Sales_data &data);

/**
* Runs the methods necessary for the Sales_data struct
*/
int sdMain();


/**
* Return the summation of two Sales_data objects
* @Warning - Throws an error if the Sales_data objects bookNo do not match
*/
Sales_data sum(Sales_data a, Sales_data b);