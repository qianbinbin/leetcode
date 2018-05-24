#include "integer_to_roman.h"

#include <stdlib.h>
#include <string.h>

char *intToRoman_12_1(int num) {
    if (num < 1 || num > 3999) return NULL;

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char *ret = (char *) calloc(20, sizeof(char));
    int idx = 0;
    while (num > 0) {
        while (values[idx] > num) ++idx;
        strcat(ret, symbols[idx]);
        num -= values[idx];
    }
    ret = (char *) realloc(ret, strlen(ret) + 1);
    return ret;
}
