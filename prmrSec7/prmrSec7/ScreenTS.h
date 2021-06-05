//#pragma once
//#include <string>
//#include <cstdio>
//#include <iostream>
//#include "Window_mgr.h"
//
//class ScreenTS
//{
//    // Designate Window_mgr as its friend, given Window_mgr access to the private members of ScreenTS
//    friend class Window_mgr;
//    
//    // the ostream version of storeOn has access to the private members of ScreenTS, but the string  version does not
//    friend std::ostream &storeOn(std::ostream &, ScreenTS &);
//
//    //// Designate Window_mgr's clear function as a friend of ScreenTS
//    //friend void Window_mgr::clear(ScreenTSIndex);
//    
//public:
//    // typedef or type alias member, this is public so users of ScreenTS won't know directly that ScreenTS uses a string to hold its data
//    using pos = std::string::size_type;
//    //typedef std::string::size_type pos;
//
//    ScreenTS() = default; // needed because ScreenTS has another constructor
//    //cursor initialized to 0 by its in-class initializer
//    ScreenTS(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
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
//        return *this;           // Return this object as an lvalue
//    }
//    inline ScreenTS &set(pos r, pos col, char ch) {
//        contents[r * width + col] = ch; // Set specified location to given value
//        return *this;                   // Return this object as an lvalue
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
