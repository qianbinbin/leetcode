#include "integer_to_roman.h"

#include <stdlib.h>
#include <string.h>

char *intToRoman_12_1(int num) {
    static int const values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5,
                                 4, 1};
    static char *const symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                    "X", "IX", "V", "IV", "I"};
    char *ret = (char *) calloc(20, sizeof(char));
    for (int i = 0, count; i < 13; ++i) {
        if ((count = num / values[i]) == 0)
            continue;
        num -= values[i] * count;
        for (; count != 0; --count) strcat(ret, symbols[i]);
    }
    ret = (char *) realloc(ret, strlen(ret) + 1);
    return ret;
}
