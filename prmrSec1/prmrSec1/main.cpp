#include<iostream>
#include "Sales_item.h"

// ------------------------------------------------- Funtion Declaration -------------------------------------------------------------
/*
 *	Print Hello, World
 */
void exercise1d3();


/*
 *	Print product of 2 variables specified by the user
 */
void exercise1d4();


/*
 *	Print product of 2 variables specified by the user
 */
void exercise1d5();


/*
 *	Sums the numbers between 50 to 100
 */
void exercise1d9();


/*
 *	Prints the numbers between 10 - 1 in descending order.
 */
void exercise1d10();


/*
	Prompt user for 2 number, then print the numbers in that range
*/
void exercise1d11();


/*
	exercise1d9(), exercise1d10(), and exercise1d11() rewriting with for loops, instead of while loops
*/
void exercise1d13();


/*
	Print the summation of an unknown number of input
*/
void exercise1d16();

/*
	Read book sales transaction, then write the transaction info
*/
void exercise1d120();


/*
	Produce's the sum of 2 Sales_item with the same isbn
*/
Sales_item exercise1d21(Sales_item item1, Sales_item item2);

/*
	Reads several transactions with the same ISBN, prints the summation of these transactions
*/
void exercise1d22();


/*
	Count the number of transactions that occur
*/
void exercise1d23();


// ------------------------------------------------- Main Method --------------------------------------------------------------------
int main() {
	

	// Example from the book for input and output streams and doing a simple arithmetic operation
	/* 
	 * std::cout << "Enter two numbers:" << std::endl;
	 * int v1 = 0, v2 = 0;
	 * std::cin >> v1 >> v2;
	 * std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
	 */
	/*
	exercise1d3();
	exercise1d4();
	exercise1d5();
	*/
	// Sandboxing some ideas
	/*
	 * std::cout << "The product of " << 3
	 * << " and " << 4
	 * << " is " << 3 * 4 << std::endl;
	 */	

	// Sum the numbers of 1 - 10 in a while loop
	// Example from the book.
	/*int val = 1;
	int sum = 0;

	while (val <= 10) {
		sum += val;
		val++;
	}

	std::cout << sum << std::endl;*/
	

	// exercise1d9();

	// exercise1d10();

	// exercise1d11();

	// Sum values 1 - 10, in a for loop
	/*int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += i;
	}

	std::cout << sum << std::endl;*/

	// exercise1d13();


	// Example from book, demonstrates how to read an unknown number of input
	//int sum = 0, value = 0;
	//// read until end-of-file, calculating a running total of all values read
	//while (std::cin >> value)
	//	sum += value;
	//std::cout << sum << std::endl;


	// exercise1d16();

	//// Example from book, using if statement to count how many consecutive times each distinct value appears
	//// currVal is the number we're counting; we'll read new values into val
	//int currVal = 0, val = 0;
	//// read first number and ensure that we have data to process
	//if (std::cin >> currVal) {
	//	int cnt = 1; // Store the count for the current value we're processing
	//		while(std::cin >> val) { // read the reamining numbers
	//			
	//			if (val == currVal)  // if the value being read matches the value we are matching
	//				++cnt;           // increment count
	//			else {               // otherwise, print the count for the previous value
	//				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	//				currVal = val;    // remember the new value
	//				cnt = 1;          // reset cnt
	//			}
	//		} // while loop ends here
	//		// print the count for the last value in the file

	//		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	//} // outermost if statement

	// exercise1d120();
	
	/*Sales_item item1, item2;

	std::cin >> item1 >> item2;
	if(item1.isbn() == item2.isbn())
		std::cout << exercise1d21(item1, item2);*/

	// exercise1d22();

	//// Example from the book, confirms that the isbn's match before adding them together
	//Sales_item item1, item2;
	//std::cin >> item1 >> item2;
	//if (item1.isbn() == item2.isbn()) {
	//	std::cout << item1 + item2 << std::endl;
	//}
	//else {
	//	std::cerr << "Data must refer to the same ISBN number" << std::endl;
	//	return - 1;
	//}	


	// exercise1d23();

	// Measure t he total revenue of each sales item
	Sales_item total;
	// read the first transaction and ensure that there is data to process
	if (std::cin >> total) {
		Sales_item trans; // variable to hold the running total
		// read and process the remaining transactions

		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans; // update the running total
			}
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}

		// print for the last statement
		std::cout << total << std::endl;
	}
	else {
		// No input! warn the user
		std::cerr << "Invalid data" << std::endl;
		return -1; // indicate failure
	}

	return 0;
}


// ------------------------------------------------- Function Definition -----------------------------------------------------------
/*
 *	Print Hello, World
 */
void exercise1d3() {
	// Print "Hello, World"
	std::cout << "Hello, World" << std::endl;
}


/*
 *	Print product of 2 variables specified by the user
 */
void exercise1d4() {

	// Prompt user to enter 2 numbers
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;		// Variables will hold user input
	std::cin >> v1 >> v2;	// Read user input
	std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
}


/*
 *	Print product of 2 variables specified by the user
 */
void exercise1d5() {

	// Prompt user to enter 2 numbers
	std::cout << "Enter two numbers:";
	std::cout << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1;
	std::cin >> v2;
	std::cout << "The product of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 * v2;
	std::cout << std::endl;
}


