#include <valid_number.h>
#include <string.h>

bool isNumber_65(char *s) {
    if (s == NULL) return false;
    while (*s == ' ') ++s;
    if (*s == '+' || *s == '-') ++s;
    int dot = 0, exponent = 0, num = 0;
    while (*s != '\0') {
        if (*s == '.') {
            ++dot;
            if (dot > 1 || exponent > 0) return false;
            ++s;
        } else if (*s == 'e') {
            ++exponent;
            if (exponent > 1 || num < 1) return false;
            num = 0;
            if (*(s + 1) == '+' || *(s + 1) == '-') {
                s += 2;
            } else ++s;
        } else if (*s < '0' || *s > '9') {
            break;
        } else {
            ++num;
            ++s;
        }
    }
    while (*s == ' ') ++s;
    return num > 0 && *s == '\0';
}
