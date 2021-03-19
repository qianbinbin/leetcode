#include "implement_strstr.h"

#include <stdlib.h>
#include <string.h>

int strStr_28_1(char *haystack, char *needle) {
    int const size_needle = (int const) strlen(needle);
    if (size_needle == 0)
        return 0;
    int const size_haystack = (int const) strlen(haystack);
    if (size_haystack < size_needle)
        return -1;

    int i = 0, j = 0;
    while (i < size_haystack && j < size_needle) {
        if (haystack[i] != needle[j]) {
            i = i - j + 1;
            j = 0;
        } else {
            ++i;
            ++j;
        }
    }
    return j == size_needle ? i - j : -1;
}

static int *get_next(char const *p, int size) {
    int *next = (int *) malloc(size * sizeof(int));
    next[0] = -1;
    int i = 0, j = -1;
    while (i < size - 1) {
        while (j != -1 && p[j] != p[i])
            j = next[j];
        ++i;
        ++j;
        next[i] = p[j] != p[i] ? j : next[j];
    }
    return next;
}

int strStr_28_2(char *haystack, char *needle) {
    int const size_needle = (int const) strlen(needle);
    if (size_needle == 0)
        return 0;
    int const size_haystack = (int const) strlen(haystack);
    if (size_haystack < size_needle)
        return -1;

    int *next = get_next(needle, size_needle);
    int i = 0, j = 0;
    while (i < size_haystack && j < size_needle) {
        while (j != -1 && haystack[i] != needle[j])
            j = next[j];
        ++i;
        ++j;
    }
    free(next);
    return j == size_needle ? i - j : -1;
}
