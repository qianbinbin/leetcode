#include <count-and-say.h>
#include <string.h>
#include <stdlib.h>

char *next_str(char *str) {
    char *ret = (char *) malloc(2 * strlen(str) + 1);
    memset(ret, 0, 2 * strlen(str) + 1);
    int count, idx = 0;
    while (*str != '\0') {
        count = 1;
        while (*str == *(str + 1)) {
            ++str;
            ++count;
        }
        ret[idx++] = count + '0';
        ret[idx++] = *str;
        ++str;
    }
    ret[idx] = '\0';
    ret = realloc(ret, idx + 1);
    return ret;
}

char *countAndSay_38(int n) {
    if (n < 1) return NULL;

    char *tmp, *ret = (char *) malloc(2);
    ret[0] = '1';
    ret[1] = '\0';
    while (n > 1) {
        tmp = next_str(ret);
        free(ret);
        ret = (char *) malloc(strlen(tmp) + 1);
        strcpy(ret, tmp);
        free(tmp);
        --n;
    }
    return ret;
}
