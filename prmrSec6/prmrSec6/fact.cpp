#include "Chapter6.h"

// Factorial function
int factorial(int val) {
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) {
        ret *= val--;   // assign ret * val to ret and decrement val
    }
    return ret;
}