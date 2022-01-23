#include "minimum_window_substring.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *minWindow_76_1(char *s, char *t) {
    const size_t m = strlen(s);
    const size_t n = strlen(t);

    int expected[128];
    memset(expected, 0, 128 * sizeof(int));
    for (int i = 0; i < n; ++i) ++expected[t[i]];
    size_t expected_count = 0;

    size_t start = -1, len = SIZE_MAX; // -1 == MAX
    for (size_t i = 0, j = 0; j < m; ++j) {
        if (expected[s[j]] > 0)
            ++expected_count;
        --expected[s[j]];
        for (; expected_count == n; ++i) {
            if (j - i + 1 < len)
                len = j - (start = i) + 1;
            if (++expected[s[i]] > 0)
                --expected_count;
        }
    }

    char *ret;
    if (start == -1) {
        ret = (char *) malloc(1);
        ret[0] = '\0';
    } else {
        ret = (char *) malloc(len + 1);
        ret[len] = '\0';
        memcpy(ret, s + start, len);
    }
    return ret;
}
