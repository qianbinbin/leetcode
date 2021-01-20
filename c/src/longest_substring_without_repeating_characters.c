#include "longest_substring_without_repeating_characters.h"

#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring_3_1(char *s) {
    int map[128];
    memset(map, -1, 128 * sizeof(int));
    int pre = -1, i, len = 0, size = (int) strlen(s), *p_idx;
    for (i = 0; i < size; ++i) {
        p_idx = map + s[i];
        pre = MAX(pre, *p_idx);
        len = MAX(len, i - pre);
        *p_idx = i;
    }
    return len;
}
