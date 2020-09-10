#include <cstdlib>
// below: include statement for is and os
#include <iostream>
// below: include statement for string
#include <string>
// below: include statement for vectors
#include <vector>
// below: include statement for C-style strings
#include <cstring>

//// Using declarations for names from the standard library
//using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using namespace std;

// Mock Sales_item class
class Sales_item {
private:
    int number;
public:
    Sales_item() { number = 0; }
};




// Return the sum of the numbers from 50 - 100
int exc1d9() {
    int rtnVal = 0, index = 50;
    while (index <= 100) {
        rtnVal += index;
        index++;
    }
    return rtnVal;
}

// Print the  numbers from 10 to 0
void exc1d10() {
    int printVal = 10;
    while (printVal >= 0) {
        cout << printVal << endl;
        printVal--;
    }
}

// Prompt user for 2 numbers than print the numbers within the range of the 2 numbers
void exc1d11() {
    cout << "Enter 2 numbers" << endl;
    int max, min, temp;
    cin >> max >> min;
    if (max < min) {
        temp = max;
        max = min;
        min = temp;
    } 

    for (int i = min; i <= max; i++) {
        cout << i << endl;
    }
}

// Read user input one line at a time, or word by word depenging on argument
void exc3d2(bool line) {
    string str;
    if (line) {
        while (getline(cin, str)) {
            cout << str << endl;
        }
    }
    else {
        while (cin >> str) {
            cout << str << endl;
        }
    }
    cin.clear(); // clear buffer so the input stream can be used after this function ends
}

// Read 2 strings and report if they are equal or which of the two is larger, and whether 2 string have the same length, and if not report the longer string
void exc3d4() {
    string a, b;
    cout << "Enter 2 different strings: " << endl;
    cin >> a >> b;
    if (a == b) {
        cout << "Strings are equal" << endl;
    }
    else if (a < b) {
        cout << b << " is larger than " << a << endl;
    }
    else {
        cout << a << " is larger than " << b << endl;
    }

    cout << "Enter 2 different strings: " << endl;
    cin >> a >> b;
    if (a.size() == b.size()) {
        cout << "Same length" << endl;
    }
    else if (a.size() < b.size()) {
        cout << b << " is longer than " << a << endl;
    }
    else {
        cout << a << " is longer than " << b << endl;
    }
    
}

// Read strings into input and print the strings concatenated onto one another with or without a space depending on argument value
void exc3d5(bool space) {
    string word, printStr;
    char spaceChar(32 * space);   // if space is true space is ' ' otherwise space is '\0'

    while (cin >> word) {
        printStr += word + spaceChar;
        cout << printStr << endl;;
    }
    cin.clear(); // clear buffer so the input stream can be used after this function ends
}

// Change all the char in a string to X
void exc3d6(string& str) {
    for (char c : str) {
        c = 'X';
    }
}

// Change all the char in a string to X using a while loop and a for loop
void exc3d8(string &str) {
    decltype(str.size()) index = 0;
    while (index < str.size()) {
        str[index] = 'X';
        index++;
    }

    cout << str << endl;
    str = "Balognie Sandwich";

    for (decltype(str.size()) index = 0; index < str.size(); index++) {
        str[index] = 'X';
    }

    cout << str << endl;
}

// Reads a string of characters than writes what was read without punctioation
void exc3d10() {
    string word, printWord;
    while (cin >> word) {
        printWord = "";
        for (char c : word) {
            if (!ispunct(c)) {
                printWord += c;
            }
        }
        cout << printWord << ' ';
    }
    cout << endl;
    cin.clear();
}

// Takes a vector, prints the size and the content of the vector
template <typename T>
void exc3d13(vector<T> vec) {
    cout << "Vector size: " << vec.size() << "\nContent: ";
    for (T t : vec) {
        cout << t << ' ';
    }
    cout << endl;
}

// Reads a sequence of ints from cin and stores them in a vector, print content of new vector
void exc3d14() {
    vector<int> v;
    int n;
    
    while (cin >> n){
        v.push_back(n);
    }

    exc3d13(v);
}

// Reads a sequence of strings from cin and stores them in a vector, print content of the new vector
void exc3d15() {
    vector<string> v;
    string w;

    while (cin >> w) { v.push_back(w); }

    exc3d13(v);
}

// Take input, capitalize the input, than print the input capitilized and 8 to a line
void exc3d17() {
    vector<string> words;
    string word;

    cout << "enter words: ";
    while (cin >> word) {
        for (char &c : word) {
            if (islower(c)) {
                c -= 32;
            }
        }

        words.push_back(word);
    }

    decltype(words.size()) index = 0;
    while (index < words.size()) {
        if (index % 8 == 0) {
            cout << endl;
        }
        cout << words[index++] << ' ';
    }
}

// Lists three wats to defina vector and give it ten elements, each with value 42
void exc3d19(){
    // way one easiest one to code, my preferred way to init a vector of a specified size all with the same element
    vector<int> v1(10, 42);
    exc3d13(v1);

    // way two, maybe the most efficient way to create a vector, since vectors are optimized to grow at runtime
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(42);
    }
    exc3d13(v2);

    // way three, worst way yo create a vector
    vector<int> v3{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    exc3d13(v3);
}

// Read a set of integers into a vector, print the sum of each pait of adjacent elements, than print the sum of
// the first and last elements, followed by the sum of the second and second-to-last, and so on
void exc3d20() {
    cout << "Enter a set of integers: ";
    vector<int> values;
    int val, count = 0;

    while (cin >> val) {
        if (count > 0) {
            cout << values[count - 1] << " + " << val << " = " << values[count - 1] + val << endl;
        }

        values.push_back(val);
        count++;
    }

    for (decltype(values.size()) numb = 0; numb < values.size() / 2; numb++) {
        cout << "sum of values[" << numb << "] and values[" << values.size() - (numb + 1) << "] = " << values[numb] + values[values.size() - (numb + 1)] << endl;
    }

    if (values.size() % 2 == 1) {
        cout << "center value[" << (values.size() / 2) + 1 << "] = " << values[(values.size() / 2) + 1] << endl;
    }
    
}

