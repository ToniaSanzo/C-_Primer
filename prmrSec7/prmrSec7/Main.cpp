#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "ScreenTS.h"
#include "Account.h"
#include <functional>
#include <memory>
using namespace std;

// Original Sales_data class
//class Sales_data {
//public:
//    string isbn;
//    int sold;
//    double revenue;
//
//    // Constructor
//    Sales_data() {
//        isbn = "";
//        sold = 0;
//        revenue = 0;
//    }
//
//    // Combine's this Sales_data object with another Sales_data object
//    Sales_data& combine(const Sales_data &oData) {
//        revenue += oData.revenue;
//        sold += oData.sold;
//        return *this;
//    }
//};
//
//// function used to create a Sales_data object from a input
//bool read(istream &in, Sales_data &data) {
//    double price;
//    in >> data.isbn >> data.sold >> price;
//
//    // check that the inputs succeeded
//    if (in) {
//        data.revenue = data.sold * price;
//        return true;
//    }
//    else {
//        data = Sales_data();    // input failed: reset object ro default state
//        return false;
//    }
//}
//
//ostream &print(ostream &out, const Sales_data &data) {
//    out << data.isbn << " " << data.sold << " " << data.revenue << " " << (data.revenue / data.sold);
//    return out;
//} 

//// Friend declarations do not count as normal declarations, so we declare the friend functions above the class,
//// so that the friend function is visible to users of the class.
//class Sales_data;
//std::istream &read(istream &in, Sales_data &data);
//ostream &print(ostream &out, const Sales_data &data);
//Sales_data add(const Sales_data &a, const Sales_data &b);
//
//class Sales_data
//{
//// Friend declarations for nonmember Sales_data operations
//friend std::istream &read(istream &in, Sales_data &data);
//friend ostream &print(ostream &out, const Sales_data &data);
//friend Sales_data add(const Sales_data &a, const Sales_data &b);
//// Other members and access specifiers as before
//public:
//    // Constructor's used to initialize a Sales_data object
//
//    // Delegating constructor example
//    // Non-delegating contructor
//    Sales_data(const string &isbn, unsigned sold, double p) :
//        bookNo(isbn), units_sold(sold), revenue(sold *p) { printf("Sales_data(std::string, unsigned, double)\n"); }
//    // Delegating contructor that uses the non-delegating constructor
//    Sales_data() : Sales_data("", 0, 0) { printf("Sales_data()\n"); }
//    Sales_data(std::string s) : Sales_data(s, 0, 0) { printf("Sales_data(std::string)\n"); }
//    Sales_data(istream &is) : Sales_data() { printf("Sales_data(istream&)\n");  read(is, *this); }
//
//
//    // We can combine these 2 constructors into 1
//    //Sales_data() = default;
//    //Sales_data(const string &isbn) : bookNo(isbn) {};
//    
//    // Because the default constructor makes string variables the empty string,
//    // using a default argument of the empty string will default initialize the
//    // string in the event that the user calls the constructor with no
//    //// argument.
//    //Sales_data(const string &s = "") : bookNo(s) {};
//
//
//    //Sales_data(istream &is) { read(is, *this); }
//    //Sales_data(const string &isbn, unsigned sold, double p) :
//    //    bookNo(isbn), units_sold(sold), revenue(sold *p) {}
//
//
//    // new members: operations on Sales_data objects
//    // Functions defined in the class are implicitly inline
//    std::string isbn() const { return bookNo; }
//    Sales_data &combine(const Sales_data &);
//    
//private:
//    inline double avg_price() const {
//        return ((units_sold) ? (revenue / units_sold) : 0);
//    }
//    // data members are unchanged
//    std::string bookNo;
//    unsigned units_sold = 0;
//    double revenue = 0.0;
//};
//
//// nonmember Sales_data interface functions
//Sales_data add(const Sales_data &, const Sales_data &);
//std::ostream &print(std::iostream &, const Sales_data &);
//std::istream &read(std::istream &, Sales_data &);
//
//Sales_data &Sales_data::combine(const Sales_data &rhs) 
//{
//    units_sold += rhs.units_sold;
//    revenue += rhs.revenue;
//    return *this;
//}
//
//// function used to create a Sales_data object from a input
//std::istream &read(istream &in, Sales_data &data) {
//    double price = 0.0;
//    in >> data.bookNo >> data.units_sold >> price;
//    data.revenue = data.units_sold * price;
//    return in;
//}
//
//ostream &print(ostream &out, const Sales_data &data) {
//    if (data.units_sold == 0) {
//        out << data.bookNo << " " << data.units_sold << " " << data.revenue << " 0";
//    }
//    else {
//        out << data.bookNo << " " << data.units_sold << " " << data.revenue << " " << (data.revenue / data.units_sold);
//    }
//    return out;
//}
//
//Sales_data add(const Sales_data &a, const Sales_data &b) {
//    Sales_data sum(a);
//    sum.combine(b);
//    return sum;
//    
//}

