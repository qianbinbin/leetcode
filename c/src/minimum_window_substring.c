#include "minimum_window_substring.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *minWindow_76_1(char *s, char *t) {
    if (s == NULL || t == NULL) return NULL;

    const size_t len_s = strlen(s);
    const size_t len_t = strlen(t);

    int expected[128];
    memset(expected, 0, 128 * sizeof(int));
    for (int i = 0; i < len_t; ++i) ++expected[t[i]];
    size_t expected_count = 0;

    size_t start = 0, end = 0;
    size_t min_start = 0, min_len = SIZE_MAX;
    while (end < len_s) {
        if (expected[s[end]] > 0)
            ++expected_count;
        --expected[s[end]];
        ++end;
        while (expected_count == len_t) {
            if (end - start < min_len) {
                min_len = end - start;
                min_start = start;
            }
            ++expected[s[start]];
            if (expected[s[start]] > 0)
                --expected_count;
            ++start;
        }
    }

    char *ret;
    if (min_len == SIZE_MAX) {
        ret = (char *) malloc(1);
        ret[0] = '\0';
    } else {
        ret = (char *) malloc(min_len + 1);
        ret[min_len] = '\0';
        memcpy(ret, s + min_start, min_len);
    }
    return ret;
}
