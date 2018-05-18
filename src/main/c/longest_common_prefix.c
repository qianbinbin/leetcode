#include <longest_common_prefix.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix_14(char **strs, int strsSize) {
    if (strs == NULL || strsSize < 0) return NULL;
    char *ret = NULL;
    if (strsSize == 0) {
        ret = (char *) malloc(1);
        ret[0] = '\0';
        return ret;
    }

    for (int i = 0; i < strlen(strs[0]); ++i) {
        for (int j = 1; j < strsSize; ++j) {
            if (strs[j][i] != strs[0][i]) {
                ret = (char *) malloc(i + 1);
                ret[i] = '\0';
                memcpy(ret, strs[0], i);
                return ret;
            }
        }
    }
    ret = (char *) malloc(strlen(strs[0]) + 1);
    ret[strlen(strs[0])] = '\0';
    memcpy(ret, strs[0], strlen(strs[0]));
    return ret;
}