// Takes a vector, prints the size and the content of the vector, using iterators
template <typename T>
void exc3d21(vector<T> vec) {
    cout << "Vector size: " << vec.size() << "\nContent: ";
    for (auto it = vec.cbegin(); it != vec.cend(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

// Capitilize and print the first paragraph of a vector<string> of text data
void exc3d22(vector<string> text) {
    for (auto it = text.begin(); it != text.end() && !it->empty(); it++) {
        // capitilize the word
        for (char &c : *it) {
            c = toupper(c);
        }

        cout << *it << " ";
    }
    cout << endl;
}

// Creates a vector with ten int elements. using an iterator adding each element a value with twice its original value
void exc3d23() {
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    exc3d13(v);
    for (auto it = v.begin(); it != v.end(); it++) {
        *it = *it * *it;
    }
    exc3d13(v);
}

// Read a set of integers into a vector, print the sum of each pait of adjacent elements, than print the sum of
// the first and last elements, followed by the sum of the second and second-to-last, and so on. Using iterators
void exc3d24() {
    cout << "Enter a set of integers: ";
    vector<int> values;
    int val;

    while (cin >> val) {
        values.push_back(val);
    }

    // print adjacent sums
    for (auto it = values.begin() + 1; it != values.end(); it++) {
        cout << *(it - 1) << " + " << *it << " = " << *(it - 1) + *it << endl;
    }

    // print the sum of the last and first iterator, followed by the second and the second-to-last and so on.
    for (auto beg = values.begin(), end = values.end() - 1; beg <= end; beg++, end--) {
        cout << "sum of values[" << beg - values.begin() << "] and values[" << end - values.begin() << "] = " << *beg + *end << endl;
    }

    if (values.size() % 2 == 1) {
        cout << "center value[" << (values.size() / 2) + 1 << "] = " << values[(values.size() / 2) + 1] << endl;
    }
}

// Grade clustering program rewriting with iterators
void exc3d25() {
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100) {    // handle only valid grades
            auto it = scores.begin() + (grade / 10);
            ++(*it);
        }
    }
    exc3d21(scores);
}

// takes no arguments returns an int value
int txt_size() { return 1; }


template <typename T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ' << endl;
    }
}


void print_string_array(string sarr[], int size) {
    for (int i = 0; i < size; i++) {
        for (char c : sarr[i]) {
            cout << (int)(c) << ' ';
        }
        cout << endl;
    }
}

// Define an array of ten ints, give each element the same value as its position in the array
void exc3d31t32() {
    int arr[10];
    int cArr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        cArr[i] = arr[i];
    }

    for (int e : arr) {
        cout << e << ' ';
    }

    cout << endl;
}

// Define a vector of ten ints, give each element the same value as its position in the vector
void exc3d32() {
    vector<int> vec;
    vector<int> cVec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        cVec.push_back(vec[i]);
    }

    for (int e : vec) {
        cout << e << ' ';
    }

    cout << endl;
}


void exc3d39(string s1, string s2, const char *c1, const char *c2) {
    if (s1 < s2) {
        cout << s1 << " is less than " << s2 << endl;
    }
    else if (s2 < s1) {
        cout << s2 << " is less than " << s1 << endl;
    }
    else {
        cout << s1 << " is the same as " << s2 << endl;
    }

    auto cmp = strcmp(c1, c2);

    if (cmp == 0) {
        cout << c1 << " is the same as " << c2 << endl;
    }
    else if (cmp < 0) {
        cout << c1 << " is less than " << c2 << endl;
    }
    else {
        cout << c2 << " is less than " << c1 << endl;
    }
}

// Initialize a vector from an array of ints
void exc3d41() {
    int arr[] = { 9, 13, 1994, 9, 9, 2020 };
    vector<int> ivec(std::begin(arr), std::end(arr));
    cout << "Size: " << ivec.size() << "\nContent:" << endl;
    for (int e : ivec) {
        cout << e << endl;
    }
}

// Initialize an array of ints from a vector
void exc3d42() {
    vector<int> ivec{ 9, 13, 1994, 9, 9, 2020 };
    int arr[6] = { 0 };
    for (int i = 0; i < 6; i++) {
        arr[i] = ivec[i];
    }

    cout << "Size: " << 6 << "\nContent:" << endl;
    for (int e : arr) {
        cout << e << endl;
    }
}

//string sa[10];
//int ia[10];

