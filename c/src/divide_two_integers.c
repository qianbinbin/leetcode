#include "divide_two_integers.h"

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int divide_29_1(int dividend, int divisor) {
    bool sign = dividend < 0 == divisor < 0;
    int64_t dvd = llabs((int64_t) dividend), dvs = llabs((int64_t) divisor);

    int64_t ret = 0;
    while (dvd >= dvs) {
        int64_t sub = dvs, count = 1;
        while (dvd >= sub) {
            sub <<= 1;
            count <<= 1;
        }
        dvd -= sub >> 1;
        ret += count >> 1;
    }

    if (ret > INT_MAX)
        return sign ? INT_MAX : INT_MIN;
    return (int) (sign ? ret : -ret);
}
