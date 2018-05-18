#include <divide_two_integers.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

int divide_29(int dividend, int divisor) {
    int64_t a = dividend, b = divisor;
    bool sign = a < 0 == b < 0;

    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;

    int64_t ret = 0;
    while (a >= b) {
        int64_t c = b;
        for (int i = 0; a >= c; ++i) {
            a -= c;
            c += c;
            ret += 1 << i;
        }
    }

    if (ret > INT_MAX) {
        return sign ? INT_MAX : INT_MIN;
    }
    return (int) (sign ? ret : -ret);
}
