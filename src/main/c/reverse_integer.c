#include "reverse_integer.h"

#include <limits.h>
#include <stdint.h>

int reverse_7_1(int x) {
    int sign = x < 0 ? -1 : 1;
    int64_t n = x;
    n = n < 0 ? -n : n;
    int64_t ret = 0;
    while (n != 0) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    if ((sign == 1 && ret > INT_MAX) || (sign == -1 && -ret < INT_MIN)) return 0;
    return (int) (sign * ret);
}
