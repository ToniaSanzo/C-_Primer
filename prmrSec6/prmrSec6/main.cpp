#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "Chapter6.h"
using namespace std;

// prompt user for a number, and print the factorial of that number
void exc6d4() {
    int num;
    cout << "Enter a number:";
    cin >> num;
    cout << factorial(num) << endl;
}

// Returns the absolute value of the argument
inline int exc6d5(int i) {
    return (i < 0) ? -i : i;
}

size_t count_calls() {
    static size_t ctr = 0;  // value will persist across calls
    return ++ctr;
}

// Returns a number starting from 0 and increasing on subsequent calls
int exc6d7() {
    static int cnt = -1;
    return ++cnt;
}

// Function declaration, Parameter names chosen to indicate that the iterators denote a range of values to print
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);

// sets the integer a pointer points to 0
inline void reset(int *ip) {
    *ip = 0;    // Changes the value that ip points to
}

// Switch the values of two ints using pointers
inline void exc6d10(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

// Sets the integer argument to 0 using call by reference
inline void reset(int &r) {
    r = 0;
}

// Swaps the values of 2 integers using references
inline void exc6d12(int &i, int &j) {
    int tmp = i;
    i = j;
    j = tmp;
}

// Compare the length of two strings, used a pass by refenence because strings can be very long and it is more efficient 
// to pass by reference versus making a copy
//bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size();
//}

// Rewrite of isShorter to be inline
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// Using reference parameters to return additional information
string::size_type findChar(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();    // Position of the first occurrence, if any set the occurances count parameter
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;    // remember the first occurrence of c
            }
            ++occurs;
        }
    }
    return ret;             // count is returned implicitly in occurs
}

// bad design: the first parameter should be a const string&
string::size_type findChar(string &s, char c, string::size_type &occurs);

// despite appearances, these three declarations of print are equivalent
// each function has a single parameter of type const int*
void print(const int *);
void print(const int[]);    // shows the intent that the function takes an array
void print(const int[10]);  // dimensions for documentation purposes (at best)

// return a boolean whether a string has a capital letter in it
inline bool containsCapitalLetters(const string &s) {
    for (char c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// change a string to all lowercase
inline void toLowerCase(string &s) {
    for (char &c : s) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }
}

// Prints the contents of a string, and uses the fact that C-style strings are terminated with
// null characters to control the loop
inline void print(const char *cp) {
    // If cp is not the null pointer
    if (cp) {
        // While cp does not dereference to the null character
        while (*cp) {
            // print the current element and advance the pointer
            cout << *(cp++);
        }
    }
}

// Using the standard library convention of passing a pointer to the first element and a pointer one past the last element
// to print an array
inline void print(const int *beg, const int *end) {
    // print every element in the array
    do {
        // Print current element, than advance the pointer
        cout << *beg++;
        // while it is not the last element print a space, and continue
    } while (beg != end && cout << " ");
    
}

// Using a second parameter that indicates the size of the array
inline void print(const int ai[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << *(ai + i) << " ";
    }
}

// Parameter is a reference to an array; the dimension is part of the type
// because the dimension is part of the type, this limits this function
// becaues its argument has to be an integer array with 10 ints.
inline void print(int (&arr)[10]) {
    for (auto elem : arr) {
        cout << elem << endl;
    }
}

// Multidimensional arrays, matrix points to the first element in an array whose elements are arrays of ten ints
inline void print2D(int (*matrix)[10], size_t rowSize) {
    for (size_t i = 0; i < rowSize; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            cout << (*matrix)[j] << " ";
        }
        cout << endl;
        ++matrix;
    }
}

// compare the value of an int, and the value pointed to by an int pointer
inline int exc6d21(int a, const int *b) {
    if (a > (*b)) {
        return a;
    }
    else {
        return (*b);
    }
}

// Switch two int pointers
inline void exc6d22(int *&a, int *&b) {
    int *tmp = a;
    a = b;
    b = tmp;
}


inline void exc6d24(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i) {
        cout << ia[i] << endl;
    }
}

// Using an initiliazer list to get a varying number of parameters of the same type
void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

// Functions with an initializer list can also have other parameters of different types
void error_msg(int e, initializer_list<string> il) {
    cout << e << ": ";
    for (const auto &elem : il) {
        cout << elem << " ";
    }
    cout << endl;
}

