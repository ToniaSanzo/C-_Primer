#pragma once
#include <string>

typedef double Money;
std::string bal;

double currency = 1.0;
class Account
{
public:
    // This works because the member declarrations are compiled before the function bodies.
    // So for the name lookup of bal, it looks in the first enclosing scope, the Account
    // and finds the bal there. Money can be used because it is typedeffed before it is used
    // by the account class.
    Money balance() { return bal; }

    // Bad practice since currency is redefined so much
    void setCurrency(std::string currency)
    {
        currency = std::to_string(currency.length());   // which currency? the parameter
    }

    // Bad practive cames local to a memeber function shouldn't hide member names
    void dummy_fcn(int currency)
    {
        // Refence the class member currency
        int x = this->currency * 3;
        // Alternative way to indicate the memeber
        int cursor =  Account::currency * 3;    // member height
    }

    // good practive: don't use a member name for a parameter or othe local variable
    void dummy_fcn1(int crncy)
    {
        // Parameter name doesn't hide member variable name currency
        int x = currency * 3;

        // The :: tells the compiler to look in the outerscope 
        double y = ::currency * 2;
    }


private:
    typedef double Money;   // error cannot redefine Money


    int currency = 3;
    Money bal;
};