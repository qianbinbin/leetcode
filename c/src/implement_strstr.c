#include "implement_strstr.h"

#include <stdlib.h>
#include <string.h>

int strStr_28_1(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) return -1;

    const int size_needle = (const int) strlen(needle);
    if (size_needle == 0)
        return 0;
    const int size_haystack = (const int) strlen(haystack);
    if (size_haystack < size_needle)
        return -1;

    const char first = needle[0];
    const int end = size_haystack - size_needle;
    int j;
    for (int i = 0; i <= end; ++i) {
        while (i <= end && haystack[i] != first) ++i;
        if (i > end)
            return -1;
        j = 1;
        while (j < size_needle && haystack[i + j] == needle[j]) ++j;
        if (j >= size_needle)
            return i;
    }
    return -1;
}

static void generate_next(const char *pattern, int size, int *next) {
    if (size < 1)
        return;
    next[0] = -1;
    if (size == 1)
        return;
    next[1] = 0;
    if (size == 2)
        return;

    int i = 2, j = 0;
    while (i < size) {
        if (j == -1 || pattern[i - 1] == pattern[j]) {
            if (pattern[i] == pattern[j + 1])
                next[i++] = next[++j];
            else
                next[i++] = ++j;
        } else {
            j = next[j];
        }
    }
}

int strStr_28_2(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) return -1;

    const int size_needle = (const int) strlen(needle);
    if (size_needle == 0)
        return 0;
    const int size_haystack = (const int) strlen(haystack);
    if (size_haystack < size_needle)
        return -1;

    int *next = (int *) malloc(size_needle * sizeof(int));
    generate_next(needle, size_needle, next);

    int i = 0, j = 0;
    while (i < size_haystack && j < size_needle) {
        if (j == -1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    free(next);

    if (j == size_needle)
        return i - j;
    return -1;
}
