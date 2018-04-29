#include <powx-n.h>
#include <limits.h>

static double my_pow(double x, int n) {
    if (n == 0) return 1;
    double ret = my_pow(x, n / 2);
    ret *= ret;
    if (n % 2 == 1)
        ret *= x;
    return ret;
}

double myPow_50(double x, int n) {
    if (n < 0) {
        if (n == INT_MIN)
            return 1.0 / (my_pow(x, INT_MAX) * x);
        return 1.0 / my_pow(x, -n);
    }
    return my_pow(x, n);
}
