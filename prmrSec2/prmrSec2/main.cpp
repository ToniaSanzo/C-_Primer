#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Sales_item.h"
#include "Sales_data.h"

using namespace std;

//struct Sales_data {
//	std::string bookNo;
//	long isbn;
//	unsigned units_sold;
//	double revenue;
//};


// 2 different but equivalent ways to define Sales_data varaibles
//struct Sales_data {/* ... */ } accum, trans, *salesptr;
//// Varaibles are defined before the semicolon for the struct
//// The below method is equivalent but a better way of defining these objects
//struct Sales_data{/* ... */ };
//Sales_data accum, trans, *salesptr;


//// Define aliases for types with typedef
//typedef double wages;				// wages is a synonym for double
//typedef wages base, *p;				// base is a synonym for double, and p for double*
//
//// You can also assign type aliases for types via an alias declaration
//using SI = Sales_item;				// SI is synonymous with Sales_item

// ~~~~~~~~~ Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// constexpr is a top-level const, therefore these statements are very similar
//	[constexpr int *np = nullptr; ] is logically equivalent to [int *const np = nullptr;]
//constexpr int *np = nullptr;		// np is a const pointer to the nullptr
//int j = 0;
//constexpr int i = 42;				// i is a const int
//// i and j must be defined outside of any function
//constexpr const int *p = &i;		// p is a const pointer to a const int i
//constexpr int *p1 = &j;				// p1 is a const pointer to a int j

// ~~~~~~~~~ Function declaration ~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
	Check the output of different arithmetic expressions between signed and unsigned typoes
*/
void exercise2d4();


/*
	Apply the discount to a price
*/
double applyDiscount(double price, double discount);


/*
	Example of global and local scope
*/
void scopeExample();


/*
	Method to confirm my assumption about scope
*/
void exercise2d13();


/*
	Method to see the legality of some code
*/
void exercise2d14();


// Transitioned to a new style to keep the definition and declaration together above the main method

void exercise2d18() {
	int iVal1 = 13, iVal2 = 42;
	int *p1 = &iVal1;	// p1 initially points to the address of iVal1
	cout << "p1 is equal to 13: " << *p1 << endl;
	p1 = &iVal2;		// p1 is updated to point to the addrses of iVal2
	cout << "p1 is now equal to 42: " << *p1 << endl;
	*p1 = 33;			// iVal2 is updated through the pointer p1
	cout << "iVal2 is now equal to 33: " << iVal2 << endl;
}


void exercise2d20() {
	int i = 42;
	int *p = &i;
	*p = *p * *p;
	cout << "i = 1764 : " << i << endl;
}

 
/**
* function used to return a variable of type int, used for testing the decltype() base type 
*/
int f() { return 0; }


// ~~~~~~~~~ Main Method ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
	Main Method
*/

