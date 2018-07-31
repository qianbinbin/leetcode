#include "palindrome_number.h"

#include <stdint.h>

bool isPalindrome_9_1(int x) {
    if (x < 0) return false;
    int64_t origin = x, reverse = 0;
    while (x != 0) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return origin == reverse;
}
