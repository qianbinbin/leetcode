#include <climbing_stairs.h>

int climbStairs_70(int n) {
    if (n < 1) return 0;

    int pre = 0, cur = 1;
    int tmp;
    for (int i = 1; i <= n; ++i) {
        tmp = pre + cur;
        pre = cur;
        cur = tmp;
    }
    return cur;
}
