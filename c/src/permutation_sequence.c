#include "permutation_sequence.h"

#include <stdlib.h>
#include <string.h>

static char array_remove(char *chars, int *size, int index) {
    char ret = chars[index];
    memmove(chars + index, chars + index + 1,
            (*size - index - 1) * sizeof(char));
    --*size;
    return ret;
}

char *getPermutation_60_1(int n, int k) {
    char *ret = (char *) malloc((n + 1) * sizeof(char));
    ret[n] = '\0';

    int factorial[10];
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i;

    int size = n;
    char chars[] = "123456789";
    --k;
    for (int i = 0, index; n > 0; --n) {
        index = k / factorial[n - 1];
        ret[i++] = array_remove(chars, &size, index);
        k %= factorial[n - 1];
    }
    return ret;
}
