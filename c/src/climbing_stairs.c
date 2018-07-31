#include "climbing_stairs.h"

int climbStairs_70_1(int n) {
    if (n < 1) return -1;
    if (n < 4) return n;

    int pre_pre = 2, pre = 3, ret;
    for (int i = 4; i <= n; ++i) {
        ret = pre_pre + pre;
        pre_pre = pre;
        pre = ret;
    }
    return ret;
}
