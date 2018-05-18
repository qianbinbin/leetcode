#include <longest_palindromic_substring.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

char *longestPalindrome_5_2(char *s) {
    if (s == NULL) return NULL;
    const int len = strlen(s);

    int length = 0, longest = len == 0 ? 0 : 1, start = 0;
    bool f[len][len];
    memset(f, 0, len * len * sizeof(bool));
    for (int j = 0; j < len; ++j) {
        f[j][j] = true;
        for (int i = 0; i < j; ++i) {
            f[i][j] = s[i] == s[j] && (i + 1 == j || f[i + 1][j - 1]);
            length = f[i][j] ? j - i + 1 : 0;
            if (length > longest) {
                longest = length;
                start = i;
            }
        }
    }
    char *ret = (char *) malloc(longest + 1);
    ret[longest] = '\0';
    memcpy(ret, s + start, longest);
    return ret;
}
