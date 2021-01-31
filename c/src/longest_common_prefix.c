#include "longest_common_prefix.h"

#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix_14_1(char **strs, int strsSize) {
    size_t j = 0;
    if (strsSize == 0)
        goto ret;

    size_t i;
    for (char *s = strs[0]; *s; ++s, ++j) {
        for (i = 1; i != strsSize; ++i) {
            if (strs[i][j] != *s)
                goto ret;
        }
    }
    ret:;
    char *prefix = (char *) malloc(j + 1);
    prefix[j] = '\0';
    if (strsSize != 0)
        memcpy(prefix, strs[0], j);
    return prefix;
}
