#include "string_to_integer_atoi.h"

#include <limits.h>
#include <string.h>

#define IS_NUMERIC(c) ('0' <= (c) && (c) <= '9')

int myAtoi_8_1(char *str) {
    if (str == NULL) return 0;

    const size_t len = strlen(str);
    int i = 0;
    while (i < len && str[i] == ' ') ++i;
    if (i == len) return 0;

    int sign = 1;
    if (str[i] == '+') ++i;
    else if (str[i] == '-') {
        sign = -1;
        ++i;
    }

    int64_t num = 0;
    while (i < len && IS_NUMERIC(str[i])) {
        num = num * 10 + (str[i] - '0');
        if (num > INT_MAX)
            break;
        ++i;
    }
    if (num > INT_MAX)
        return sign == 1 ? INT_MAX : INT_MIN;
    return (int) (sign * num);
}