//// Even though First and Second define the same variables and functions,
//// they are still unique member variables
//struct First {
//    int memi;
//    int getMem();
//};
//
//struct Second {
//    int memi;
//    int getMem();
//};
//
//First obj1;
//Second obj2 = obj1; // Error: obj1 and obj2 have different types

//class Link_ScreenTS {
//    ScreenTS window;
//    Link_ScreenTS *next;  // Classes can have references and pointers to classes of there own type
//    Link_ScreenTS *prev;  // But not memeber varaibles because the compiler doesn't know the size of the Link_ScreenTS
//};

//// Exc 7d31
//class Y;
//class X {
//    Y *pY;
//};
//
//class Y {
//    X x;
//};

//class Window_mgr
//{
//public:
//    // Location ID for each screen on the window
//    using ScreenTSIndex = std::vector<ScreenTS>::size_type;
//    // Reset the ScreenTS at the given position to all blanks
//    void clear(ScreenTSIndex);
//
//private:
//    // ScreenTSs this Wiondow_mgr is tracking
//    // by default, a window mgr has one standard sized blank ScreenTS
//    std::vector<ScreenTS> screens{ ScreenTS(24, 80, ' ') };
//};
//
//class ScreenTS
//{
//    //// Designate Window_mgr as its friend, given Window_mgr access to the private members of ScreenTS
//    //friend class Window_mgr;
//
//    // Designate Window_mgr's clear function as a friend of ScreenTS
//    friend void Window_mgr::clear(ScreenTSIndex);
//
//public:
//    // typedef or type alias member, this is public so users of ScreenTS won't know directly that ScreenTS uses a string to hold its data
//    using pos = std::string::size_type;
//    //typedef std::string::size_type pos;
//
//    ScreenTS() = default; // needed because ScreenTS has another constructor
//    //cursor initialized to 0 by its in-class initializer
//    ScreenTS(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht *wd, c) {}
//    ScreenTS(pos ht, pos wd) : height(ht), width(wd), contents(ht *wd, ' ') {}
//
//    char get() const { return contents[cursor]; }   // Get the character at the cursor
//    inline char get(pos ht, pos wd) const;          // Explicitly inline
//    inline ScreenTS &move(pos r, pos c) {
//        pos row = r * width;    // Compute the row location
//        cursor = row + c;       // move cursor to the column within that row
//        return *this;           // return this object as an lvalue
//    }
//
//    void some_member() const;
//
//    inline ScreenTS &set(char c) {
//        contents[cursor] = c;   // Set the new value at the current cursor location
//        return *this;           // Return trhis object as an lvalue
//    }
//    inline ScreenTS &set(pos r, pos col, char ch) {
//        contents[r * width + col] = ch; // Set specified location to given value
//        return *this;                   // Return thisobject as an lvalue
//    }
//
//
//    ScreenTS &display(std::ostream &os) {
//        do_display(os); return *this;
//    }
//    const ScreenTS &display(std::ostream &os) const {
//        do_display(os); return *this;
//    }
//
//private:
//    // Function displays a screen
//    void do_display(std::ostream &os) const { os << contents; }
//
//    mutable size_t access_ctr = 0;  // may change even in const object
//
//    pos cursor = 0;
//    pos height = 0, width = 0;
//    std::string contents;
//};
//
//void Window_mgr::clear(ScreenTSIndex i)
//{
//    // s is a reference to the ScreenTS we want to clear
//    ScreenTS &s = screens[i];
//    // reset the contents of that ScreenTS to all blanks
//    s.contents = std::string(s.height * s.width, ' ');
//}

//class ConstRef
//{
//public:
//    ConstRef(int ii);
//private:
//    int i;
//    const int ci;
//    int &ri;
//};
//
//// error: ci and ri must be initialized
//ConstRef::ConstRef(int ii)
//{
//    // assignments:
//    i = ii;     // ok
//    ci = ii;    // error: cannot assign to a const
//    ri = i;     // error: ri was never initialized
//
//}
//
//// ok: explicitly initialize reference and const memebers
//ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {}

