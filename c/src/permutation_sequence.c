#include "permutation_sequence.h"

#include <stdlib.h>
#include <string.h>

static char array_remove(char *chars, int *size, int index) {
    char ret = chars[index];
    memmove(chars + index, chars + index + 1, (*size - index - 1) * sizeof(char));
    --*size;
    return ret;
}

char *getPermutation_60_1(int n, int k) {
    if (n < 1 || n > 9 || k < 1) return NULL;

    char *ret = (char *) malloc((n + 1) * sizeof(char));

    int factorial[10];
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i;
    if (k > factorial[n]) {
        free(ret);
        return NULL;
    }

    int size = n;
    char chars[] = "123456789";
    --k;
    for (int i = 0, index; i < n; ++i) {
        index = k / factorial[n - i - 1];
        ret[i] = array_remove(chars, &size, index);
        k = k % factorial[n - i - 1];
    }
    ret[n] = '\0';
    return ret;
}