int main() {
	//// Example: [Type Conversion] shows what happens when we assign an arithmetic type to another arithmetic type
	//bool b = 42;			// b is true
	//int i = b;				// i has value 1
	//i = 3.14;				// i has value 3
	//double pi = i;			// pi has value 3.0
	//unsigned char c = -1;	// Assuming 8-bit char, c has a value of 255
	//signed char c2 = 256;	// Assuming 8-bit char, the value of c2 is undefined

	//int j = 42;
	//if (j) // j is converted to a bool, resulting in j being seen as true since j is a nonzero value
	//	j = 0;

	//// Undefined behavior when adding an int to an unsigned int
	//unsigned int u = 10;
	//int s = -42;
	//std::cout << s + s << std::endl; // prints -84
	//std::cout << u + s << std::endl; // undefined behavior, prints 4294967264 because of 32-bit ints

	//// Integer wrapping error because unsigned subtraction results in a negative number
	//unsigned u1 = 42, u2 = 10;
	//std::cout << u1 - u2 << std::endl; // OK: results in 32
	//std::cout << u2 - u1 << std::endl; // "OK"(ish): result wraps around because the difference results in a negative value


	////// Wrong: u can never be less than 0; the condition always succeeds (infinite loop)
	////for (unsigned u = 10; u >= 0; u--) {
	////	std::cout << u << std::endl;
	////}

	//// In order to rewrite the above loop, so that it is not infinite
	//unsigned u4 = 11;	// Start the loop one past the first element we want to print
	//while (u4 > 0) {
	//	--u4;			// decrement first, so that the last iteration will print 0
	//	std::cout << u4 << std::endl;
	//}

	//// exercise2d4();
	//
	//
	//L'a';		// Wide character literal, type is wchar_t
	//u8"hi!";	// utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
	//42ULL;		// unsigned integer literal, type is unsigned long long
	//1E-3F;		// single-precesion floating-point number, type is a float
	//3.14159L;	// extended-precision floating-point literal, type is long double

	//
	//cout << "2M\n";			// Print 2M followed by a newline
	//cout << "2\tM\n";		// Print 2 followed by a tab, than M followed by a newline
	//cout << endl;			// Flush buffer


	//// Variable declaration, example from the book
	//int sum = 0, value,					// Sum, value, and units_sold have type int
	//	units_sold = 0;					// sum and units_sold have a initial value 0
	//Sales_item item;					// item has type Sales_item
	//// String is a library type, representing a variable-length sequence of characters
	//std::string book("0-201-78345-X");	// Book initializaed to a string literal

	//// Initialization , example from the book
	//// OK: price is initialized before it used to initialize discount
	//double price = 109.99, discount = price * 0.16;
	//// OK: call applyDiscount and use the return value to initialize salePrice
	//double salePrice = applyDiscount(price, discount);

	//// Initializing a varaible 4 different ways
	//int units_sold1 = 0;
	//int units_sold2 = { 0 };	// The form of initialization that uses the curly braces is referred to as list initialization
	//int units_sold3 { 0 };		// Braced kist initializers can now be used used whenever we initialize an object and in some cases 
	//							// when we assign a new value to an object
	//int units_sold4(0);


	//// List initialization, eexample from the book
	//long double ld = 3.1415926536;
	//int a{ ld }, b = { ld };	// error: because a loss of precision occurs, list initialization "curly brace" is not allowed
	//int c(ld), d = ld;			// OK: but the value will be truncated

	//// Default initialization, example from the book
	//std::string empty;	// empty is implicitly initialized to the empty string
	//Sales_item item;	// item is initialized to the default value for objects of type Sales_item

	//// Variable Declarations and Definitions, example from the book
	//extern int i;	// Declares but does not define i
	//int j;			// declares and defines j

	//// If we initiliaze a variable declared with extern, than we are defining the varaible and it is no longer just a declarations
	//
	//extern double pi = 3.14159265358979323; // definition

	//scopeExample();

	//exercise2d13();
	//exercise2d14();

	//// References &, example from the book
	//int ival = 1024;
	//int &refVal = ival;	// refVal refers to (is another name for) ival
	////int &refVal2;		// error: a referenece must be initialized
	//
	//refVal = 2;			// assigns 2 to the object which refVal refers, i.e., to ival
	//int ii = refVal;	// same as ii = ival

	//// ok: refVal3 is bound to the object which refVal is bound, i.e., ival
	//int &refVal3 = refVal;
	//int i = refVal;		// OK: initilizesi to the same value as ival

	//int i = 1024, i2 = 2048;	// i and i2 aare both ints
	//int &r = i, r2 = i2;		// r is a reference bound to i; r2 is an int
	//int i3 = 1024, &ri = i3;	// i3 is an int; r1 is a reference bound to i3
	//int &r3 = i3, &r4 = i2;		// both r3 and rr4 are references

	//int &refVal4 = 10;			// error: intiliazer must be an object
	//double dval = 3.14;
	//int &refVal5 = dval;		// error: intializer must be an int object
	
	//// Test some references
	//int i = 0, &r1 = i; double d = 0, &r2 = d;
	//r2 = 3.1415;
	//cout << d << " = pi" << endl;
	//r2 = r1;
	//cout << d << " = 0" << endl;
	//i = r2;
	//cout << i << " = 0" << endl;
	//r2 = 3;
	//r1 = d;
	//cout << i << " = 3" << endl;

	//int i, &ri = i;
	//i = 5; ri = 10;
	//cout << 10 << 10 << endl;

	// Pointer Example from the text
	//int ival = 42;
	//int *p = &ival;	// pointer p points to the address of ival

	//double dval;
	//double *pd = &dval;	// OK: inittializer is the address of a double
	//double *pd2 = pd;	// OK: initializer is a pointer to a double
	//int *pi = pd;		// ERROR: *pi is an int pointer and pd is a double address
	//pi = &dval;			// ERROR: assigning the address of a double to an int pointer

	//int ival = 42;
	//int *p = &ival;	// pointer p stores the address of ival
	//cout << *p;		// " * " dereferences the pointer p, to get the object stored in memory at that location 42
	//
	//// We can assign values to ival by dereferencing the pointer p
	//*p = 0;
	//cout << " " << ival;

	//int i = 42;
	//int &r = i;		// r is a reference of i
	//int *p;			// p is an int pointer
	//p = &i;			// &i is the address of int i, and p now points to that address
	//*p = i;			// the object p points to is updated to i
	//int &r2 = *p;	// r2 is a reference to the object pointed to by p

	//// Null pointer examples from the text
	//int *p1 = nullptr;	// equivalent to int *p1 = 0;
	//int *p2 = 0;		// Initialize p2 from the literal constant 0
	//// must #include cstdlib
	//int *p3 = NULL;		// Equivalent to int *p3 = 0;

	//int zero = 0;
	//int *pi = zero;		// ERROR: cannot assign an int to a pointer

	// Pointer's can be used to point to mutiple address, but a reference can not be changed once initialized
	//int i = 42;
	//int *p1 = nullptr;	// p1 is initialized, but with no address
	//int *p2 = &i;		// p2  contains the address of i
	//int *p3;			// p3 is uninitialized
	//p3 = p2;			// p3 points to the address of i
	//p2 = nullptr;		// p2 now addresses no object

	//int ival = 33;
	//p1 = &ival;			// p1 is updated to contain the address of ival
	//*p1 = 0;			// ival is updated to 0

	
	//// pointers in conditionals
	//int ival = 1024;
	//int *p1 = nullptr;
	//int *p2 = &ival;
	//if (p1) { // evaluates to false because p1 is the nullptr
	//}

	//if (p2) { // evalutes to true because p2 contains the address of ival
	//}

	//double obj = 3.14, *pd = &obj;
	//// OK: void* can hold the address of any data pointer type
	//void *pv = &obj;	// obj can be an object of any type
	//pv = pd;			// pv can hold a pointer to any type

	//exercise2d18();
	//exercise2d20();
	//int i = 0;
	//double *d = &i; // error
	//int *ip = i;	// error
	//int *p = &i;	// legal
	
	//// i is an int, p is a pointer to an int, and r is a reference to an int
	//int i = 1024, *p = &i, &r = i;

	//int ival = 1024;
	//int *pi = &ival;	// pi points to an int
	//int **ppi = &pi;	// ppi points to a pointer that points to an int

	// [ppi]->[pi]->[1024]

	//int i = 42;
	//int *p = nullptr;	// p is an int pointer
	//int *&r = p;		// r is a reference to the pointer p
	//r = &i;				// r refers to a pointer, this statement sets p to point to i
	//*r = 0;				// dereferencing r yields i, the object to which p points; changes i to 0

	//const int I = 42;
	//const int CI = I;	// OK: the value in I is copied into CI
	//const int J = CI;	// OK: the value in CI is copied into J

	//// file_1.cc defines and initializes a const that is accessible to other files.
	//extern const int bufSize = fcn();
	////	file_1.h
	//extern const int bufSize;	// Same bufSize as defined in file_1.cc

	//const int ci = 1024;
	//const int &r1 = ci;	// OK: both reference and underlying object are const
	//r1 = 42;			// ERROR: r1 is a reference to const
	//int &r2 = ci;		// ERROR: nonconst reference to a const object
	
	//int i = 42;
	//const int &r1 = i;			// OK: we can bind a const int& to a plain int object
	//const int &r2 = 42;			// OK: r2 is a reference to const
	//const int &r3 = r1 * r2;	// OK: r3 is reference to const
	//int &r4 = r1 * 2;			// ERROR: r4 is a nonconst reference

	//// The easiest way to understand this difference in initialization rules is to consider what happens when we bind a reference to an object of a different type:
	//double dVal = 3.14;
	//const int &ri = dVal;

	//// Here ri refers to an int, operations of ri will be integer operations, but dVal is a double not an int... Therefore, the compiler transforms the code into something like this...
	//const int temp = dVal;		// Creater a temporary const int from the double
	//const int &ri = temp;		// bind ri tho that temporary

	//int i = 42;
	//int &r1 = i;			// i is bound to r1
	//const int &r2 = i;		// r2 also bound to i; but cannot be used to change i
	//r1 = 0;					// r1 is nonconst, i is 0
	//r2 = 0;					// r2 is const so this is illegal
	
	//const double pi = 3.14159;		// pi is a const
	//double *ptr = &pi;				// ERROR: normal double pointer can not point to a const double
	//const double *cptr = &pi;		// OK: cptr is a constant double pointer, therefor can refer to const double objects
	//*cptr = 42;						// ERROR: cannot update the value of a const double
	//double dval = 3.14;				// dval is a normal double and can be updated
	//cptr = &dval;					// this is ok, you just cannot update dval with cptr

	//int errNo = 0;
	//int *const curErr = &errNo;		// curErr, is a const pointer, it will always point to errNo
	//const double pip = 1.1;			// pip is a const double, its value cannot be updated
	//const double *const pipp = &pi;	// pip cannot be updated through pipp, and pipp will always point to pip think "const pointer to const"

	//*pipp = 2.72;					// ERROR: pipp points to a const
	//// if the object to which curErr points (i.e., errNo) is nonzero
	//if (*curErr) {
	//	// Call errorhandler here
	//	*curErr = 0;	// OK: curErr is a const pointer to a non const object so it can update the non const object
	//}

	//const int i2 = 0, &r = i2;
	//int *p, *const p2 = p;
	//const int *const p3 = &i2;
	

	//// Example of top-level const (An object const) and low-level const (A reference or pointer to a const)
	//int i = 0;
	//int *const p1 = &i;			//  We can't change what p1 points to
	//const int ci = 42;			// We can't change the value of ci
	//const int *p2 = &ci;		// We can't change what p2 points too
	//const int *const p3 = p2;	// Right-most const is top-level const, leftmost const is low-level const
	//const int &r = ci;			// Low-level const, cannot change the value referenced by r, with r
	//i = ci;						// copying top-level const in ci is ignored
	//p2 = p3;					// copying top-level const in p3 is ignored

	//int *p = p3;				// ERROR: p3 has low-level const but p doesn't
	//p2 = p3;					// OK: p2 has the same low-level const as p3
	//p2 = &i;					// OK: a low-level const pointer can refer to a nonconst object
	//int &r = ci;				// ERROR: r does not have the low-level const to refer to a const object
	//const int &r2 = i;			// OK: can bind const int& to plain int

	//const int v2 = 0;
	//int v1 = v2;
	//int *p1 = &v1, &r1 = v1;
	//const int *p2 = &v2, *const p3 = &i, &r2 = v2;

	//r1 = v2;
	//p2 = p3;
	
	//// Constant expressions are expressions whose values cannot change, therefor are evaluated at compile time
	//const int max_files = 20;			// Constant expression
	//const int limit = max_files + 1;	// Constant expression
	//int staff_size = 27;				// Not a constant expression
	//const int sz = getSize();			// Not a constant expression

	//constexpr int mf = 20;				// 20 is a constant expression
	//constexpr int limit = mf + 1;		// mf + 1 is a constant expression
	//constexpr int sz = size();			// ok only if size is a constexpr function

	//const int *p = nullptr;				// p is a pointer to a const int
	//constexpr int *q = nullptr;			// q is a const pointer to int

	//int null = 0, *p = &null;

	//typedef char *pstring;				// pString is a character pointer
	//char x = 0;
	//const pstring cstr = &x;			// cstr is a const pointer to a char
	//// [ const pstring cstr = &x; ] logically equivalent to [ char *const cstr = &x;
	//const pstring *ps;					// ps is a pointer to a constant pointer to char
	
	//int val1 = 0, val2 = 3;
	//// item's type is deduced by the compilier to be equal to an int because val1 + val2 returns an int
	//auto item = val1 + val2;	// item initialized to the result of val1 + val2

	//// You can use auto to declare mutiple variables on one line, however you have to make sure that they all are being declared to the same base type
	//auto i = 0, *p = &i;	// OK: because i and p share the same base type(int) despite p being a compound type (pointer to int)
	//auto sz = 0, pi = 3.14;	// ERROR: because sz has base type (int) and pi has base type (double) they cannot be declared on the same line

	//int i = 0, &r = i;
	//auto a = r;				// a is an int (r is an alias for i)

	//const int ci = i, &cr = ci;
	//auto b = ci;		// b is an int because the top level const is dropped
	//auto c = cr;		// c is an int because cr is a reference to a const int (the const is top-level here though because cr is an alias for const int)
	//auto d = &i;		// d is a pointer to an int
	//auto e = &ci;		// e is a pointer to a const int, since the const is low level here
	//
	//// if we want the deduced type to have a top-level const, we must say so explicitly
	//const auto f = ci;	// deduced type of f is int, but f is a const int because f was declared as a const

	//auto &g = ci;		// g is a reference to the const int ci
	////auto &h = 42;		// ERROR: we can't bind an int reference to a literal
	//const auto &j = 42;	// OK: we can bind a const int reference to a literal

	//auto k = ci, &l = i;	// k is an int, and l is a reference to an i, this is ok because they share the same base type
	//auto &m = ci, *p = &ci;	// m is a reference to a const int; p is a pointer to const int
	//
	////auto &n = i, *p2 = &ci;	// ERROR: n is of base type int and p2 is of base type const int
	//a = 42;
	//b = 42;
	//c = 42;
	////d = 42;
	////e = 42;
	////g = 42;

	//cout << "42 = " << a << endl;
	//cout << "42 = " << b << endl;
	//cout << "42 = " << c << endl;
	//cout << "0 = " << i << endl;

	//const int i = 42;
	//auto j = i; const auto &k = i; auto *p = &i;
	//const auto j2 = i, &k2 = i;

	//cout << "j is (42:" << j << ")";
	//j = 13;
	//cout << ", j is now (13:" << j << ")" << endl;

	//cout << "k is (42:" << k << ") k is a reference to a const int so trying to change it results in an error" << endl;
	//
	//cout << "*p is (42:" << *p << ") its a pointer to a const so we cannot change it" << endl;

	//cout << "j2 is (42:" << j2 << ") its a const int so we cannot change it" << endl;

	//cout << "k2 is (42:" << k2 << ") a const int reference so we cannot change it" << endl;

	//int x = 3;
	//decltype(f()) sum = x; // sum has whatever type f() returns

	//const int ci = 0, &cj = ci;
	//decltype(ci) x = 0;	// x is type const int
	//decltype(cj) y = x;	// y is const int &[reference] and is bound to x
	//decltype(cj) z;		// ERROR: references must be initialized when they are declared

	//// decltype of an expression can be a reference type
	//int i = 42, *p = &i, &r = i;
	//decltype(r + 0) b;		// OK: addition yields an int; b is an (uninitialized) int
	//decltype(*p) c = i;		// ERROR: c is an int& and must be initialized

	//// decltype of a parenthesized variable is always a reference
	//decltype((i)) d;	// ERROR: d is an int&; must be initialized
	//decltype(i) e;		// OK: e is an (uninitialized) int

	//// Exercise 2.36, expected output 4444
	//int a = 3, b = 4;
	//decltype(a) c = a;
	//decltype((b)) d = a;
	//++c;
	//++d;
	//cout << a << b << c << d << endl;

	//// Exercise 2.37, expected output 3433
	//int a = 3, b = 4;
	//decltype(a) c = a;
	//decltype(a = b) d = a;
	//cout << a << b << c << d << endl;
	
	//// Exercise 2.38 2 situations where auto and decltype differ (auto ignores top-level const, decltype does not)
	//int i = 3;
	//auto j = i;
	//decltype(i) k = i;

	//const int x = 3;
	//auto y = x;
	//decltype(x) z = 4;

	//Sales_data sales_data = Sales_data();
	//printf("Empty String( = %s), (0 = %ld), (0.0 = %f), (0 = %u)", sales_data.bookNo.c_str(), sales_data.isbn, sales_data.revenue, sales_data.units_sold);

	sdMain();

	return 0;
}


// ~~~~~~~~~ function definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
	Check the output of different arithmetic expressions between signed and unsigned typoes
*/
void exercise2d4() {
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;

	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;
}


/*
	Apply the discount to a price
*/
double applyDiscount(double price, double discount) {
	return price -= discount;
}


/*
	Example of global and local scope, note it is bad practice to use the same name for a local and global variable
	This was demonstrated only for educational value
*/
int reused = 42;	// reused has global scope

void scopeExample() {
	int unique = 0; // unique has block scope
	// output #1: uses global reused; prints 42 0
	cout << reused << " " << unique << endl;
	int reused = 0;	// new local varaible named reused, hides reused's global scope
	// output #2: uses the local reused; prints 0 0
	cout << reused << " " << unique << endl;
	// output #3: explicitly requests the global reused; prints 42 0
	cout << ::reused << " " << unique << endl;
}


/*
	Method to confirm my assumption about scope
*/
void exercise2d13() {
	int i = 100;
	int j = i;
	cout << i << endl;
}


/*
	Method to see the legality of some code
*/
void exercise2d14() {
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i) {
		sum += i;
		cout << i << endl;
	}
	cout << i << " " << sum << endl;
}