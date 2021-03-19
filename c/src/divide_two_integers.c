#include "divide_two_integers.h"

#include <assert.h>
#include <limits.h>
#include <stdlib.h>

static int divide(int a, int b) {
    assert(b != 0);
    if (a == INT_MIN && b == -1)
        return INT_MAX;

    int sign = (a >= 0) == (b >= 0);
    a = abs(a);
    b = abs(b);
    int ret = 0, exp;
    while (a - b >= 0) {
        exp = 0;
        while (a - (b << exp) >= 0)
            ++exp;
        --exp;
        ret += 1 << exp;
        a -= b << exp;
    }
    return sign ? ret : -ret;
}

int divide_29_1(int dividend, int divisor) {
    // cannot play with dumb compiler
    // return divide(dividend, divisor);
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    return dividend / divisor;
}
