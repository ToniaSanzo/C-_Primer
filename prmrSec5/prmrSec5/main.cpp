#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Rewrite of a previous loop, except exectued in a single statement instead of in a block
void exc5d3() {
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) sum += val, ++val;
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
}

// Return a random number between (inclusive)[0, 36)(not inclusive) 
int get_num() {
    return rand() % 36;
}

// Given a numerical grade assigns a letter grade, using if-else blocks
void exc5d5(int grade) {
    // Potential letter grades
    const vector<string> letters{ "F", "D", "C", "B", "A", "A++" };
    string lettergrade;

    // Any grade 60 and above receives a non-failing grade
    if (grade > 59) {
        // Determine the range of potential grades
        lettergrade = letters[(grade - 50) / 10];

        // If the grade is between 60 and 99 inclusive, add a "+" or "-" appropriately
        if (grade != 100) {
            if (grade % 10 > 7) {
                lettergrade += '+';
            }
            else if(grade % 10 < 3) {
                lettergrade += '-';
            }
        }
    }
    else {
        lettergrade = letters[0];
    }

    cout << grade << " = " << lettergrade << endl;
}

// Given a numerical grade assigns a letter grade, using the conditional statement
void exc5d6(int grade) {
    // Potential letter grades
    const vector<string> letters{ "F", "D", "C", "B", "A", "A++" };
    string lettergrade;

    // Set letter grade
    (grade < 60) ? lettergrade = letters[0] : lettergrade = letters[(grade - 50) / 10];

    // IF the lettergrade is between 60 - 99 inclusive add either the '+' or the '-' appropriately
    if ((grade >= 60) && (grade < 100)) {
        // If grade's LSD is 0, 1, or 2 add a '-'
        if (grade % 10 < 3) {
            lettergrade += '-';
        }
        
        // If grade's LSD is 8 or 9 add a '+'
        if (grade % 10 > 7) {
            lettergrade += '+';
        }
    }
   

    cout << grade << " = " << lettergrade << endl;
}

// Counts the number of vowels read from cin using if statements
void exc5d9() {
    int vowelCnt = 0;

    char ch;
    while (cin >> ch) {
        if (ch == 'a') {
            ++vowelCnt;
        }
        if (ch == 'e') {
            ++vowelCnt;
        }
        if (ch == 'i') {
            ++vowelCnt;
        }
        if (ch == 'o') {
            ++vowelCnt;
        }
        if (ch == 'u') {
            ++vowelCnt;
        }
    }
    
    cout << "vowel count: " << vowelCnt << endl;
}

// counts the number of vowels including capital vowels
void exc5d10() {
    // Counters
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;
    while (cin >> ch) {
        switch (ch) {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        default:; // Default case does nothing
        }
    }

    cout << "A count: " << aCnt << "\nE count: " << eCnt << "\nI count: " << iCnt << "\nO count: " << oCnt << "\nU count: " << uCnt << endl;
}

// Counts the number of vowls and whitespace characters
void exc5d11() {
    unsigned vowelCnt = 0, otherCnt = 0, spaceCnt = 0;

    string line = "";

    cout << " Enter \"tonia\" to exit" << endl;

    while (line != "tonia") {
        getline(cin, line);
        for (char ch : line) {
            switch (ch) {
                // The cases appearing on the same line emphasize that the cases represent a range of values, that all do the same thing
            case
            'a': case 'e': case 'i': case 'o': case 'u':
                ++vowelCnt;
                break;
            case ' ': case '\t': case '\v': case '\f': case '\r':
                ++spaceCnt;
                break;
                // using the default label to count nonvowels, non space characters
            default:
                ++otherCnt;
                break;
            }
        }
    }

    cout << "Vowel Count:" << vowelCnt << "\nOther Count:" << otherCnt << "\nSpace Count:" << spaceCnt << endl;
}

// Counts the number of vowls and whitespace characters
void exc5d12() {
    unsigned seqCnt = 0;
    bool fflag = false;

    char ch;
    while (cin >> ch) {
        if (fflag) {
            switch (ch) {
            case 'f': case 'l': case 'i':
                ++seqCnt;
            default:
                fflag = false;
            }
        }
        else if (ch == 'f') {
            fflag = true;
        }
    }

    cout << "Sequence Count:" << seqCnt << endl;
}

