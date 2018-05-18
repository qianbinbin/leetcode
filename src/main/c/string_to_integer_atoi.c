#include <string_to_integer_atoi.h>
#include <limits.h>
#include <string.h>

#define IS_NUMERIC(c) ('0' <= (c) && (c) <= '9')

int myAtoi_8(char *str) {
    if (str == NULL) return 0;

    const int len = strlen(str);
    int i = 0;
    while (i < len && str[i] == ' ') ++i;
    if (i == len) return 0;

    int sign = 1;
    if (str[i] == '+') ++i;
    else if (str[i] == '-') {
        sign = -1;
        ++i;
    }

    int num = 0;
    while (i < len && IS_NUMERIC(str[i])) {
        if (num > INT_MAX / 10 ||
            (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + (str[i] - '0');
        ++i;
    }
    return sign * num;
}