//struct C {
//    
//    C(string s = "") : rem(3), base(4) {} 
//    C(double i = 0) : rem(6), base(2) {}
//
//    //C(int i, int j) : base(i), rem((base % j)) {}
//    int rem, base;
//};
//
//struct Vehicle
//{
//    Vehicle(string aMake, string aModel = "UNK", string aYear = "UNK", string aColor = "UNK") : make(aMake), model(aModel), year(aYear), color(aColor) {}
//    Vehicle() : Vehicle("UNK", "UNK", "UNK", "UNK") {}
//
//    string make, model, year, color;
//};

//// Takes a collection of ints, and a pointer to a function that takes a int argument, and
//// returns void. This function will iterate through eeach value and call the function 
//// that is the second argument with every value in values
//void ForEach(const std::vector<int> &values, const std::function<void(int)>& func)
//{
//    for (int value : values)
//        func(value);
//}

//struct MyObj {
//    int x, y, z;
//};
//
//class NoDefault
//{
//public:
//    int m_nI;
//
//    NoDefault(int a_nI)
//    {
//        m_nI = a_nI;
//    }
//
//    ~NoDefault()
//    {
//        cout << "DELETED\n";
//    }
//};
//
//class D
//{
//public:
//    int m_nVal;
//    float m_fVal;
//
//    D()
//    {
//        m_nVal = 0;
//        m_fVal = 0;
//    }
//
//    D(int a_nVal)
//    {
//        m_nVal = a_nVal;
//        m_fVal = static_cast<float>(a_nVal);
//    }
//
//    D(string s)
//    {
//        m_nVal = 4;
//        m_fVal = 3.14f;
//    }
//
//    // An istream object can not be implicitly converted to type D  
//    explicit D(istream& in)
//    {
//        cout << "explicit\n";
//        m_nVal = 4;
//        m_fVal = 3.14f;
//    }
//};
//
//class C
//{
//public:
//    shared_ptr<NoDefault> m_pND;
//
//    C()
//    {
//        m_pND = make_shared<NoDefault>(NoDefault(3));
//    }
//
//    D &use_D(const D& d) const
//    {
//        cout << "using D\n";
//        D dd(d);
//        return dd;
//    }
//};
//
//// This is an example of an aggregate class 1) all of its data members are public 2) it has no in-class intializers 3) it has no base classes or virtual functions
//struct AggregateClass
//{
//    int ival;
//    std::string s;
//};
//
//struct BNAFBFAS
//{
//    std::string a;
//    unsigned b = 0;
//    double c = 0.0;
//};
//
//struct OddTest
//{
//    enum class eas
//    {
//        A,
//        B,
//        C,
//    };
//
//    eas asdfa : 2;
//};
//
//// Constexpr constructor example
//class ConstExprCtor
//{
//private:
//    bool hw, io, ot;
//
//public:
//    constexpr ConstExprCtor(bool b = true) : hw(b), io(b), ot(b) {}
//    constexpr ConstExprCtor(bool h, bool i, bool o) : hw(h), io(i), ot(o) {}
//    constexpr bool any() { return hw || io || ot; }
//    void set_io(bool b) { io = b; }
//    void set_hw(bool b) { hw = b; }
//    void set_other(bool b) { hw = b; }
//};

//class Account
//{
//public:
//    // Apply interest rate to amount in account
//    void calculate() 
//    { 
//        amount += amount * interestRate; 
//    }
//    
//    // get interest rate
//    static double rate() 
//    {
//        return interestRate;
//    }
//
//    static void rate(double);
//
//private:
//    std::string owner;
//    static constexpr int period = 30;
//    double daily_tbl[period];
//    double amount;
//    static double interestRate;
//    static double initRate();
//};
//
//void Account::rate(double newRate)
//{
//    interestRate = newRate;
//}
//
//class Bar
//{
//public:
//    // ...
//private:
//    static Bar mem1;    // ok:static member can have incomplete type
//    Bar* mem2;          // ok: pointer member can have incomplete type
//    Bar mem3;           // error: data members must have complete type
//};

class Screen
{
public:
    // bckgrnd refers to the static member
    // declared later in the class definition
    Screen& clear(char = bckgrnd);
private:
    static const char bckgrnd;
};

