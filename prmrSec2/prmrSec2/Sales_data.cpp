#include "Sales_data.h"

/**
* Takes input from the user, in this order [string, unsigned int, double] and creates a Sales_data object from that information
*/
void readData(Sales_data &data) {
	std::cout << "Enter the ISBN number, the units sold, and the price: " << std::endl;
	double price;
	std::cin >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
}


/**
* Runs the methods necessary for the Sales_data struct
*/
int sdMain() {
	Sales_data data1, data2;
	readData(data1);
	readData(data2);
	data1 = sum(data1, data2);
	return 0;
}


/**
* Return the summation of two Sales_data objects
* @Warning - Prints an error message if the Sales_data objects bookNo do not match, then returns the first parameter
*/
Sales_data sum(Sales_data a, Sales_data b) {
	Sales_data rtnVal = Sales_data();
	if (a.bookNo == b.bookNo) {
		rtnVal.bookNo = a.bookNo;
		rtnVal.units_sold = a.units_sold + b.units_sold;
		rtnVal.revenue = a.revenue + b.revenue;
		// Print: ISBN, total sold, total revenue, average price per sale
		std::cout << "ISBN: " << rtnVal.bookNo << "\nTotal Sold: " << rtnVal.units_sold << "\nTotal Revenue: " << rtnVal.revenue << std::endl;
		if (rtnVal.units_sold == 0) {
			std::cout << "No units sold" << std::endl;
		}
		else {
			std::cout << "Average Price/Sale: " << rtnVal.revenue / rtnVal.units_sold << std::endl;
		}
	}
	else {
		std::cerr << "ISBN's do not match" << std::endl;
	}
	return rtnVal;
}