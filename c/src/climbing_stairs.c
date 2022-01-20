#include "climbing_stairs.h"

int climbStairs_70_1(int n) {
    int pre_pre = 1, pre = 1, ret = 1;
    for (int i = 2; i <= n; ++i) {
        ret = pre_pre + pre;
        pre_pre = pre;
        pre = ret;
    }
    return ret;
}
