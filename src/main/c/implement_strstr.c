#include <implement_strstr.h>
#include <string.h>

int strStr_28_1(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) return -1;
    const int size_needle = strlen(needle);
    if (size_needle == 0) return 0;
    const int size_haystack = strlen(haystack);

    for (int i = 0; i <= size_haystack - size_needle; ++i) {
        for (int j = 0; j < size_needle; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
            if (j == size_needle - 1) return i;
        }
    }
    return -1;
}
