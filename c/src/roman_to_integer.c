#include "roman_to_integer.h"

#include <string.h>

int romanToInt_13_1(char *s) {
    static int const values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5,
                                 4, 1};
    static char *const symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                    "X", "IX", "V", "IV", "I"};
    int result = 0;
    size_t len;
    for (int i = 0; i < 13; ++i) {
        len = strlen(symbols[i]);
        while (strncmp(s, symbols[i], len) == 0) {
            result += values[i];
            s += len;
        }
    }
    return result;
}
