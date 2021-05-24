#include "powx_n.h"

double myPow_50_1(double x, int n) {
    if (n == 0) return 1;

    double ret = 1;
    for (unsigned e = n < 0 ? 0u - n : n; e > 0; e >>= 1) {
        if (e & 1)
            ret = ret * x;
        x *= x;
    }
    return n >= 0 ? ret : 1 / ret;
}
