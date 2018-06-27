#include "length_of_last_word.h"

#include <string.h>

int lengthOfLastWord_58_1(char *s) {
    if (s == NULL) return 0;

    int end = strlen(s) - 1;
    while (end >= 0 && s[end] == ' ') --end;
    int start = end;
    while (start >= 0 && s[start] != ' ') --start;
    return end - start;
}
