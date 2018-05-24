#include "roman_to_integer.h"

#include <string.h>

int map(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}

int romanToInt_13_1(char *s) {
    if (s == NULL) return -1;

    const size_t len = strlen(s);
    int value = 0;
    for (size_t i = 0; i < len;) {
        if (map(s[i]) < map(s[i + 1])) {
            value += map(s[i + 1]) - map(s[i]);
            i += 2;
        } else {
            value += map(s[i]);
            ++i;
        }
    }
    return value;
}
