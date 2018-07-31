#include "powx_n.h"

#include <stdint.h>

double myPow_50_1(double x, int n) {
    if (n == 0) return 1;

    int64_t e = n;
    e = e > 0 ? e : -e;
    double ret = 1;
    while (e > 0) {
        if (e & 1)
            ret = ret * x;
        x *= x;
        e >>= 1;
    }
    return n > 0 ? ret : 1 / ret;
}