void exc5d14() {
    string maxWord(""), prevWord(""), currWord("");
    int currCnt = 1, maxCnt = 1;

    while (cin >> currWord) {
        // if the currWord is equal to the previous word increment current count, and than update maxWord if necessary
        if (currWord == prevWord) {
            ++currCnt;
            if (currCnt > maxCnt) {
                maxWord = currWord;
                maxCnt = currCnt;
            }
        }
        else {
            prevWord = currWord;
            currCnt = 1;
        }
    }

    if (maxCnt > 1) { cout << "Word: " << maxWord << ", Count: " << maxCnt << endl; }
    else { cout << "No repeats." << endl; }

}

// Determines if one of the argument vectors is a prefix to the other vector
bool exc5d17(vector<int> v1, vector<int> v2) {
    for (decltype(v1.size()) i = 0; i != v1.size() && i != v2.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// prompts user for two strings and reports which of the strings is smaller
void exc5d19() {
    string s1, s2;
    do {
        cout << "Enter two strings: ";
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            if (s1.size() > s2.size()) {
                cout << s1 << " is longer than " << s2 << endl;
            }
            else {
                cout << s2 << " is longer than " << s1 << endl;
            }
        }
        else {
            cout << "same length: " << s1 << " " << s2 << endl;
        }

        cout << "Continue? [y/n]: ";
        cin >> s1;
    }while (!s1.empty() && s1[0] != 'n');

}

// Reads a sequence of strings until a word is repeated in succession, depending on how the input stream terminates the program will print an appropriate message
void exc5d20() {
    string currStr, prevStr;
    bool rflag = false;

    // Continue reading from the istream until a string is repeated, or the istream is closed
    while (cin >> currStr) {
        if (prevStr == currStr) {
            rflag = true;
            break;
        }

        prevStr = currStr;
    }

    // output statements
    if (rflag) {
        cout << prevStr << " has occured twice" << endl;
    }
    else {
        cout << "No repeats" << endl;
    }

}

// Reads a sequence of strings until a word that starts with a capital letter is repeated in succession, depending on how the input stream terminates the program will
// print an appropriate message
void exc5d21() {
    string currStr, prevStr;
    bool rflag = false;

    // Continue reading from the istream until a string is repeated, or the istream is closed
    while (cin >> currStr) {

        if (!isupper(currStr[0])) {
            prevStr = "";
            continue;
        }

        if (prevStr == currStr) {
            rflag = true;
            break;
        }

        prevStr = currStr;
    }

    // output statements
    if (rflag) {
        cout << prevStr << " has occured twice" << endl;
    }
    else {
        cout << "No repeats" << endl;
    }
}

// Redefines varaible sz everytime it goes over 34
void exc5d22() {

    int sz = rand() % 36;
    while (sz <= 33) {
        cout << sz << endl;
        sz = rand() % 35;
    }
}

// Function to demonstrate
void matching(int i1, int i2) {
    if (i1 != i2) {
        throw runtime_error("Arguments in matching must match!");
    }
    cout << "Match" << endl;
}

// Reads two integers from standard input and prints the results of dividing them
void exc5d23() {
    int i1, i2;
    cin >> i1 >> i2;
    if (i2 == 0) {
        cout << "Can't divide by 0" << endl;
    }
    else {
        cout << (static_cast<double>(i1) / i2) << endl;
    }
}

// Reads two integers from standard input and prints the results of dividing them, if i2 is 0 throw a runtime exception
void exc5d24() {

    int i1, i2;
    cin >> i1 >> i2;
    if (i2 == 0) {
        throw runtime_error("Can't not divide by 0");
    }
    else {
        cout << (static_cast<double>(i1) / i2) << endl;
    }
}

int main() {
    //// Expression statement: When in expression is followd by ;
    //ival + 5;       // rather useless expression statement
    //cout << ival;   // useful expression statement

    //// The null statement, useful for when the language requires a statement but the programs logic does not
    //;               // null statement
    //
    //// The null statement allows us to read until 3 is inputed by the user
    //int sought = 3;
    //int s;
    //// while loop with the semi colon on the inside
    //while (cin >> s && s != sought)
    //    ;   // Intentional omition

    //int ival = 1 + 2;; // ok: second semicolon is a superfluous null statement
    //// Although semi colons may be legal, if used improperly they can break your program
    //// For example the statment below loops infinitely but the programmer all most certainly had diffrent intentions
    //vector<int> v(1, 1);
    //auto iter = v.begin();
    //
    //// loops infinitely because of the null statement precedening the while loop conditional
    //while (iter != v.end());
    //    iter++;

    //// An empty block is equivalent to the null statement {} == ;
    //;
    //// is the same as
    //{}


    //while (int i = get_num())    // i is created and initialized on each iteration
    //    cout << i << endl;
    //i = 0;                       // error: i is not accessible outside the loop, if we need access to i we must define i outside of the while loop

    //// find the first negative element
    //vector<int> v{ 1, 2, 3, 46, 78, 94, 10066, -12 };
    //auto beg = v.begin();
    //while (beg != v.end() && *beg >= 0)
    //    ++beg;
    //if (beg == v.end());        // We know that there is no negative element in the collection if this if statement evaluates as true

    //// if - else example
    //const vector<string> scores{ "F", "D", "C", "B", "A", "A++" };

    //string lettergrade;
    //int grade = 55;
    //if (grade < 60) lettergrade = scores[0];
    //else lettergrade = scores[(grade - 50) / 10];

    //if (grade % 10 > 7)
    //    lettergrade += '+'; // concatenate a '+' char to the grades ending with an 8 or 9
    //else if (grade % 10 < 3)
    //    lettergrade += '-'; // concatenate a '-' char to the grades ending with either a 0, 1, or 2


    //// Combing the 2 previous if - else statements into a single if statement
    //if (grade < 60)
    //    lettergrade = scores[0];
    //else {
    //    lettergrade = scores[(grade - 50) / 10];

    //    // Nested if statement
    //    if (grade != 100) { // ignore the "A++" case
    //        if (grade % 10 > 7)
    //            lettergrade += '+'; // concatenate a '+' char to the grades ending with an 8 or 9
    //        else if (grade % 10 < 3)
    //            lettergrade += '-'; // concatenate a '-' char to the grades ending with either a 0, 1, or 2
    //    }
    //}

    //// The following example is wrong despite being indented to appear correct
    //if (grade < 60)
    //    lettergrade = scores[0];
    //else
    //    lettergrade = scores[(grade - 50) / 10];
    //    // Nested if statement
    //    if (grade != 100) // ignore the "A++" case
    //        if (grade % 10 > 7)
    //            lettergrade += '+'; // concatenate a '+' char to the grades ending with an 8 or 9
    //        else if (grade % 10 < 3)
    //            lettergrade += '-'; // concatenate a '-' char to the grades ending with either a 0, 1, or 2

    //// Dangling else problem example, 
    //// despite the indentation this else statement is tied to the innermost if statement
    //if (true)
    //    if (false)
    //        lettergrade += '1';
    //else
    //    lettergrade += '2';

    //// how this problem executes with correct indentation
    //if (true)
    //    if (false)
    //        lettergrade += '1';
    //    else
    //        lettergrade += '2';

    //// You control the execution path with curly braces
    //if (true) {
    //    if (false) {
    //        lettergrade += '1';
    //    }
    //}
    //else {
    //    lettergrade += '2';
    //}

    //exc5d5(55);
    //exc5d5(61);
    //exc5d5(78);
    //exc5d5(85);
    //exc5d5(91);
    //exc5d5(100);
    //exc5d5(89);

    //exc5d6(55);
    //exc5d6(61);
    //exc5d6(78);
    //exc5d6(85);
    //exc5d6(91);
    //exc5d6(100);
    //exc5d6(89);


    //// The following code uses a switch statement to count the number of vowels that appear in somee text
    //unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    //char ch;
    //while (cin >> ch) {
    //    // If ch is a vowel increment the appropriate counter
    //    switch (ch) {
    //    case 'a':
    //        ++aCnt;
    //        break;
    //    case 'e':
    //        ++eCnt;
    //        break;
    //    case 'i':
    //        ++iCnt;
    //        break;
    //    case 'o':
    //        ++oCnt;
    //        break;
    //    case 'u':
    //        ++uCnt;
    //        break;
    //    default:
    //        break;
    //    }
    //}

    //// print the results
    //cout << " Number of a's: " << aCnt << endl;
    //cout << " Number of e's: " << eCnt << endl;
    //cout << " Number of i's: " << iCnt << endl;
    //cout << " Number of o's: " << oCnt << endl;
    //cout << " Number of u's: " << uCnt << endl;
    //
    //int ival = 4;
    //// Note* case statements have to be constant integral types
    //switch (ch) {
    //case 3.14:  // error: noninteger in case label
    //case ival:  // error: nonconst in case label
    //}

    //// Mutiple cases where the same statements need to be executed, so we omit the break statements allowing the sequence of execution to fall through each statement
    //unsigned vowelCnt = 0, otherCnt = 0;

    //char ch;
    //while (cin >> ch) {
    //    switch (ch) {
    //    // The cases appearing on the same line emphasize that the cases represent a range of values, that all do the same thing
    //    case 'a': case 'e': case 'i': case 'o': case 'u':
    //        ++vowelCnt;
    //        break;
    //    // using the default label to count nonvowels
    //    default:
    //        ++otherCnt;
    //        break;
    //    }
    //}
    //
    //cout << "Vowel Count:" << vowelCnt << "\nOther Count:" << otherCnt << endl;

    //bool b = false;
    //// Illegal switch statement
    //switch (b) {
    //case true:
    //    // this switch statement is illegal because these initilizationa might be bypassed
    //    string file_name;   // error: control bypasses an implicitly initiliazed variable
    //    int ival = 0;       // error: control bypasses an explicitly initialized variable
    //    int jval;           // ok: vecause jval is not initialkized
    //case false:
    //    // ok: jval is in scope but is uninitialized
    //    jval = get_num();      // ok: assign a value to jval
    //    if(file_name.empty())   // file_name is in scope but wasn't initialized 
    //default:
    //    ;   // Null statement, nothing is executed inside the default clause
    //}

    //// If you need to define and initialize a varaible for a particular case, we can do this by defining the 
    //// variable inside a block therefore it is out of scope for subsequent case labels
    //switch (b) {
    //case true:
    //    // this switch statement is legal because these initilizationsgo out of scope for subsequence case labels
    //{
    //    string file_name;   // error: control bypasses an implicitly initiliazed variable
    //    int ival = 0;       // error: control bypasses an explicitly initialized variable
    //}
    //    int jval;           // ok: vecause jval is not initialkized
    //case false:
    //    // ok: jval is in scope but is uninitialized
    //    jval = get_num();       // ok: assign a value to jval
    //    if (file_name.empty())  // error: file_name is out of scope 
    //default:
    //    ;   // Null statement, nothing is executed inside the default clause
    //}

    //exc5d9();
    //exc5d10();
    //exc5d12();

    //// While loop example
    //vector<int> v{1,2,3,4,5,6,7,8,9,10};
    //int i;

    //// read until end-of-file or other input failure
    //while (cin >> i) {
    //    v.push_back(i);
    //}

    //// find the first negative value
    //auto beg = v.begin();
    //while (beg != v.end() && *beg >= 0)
    //    ++beg;
    //if (beg == v.end())
    //    cout << "No negative values in the collection" << endl;
    //else
    //    cout << "Negative value in collection" << endl;

    //exc5d14();

    //// Execution flow in a traditional for loop
    ////process characters in s until we run out of characters or we hit a whitespace
    //string s("Hello Friend");
    //for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    //    s[index] = toupper(s[index]);   // capitalize the current character
    //printf("%s\n", s.c_str());

    //// Duplicates the elements of a vector onto the end of the vector
    //vector<int> v{ 1,2,3,4 };
    //cout << "{";
    //for (int e : v) {
    //    cout << e;
    //}
    //cout << "}" << endl;

    //// remember the size of v and stop when we get to the original last element
    //for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
    //    v.push_back(v[i]);
    //cout << "{";
    //for (int e : v) {
    //    cout << e;
    //}
    //cout << "}" << endl;

    //// Omition in a for loop
    //// no initializer
    //auto b = v.begin();
    //for (/* null */; b != v.end() && *b >= 0; ++b); // Iterates through the vector v until the end or a negative element is reached
    //
    //// no condition ( equivalent to writting true as the condition
    //for (int i = 0; /* no condition */; ++i) {
    //    break;
    //}

    //// no expression
    //for (int i; cin >> i; /* no expression */) {
    //    v.push_back(i);
    //}

    //// for completness for range example
    //// range variable must be a reference so we can write to the elements
    //for (auto &r : v) // for each element in r
    //    r *= r;       // double that element
    //// The above range for defined in a traditional for loop
    //for (auto b = v.begin(); b != v.end(); ++b) {   // iterate through the collection
    //    auto &r = *b;   // define r as a reference to b's element to update the vector
    //    r *= r;         // double r
    //}

    //int ix;
    //cout << ix << endl;
    
    //char ch;
    //// "While" valid inpuit is still coming
    //while (cin >> ch) {
    //    printf("%c", ch);
    //}

    //// This for loops steps through/ iterates through a collection
    //vector<int> coll{ 1,2,3,4,5,6 };
    //for (decltype(coll.size()) i = 0; i != coll.size(); ++i) printf("\n%d", coll[i]);
    
    //vector<int> c1{ 1,2,3,4,5,6,7,8,9 };
    //vector<int> c2{ 1,2,3,4 };
    //if (exc5d17(c2, c1))
    //    printf("Yes");
    //else
    //    printf("No");

    //// The do-while statment
    //// repeatedly ask THE USER FOR A PAIR OF NMUMBERS TO SUM
    //string rsp;     // used in the condition; can't be defined inside the do
    //do {
    //    cout << "Please enter two values: ";
    //    int val1 = 0, val2 = 0;
    //    cin >> val1 >> val2;
    //    cout << val1 << " + " << val2 << " = " << (val1 + val2) << "\n\n";
    //    cout << "Continue? [y/n]: ";
    //    cin >> rsp;
    //} while (!rsp.empty() && rsp[0] != 'n');

    //// Illegal statement because the condition is evaluated last, you can't define variables in the condition
    //do {
    //    mumble(foo);
    //} while (int foo = 32); // error: declaration in a do-while condition
    
    //exc5d19();

    //// Breaks statement example
    //string buf;
    //while (cin >> buf && !buf.empty()) {
    //    switch (buf[0]) {
    //    case '-':
    //        // process up to the first blank
    //        for (auto it = buf.begin() + 1; it != buf.end(); ++it) {
    //            if (*it == ' ') break;  // # 1, leaves the for loop
    //            // ...
    //        }
    //        //break #1 transfers control here
    //        //remaining '-' processing
    //        break;  // #2, leaves the switch statement
    //    case '+':
    //        // ...
    //    } // end switch
    //    // end switch break # 2 transfers control here
    //}   // end while


    //exc5d20();

    //// Continue example
    //string buf;
    //while (cin >> buf && !buf.empty()) {
    //    if (buf[0] != '_')
    //        continue;
    //    // If you are still here the input starts with the input
    //}

    //exc5d21();

//    // Go-to examples
//    goto end;
//    int ix = 10;    // error goto bypasses an initialized varaible definition
//end:
//    // errpr: code here could use ix but the goto bypassed its declaration
//    ix = 42;

//    // ix needs to be initialized for the previous goto statement to work
//    int ix = 10;
//    goto end;
//    
//end:
//    ix = 42;
//
//    // backward jump over an initialized varaible definition is okay
//begin:
//    int sz = rand() % 36;
//    if (sz <= 34) {
//        cout << sz << endl;;
//        goto begin;
//    }
    //exc5d22();
    

    //// Writing our own exception handler
    //int i1, i2;
    //while (cin >> i1 >> i2) {
    //    try {
    //        matching(i1, i2);
    //    }
    //    catch (runtime_error err) {
    //        cout << err.what() << "\nTry again? [y/n]" << endl;
    //        char c;
    //        cin >> c;
    //        if (!cin || c == 'n') {
    //            break; // exit the while loop
    //        }
    //    }

    //}

    // Table 5.1: Standard Exception Classes Defined in <stdexcept>
    // exception - The most general kind of problem
    // runtime_error - Problem that can be detected only at run time.
    // range_error - Run-time error: result generated outside the range
    //              of values that are meaningful
    // overflow_error - Run-time error: computation that overflowed.
    // underflow_error - Run-time error: computation that underflowed.
    // logic_error - Error in the logic of the program.
    // domain_error - Logic error: argument for which no result exists.
    // invalid_argument - Logic error: inappropraite argument.
    // length_error - Logic error: attempt to create an object larger
    //                than the maximum size for that type.
    // out_of_range - Logic error: used a value outside the valid range.

    while (true) {
        try {
            exc5d24();
        }
        catch (runtime_error err) {
            cout << "enter a new number." << endl;
            continue;
        }
    }

    

    return 0;
}