#include "valid_number.h"

#include <string.h>

bool isNumber_65_1(char *s) {
    if (s == NULL) return false;
    while (*s == ' ') ++s;
    if (*s == '+' || *s == '-') ++s;
    int dot = 0, exponent = 0, num = 0;
    while (*s != '\0') {
        if (*s == '.') {
            if (dot > 0 || exponent > 0) return false;
            ++dot;
            ++s;
        } else if (*s == 'e') {
            if (exponent > 0 || num < 1) return false;
            ++exponent;
            num = 0;
            if (*(s + 1) == '+' || *(s + 1) == '-')
                s += 2;
            else
                ++s;
        } else if ('0' <= *s && *s <= '9') {
            ++num;
            ++s;
        } else break;
    }
    while (*s == ' ') ++s;
    return num > 0 && *s == '\0';
}
