#include "decode_ways.h"

int numDecodings_91_1(char *s) {
    int pre_pre = 1, pre = s[0] == '0' ? 0 : 1, dp = pre;
    for (++s; *s; ++s) {
        dp = *s == '0' ? 0 : pre;
        if (*(s - 1) == '1' || (*(s - 1) == '2' && *s <= '6'))
            dp += pre_pre;
        pre_pre = pre;
        pre = dp;
    }
    return dp;
}
