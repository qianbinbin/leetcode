#include "multiply_strings.h"

#include <stdlib.h>
#include <string.h>

char *multiply_43_1(char *num1, char *num2) {
    size_t const len1 = strlen(num1), len2 = strlen(num2);
    size_t const max_len = len1 + len2;
    char *product = (char *) calloc(max_len + 1, sizeof(int));
    for (size_t i = len1 - 1, j, e = -1; i != e; --i) {
        for (j = len2 - 1; j != e; --j) {
            product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            product[i + j] += product[i + j + 1] / 10;
            product[i + j + 1] %= 10;
        }
    }
    for (size_t i = 0; i != max_len; ++i) product[i] += '0';
    size_t high = 0;
    while (high + 1 < max_len && product[high] == '0') ++high;
    char *ret = (char *) malloc(max_len - high + 1);
    strcpy(ret, product + high);
    free(product);
    return ret;
}
