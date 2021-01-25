#include "palindrome_number.h"

bool isPalindrome_9_1(int x) {
    if (x < 0) return false;
    // int overflow, dupe LeetCode compiler
    // int old = x, new = 0;
    unsigned int old = x, new = 0;
    for (; x != 0; x /= 10)
        new = new * 10 + x % 10;
    return old == new;
}
