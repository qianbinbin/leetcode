#include "count_and_say.h"

#include <stdlib.h>
#include <string.h>

static char *count_and_say(char *str) {
    char *ret = (char *) malloc(2 * strlen(str) + 1);
    size_t idx = 0;
    char count;
    while (*str) {
        count = '1';
        while (*str == *(str + 1)) {
            ++str;
            ++count;
        }
        ret[idx++] = count;
        ret[idx++] = *str;
        ++str;
    }
    ret[idx] = '\0';
    ret = realloc(ret, idx + 1);
    return ret;
}

char *countAndSay_38_1(int n) {
    char *pre, *ret = (char *) malloc(2);
    ret[0] = '1';
    ret[1] = '\0';
    while (n-- > 1) {
        pre = ret;
        ret = count_and_say(pre);
        free(pre);
    }
    return ret;
}
