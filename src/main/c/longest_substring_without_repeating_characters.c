#include "longest_substring_without_repeating_characters.h"

#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring_3_1(char *s) {
    if (s == NULL) return 0;
    const int len = (const int) strlen(s);
    if (len == 0) return 0;

    int map[256];
    memset(map, -1, 256 * sizeof(int));
    map[s[0] + 128] = 0;
    int start = 0;
    int longest = 1;
    for (int i = 1; i < len; ++i) {
        if (map[s[i] + 128] >= start) {
            longest = MAX(longest, i - start);
            start = map[s[i] + 128] + 1;
        }
        map[s[i] + 128] = i;
    }
    longest = MAX(longest, len - start);
    return longest;
}
