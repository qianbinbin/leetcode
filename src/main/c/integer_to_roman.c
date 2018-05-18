#include <integer_to_roman.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman_12(int num) {
    if (num < 1 || num > 3999) return NULL;

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman_numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char str[20] = {0};
    int idx = 0;
    while (num > 0) {
        while (values[idx] > num) ++idx;
        strcat(str, roman_numerals[idx]);
        num -= values[idx];
    }
    char *ret = (char *) malloc(strlen(str));
    strcpy(ret, str);
    return ret;
}
