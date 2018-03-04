#include <longest-palindromic-substring.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome_5_1(char *s) {
    if (s == NULL) return NULL;

    const int len = strlen(s);
    char *start;
    int length, longest = 0;
    int begin, end;
    for (int i = 0; i < len; ++i) {
        length = 1;
        begin = i - 1;
        end = i + 1;
        while (0 <= begin && end < len && s[begin] == s[end]) {
            length = end - begin + 1;
            --begin;
            ++end;
        }
        if (length > longest) {
            longest = length;
            start = s + begin + 1;
        }

        length = 0;
        begin = i;
        end = i + 1;
        while (0 <= begin && end < len && s[begin] == s[end]) {
            length = end - begin + 1;
            --begin;
            ++end;
        }
        if (length > longest) {
            longest = length;
            start = s + begin + 1;
        }
    }
    char *ret = (char *) malloc(longest + 1);
    ret[longest] = '\0';
    if (longest > 0) {
        memcpy(ret, start, longest);
    }
    return ret;
}