int main()
{

    

    //// We can  init an aggergate class by providing a braced list
    //// Note* must data in braced list must be ordered to match the
    ////       class's member variable declaration order
    //AggregateClass exmp = { 0, "Cheese" };

    //BNAFBFAS item = { "asd", 21, 1.1 };

    //// use_D
    //std::string tmpStr = "3.33";
    //C c;
    //c.use_D(tmpStr);

    OddTest a;

    printf("%d", a.asdfa);



    //Sales_data total(cin);       // variable to hold the running sum
    //
    //// Read the first transaction
    //if (cin) {
    //    do {
    //        Sales_data trans(cin);   // varaible to hold the data for the next transaction
    //        // Make sure the isbn match
    //        if (total.isbn() == trans.isbn()) {
    //            total = add(trans, total);   // update the running total
    //        }
    //        else {
    //            print(cout, total) << endl; // print the results
    //            total = trans;              // process the next book
    //        }
    //    } while (cin);
    //
    //    print(cout, total) << endl;         // print the last transactions
    //}
    //else {
    //    cerr << "No data?!" << endl;        // notify the userfe
    //}

    /*for (int i = 0; i < 3; ++i)
    {
#pragma message ("Balognie")
    }*/

    //Person person;
    //cout << "Enter name and address: ";
    //person.read(cin);
    //person.print(cout) << endl;


    //int ar[5] = { 1, 2, 3, 4, 5 };
    //int *p = ar;
    //
    //printf("*(p++) = %d\n", *(p++));
    //printf("*(p+3) = %d\n", *(p + 3));

    
    //ScreenTS myScreenTS(5, 5, 'c');
    //myScreenTS.move(4,0).set('\n').display(cout);
    //cout << endl;
    //myScreenTS.display(cout);
    //cout << endl;

    
    //ScreenTS::pos ht = 24, wd = 80;   // use the pos type defined by screen
    //ScreenTS scr(ht, wd, ' ');
    //ScreenTS *p = &scr;
    //char c = scr.get();             // fetches the get member from the object scr
    //c = p->get();                   // fetches the get member from the object to which p points


    //string foo = "Hello World!"; // Define and initialize
    //string bar;                  // Default initialize bar to the empty string
    //bar = "Hello World!";        // Assign a new value to bar
    //C c;
    //printf("rem: %d, base: %d", c.rem, c.base);
    //printf("Sales_data(3 param), Saled_data(no param)\n");
    //Sales_data d;
    //printf("Sales_data(3 param), Saled_data(1 param string)\n");
    //Sales_data e("Hello");
    //printf("Sales_data(3 param), Saled_data(no param), Sales_data(1 param instream)\n");
    //Sales_data f(cin);
    //printf("Sales_data(3 params)\n");
    //Sales_data g("3", 3, 3);
    //
    //Vehicle v;
    //printf("%s, %s, %s, %s\n", v.make.c_str(), v.model.c_str(), v.year.c_str(), v.color.c_str());
    //Vehicle u("CHVR", "IMPALA", "2011", "SLVR");
    //printf("%s, %s, %s, %s\n", u.make.c_str(), u.model.c_str(), u.year.c_str(), u.color.c_str());

    //vector<int> values = { 2, 2, 2, 2, 2 };
    //// [] - capture list, grabs the list of variables from the enclosing scope
    //int a = 1;
    //auto lambda = [&a](int value) { a *= 2, std::cout << "Value: " << value * a << std::endl; };
    //ForEach(values, lambda);

    //auto AnotherOne = [values]()
    //{
    //    for (const int &e : values)
    //    {
    //        printf("Value: %d\n", e);
    //    }
    //};

    //ForEach(values, [a](int)->void { printf("Works %d\n", a); });
    ////AnotherOne();

    //std::cin.get();

    //MyObj myObj1(); // OOPS! declares a function
    //MyObj myObj2;   // CORRECT! declares an object not a function

    //vector<D> vec(10); // Legal value initialized 
    //for (D &e : vec)
    //{
    //    cout << e.m_nVal << '\n';
    //}

    //// Implicit conversion of a string to D
    //C c;
    //string tmpStr = "this is an example";
    //
    //// Because D has a single argument constructor that takes type string,
    //// tmpStr is implicitly converted to type D. 
    //c.use_D(tmpStr);

    ////// This does not work because the compiler can't do more than 1 implicit conversion
    ////c.use_D("error");

    //// This works because of the explicit cast, and the compiler does the explicit cast
    //c.use_D(static_cast<string>("works"));
    //// This also works because we explicitly convert to an object of type D
    //c.use_D(D("This also works"));

    //// Can only use direct intialization to make objects with explicit constructors
    //D dd(cin);
    //// can't use the copy initialization to make objects with explicit constructors
    //D ddd = cin;

    
    //string tmpStr("3-33");
    //D tmpD1(tmpStr);
    //D tmpD2("3-33");

    return 0;
}