#include "valid_number.h"

bool isNumber_65_1(char *s) {
    int point = 0, exponent = 0, digit = 0;
    char *p = s;
    for (; *p != '\0'; ++p) {
        if (*p == '+' || *p == '-') {
            if (p != s && *(p - 1) != 'e' && *(p - 1) != 'E')
                return false;
        } else if ('0' <= *p && *p <= '9') {
            ++digit;
        } else if (*p == '.') {
            if (point > 0 || exponent > 0)
                return false;
            ++point;
        } else if (*p == 'e' || *p == 'E') {
            if (exponent > 0 || digit == 0)
                return false;
            ++exponent;
            digit = 0;
        } else {
            break;
        }
    }
    return digit > 0 && *p == '\0';
}