/*
 *	Sums the numbers between 50 to 100
 */
void exercise1d9() {

	// Sum the numbers of 50 - 100 in a while loop
	int val = 50;
	int sum = 0;

	while (val <= 100) {
		sum += val;
		val++;
	}

	std::cout << sum << std::endl;
}


/*
 *	Prints the numbers between 10 - 1 in descending order.
 */
void exercise1d10() {

	// Count down from 10 to 1
	int val = 10;

	while (val >= 1) {
		std::cout << val << std::endl;
		--val;
	}
}


/*
	Prompt user for 2 number, then print the numbers in that range
*/
void exercise1d11() {
	int a = 0, b = 0, i = 0;

	// Prompt user for 2 numbers
	std::cout << "Enter 2 numbers" << std::endl;
	std::cin >> a >> b;
	if (a < b) {
		i = a;
		while (i <= b) {
			std::cout << i << std::endl;
			++i;
		}
	} 
	else {
		i = b;
		while (i <= a) {
			std::cout << i << std::endl;
			++i;
		}
	}
}


/*
	exercise1d9(), exercise1d10(), and exercise1d11() rewriting with for loops, instead of while loops 
*/
void exercise1d13() {
	/*
	Sums the numbers between 50 to 100
	*/
	
	// Sum the numbers of 50 - 100 in a while loop
	int sum = 0;

	for (int i = 50; i <= 100; i++) {
		sum += i;
	}

	std::cout << sum << std::endl;

	/*
	 *	Prints the numbers between 10 - 1 in descending order.
	 */

	// Count down from 10 to 1
	for (int val = 10; val >= 1; val--) {
		std::cout << val << std::endl;
	}

	int a = 0, b = 0, i = 0;

	// Prompt user for 2 numbers
	std::cout << "Enter 2 numbers" << std::endl;
	std::cin >> a >> b;
	if (a < b) {
		for (int i = a; i <= b; i++) {
			std::cout << i << std::endl;
		}
	}
	else {
		for (int i = b; i <= a; i++) {
			std::cout << i << std::endl;
		}
	}
}


/*
	Common erros in C++
*/
/*
int exercise1d15(){
	// error: used colon, not semicolon, after endl
	std::cout << "Read each file." << std::endl:
	// 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(252, 45) : error C2143 : syntax error : missing ';' before ':'
	// 1>D:\C++\prmrSec1\prmrSec1\main.cpp(252,45): error C2059: syntax error: ':'

	

	// error: missing quotes from string literal
	std::cout << Read each file. << std::endl;
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 16) : error C2065 : 'Read' : undeclared identifier
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 21) : error C2146 : syntax error : missing ';' before identifier 'each'
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 21) : error C2065 : 'each' : undeclared identifier
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 26) : error C2146 : syntax error : missing ';' before identifier 'file'
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 26) : error C2065 : 'file' : undeclared identifier
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 32) : error C2059 : syntax error : '<<'
		 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(259, 44) : error C2228 : left of '.endl' must have class / struct / union
	
	// error: second output operator is missing
	std::cout << "Write new master." std::endl;
	// 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(269, 40) : error C2143 : syntax error : missing ';' before 'std::endl'
	// 1 > D:\C++\prmrSec1\prmrSec1\main.cpp(269, 40) : warning C4551 : function call missing argument list

	return 0
	// 1>D:\C++\prmrSec1\prmrSec1\main.cpp(273,1): error C2143: syntax error: missing ';' before '}'

}*/


/*
	Print the summation of an unknown number of input
*/
void exercise1d16() {
	int sum = 0, in = 0;

	while (std::cin >> in) {
		sum += (int)in;
	}

	std::cout << sum << std::endl;
}


/*
	Read book sales transaction, then write the transaction info
*/
void exercise1d120() {
	
	// Check if the user has more transactions to enter
	char cont = 'y';
	Sales_item transaction; // Stores the transaction

	do {
		std::cout << "Enter transaction" << std::endl;
		std::cin >> transaction;												  // Get the transaction information from the user
		std::cout << transaction << "\n\n Enter [y] to continue: " << std::endl;  // Print transaction to the console, prompt user to
		                                                                          // enter another transaction.
		std::cin >> cont;
		
	} while (cont == 'y');
}


/*
	Produce's the sum of 2 Sales_item with the same isbn
*/
Sales_item exercise1d21(Sales_item item1, Sales_item item2) {
	return item1 + item2;
}


/*
	Reads several transactions with the same ISBN, prints the summation of these transactions
*/
void exercise1d22() {
	Sales_item currItem, sumItem;

	std::cin >> sumItem;
	while (std::cin >> currItem) {
		sumItem += currItem;
	}

	std::cout << sumItem << std::endl;
}


/*
	Count the number of transactions that occur
*/
void exercise1d23() {
	Sales_item currItem, valItem;

	// Get the first transaction the count is set to 1
	std::cin >> currItem;
	int count = 1;
	while (std::cin >> valItem) {
		if (currItem.isbn() == valItem.isbn()) {
			count++;
		}
		else {
			std::cout << currItem.isbn() << " had " << count << " different transactions" << std::endl;
			currItem = valItem;
			count = 1;
		}
	}

	// print for the last statement
	std::cout << currItem.isbn() << " had " << count << " different transactions" << std::endl;
}