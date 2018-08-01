#include "reverse_words_in_a_string.h"

#include <string.h>

static void reverse(char *s, size_t start, size_t end) {
    const size_t sum = start + end, half = sum / 2;
    char tmp;
    for (size_t i = start; i < half; ++i) {
        tmp = s[i];
        s[i] = s[sum - i - 1];
        s[sum - i - 1] = tmp;
    }
}

void reverseWords_151_1(char *s) {
    if (s == NULL) return;
    const size_t len = strlen(s);
    if (len == 0) return;
    reverse(s, 0, len);

    size_t i, j, size = 0;
    for (i = 0; i < len && s[i] == ' '; ++i);
    while (i < len) {
        for (j = i + 1; j < len && s[j] != ' '; ++j);
        reverse(s, i, j);
        memmove(s + size, s + i, j - i);
        size += j - i;
        if (size < len) s[size++] = ' ';
        for (i = j + 1; i < len && s[i] == ' '; ++i);
    }
    if (size == 0) s[0] = '\0';
    else if (s[size - 1] == ' ') s[size - 1] = '\0';
}
