#include "count_and_say.h"

#include <stdlib.h>
#include <string.h>

static char *count_and_say(char *str) {
    const size_t len = strlen(str);
    char *ret = (char *) malloc(2 * len + 1);
    size_t idx = 0;
    int count;
    while (*str != '\0') {
        count = 1;
        while (*str == *(str + 1)) {
            ++str;
            ++count;
        }
        ret[idx++] = (char) (count + '0');
        ret[idx++] = *str;
        ++str;
    }
    ret[idx] = '\0';
    ret = realloc(ret, idx + 1);
    return ret;
}

char *countAndSay_38_1(int n) {
    if (n < 1) return NULL;

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
