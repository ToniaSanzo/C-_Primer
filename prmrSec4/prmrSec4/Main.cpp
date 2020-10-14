#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ClassExample {
public:
    int i;
    double d;
    ClassExample() { i = 0; d = 0.0; }
};

// Determines if an int is odd
bool exc4d5(int i) {
    return i % 2;
}

// Reads ints from the input and stops when it reads a 42
void exc4d10() {
    int temp;
    while (cin >> temp && temp != 42) {
        cout << temp << endl;
    }
}

// check is a is less than b, b is less than c, and c is less than d 
bool exc4d11(int a, int b, int c, int d) {
    return a < b && b < c && c < d;
}

// Uses the conditional operator to find and double the odd values within a vector
void exc4d21(vector<int> &v) {
    for (auto itr = v.begin(); itr != v.end(); ++itr) {
        (((*itr) % 2) == 1) ? (*itr *= 2) : NULL;
    }
}

// Prints the integer as a binary number
void print_bits(int b) {
    unsigned int left_end = 1U << 31;
    for (auto index = 0; index < 32; ++index) {
        cout << (bool)(left_end & b);
         b = b << 1;
    }
    cout << endl;
}

// Prints the char as a binary number
void print_bits(char b) {
    unsigned int right_end = 1U << 7;
    for (auto index = 0; index < 8; ++index) {
        cout << (bool)(right_end & b);
        b = b << 1;
    }
    cout << endl;
}

int test(int i) {
    cout << i << endl;
    return i;
}

// Function to print the size of all the built in types
void exc4d28() {

    cout << "nullptr_t size: " << sizeof(nullptr_t) << endl;
    cout << "bool size: " << sizeof(bool) << endl;
    cout << "char size: " << sizeof(char) << endl;
    cout << "signed char size: " << sizeof(signed char) << endl;
    cout << "unsigned char size: " << sizeof(unsigned char) << endl;
    cout << "float size: " << sizeof(float) << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "long double size: " << sizeof(long double) << endl;
    cout << "short size: " << sizeof(short) << endl;
    cout << "unsigned short size: " << sizeof(unsigned short) << endl;
    cout << "int size: " << sizeof(int) << endl;
    cout << "unsigned int size: " << sizeof(unsigned int) << endl;
    cout << "long size: " << sizeof(long) << endl;
    cout << "unsigned long size: " << sizeof(unsigned long) << endl;
    cout << "long long size: " << sizeof(long long) << endl;
    cout << "unsigned long long size: " << sizeof(unsigned long long) << endl;

}