// Takes an initializer_list of ints and returns the sum of them
int exc6d27(initializer_list<int> il) {
    int rtn = 0;
    for (const auto &elem : il) {
        rtn += elem;
    }
    return rtn;
}

// swap function that returns early if the parameter arguments are the same
inline void swap(int &v1, int &v2) {
    if (v1 == v2)
        return;
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

inline int &get(int *arr, int index) { return arr[index]; }

void printVec(vector<int> vc) {
    if (vc.empty()) {
        cout << endl;
        return;
    }

    cout << (vc[0]) << " ";
    vc.erase(begin(vc));
    printVec(vc);
}

//// incorrect return values, this code will not compile
//bool str_subrange(const string &str1, const string &str2) {
//    // same sizes: return normal equality test
//    if (str1.size() == str2.size()) {
//        return str1 == str2;    // ok returns a bool values
//    }
//
//    // find teh size of the smaller string using the conditional operator
//    size_t small = (str1.size() < str2.size()) ? str1.size() : str2.size();
//
//    // compare each element up to the last element in the smaller string
//    for (size_t i; i < small; ++i) {
//        if (str1[i] != str2[i]) {
//            return; // error 1 no return value
//        }
//    }
//    // error 2 control might flow off the end of the function without a return type
//}

//// correct return values, this code will compile
//bool str_subrange(const string &str1, const string &str2) {
//    // same sizes: return normal equality test
//    if (str1.size() == str2.size()) {
//        return str1 == str2;    // ok returns a bool values
//    }
//
//    // find teh size of the smaller string using the conditional operator
//    size_t small = (str1.size() < str2.size()) ? str1.size() : str2.size();
//
//    // compare each element up to the last element in the smaller string
//    for (size_t i = 0; i < small; ++i) {
//        if (str1[i] != str2[i]) {
//            return false; 
//        }
//    }
//    return true;
//}

// How values are returned
// This returns the plural version of the work if cnt is greater than 1
inline string make_plural(size_t cnt, const string &word, const string &ending = "s") {
    // depening on how the conditional operator is evaluated this function will either
    // initialize an unnamed string that is a copy of the concatenation of word and ending,
    // or just a copy of word.
    return (cnt > 1) ? word + ending : word;
}

// Example for returning a reference, this will return a reference to either of the parameter arguments.
// The returned object will refer to the object returned, so the strings are not copied when the functions called 
// or when the results are returned
//const string &shorterString(const string &s1, const string &s2) {
//    return (s1.size() <= s2.size()) ? s1 : s2;
//}

// inline version of shorter string, finds and returns a refernce to the shorter of the 2 strings
inline const string &shorterString(const string &s1, const string &s2) {
    return (s1.size() < s2.size()) ? s1 : s2 ;
}

// constexpr function
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();       // ok: foo is a constant expression

// scale(arg) is a constant expression if arg is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int arr[scale(2)];  // this works because 2 is a constant expression therefor scale(2) is a constant expression
int i = 3;
//int arr1[scale(i)]; // This does not work because i is not a constant expression therefor scale(i) is not a constant expression

//// disasteer: this function returns a reference to a local object, unfortunately the local object is saved to the stack
//// and when the function terminates the memory that the local object pointed/refered to is no longer valid
//const string &manip() {
//    string ret;
//    //transform ret in some way
//    if (!ret.empty())
//        return ret;         // wrong returning a reference to a local object
//    else
//        return "Empty";     // wrong: "empty" is a local temporary stringnb  n
//}

// Reference returning an lvalue
inline char &get_val(string &str, string::size_type ix) {
    return str[ix];     // get_val assumes the given index is valid, returns a refernce to the character in the string reference
}
  
// List initializing the return value, this example returns a collection of strings that are initialized in curly brackets
vector<string> process() {
    string actual = "actual", expected = "expected";

    if (expected.empty())
        return {};  // return an empty vector
    else if (expected == actual)
        return{ "functionX", "okay" };      // return list-initialized vector
    else
        return { "functionX", actual, "expected" };
}

// rewriting the factorial function to be recursice
inline int rFact(int n) {
#ifndef NDEBUG
    cout << __func__ << " at " << __TIME__ << endl << "    n = " << n << endl;
#endif // !NDEBUG

    if (n > 1) {
        return n * rFact(n - 1);
    }
    return 1;
}

// Returning a pointer to an arrays syntax can be intimidating but it can be simplified by using type aliases
using arrT = int[10];   // arrT is equivalent to the type int[10]
arrT *func(int i);      // Function returns a pointer to an array of ten ints

// Without using type alias the syntax looks like this
//int arr[10];            // arr is an array of ten ints
int *p1[10];            // p1 is an array of ten pointers
//int(*p2)[10] = &arr;   // pointer to an array of ten ints

// The same form we defined a pointer to an array of ten ints is used to declare a function that returns a pointer to an array of ten ints
// Type (*function(parameter_list))[array_dimension]
// without the parenthesis around (*function(parameter_list)) we would return an array list of 
int (&func3(int i))[10];      // concrete example of defining a function that returns a pointer to an array of ten ints without type aliases

// Trailing return types also make complicated return type easier
auto func(int i) -> int(*)[10]; // takes an int argument, returns a pointer to an array of ten ints

// using decltype to return a pointer to a array
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
// returns a pointer to an array of 5 ints
decltype(odd) *func2(int i){
    return (i % 2) ? &odd : &even;  // returns  pointer to an array
}

// Returns a reference to an array of ten strings, default
string (&exc6d36())[10];

// Returns a reference to an array of ten strings, type alias
using str_arr = string[10];
str_arr &exc6d36();

// Returns a reference to an array of ten strings, trailing return 
auto exc6d36() -> string(&)[10];

// Returns a reference to an array of ten strings, decltype
string str_aRr[10];
decltype(str_aRr) &exc6d26();

//struct Record {
//    int i;
//};
//
//struct Account {
//    int i;
//};
//
//struct Name {
//    int i;
//};
//
//struct Phone {
//    int i;
//};
//
//// Overloading example
//Record lookup(const Account &); // find by Account
//Record lookup(const Phone &);   // find by Phone
//Record lookup(const Name &);    // find by Name
//
//Account gAcct;
//Phone gPhone;
//Record gR1 = lookup(gAcct);     // call version that takes an account
//Record gR2 = lookup(gPhone);    // call version that takes a phone
//
//// If 2 functions only differ in return type its an error
//Record lookup(const int &);
////bool lookup(const int &);   // error: only the return type is different
//
//// Each pair of functions define that same function
//Record lookup2(const Account &acct);
//Record lookup2(const Account &);    // parameter names are ignored
//using Telno = Phone;
//Record lookup2(const Phone &);
//Record lookup2(const Telno &);      // Telno and Phone are the same type
//                          
//// A parameter with top level const is the same as non top level const
//// examples:
//Record lookup3(Phone);    
//Record lookup3(const Phone);         // redeclared Record lookup(Phone)
//Record lookup3(Phone* );           
//Record lookup3(Phone* const);       // redeclares Record lookupp(Phone*)
//
//// functions taking const and nonconst references and pointers have different parameters
//// declarations of four independent overloaded functions
//Record lookup3(Account &);          // Function that takes a reference to Account
//Record lookup3(const Account &);    // new function that takes a const reference
//Record lookup3(Account *);          // new function


//int *qj(int *);
//double *qj(double *);
//
//// Overloading and scope
//string read();
////void println(const string &);
////void println(double);           // overloads println function
////void fooBar(int ival) {
////    bool read = false;  // new scope: hides the outer declaration of read
////    string s = read();  // error: read is a bool, not a function
////    // bad practice: usually it's a bad idea to declare functions at local scope
////    void println(int);  // new scope: hides previous instance of println
////    println("Value: "); // error: print(const string &) is hidden
////    println(ival);      // ok: print(int) is visible
////    println(3.14);      // ok: 3.14 can be implicitly cast to an int, println(int) is called
////}
//
//void println(const string &);
//void println(double);           // overloads println function
//void println(int);              // overloads println function
//void fooBar(int ival) {
//    bool read = false;  // new scope: hides the outer declaration of read
//    //string s = read();  // error: read is a bool, not a function
//    // bad practice: usually it's a bad idea to declare functions at local scope
//    println("Value: "); // ok: print(const string&) is called
//    println(ival);      // ok: print(int) is called
//    println(3.14);      // ok: println(double) is called
//}
//
//// Default arguments
//using sz = string::size_type;   // sz is equivalent to string::size_type
////string screen(sz ht = 24, sz wid = 80, char background = ' ');
//
//string screen(sz, sz = 80, char = ' ');      // no default for ht and wid parameteres
////string screen(sz, sz, char = '*');    // error, can't change a default parameters that's already declared
////string screen(sz = 24, sz = 80, char);  // error: default arguments no at end
//
//// the declarations of wd, def , and ht must appear outside of a function
//sz wd = 80;
//char def = ' ';
//sz ht();
//string screen1(sz = ht(), sz = wd, char = def);
//string window = screen1();   // calls screen(ht(), wd, def);

//void f2() {
//    def = '*';      // changes the value of a default argument
//    sz wd = 100;    // hides the outer definition of wd but does not change the default
//    window = screen1();  // calls screen(ht(), 80, '*');
//}
//
//int ff(int a, int b = 0, int c = 0);
//
////char *init(int ht = 24, int wd, char bckgrnd);

// using the NDEBUG preprocessor variable
void debugCheck(int i) {
#ifndef NDEBUG
    // __func__ is a local static defined by the complier that holds the functions name
    cout << __func__ << " argument is " << i << " also debug is on" << endl;
#endif // !NDEBUG

}

void f() {
    cout << "f()" << endl;
}
void f(int) {
    cout << "f(int)" << endl;
}
void f(int, int) {
    cout << "f(int, int)" << endl;
}
void f(double, double = 3.14) {
    cout << "f(double double)" << endl;
}

int lookup2(string &);       // function that takes a reference to Account
int lookup2(const string &); // new function that takes a const reference

// compares the length of two strings
bool lengthCompare(const string &, const string &);

string::size_type sumLength(const string &, const string &);
bool cstringCompare(const char *, const char *);

// overloaded function
void of(int *);
void of(unsigned int);

// third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));

// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

// type aliasing function types
// Func and Func1 have fucntion types
using Func = bool(const string &, const string &);
using Func1 = decltype(lengthCompare);
// FuncP and FuncP2 are pointer to functions
using FuncP = bool(*)(const string &, const string &);
using FuncP2 = decltype(lengthCompare) *;                    // equivalent type

using F = int(int *, int);          // F is a function type
using PF = int(*)(int *, int);      // PF is a function pointer type

//PF f1(int); // ok: PF is apointer to function; f1 returnas a pointer to a function
////F f1(int);  // error: F is a function type but functions can only return pointers to function types
//F* f1(int); // ok: explicitly specify that the return type is apointer to function
//
//// withour type aliases the function declaration looks like this
//int(*f1(int))(int *, int);
//// reading this declaration from the inside out we can see that f1 is a function that takes an int parameter
//// f1 is preceded by a * so it returns a pointer, and the type and parameter list specify that it points to a
//// functyion that returns an int and takes an int* and a int as arguments.

//// for completeness another way to define a function that returns a pointer to a function is shown below
//auto f1(int) -> int (*)(int *, int);

//// we can use either the function type or the pointer to the function type to define useBigger
//void useBigger(const string &s1, const string &s2, Func);
//void useBigger(const string &s1, const string &s2, FuncP2);

// These functions have the same function type
string::size_type sumLength(const string &, const string &);
string::size_type largerLength(const string &, const string &);

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength
decltype(sumLength) *getFcn(const string &);

// function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.
int exc6d54(int, int) {
    return 0;
}
using EXC6D54 = int(*)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN METHOD
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    //vector<EXC6D54> funcVec{add, subtract, multiply, divide};
    //int tmp = funcVec[0](3, 2);
    //printf("3 + 2 = %d\n", tmp);

    //tmp = funcVec[1](1, 2);
    //printf("1 - 2 = %d\n", tmp);

    //tmp = funcVec[2](5, 6);
    //printf("5 * 6 = %d\n", tmp);

    //tmp = funcVec[3](6, 2);
    //printf("6 / 2 = %d\n", tmp);

    //f(2.56, 42);
    //f(42);
    //f(42, 0);
    //f(2.56, 3.14);
    //debugCheck(3);s

    //cout << factorial(5) << endl;

    //factorial("hello"); // error: wrong argument type
    //factorial();        // error: not enough arguments
    //factorial(1, 2, 3); // error: too many arguments
    //factorial(3.14);    // ok: 3.14 can be converted to type int

    //cout << exc6d5(-3) << endl;
    //cout << exc6d5(-36) << endl;
    //cout << exc6d5(72) << endl;

    //for (int i = 0; i < 4; ++i) {
    //    //cout << count_calls() << endl;
    //    cout << exc6d7() << endl;
    //}

    //int p = 32;
    //cout << p << endl;
    //reset(&p);
    //cout << p << endl;
    //
    //int i(14), j(3);
    //exc6d11(i);
    //exc6d12(i, j);
    //cout << "0 = " << j << "\n14 = " << i << endl;

    //// const parameters and arguments
    //const int ci = 42;  // we cannot change ci; const is top level
    //int i = ci;         // ok: when we copy ci, its top level const is ignored
    //int *const p = &i;  // const is top-level; we cannot assign to p
    //*p = 0;             // ok changes through p are allowed; i is now 0

    //// Pointer or Reference parameters and const
    //int i = 42;
    //const int *cp = &i; // ok: but cp can't change i
    //const int &r = i;   // ok: but r can't change i
    //const int &r2 = 42; // ok: because r2 is a const reference to a a integer literal

    //int *p = cp;        // error: can't initialize a pointer to an int, to a pointer to a const int
    //int &r3 = r;        // error: r references a const int, and since r3 is a just an int reference this is illegal
    //int &r4 = 42;       // error: can't initialize a plain reference from a literal

    //// These exct rules apply to parameter passing

    //int i = 0;
    //const int ci = i;
    //string::size_type ctr = 0;
    //reset(&i);          // calls the version of reset that has an int * parameter
    //reset(&ci);         // error: can't initialize an int* from a pointer to a const int object
    //reset(i);           // calls the version of reset that has an int& parameter
    //reset(ci);          // error: can't bind a plain reference to the const object ci
    //reset(42);          // error: can't bind a reference to a literal
    //reset(ctr);         // error: types dont match; ctr has an unsigned type
    //// ok: find_char's first parameter is a reference to const
    //findChar("Hello World", 'o', ctr);

    //if (containsCapitalLetters("hEllo")) {
    //    cout << "success" << endl;
    //}

    //if (containsCapitalLetters("hello")) {
    //    cerr << "ERROR" << endl;
    //    return -1;
    //}



    //string p = "aLL in The Family";
    //toLowerCase(p);
    //cout << p << endl;

    //exc6d5(3.6);
    //int ai[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    //print(begin(ai), end(ai));
    //print("BAlognie\n");
    //print(ai, end(ai) - begin(ai));

    //int i = 0, j[2] = { 0, 1 };
    //int k[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //print(&i);  // error: &i is not an array of 10 ints
    //print(j);   // error: j is not an array of 10 ints
    //print(k);   // ok: k is an arry of ten ints

    //int l[2][10] = {
    //    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    //    { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
    //};
    //print2D(l, 2);

    //int a = 42;
    //int b = 43;
    //int *ap = &a;
    //int *bp = &b;
    //exc6d22(ap, bp);
    //a = 10, b = 32;
    //cout << *bp << " = 10, " << *ap << " = 32" << endl;

    //int i = 0, j[2] = { 0, 1 };
    //
    //print(&i, 1);
    //print(j, 2);

    //print(&i, &i + 1);
    //print(begin(j), end(j));

    //exc6d24(k);

    // Table 6.1: Operations on initializer_lists
    // initializer_list<T> lst;
    //                  Default initialization; an empty list of elements of type T.
    // initializer_list<T> lst{a,b,c...};
    //                  lst has as many elements as there are initializers; elements are copies of the corresponding initializers.
    //                  Elements in the list are const.
    // lst2(lst)        Copying or assigning an initializer_list does not copy the elements in the list. After the copy, the original
    // lst2 = lst       and the copy share the elements.
    // lst.size()       Number of elements in the list.
    // lst.begin()      Returns a pointer to the first and one past the last element in lst.
    // lst.end()
    

    //// initializer_list<T> is a template type, you have to specify the type in arrow brackets <>
    //// it's also a list of const 
    //initializer_list<int> li;       // list of ints
    //initializer_list<string> ls;    // list of strings

    //// To pass a variable number of elements to a function with an initializer_list as the variable
    //string expected("hello"), actual("gfd");

    //if (expected != actual) {
    //    error_msg(1,{"functionX", expected, actual});
    //}
    //else {
    //    error_msg(0,{"functionX", "okay"});
    //}


    //cout << "9 = " << (exc6d27({3,3,3})) << endl;

    //cout << str_subrange("hello", "hefdsa") << endl;


    //// assignign values to functions that return lvalue references
    //string s("a value");
    //cout << s << endl;                  // prints a value
    //get_val(s, 0) = 'A';                // changes s[0] to A
    //cout << s << endl;                  // prints A value
    ////shorterString("hi", "bye") = "X";   // error: although shorter string returns a reference it is a const reference so it can't be updated
    //if (3 < 2) {
    //    return EXIT_FAILURE;    // cstdlib defined return value for main, makes this main method machine independent
    //}

    //cout << rFact(6) << endl;

    //int ia[10];
    //for (int i = 0; i < 10; ++i) {
    //    get(ia, i) = i;
    //}
    //for (auto i : ia) {
    //    cout << i << endl;
    //}
    //vector<int> balogna{ 1,2,3,4 };
    //printVec(balogna);

    //// Calling functions with default arguments
    //string window;
    ////window = screen();              // equivalent to screen(24, 90, ' ');
    //window = screen(76);            // equivalent to screen(76, 90, ' ');
    //window = screen(76, 256);       // equivalent to screen(76, 256, ' ');
    //window = screen(76, 256, '(');  // equivalent to screen(76, 256, '(');

    //// How default arguments are resovled
    ////window = screen(, , '?');       // error: can omit only trailing arguments
    //window = screen('?');           // equivalent to screen('?', 90, ' ');

    //int j = rFact(5);

    //string pj = "pj";
    //string s;
    //while (cin >> s && s != pj) {}
    //assert(cin);
    //cout << make_plural(1, "success") << " and " << make_plural(2, "failure") << endl;

    //// Using assert for debugging checks
    //// Example assume that we know that all words need to be more than 3 chars we can check that with the asser function
    //string b = "b";
    //
    //// using string literals defined by the C++ compiler to output error statements with alot of information
    //if (b.size() < 3) {
    //    cerr << "Error: " << __FILE__ << " : in function " << __func__ << " at line " << __LINE__ << endl
    //        << "       Compiled on " << __DATE__ << " at " << __TIME__ << endl
    //        << "       Word read was \"" << b << "\" : Length too short " << endl;
    //}

    //const string a;
    //string b;

    //lookup2(a);  // calls lookup2(const string &)
    //lookup2(b);  // calls lookup2(string &)


    //// pf points to a function returning bool that takes two const string references
    //bool (*pf)(const string &, const string &);
    ////If we omit the parenthesis around pf than we are declaring a function that returns a pointer to a bool
    //bool* pff(const string &, const string &);
    // to assign a function pointer to a function just use the function name as this returns a pointer to the function
    //pf = lengthCompare;     // pf points to the function named lengthCompare
    //pf = &lengthCompare;    // eqyuivalent assignment: address-of operator is optional


    //bool b1 = pf("hello", "goodbye");               // calls lengthCompare
    //bool b2 = (*pf)("hello", "goodbye");            // equivalent call
    //bool b3 = lengthCompare("hello", "goodbye");    // equivalent call

    //pf = 0;
    //pf = sumLength;               // error: return type differs
    //pf = cstringCompare;          // error: parameter type differs
    //pf = lengthCompare;           // ok: return and parameter type match exactly

    //void (*pf1)(unsigned int) = of;     //  pf1 points to of(unsigned int)

    //// the compiler uses the type of the pointer to detrtermine which overloaded function to use, the type of the 
    //// function pointer must match the overloaded function exactly
    //void (*pf2)(int) = of;              // error: no of with a matchin parameter list
    //double (*pf2)(int *) = of;          // error: no of with a matching return type

    
    // automatically converts the function lengthCompare to a pointer function
    //useBigger("hello", "goodbye", lengthCompare);

    return EXIT_SUCCESS;        // cstdlib defined return value for main, makes this main method machine independent
}