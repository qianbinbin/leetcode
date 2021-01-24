#include "string_to_integer_atoi.h"

#include <limits.h>

#define IS_NUMERIC(c) ('0' <= (c) && (c) <= '9')

int myAtoi_8_1(char *s) {
    char *ch = s;
    while (ch && *ch == ' ') ++ch;
    if (!ch) return 0;

    int sign = 1;
    if (*ch == '+') {
        ++ch;
    } else if (*ch == '-') {
        sign = -1;
        ++ch;
    }
    const int LIMIT = INT_MAX / 10;
    int val = 0;
    for (; ch && IS_NUMERIC(*ch); ++ch) {
        if (val > LIMIT || (val == LIMIT && *ch - '0' > 7))
            return sign == 1 ? INT_MAX : INT_MIN;
        // int overflow, dupe LeetCode compiler
        // val = val * 10 + *ch - '0';
        val = val * 10 + (*ch - '0');
    }
    return sign * val;
}
