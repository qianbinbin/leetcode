#include <palindrome_number.h>
#include <stdint.h>

bool isPalindrome_9(int x) {
    if (x < 0) return false;
    int64_t origin = x, tmp = x;
    int64_t reverse = 0;
    while (tmp != 0) {
        reverse = reverse * 10 + tmp % 10;
        tmp /= 10;
    }
    return origin == reverse;
}
