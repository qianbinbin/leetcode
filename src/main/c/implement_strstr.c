#include "implement_strstr.h"

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