int main() {

    //string sa2[10];
    //int ia2[10];

    //print_string_array(sa, 10);
    //print_array(ia, 10);
    //print_string_array(sa2, 10);
    //print_array(ia2, 10);

    //int i;
    //cin >> i;                       // Ok: we were using the std::cin 
    //// cout << i;                   // Error: we were not using the std::cout name
    //std::cout << i << std::endl;    // Ok: we were referencing the std namespace to use cout and endl

    //cout << "Enter 2 numbers:" << endl;
    //int v1, v2;
    //cin >> v1 >> v2;
    //cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;

    //// Exercises
    //cout << exc1d9() << endl;
    //exc1d10();
    //exc1d11();

    //string s1;          // Default initialization; s1 is the empty string
    //string s2 = s1;     // s2 is a copy of s1
    //string s3 = "hiya"; // s3 is a copy of the string literal
    //string s4(10, 'c'); // s4 is cccccccccc
    //
    //string s5 = "hiya"; // s5 is copy initialized
    //string s6("hiya");  // s6 is direct initialized
    //string s7(10, 't'); // s7 is direct initialized

    //string s8 = string(10, 'c');    // Copy initialization, s8 is cccccccccc, NOTE* this first directly initializes a string literal "cccccccccc" than copy
    //                                // than copy initializes the string to s8. Not very efficient and also not very readable

    //// the above statement is the same as the following statement
    //string temp(10, 'c');
    //string s8 = temp;

    //// --------------------------------------------------------------
    //// Ways to initialize a string
    //string s1;          // default initialization s1 is the empty string
    //string s2(s1);      // direct initialization s2 is a copy of s1
    //string s2 = s1;     // copy initializtion s2 is a copy of s1
    //string s3("value"); // Direct initialization of s3, s3 is "value"
    //string s3 = "value";// Copy initialization of s3, s3 is "value"
    //string s4(n, 'c');  // Direct initializtion of s4, s4 is a string of n 'c's

    //string s;           // empty string
    //cin >> s;           // read a whitespace-separated string into s
    //cout << s << endl;  // print s to console

    //// --------------------------------------------------------------
    //// string Operations
    //os << s;            // Writes s onto the output stream os, returns os
    //is >> s;            // Reads a whitespace-separated  
    //geline(is, s);      // Reads a line of input from is into s. Returns is
    //s.empty();          // Returns true if s is the empty string; otherwise false
    //s.size();           // Returns the number of characters in s
    //s[n];               // Returns a reference to the char at position n in s; position starts at 0
    //s1 + s2;            // Returns the concatanation os s1 and s2 respectivelyt
    //s1 = s2;            // s1 becomes a copy of s2
    //s1 == s2;           // Returns true if s1 and s2 are the same; otherwise false
    //s1 != s2;           // Returns true if s1 and s2 are not the same; otherwise false
    //<, <=, >=, >        // Comparasion operators that can be used on strings, comparasions are case-sensitive and use dictionary ordering

    //// Reading an unknown number of strings
    //string word;
    //// Read until EOF
    //while (cin >> word) {
    //    cout << word << endl; // Print each white-space separated word onto a newline
    //}

    //// Using getline to read an entire line
    // string line;
    //// read input a line ata  time until EOF
    //while (getline(cin, line)) {
    //    cout << line << endl;
    //}

    //// NOTE* string::size() returns type string::size_type, size_type is an unsigned type but its technically not an int
    ////       because it is tedious to type string::size_type we can have the compiler do it auto or decltype
    //auto len = line.size();     // len has type string::size_type 
    
    //// Comparators with string type
    //string str = "hello";
    //string phrase = "hello world";  // because phrase has the same characters as str, but is longer str is less than phrase
    //string slang = "hiya";          // because str and phrase characters differ from slang at index 1, they are both less than slang, i comes later in the alphabet than e

    //// Assignments for string
    //string st1(10, 'c'), st2;   // st1 is cccccccccc; st2 is an empty string
    //st1 = st2;                  // assignment operator st1 is a copy of st2, string is as easy to use as most built-in types and includes alot of the operator functionality we expect
    //                            // to see in built-in type

    ////// + and +=  string operators 
    //string s1 = "hello", s2 = "world\n";
    //string s3 = s1 + s2;    // s3 is the concatentation of s1 and s2, s3 is "helloworld\n"
    //s1 += s2;        // += operand works as you expect it to and this statement is logically equivalent to s1 = s1 + s2;

    //// Adding literals and strings
    //string s4 = s4 + ", ";              // ok: adding string and literal
    //string s5 = "hello" + " ";          // error: no string operand
    //string s6 = s1 + ", " + "world";    // ok: each + has a string operand
    //string s7 = "hello" + " " + s2;     // error: cant add string literals

    //// read input line by line
    //exc3d2(true);
    //cout << "__" << endl;
    //// read input word by word
    //exc3d2(false);
    //while(1)
    //    exc3d4();

    //exc3d5(false);
    //cout << "__" << endl;
    //exc3d5(true);

    //// Simple for range example
    //string str("some string");
    //// print each char in str on a newline
    //for (auto c : str) {
    //    // the compiler sets c's type to char, than we output it to the console followed by a newline
    //    cout << c << endl;
    //}

    //// More complex for range example
    //string s("Hello World!!!");
    //decltype(s.size()) punct_cnt = 0;   // Note* punct_cnt has type string::size_type, this is because decltype determines the type the size() function returns and without actually executing the size()
    //                                    // function sets punct_cnt to that type
    //// count the number of punctuation chars in string s
    //for (auto c : s) {  // for every char 'c' in string "str"
    //    if (ispunct(c)) {
    //        // if c is punctiation increment punct_cnt
    //        punct_cnt++;
    //    }
    //}

    //cout << punct_cnt << " Punctiation count in " << s << endl;

    //char c;
    ////_________________________________________________________________________________
    //// cctype library functions (for knowing and/or changing the charecteristics of a character)
    //isalnum(c);         // return true if c is a letter or a digit
    //isalpha(c);         // return true if c is a letter
    //iscntrl(c);         // return true if c is a control character (a code point (a number) in a character set, that does not represent a written symbol such as \0 or ctrl+Z(^Z), etc.)
    //isdigit(c);         // return true if c is a digit
    //isgraph(c);         // return true if c is not a space but is printable
    //islower(c);         // return true if c is a lowercase letter
    //isprint(c);         // return true if c is a printable character(any character with a visible representation including space)
    //ispunct(c);         // return true if c is a punctuation character such as !
    //isspace(c);         // return true if c is whitespace(such as newline or space etc.)
    //isupper(c);         // return true if c is an uppercase letter
    //isxdigit(c);        // return ture if c is a hexadecimal digit
    //tolower(c);         // If c is uppercase letter turn it to a lowercase letter; otherwise do nothing
    //toupper(c);         // If c is lowercase letter turn it to a uppercase letter; otherwise do nothing

    //string s("Hello World!!!");
    ////convert s to uppercase
    //for (auto &c : s) { // EMPHASIS ON THE & THIS MAKES C A CHAR REFERENCE
    //    // c is a reference, so changing c changes s
    //    c = toupper(c); // make c an upper case
    //}
    //cout << s << endl;

    //// Code to print the first element in a string
    //if (!s.empty())
    //    cout << s[0] << endl;

    //// We can use the string array access to update the string
    //// Example: update "Hello World!!!" to "Howdy World!!!"
    //s[1] = 'o'; s[2] = 'w'; s[3] = 'd'; s[4] = 'y';
    //cout << s << endl;

    //// Using "subscript" array index's to uppercase the first word in string s
    //for (string::size_type index = 0; index < s.size() && !isspace(s[index]); index++) {
    //    s[index] = toupper(s[index]);
    //}
    //cout << s << endl;

    //// We have a number between 0 - 15, and we want to generate the hexadecimal representation of that number. We can do this using a string initialized to all the hexadecimal characters
    //const string hexdigits = "0123456789ABCDEF";    // Possible hex digits
    //cout << "Enter a series of numbers between 0 and 15 separated by spaces. then enter when done" << endl;
    //string result;          // will hold the hex digit for the users input
    //string::size_type n;    // contains the number entered by the user
    //while (cin >> n) {
    //    cout << hexdigits[n];
    //}

    //exc3d6(s);
    //cout << s << endl;

    //exc3d8(s);
    //string s1;
    //if (s1[0] == 0) {
    //    cout << "NULL" << endl;
    //}

    //exc3d10();

    //const string ko = "Keep Out!";
    //for (auto &c : ko) {
    //    cout << typeid(c).name();
    //}
    
    //vector<int> ivec;               // ivec holds int objects
    //vector<Sales_item> sales_vec;   // holds Sales_items
    //vector<vector<string>> file;    // vector whose elements are vectors
    

    //vector<string> svec;    // default initialization; svec has no elements
    //
    //vector<int> ivec;   // initially an empty vector
    //// give ivec some values
    //ivec.push_back(3);
    //vector<int> ivec2(ivec);    // ivec2 is a copy of ivec
    //vector<int> ivec3(ivec);    // ivec3 is a copy of ivec
    //vector<string> svec(ivec);  // error: ivec is a vector of ints and svec is a vector of strings this type mismatch


    //// list initializing a vector
    //vector<string> articles = {"shirt", "shorts", "sandals" };
    //vector<string> words1 {"a", "an", "the" };                     // list initialization this works
    // vector<string> words2("a", "an", "the");                    // error: cannot list initilize inside parenthsis
    
    //vector<int> ivec(10, -1);       // ten int elements, each initialized to -1
    //vector<string> svec(10, "hi");  // ten string elements, each initialized to "hi"

    //vector<int> ivec(10);   // ten int elements, each int element is default initialized to 0
    //vector<int> svec(10);   // ten string elements, each string element is default initialized to the empty string

    //vector<int> vi = 10;    // error: must use direct initializat ntion to supply a size
    
    ////_________________________________________________________________________________________________________________
    //// Ways to initialize a vector
    //int n = 3, val = 4;
    //int arr[] = { 3, 2, 1 };
    //vector<T> v1;                               // vector that holds objects of type T, default initialized v1 is empty
    //vector<T> v2(v1);                           // vector that holds objects of type T, v2 is a copy of v1
    //vector<T> v2 = v1;                          // equivalent to vector<T> v2(v1), v2 is a copy of v1
    //vector<T> v3(n, val);                       // v3 has n elements with value val
    //vector<T> v4(n);                            // v4 has n copies of the default initialized objects T
    //vector<T> v5{ arr[0], arr[1], arr[2] };     // v5 has as many elements as there are initializers; elements are initialized by corresponnding initializers.
    //vector<T> v5 = { arr[0], arr[1], arr[2] };  // this is logically equivalent to v5{ arr[0], arr[1], arr[2] };

    //vector<int> v1(10);     // A vector of 10 ints initialized to 0 (default value)
    //vector<int> v2{ 10 };   // A vector with one int element 10
    //vector<int> v3(10, 1);  // A vector with 10 ints all initialized to 1
    //vector<int> v4{ 10, 1 };// A vector with 2 elements, 10 and 1


    //// If we use braces to list initialize the object but there is no way we can use the initializers, than those values will be used to contruct the object
    //vector<string> v5{ "hi" };      // list initialized v5, has one element "hi"
    //vector<string> v6("hi");        // error: can't construct a vector from a string literal
    //vector<string> v7{ 10 };        // v7 has 10 elements all the empty string
    //vector<string> v8{ 10, "hi" };  // v8 has 10 elements with value "hi"

    //vector<int> v1;
    //cout << "a) ";
    //exc3d13(v1);

    //vector<int> v2(10);
    //cout << "b) ";
    //exc3d13(v2);

    //vector<int> v3(10, 42);
    //cout << "c) ";
    //exc3d13(v3);

    //vector<int> v4{ 10 };
    //cout << "d) ";
    //exc3d13(v4);

    //vector<int> v5{ 10, 42 };
    //cout << "e) ";
    //exc3d13(v5);

    //vector<string> v6{ 10 };
    //cout << "f) ";
    //exc3d13(v6);

    //vector<string> v7{ 10, "hi" };
    //cout << "g) ";
    //exc3d13(v7);


    //vector<int> v2; // v2 is an empty vector
    //for (int i = 0; i != 100; ++i) {
    //    v2.push_back(i);    // append sequentially to v2
    //}
    //// after this loop v2 is 100 elements 0 - 99
    //exc3d13(v2);

    //// read words from input, then store them in text
    //string word;
    //vector<string> text;        // empty vector
    //while (cin >> word) {
    //    text.push_back(word);   // append word to text
    //}
    //exc3d13(text);

    //exc3d14();
    //exc3d15();


    //vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (auto &i : v)    // for each element in v
    //    i *= i;          // square the element value
    //for (auto i : v)     // for each element in v
    //    cout << i << " ";// print the element

    //int t = 3;
    //vector<int> v1(v);
    //vector<int> v2(10, 3);
    //vector<int>::size_type n = 0;
    //vector<int>::size_type ok;   // ok: Vector must include the type of the vectors elements <int>
    //vector::size_type error;     // error: This vector forgot to include the type of the vectors elements <int>
    //
    ////________________________________________________________________________________________________________
    //// Table 3.5: vector operations
    //v.empty();                  // Returns true if v is empty; otherwise false
    //v.size();                   // Returns the number of elements in v (vector<T>::size_type) <- returns an unsigned size_type not int
    //v.push_back(t);             // Adds an element with value t to the end of v
    //v[n];                       // Returns a reference to the element at position n in v 
    //v1 = v2;                    // Replaces the elements in v1 with a copy of the elements in v2
    //v1 = { 1, 2, 3 };           // Replaces the elements in v1 with a copy of the elements in the comma-separated list
    //v1 == v2;                   // v1 and v2 are equal if they have the same number of elements and each and each element in v1 is equal to the corresponding element in v2
    //v1 != v2;                   // opposite of v1 == v2
    //<, <=, >, >=                // Have their normal menings using dictionary ordering


    //vector<unsigned> scores(11, 0); // 11 initial groups, all set to 0
    //unsigned grade;
    //while (cin >> grade) {
    //    if (grade <= 100)           // If the grade is in the correct range
    //        scores[grade / 10]++;
    //}

    //for (unsigned val : scores) {
    //    cout << val << " ";
    //}
    //cout << endl;


    //// You can not insert new elements in a vector by subscripting/[using the index] 
    //vector<int> ivec; // empty vector
    //
    ////// INCORRECT LOOP TO ADD NEW ELEMENTS TO VECTOR
    ////for (decltype(ivec.size()) ix = 0; ix < 10; ++ix) {
    ////    ivec[ix] = ix;  // disaster: ivec has no elements                                                
    ////}
    ////exc3d13(ivec);

    //// CORRECT LOOP TO ADD NEW ELEMENTS TO VECTOR
    //for (decltype(ivec.size()) ix = 0; ix < 10; ++ix) {
    //    ivec.push_back(ix); // adds a new element to ivec
    //}
    //exc3d13(ivec);

    //exc3d17();

    //vector<int> ivec;
    //ivec.push_back(42);

    //exc3d19();
    //exc3d20();
    
    //vector<int> v(10, 42);
    //auto b = v.begin(), e = v.end();

    //string s("balognie sandwich");
    //// using an iterator to capitilize the first character in the string
    //if (s.begin() != s.end()) { // dont try to capitilize the empty string
    //    cout << "a" << s << endl;
    //    auto it = s.begin();    // it denotes the first character in the string
    //    *it = toupper(*it);     // capitilize the character it refers to
    //}

    //auto iter = s.begin();
    //auto iter1 = iter;
    //auto iter2 = s.end();
    //cout << "b" << s[0] << endl;
    

    ////__________________________________________________________________________
    //// Table 3.6 Standard Container Iterator Operations
    //*iter;          // Returns a referenceto the element denoted by the iter
    //iter->mem;      // Dereference iter and fetches the member names mem from the underlying element equivalent to (*iter).mem
    //++iter;         // Increments iter to reference the next element in the container
    //--iter;         // Decrements iter to refer to the previous element in the container
    //iter1 == iter2; // Compares two iterators for equality(inequality). Two iterators are equal if they denote the same element or if they are the off-the-end
    //                // iterator for the same container
    //iter1 != iter2; // opposite of iter1 == iter2
    
    //for (auto it = s.begin(); it != s.end() && !isspace(*it); it++) {
    //    *it = toupper(*it);
    //}
    //cout << s << endl;

    //vector<int>::iterator it;           // it can read and write vector<int> elements
    //string::iterator it2;               // it2 can read and write chars in a string
    //vector<int>::const_iterator it3;    // it3 can read but not write elements
    //string::const_iterator it4;         // it4 can read but not write chars

    //vector<int> v;
    //const vector<int> cv;
    //auto it1 = v.begin();   // it1 has type iterator
    //auto it2 = cv.begin();  // it2 has type const_iterator

    //auto it3 = v.cbegin();  // Even though v is not a const vector cbegin and cend return a const_iterator

    //vector<string> vs{ "hello", "Tonia", "Sanzo" };
    //auto itvs = vs.begin();

    //(*itvs).empty();    // Returns true if itvs references an empty string; otherwise true

    //(*itvs).empty();    // Dereferences it and calls the member empty on the resulting object
    //*itvs.empty();      // error: attempts to derefence the object returned by calling .empty() on the iterator itvs, but itvs doesn't have a function called empty()

    //// Assume text is a vector<string> that contains data from a text file, each element in text is either a word, or the empty string to represent a paragraph break
    //// the following code will print the first paragraph of data
    //vector<string> text{ "This", "is", "one", "paragraph", "", "this is", "two" };
    //for (auto it = text.cbegin(); it != text.cend() && !it->empty(); it++) {
    //    cout << *it << " ";
    //}
    //cout << endl;

    //exc3d21(text);
    //exc3d22(text);
    //exc3d23();

    //_________________________________________________________________________________________________________
    // Table 3.7: Operations Supported by vector and string Iterators
    // iter + n         // Adding (substracting) an integral value n to (from) an iterator yields an iterator that 
    // iter - n         // Many elements forward (backward) within the container. The resulting iterator must denote
    //                  // elements in, or one past the end of, the same container
    // iter1 += n       // Compund-assignment for iterator addition and subtraction. Assigns to iter1 the value of
    // iter1 -= n       // adding n to, or subtracting n from, iter1
    // iter1 - iter2    // subtracting two iterators yields the number that when added to the right-hand iterator 
                        // yields the left-hand iterator. The iterators must denote elements in, or one past the end
                        // of, the same container
    // >, >=, <, <=     // Relational operators on iterators. One iterator is less than another if it refers to an 
                        // element that appears in the container before the one reffered to by the other iterator.
                        // The iterators must denote elements in, or one past the end of, the same container.
    
    //vector<int> vi(20, 3);
    //auto it = vi.begin() + 2;
    //auto mid = vi.begin() + vi.size() / 2;  // compute an iterator to the element closest to the midpoint in vi
    //// if it is an iterator in vi, than we can check  to see if it occurs before the mid point with the code below
    //if (it < mid) {}

    //// Binary search using iterators!
    //// text must be sorted
    //// beg and end wil ldenote the range we're searching
    //vector<string> text{ "a", "b", "c", "d", "e" };
    //string sought = "d";
    //auto beg = text.begin(), end = text.end();
    //auto mid = text.begin() + ((end - beg) / 2);  // original midpoint

    //// while there are still elements to look at and we haven't yet found sought
    //while ((mid != end && *mid != sought)) {
    //    if (sought < *mid)              // if the element we want in the first half
    //        end = mid;                  // if so, adjust the range to ignore the second half
    //    else
    //        beg = mid + 1;              // start looking with the element just after mid
    //    mid = beg + (end - beg) / 2;    // new midpoint
    //}

    //exc3d24();
    //exc3d25();
    //mid = (beg + end) / 2;

    //unsigned cnt = 42;          // not a constant expression
    //constexpr unsigned sz = 42; // constant expression
    //int arr[10];                // array of 10 ints
    //int *parr[sz];              // array of 42 pointers to ints
    //string bad[cnt];            // error: cnt is not a constantexpr so you can't define the size of an
    //                            // array with it
    //string strs[get_size()];    // ok if get_size() is a constexpr, error otherwise

    //// Explicitly Initializing Array Elements
    //const unsigned sz = 3;
    //int ia1[sz] = { 0, 1, 2 };      // array of three ints with values 0, 1, 2
    //int a2[] = { 0, 1, 2 };         // an array of dimension 3, with values 0, 1, 2
    //int a3[5] = { 0, 1, 2 };        // equivalent to a3 [] = {0, 1, 2, 0, 0}
    //string a4[3] = { "hi", "bye" }; // same as a4[] = {"hi", "bye, ""}
    //int a5[2] = { 0, 1, 2 };        // error: to many initializers for an array with dimesion 2 

    //char a1[] = { 'C', '+', '+' };          // list initialized no null character
    //char a2[] = { 'C', '+', '+', '\0' };    // list initialized with null character
    //char a3[] = "C++";                      // initialized with string literal, automatically null terminated
    //char a4[6] = "Daniel";                  // error: no space for the null character

    //// we can't initialize an array with another array, or copy an array into another array
    //int a[] = { 0, 1, 2 };
    //int a2[] = a;           // error: can't initialize an array with another array
    //a2 = a;                 // error: can't assign an array to nother array

    //int arr[10];
    //int *ptrs[10];              // ptrs is an array of ten pointers to int
    //int &refs[10];              // error: no array of references
    //int(*Parray)[10] = &arr;    // Parray is a pointer to an array of ten ints
    //int(&arrRef)[10] = arr;     // arrRef is a reference to an array of ten ints

    //// Exercise 3.27
    //unsigned buf_size = 1024;
    //int ia[buf_size];               // cant define an array with a non constexpr val
    //int ib[txt_size()];             // cant define an array with a non constexpr function
    //int ia[4 * 7 - 14];             // legal, this arithemitic value can be determined before run time
    //char st[11] = "fundamental";    // illegal, st doesn't have enough room for the null character
    
    //// count the number of grades by clusters of ten: 0 -- 9. 10 -- 19, ... , 90 -- 99, 100
    //unsigned scores[11] /*= {}*/;   // 11 buckets, all value initialized to 0
    //unsigned grade;
    //while (cin >> grade) {
    //    if (grade <= 100) {
    //        scores[grade / 10]++;   // increment the counter for the current cluster
    //    }
    //    for (auto e : scores  ) {
    //        cout << e << ' ';
    //    }
    //    cout << endl;
    //}

    //exc3d31t32();
    //exc3d32();

    //string nums[] = { "one", "two", "three" };          // array of strings
    //string *p = &nums[0];                               // p points to the first element in nums
    //string *p2 = nums;                                  // equivalent to p2 = &nums[0]
    //int *ip = nullptr;

    //int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };        // ia is an int array with ten elements
    //auto pia(ia);                                       // pia is a pointer to an int, and it points to the first element in ia
    //pia = 42;                                           // error: pia is a pointer and we cant assign an int to a pointer
    //auto pia(&ia[0]);                                   // This is how the compiler interprets "auto pia(ia);"
    //// Note: this conversion does not happen when using decltype(ia)
    //decltype(ia) ia2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };// ia2 is an array of ten ints
    //ia2 = ip;                                           // error: can't assign an int* to an array
    //ia2[4] = 3;                                         // ok: ok assigns value 3 to element 4 in ia3


    //int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //int *p = arr;       // p points to arr[0]
    //++p;                // p points to arr[1]
    //int *e = &arr[10];  // e points just past the last element in arr

    //for (int *b = arr; b != e; b++) {
    //    cout << *b << endl; // print the elements in arr
    //}

    //int ia[] = { 0,1,2,3,4,5,6,7,8,9 }; // array of ten ints
    //int *beg = std::begin(ia);          // pointer to the first element
    //int *end = std::end(ia);            // pointer one past the last element in ia
    //for (beg; beg != end; beg++) { cout << *beg << endl; }


    //// pbeg points to the first and pend points just past the last element in arr
    //int *pbeg = std::begin(ia), *pend = std::end(ia);
    //// find the first negative element, stopping if we've seen all the elements
    //while (pbeg != pend && *pbeg >= 0)
    //    ++pbeg;

    //constexpr size_t sz = 5;
    //int arr[sz] = { 1,2,3,4,5 };
    //int *ip = arr;              // equivalent to int *ip = &arr[0]
    //int *ip2 = ip + 4;          // ip2 points to arr[4], the last element in arr

    //// ok: arr is converted to a pointer to its first element; p points one past the end of arr
    //int *p = arr + sz;  // use caution do not derefence!, remember arr == &arr[0]
    //int *p2 = arr + 10; // error: arr only has 5 elements, p2 is undefined

    //auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr
    //// NOTE* n is of type ptrdiff_t, like size_t 

    //// We can use relational operators to compare pointers within an array
    //int *b = arr, *e = std::end(arr);
    //while (b < e) {
    //    cout << *b << endl;
    //    b++;
    //}
    //// We can't use relational operators to compare pointers that point to different objects
    //int i = 0, sz = 42;
    //int *p = &i, *e = &sz;
    //// undefined p and e are unrelated; comparassions are meaningless!
    //while (p < e) {
    //    cout << *p << endl;
    //    p++;
    //}

    //int ia[] = { 0,2,4,6,8 };
    //int last = *(ia + 4);     // init last to 8 aka ia[4]
    //// Parenthesis are important when dereferencing
    //last = *ia + 4;           // init last = 4, same as saying ia[0] + 4

    //int ia[] = { 0,2,4,6,8 }; // array with 5 elements of type int
    //int i = ia[2];            // ia[2] gets the element which (ia + 2) points to
    //int *p = ia;              // p points to the first element in ia
    //i = *(p + 2);             // equivalent to i = ia[2]

    //int *p = &ia[2];          // p points to the element indexed by 2 in ia
    //int j = p[1];             // p[1] is equivalent to *(p + 1),
    //                          // p[1] is the same element as ia[3]
    //int k = p[-2];            // p[-2] is the same element as ia[0]

    //int *p1 = &ia[1], *p2 = &ia[1];
    //cout << "p1 = " << *p1 << " p2 = " << *p2 << endl;
    //p1 += p2 - p1;
    //cout << "p1 = " << *p1 << endl;

    //int j[] = { 1,2,3 };
    //print_array(j, 3);
    //for (int *b = j; b != std::end(j); b++) {
    //    *b = 0;
    //}
    //print_array(j, 3);

    //int j[] = {1};
    //int k[] = {1};

    //if (end(j) - begin(j) != end(k) - begin(k)) {
    //    cout << "WRONG SIZE " << endl;
    //    return 0;
    //}

    //for (int *b1 = begin(j), *b2 = begin(k); b1 != end(j); b1++, b2++) {
    //    if (*b1 != *b2) {
    //        cout << *b1 << " != " << *b2 << endl;
    //    }
    //}

    //vector<int> a{ 1, 3, 3 };
    //vector<int> b{ 1, 2, 3, 3 };
    //if (a.size() != b.size()) {
    //    cout << "WRONG SIZE " << endl;
    //    return 0;
    //}

    //for (auto itrA = a.begin(), itrB = b.begin(); itrA != a.end(); itrA++, itrB++) {
    //    if (*itrA != *itrB) {
    //        cout << *itrA << " != " << *itrB << endl;
    //    }
    //}

    //char ca[] = { 'C', '+', '+' };  // not null terminated
    //cout << strlen(ca) << endl;     // disaster, ca isn't null terminated

    ////_____________________________________________________________________________________________________________
    //// Table 3.8. C-Style Character String Functions
    //strlen(p);      // returns the length of p, not including the null character
    //strcmp(p1, p2); // Compares p1 and p2 for equality. Returns 0 if p1 == p2, a positive value if p1 > p2, a negative
    //                // value if p2 > p1
    //strcat(p1, p2); // Appends p2 to p1, returns p1
    //strcpy(p1, p2); // Copies p2 into p1. Returns p1.

    //string s1 = "A string example";
    //string s2 = "A different string";
    //// Comparing 2 strings is simple
    //if (s1 < s2);   // evalutes false, s2 is less than s1

    //const char c1[] = "A string example";
    //const char c2[] = "A different string";
    //if (c1 < c2);   // undefined: compares two unrelated memory addresses
    ////to compare to c-style strings use the strcmp function
    //if (strcmp(c1, c2) < 0);    // evaluates false, because c2 is less than c1, same effect as s1 < s2

    ////// Simple concatenation done with string
    ////string largerStr = s1 + " " + s2;

    //// Concatenation of c-style string, disastrous id we miscalculated the size of largerStr
    //char largerStr[36];
    //strcpy(largerStr, c1);
    //strcat(largerStr, " ");
    //strcat(largerStr, c2);


    //string s0 = "balognie", s1 = "balognie";
    //const char c[] = "balognie";
    //const char c1[] = " sandwich";
    ////exc3d39(s1, s0, c1, c);
    //char c3[19];
    //strcpy_s(c3, c);
    //strcat_s(c3, c1);
    //cout << c3 << endl;

    //// initializing a string with a string literal
    //string s("Hello World");    // s holds Hello World
    //char *str = s;                  // error: can't init a c-style string from a library string
    //const char *str = s.c_str();    // member function to convert a library string into a c-style string

    //// Using an Array to initialize a vector
    //int int_arr[] = { 0,1,2,3,4,5 };
    //// ivec has sex elements; each is a copy of the corresponding element in int_arr
    //vector<int> ivec(std::begin(int_arr), std::end(int_arr));   // init vectors with an array with a pointer to the
    //                                                            // first element in the vector and a pointer to the
    //                                                            // last element in a vector
    //// You can  specify the rand of the array
    //vector<int> ivec(int_arr + 1, int_arr + 4); // creates a vector with array elements in the range of int_arr[1] - int_arr[3]

    //// Defining an array of arrays
    //int ia[3][4];   // array of size 3, each element is an int array of size 4
    //// array of size 10; each element is a 20-element array that are arrays of 30 ints
    //exc3d41();
    //exc3d42();

    
    //int arr[10][20][30] = { 0 };    // initialize all elements to 0
    //int ia[3][4] = {    // 3 elements; each element is an array of 4 ints
    //    {0,1,2,3},      // initializers for the row indexed by 0
    //    {4,5,6,7},      // initializers for the row indexed by 1
    //    {8,9,10,11}     // initializers for the row indexed by 2
    //};

    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << "Value: " << ia[row][col] << endl;
    //    }
    //}
    //cout << endl;

    //// equivalent initialization to the code above; however less clear, without the optional nested braces
    //int ia1[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << "Value: " << ia1[row][col] << endl;
    //    }
    //}
    //cout << endl;

    //// explicitly initialize only element 0 in each row
    //int ia2[3][4] = { {0}, {4}, {8} };
   
    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << "Value: " << ia2[row][col] << endl;
    //    }
    //}
    //cout << endl;
    //// explicitly initialize row 0, the remaining elements are value initialized
    //int ix[3][4] = { 0,3,6,9 };

    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << "Value: " << ix[row][col] << endl;
    //    }
    //}
    //cout << endl;
    //// assigns the first element of ia to the last element in the last row of ia
    //ia[2][3] = arr[0][0][0];
    //int (&row)[4] = ia[1];   // binds row to the second four element array in ia

    //// Using nested for loops to process the elements of a multi-dimensional array
    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << "Value: " << ia[row][col] << endl;
    //    }
    //}
    //cout << endl;

    //// We can simplify the nested for loop above by using a range for loop:
    //// Note* we have to define row as a reference otherwise it will be converted from an array to a pointer
    //for (const auto &row : ia) {                // for every element in the outer array
    //    for (int col : row) {                   // for every element in the inner array
    //        cout << "Value: " << col << endl;   // print this element
    //    }
    //}
    //cout << endl;

    //// Because a multidimensional array is really an array of arrays, the pointer type to which the array converts is a pointer to the first inner array:
    //int ia[3][4];       // array of size 3; each is an array of 4 ints
    //int(*p)[4] = ia;    // p is a pointer to the first row of 4 ints in ia
    //p = &ia[2];         // p is a pointer to the last row of 4 ints in ia

    //// parenthesis are essential when definine a pointer to an array
    //int *p1[4];         // p1 is an array of 4 int pouinters
    //int(*p2)[4];        // p2 points to an array of 4 ints 

    //// auto and decltype help us avoid having to specify the type of a pointer to an array
    //// print the value of each element in ia, with each inner array on its own line
    //// p points to an array of four ints
    //for (auto p = ia; p != ia + 3; p++) {
    //    // q points to the first element in an array of four ints; that is, q points to an int
    //    for (auto q = *p; q != *p + 4; q++) {
    //        cout << *q << endl;
    //    }
    //}
    //// easier way to right the nested for loop above using the begin and end functions
    //for (auto p = begin(ia); p != end(ia); p++) {
    //    for (auto q = begin(*p); q != end(*p); q++) {
    //        cout << *q << endl;
    //    }
    //}

    //// using type aliases to simplify poitners to multidimensional arrays
    //using int_array = int[4];   // new style int_array is equivalent to an array of 4 ints
    //typedef int int_array[4];   // equivalent to the above statement just written with typedef old style

    //// print the value of each element in ia, with each inner array on its own line
    //for (int_array *p = ia; p != ia + 3; ++p) {
    //    for (int *q = *p; q != *p + 4; q++) {
    //        cout << *q << endl; 
    //    }
    //}
    
    //// Exercise 3d43:
    //int ia[3][4] = {    // 3 elements; each element is an array of 4 ints
    //    {0,1,2,3},      // initializers for the row indexed by 0
    //    {4,5,6,7},      // initializers for the row indexed by 1
    //    {8,9,10,11}     // initializers for the row indexed by 2
    //};

    //cout << "Exercise 3d43" << endl;
    //cout << "print elements of ia using a for range" << endl;
    //// print elements of ia using a for range
    //for (const int (&o)[4] : ia) {
    //    for (int e : o) {
    //        cout << e << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and subscripting" << endl;
    //// print elements of ia using a for loop and subscripting
    //for (size_t row = 0; row != 3; row++) {
    //    for (size_t col = 0; col != 4; col++) {
    //        cout << ia[row][col] << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and pointers" << endl;
    //// print elements of ia using a for loop and pointers
    //for (int(*p)[4] = ia; p != ia + 3; ++p) {
    //    for (int *q = *p; q != *p + 4; ++q) {
    //        cout << *q << ' ';
    //    }
    //    cout << endl;
    //}
    //
    ////-------------------------------------------------------------------
    //cout << "\n\nExercise 3d44" << endl;
    //cout << "print elements of ia using a for range" << endl;
    //using int_array = int[4];
    //// print elements of ia using a for range
    //for (int_array &o : ia) {
    //    for (int e : o) {
    //        cout << e << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and subscripting" << endl;
    //using num = size_t;
    //// print elements of ia using a for loop and subscripting
    //for (num row = 0; row != 3; row++) {
    //    for (num col = 0; col != 4; col++) {
    //        cout << ia[row][col] << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and pointers" << endl;
    //// print elements of ia using a for loop and pointers
    //for (int_array *p = ia; p != ia + 3; ++p) {
    //    for (int *q = *p; q != *p + 4; ++q) {
    //        cout << *q << ' ';
    //    }
    //    cout << endl;
    //}

    ////-------------------------------------------------------------------
    //cout << "\n\nExercise 3d45" << endl;
    //cout << "print elements of ia using a for range" << endl;
    //// print elements of ia using a for range
    //for (auto &o : ia) {
    //    for (int e : o) {
    //        cout << e << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and subscripting" << endl;
    //// print elements of ia using a for loop and subscripting
    //for (auto row = 0; row != 3; row++) {
    //    for (auto col = 0; col != 4; col++) {
    //        cout << ia[row][col] << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "print elements of ia using a for loop and pointers" << endl;
    //// print elements of ia using a for loop and pointers
    //for (auto *p = ia; p != ia + 3; ++p) {
    //    for (auto *q = *p; q != *p + 4; ++q) {
    //        cout << *q << ' ';
    //    }
    //    cout << endl;
    //}

    return 0;
}