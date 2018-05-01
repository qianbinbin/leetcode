#include <longest-substring-without-repeating-characters.h>
#include <string.h>

int lengthOfLongestSubstring_3(char *s) {
    if (s == NULL) return 0;

    const int len = strlen(s);
    int index[256];
    for (int i = 0; i < 256; ++i)
        index[i] = -1;

    int start = 0;
    int longest = 0;
    for (int i = 0; i < len; ++i) {
        if (index[s[i] + 128] >= start) {
            start = index[s[i] + 128] + 1;
        }
        longest = i - start + 1 > longest ? i - start + 1 : longest;
        index[s[i] + 128] = i;
    }
    return longest;
}
