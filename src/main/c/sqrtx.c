#include "sqrtx.h"

#include <limits.h>

int mySqrt_69_1(int x) {
    if (x < 0) return INT_MIN;
    if (x < 2) return x;
    int start = 1, end = x / 2, mid;
    int x_mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        x_mid = x / mid;
        if (mid == x_mid) {
            return mid;
        } else if (mid > x_mid) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return end;
}

int mySqrt_69_2(int x) {
    if (x < 0) return INT_MIN;
    if (x < 2) return x;

    int ret = x / 2;
    while (ret > x / ret || x / (ret + 1) >= ret + 1) {
        ret = (ret + x / ret) / 2;
    }
    return ret;
}
