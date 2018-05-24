#include "longest_common_prefix.h"

#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix_14_1(char **strs, int strsSize) {
    if (strs == NULL || strsSize < 0) return NULL;
    char *ret = NULL;
    if (strsSize == 0) {
        ret = (char *) malloc(1);
        ret[0] = '\0';
        return ret;
    }

    const size_t len = strlen(strs[0]);
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 1; j < strsSize; ++j) {
            if (strs[j][i] != strs[0][i]) {
                ret = (char *) malloc(i + 1);
                ret[i] = '\0';
                memcpy(ret, strs[0], i);
                return ret;
            }
        }
    }
    ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    memcpy(ret, strs[0], len);
    return ret;
}