int main() {
    //int x = 5 + 10 * 20 / 2;    // Assuming this follows the order of operations, x is 105
    //cout << x << endl;

    //// Quick test in regards to assignment requiring a lvalue as its left-hand operator, and yielding its left-hand operator as an lvalue
    //int lVal;
    //((lVal = 3) = 14) = 26;
    //// Assuming lVal will be equal to 26.
    //cout << lVal << endl;

    //// Quick test in regards to built-in and iterator increment and decrement operators require lvalue operands and the prefix versions yielding lvalues.
    //// ++lVal should yield a lvalue that contains 27, than lVal * 2 will get the content of lVal (27) and mutiply that by 2 so lVal will be set equal to
    //// 54.
    //(++lVal) = lVal * 2;
    //// Assuming lVal will be equal to 54.
    //cout << lVal << endl;

    //// Assume p is an int*
    //int *p = &lVal;
    //int **pp = &p;
    //decltype(*p) y = lVal;
    //// Since *p is an lvalue int, it has to reference an lvalue int, so no literal ints
    //cout << typeid(y).name() << endl;
    //
    //// &p is a rvalue, so it needs to reference a pointer to an int pointer int * *
    //decltype(&p) z = pp;
    //cout << typeid(z).name() << endl;
    
    //vector<int> vec{ 5, 10, 15, 20};
    //int y = 6 + 3 * 4 / 2 + 2;
    //int x = 5 + 10 * 20 / 2;

    //cout << "5 = " << *vec.begin() << endl;
    //cout << "6 = " << *vec.begin() + 1 << endl;

    // the << operator makes no guarantees about when or how its operands are evaluated.

    //// unary operator (-) excample
    //int i = 1024;
    //int k = -i;     // k is-1024
    //cout << k;

    //bool b = true;
    //bool b2 = -b;   // b2 is true;
    //cout << " : " << b2 << endl;

    //// Integer division example
    //int ival1 = 21 / 6;     // ival1 is 3; result is truncated; remainder is discarded
    //int ival2 = 21 / 7;     // ival2 is 3; no remainder; result is an integral value

    //// Modulus/remainder example, note % operands must have integral typoes
    //int ival = 42;
    //double dval = 3.14;
    //ival % 12;      // ok: result is 6
    //ival %dval;     // error: floating-point operands
    //int q = -21 % -8;
    //cout << q;

    //int l = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    //cout << l;

    //int p;
    //// eXC 4.2.5
    //p = -30 * 3 + 21 / 5;
    //cout << p << " = -86" << endl;

    //p = -30 + 3 * 21 / 5;
    //cout << p << " = -18" << endl;

    //p = 30 / 3 * 21 % 5;
    //cout << p << " = 0" << endl;

    //p = -30 / 3 * 21 % 4;
    //cout << p << " = -2" << endl;

    //p = -21 % 5;
    //cout << p;

    // Because && and || operators do short circuit evalution
    
    // (&&) we can make statekents like this and not worry about array out of bounds exceptions because if the num would cause a out of bounds exception it short circuits and never attempts to access the collection element
    // if (num >= s.size() && !isspace(s[num])

    //// (||) using the or short circuit
    //// note s as a reference to const; the elements aren't copied and can't be changed
    //vector<string> text{ "fourteen", "", "eleven", "12.", "5", "4", "" };
    //for (const auto &s : text) { // for each element in text
    //    cout << s;               // print the current element
    //    // blank lines and those that end with a period get a newline
    //    if (s.empty() || s[s.size() - 1] == '.') {
    //        cout << endl;
    //    }
    //    else {
    //        cout << " "; // Otherwise just seperate with a space
    //    }
    //}

    //// This will not evaluate correctly, because the relational operater < is left associative,
    //// this will evaluate as true if k is greater than 0 or 1 depending on whether i < j evaluates
    //// as false or true. 
    //if (i < j < k);
    //// If you inteded to check the transitivity of these experssions you need to write it like so
    //if (i < j && j < k);

    //int val = 3;
    //// If we want to test the truth value of an arithmetic or pointer object, the most direct way is to use the values as a condition
    //if (val);  // true if val is any nonzero value
    //if (!val); // true if val is 0

    //if (val == true); // true only if val is equal to 1, true is converted to the same type as val, and since thats an int, true is the ssame as 1
    //if (val == 1);    // logically equivalent to the porevious statement
    
    //const char *cp = "Hello World";
    //char *j = nullptr;
    //if (cp) {
    //    cout << "cp is true" << endl;
    //}

    //if (*cp) {
    //    cout << "the contents of *cp is true" << endl;
    //}

    //if (j) {}
    //else { cout << "j is false"; }

    //const char *es = "";

    //if (*es) {}
    //else { cout << "es is the empty string"; }

    //exc4d10();
    //if (exc4d11(1, 2, 4, 13)) {
    //    cout << "true" << endl;
    //}
    //else {
    //    cout << "false" << endl;
    //}

    //// Assignment operator examples
    //int i = 0, j = 0, k = 0;    // initializations, not assignment
    //const int ci = i;           // initialization, not assignment

    //1024 = k;                   // Illegal literals are rvalues
    //i + j = k;                  // Illegal arithmetic exprssions are rvaluies
    //ci = k;                     // Illegal const expressions are unmodifiable lvalues

    //// The rs
    //k = 0;                      // result: type int, value 3
    //k = 3.1415;                 // result: type int, value 3

    //k = { 3.14 };                   // error: narrowing conversion
    //vector<int> vi;                 // initially empty
    //vi = { 0,1,2,3,4,5,6,7,8,9 };   // vi now has ten elements, values 0 through 9

    //int k;
    //k = {};
    //cout << k << endl;

    //// assignment is right associative
    //int ival, jval;
    //ival = jval = 0;    // ok: each assigned 0

    //int ival, *pval;    // ival is an int, and pval is an int pointer
    //ival = pval = 0;    // error: cannot assign the value of a pointer to an int
    //string s1, s2;
    //s1 = s2 = "Ok";     // This works because the string literal "Ok" is converted to a string

    //int i, j;
    //// confusing equality and assignment operators
    //// This if statement sets i equal to j, and executes depending on if i becomes a nonzero value or not
    //if (i = j);

    //// This if statement compares the equality of i and j
    //if (i == j);

    // += -= *= /= %=    arithmetic operators
    // <<= >>=  &= ^= |= bitwise operators


    //int i; double d;
    //d = i = 3.5;
    //cout << "d: " << d << ", i: " << i << endl;

    //i = d = 3.5;
    //cout << "d: " << d << ", i: " << i << endl;
    //int i;
    //if (i = 42) { cout << "as expected " << endl; }

    //double dval; int ival, *pval;
    //pval = 0;
    //dval = ival = 0;

    //int i = 0, j;
    //j = ++i;    // j = 1, i = 1: prefix yields the incremented value
    //j = i++;    // j = 1, i = 2: postfix yields the unincremented value

    // Combining ++ and the derefence operators in a single experssion *p++
    // This example uses the postfix operator t oprint the values in a vector up to but not including 
    // the first negative value
    //vector<int> v{ 0, 2, 4, 3, 5, -1};
    //auto pbeg = v.begin();
    //// print elements up to the first negative value
    //while (pbeg != v.end() && *pbeg >= 0)
    //    cout << *pbeg++ << endl; // print the current value and advance pbeg, because of the precedence of postfix ++ this statement is logically equivalent to *(pbeg++) so it increments pbeg to the next pointer and derefences the copy of pbeg before incrementing

    //pbeg = v.begin();       
    //*pbeg = 3 * (*pbeg++);  // error this is undefined
    //// depending on how the compiler functions this might be either
    //*pbeg = 3 * (*pbeg);
    //++pbeg;
    //// or
    //*(pbeg + 1) = 3 * (*pbeg);
    //++pbeg;
    //// depending on if the left operator or right operator is evaluated first
    //int *ptr = &(*v.begin());
    //cout << *ptr << " = 1" << endl;

    //if (ptr != 0 && *ptr++) {
    //    cout << "doesnt work" << endl;
    //}
    //else {
    //    cout << "Works and 2 = " << *ptr << endl;
    //}
    //int ival = 1;
    //if (ival++ && ival) {
    //    cout << "works" << endl;
    //}

    //if (v[ival++] <= v[ival]) {
    //    cout << "no works" << endl;
    //}
    //else {
    //    cout << "works work" << endl;
    //}

    //vector<string> v{ "1", "", "2", "4", "5", "6", "7" };
    //vector<string>::iterator iter(v.begin());

    //cout << "1:" << *iter++ << endl;;
    //cout << ":" << *iter << endl;

    //cout << "1:" << iter->empty() << endl;
    //cout << "1:" << iter++->empty() << endl;
    //cout << "2:" << *iter << endl;

    //string s1 = "a string", *p = &s1;
    //auto n = s1.size();     // run the size member of the string s1
    //n = (*p).size();        // run size on the object to which p points
    //n = p->size();          // equivalent to (*p).size()

    //// run the size member of p, then derefence the result because the . (dot) operator has higher precedence than the * (derefence) operator
    //*p->size();             // error: p is a pointer and has no membeer named size
     
    //// The conditional operator, (?: operator)
    //// cond ? expr1 : expr2;
    //int grade = 55;
    //string finalgrade = (grade < 60) ? "fail" : "pass";

    //// Nested conditional operator example
    //finalgrade = (grade > 90) ? "high pass" :
    //    (grade < 60) ? "fail" : "pass";

    //cout << "high pass:" << finalgrade << endl;

    // //Conditional operator has low precendence examples
    //cout << ((grade < 60) ? "fail" : "pass") << endl;   // prints pass or fail
    //cout << (cout << (grade < 60) ? "true" : "true") << endl;// error

    
    //int grade = 55;
    //string finalgrade = (grade > 95) ? "high pass" :
    //    (grade > 75) ? "pass" :
    //    (grade > 59) ? "low pass" : "fail";
    //cout << finalgrade;

    //// This is easier
    //if (grade > 95) {
    //    finalgrade = "high pass";
    //}
    //else if (grade > 75) {
    //    finalgrade = "pass";
    //}
    //else if (grade > 59) {
    //    finalgrade = "low pass";
    //}
    //else {
    //    finalgrade = "fail";
    //}
    //cout << finalgrade;


    //string s = "word";
    //string p1 = s + s[s.size() - 1] == "s" ? "" : "s";

    // Bitwise operators (Left Associative)
    //_________________________________________
    // Operator  /  Function   \  Use
    // ========================================
    //     ~     / bitwise NOT \ ~expr
    //    <<     / left shift  \ expr1 << expr2
    //    >>     / right shift \ expr1 >> expr2
    //    &      / bitwise AND \ expr1 & expr2
    //    ^      / bitwise XOR \ expr1 ^ expr2
    //    |      / bitwise OR  \ expr1 | expr2

    //// 0233 is an octal literal,
    //// assuming the
    //unsigned char bits = 0233;  // in bits: 1001 1011
    //
    //// Assuming bits is 0233 before each operation
    //bits << 8;                  // bits promoted to int and then shifted left by 8 bits 00000000 00000000 10011011 00000000
    //bits << 23;                 // ok: sign bit is unchanged 01001101 10000000 00000000 00000000
    //bits >> 3;                  // right shift 3 bits, 3 right-most bits discarded 00000000 00000000 00000000 00010011
    //~bits;                      // promotes bits to an int, meaning 0's are appended to the front of the binary representation
    //                            // how bits looks after promotion: 00000000 00000000 00000000 10011011
    //                            // than bits 0's and 1's are inverted: 11111111 11111111 11111111 01100100

    //// Octal literal 0145, b1's binary representation is: 01100101
    //unsigned char b1 = 0145;

    //// Octal literal 0257, b2's binary representation is: 10101111 
    //unsigned char b2 = 0257;

    //// And (&), or (|), and xor (^) bitwise operations on b1 and b2, assuming b1 and b2's value are not updated by the bitwise operations
    //b1 & b2; // After (&) bitwise operation: 00100101
    //b1 | b2; // After (|) bitwise operation: 11101111
    //b1 ^ b2; // After (^) bitwise operation: 11001010

    //// Using bitwise operations (Pass/Fail) class example
    //unsigned long quiz1 = 0;    // We'll use this value as the collection of bits (Explicitly initialized for well-defined bits)
    //1UL << 27;                  // This creates an unsigned long with only bit 27 turned on
    //// we can than or this vlaue with quiz1 to turn on the 27th bit in quiz1
    //quiz1 |= 1UL << 27; // this will turn on the 27th bit in quiz1 equivalent to (quiz1 = quiz1 | 1UL << 27;)
    //// if we wanted to turn bit 27 off but leave all the other bits unchanged we use the following statement
    //quiz1 &= ~(1UL << 27);  // bit 27 is set to 0
    //// say we wanted to know whether bit 27 was 1 or 0 we can use the following statement
    //bool status = quiz1 & (1UL << 27);  // what is bit 27

    //// Because the shift operator is left associative, the following statements execute in the same order
    //cout << "hi" << " there" << endl;
    //(((cout << "hi") << " there") << endl);
    //// parenthisize are important because of the issues with precendence and the shift operators
    //cout << 42 + 10;    // ok: prints 52 because + has higher precedence than <<
    //cout << (10 < 42);  // ok: because of the parenthiaize 10 is compared to 42, and returns 1, than 1 isprinted
    //cout << 10 < 42;    // error: because < has lower prcendence than << it prints 10 and than attempts to compare a ostream to a integer.

     
    //print_bits(~'q' << 6);

    // the sizeof operator, takes two forms
    // sizeof(type)
    // sizeof expr

    //ClassExample example, *p;
    //sizeof(ClassExample);   // size required to hold an object of type ClassExample
    //sizeof example;         // size of example's type, i.e., sizeof(ClassExample)
    //sizeof p;               // size of a pointer
    //sizeof *p;              // size of the type which p points to (i.e. ClassExample)
    //sizeof example.i;       // size of int, since i is of type int
    //sizeof ClassExample::i; // Alternate method of testing size of member i

    //// assuming ia is an int array
    //// sizeof(ia)/size(*ia)  returns the number of elements in ia, because sizeof a array is the entire array
    //int ia[10];
    //constexpr size_t sz = sizeof(ia) / sizeof(*ia);
    //int arr2[sz];   // ok sizeof returns a constexpr

    //exc4d28();

    //int x[10]; int *p = x;
    //cout << sizeof(x) / sizeof(*x) << endl;
    //cout << sizeof(p) / sizeof(*p) << endl;
    
    //char y = 0;
    //int x = 0;
    //cout << "4:" <<(sizeof y + x) << endl;
    //ClassExample *p;
    //cout << sizeof(*p) << " != " << sizeof p->i << endl;
    //size_t j = 2;
    //cout << "1:" << (sizeof y < j)  << endl;
    //cout << "1:" << sizeof exc4d5(3) << endl;

    //// Comma Operator example
    //vector<int> ivec{ 1, 2, 3 };
    //vector<int>::size_type cnt = ivec.size();
    //// assign values from size ... 1 to the elements in ivec
    //for (vector<int>::size_type ix = 0; ix != ivec.size(); --cnt, ++ix) {
    //    ivec[ix] = cnt;
    //}


    //int x = 10, y = 20,z = 0;
    //z = (false ? ++x, ++y : --x, --y);
    //cout << "x: " << x << ", y: " << y << ", z: " << z << endl;

    //// Type conversion and types being related to one another
    //int ival = 3.5 + 3;     // this is okay, but you will lose some precision

    //bool flag; char cval;
    //short sval; unsigned short usval;
    //int ival;   unsigned int uival;
    //long lval;  unsigned long ulval;
    //float fval; double dval;
    //3.14159L + 'a'; // 'a' promotoed to int, then that int is converted to long double
    //dval + ival;    // ival converted to double
    //dval + fval;    // fval converted to double
    //ival = dval;    // dval converted to int (truncation)
    //flag = dval;    // dval converted to bool, 0 is false, anything else is true
    //cval + fval;    // cval promote to int, then that int converted to float
    //sval + cval;    // scal and cval promoted to int
    //cval + lval;    // cval converted to long
    //ival + ulval;   // ival converted to unsigned long
    //usval + ival;   // promotions depends on the size of unsigned short and int
    //uival + lval;   // conversion depends on the size of unsigned int and long

    //int ival = -3;
    //unsigned int ui = 3;
    //float fval = 1.f;
    //auto t = ui * fval;
    //cout << typeid(t).name() << endl;


    //ival = +ival;
    //cout << ival << endl;

    //char c = 'a';
    //char *cp = &c;
    //if (cp);           // true if pointer cp is not zero
    //while (*cp);       // true while cp does not derefence to the null character \0

    //// Const conversion example
    //int i;
    //const int &j = i;   // convert a nonconst to a reference to const int
    //const int *p = &i;  // convert address of a noncont to the address of a const
    ////int &r = j, *q = p; // error: conversion from const to nonconst not allowed, this is to prevent const objects from being changed

    //// conversions defined by class types example
    //string s, t = "a value";    // character string literal converted to type string
    //while(cin >> s)             // while condition converts cin to bool

    //// static_cast example
    //// cast used to force floating point division
    //int j = 3, i = 2;
    //double k = static_cast<double>(j) / i;
    
    //// static_casting to perform a conversion the compiler does not automatically perform
    //double d = 3.14;
    //void *p = &d;   // ok: address of any nonconst object can be stored in a void*
    //// ok: converts void* back to the original point type
    //double *dp = static_cast<double *>(p);

    //// const_cast example
    //const char *pc;
    //char *p = const_cast<char *>(pc);   // ok: but writting or updating through p is undefined

    //const char *cp;
    //// error: static_cast can't cast away the const
    //char *q = static_cast<char *>(cp);
    //static_cast<string>(cp);            // ok: converts a string literal to a string
    //const_cast<string>(cp);             // error: const_cast only changes constness

    //// reinterpret_cast example
    //int *ip;
    //char *pc = reinterpret_cast<char *>(ip);
    //string str(pc);         // THIS WILL FAIL AT RUNTIME BECAUSE although str assumes that pc is a character pointer, it is really an int pointer

    // Old-style cast
    // type (expr);  // function-style cast notation
    // (type) expr;  // C-language style cast notation

    //int i = 3;
    //int j = 2;
    //double d = static_cast<double>(i/j);
    //cout << d << endl;

    return 0;
}