#include <valid-palindrome.h>
#include <string.h>

#define IS_ALPHANUMERIC(s) \
(('0' <= (s) && (s) <= '9') || ('A' <= (s) && (s) <= 'Z') || ('a' <= (s) && (s) <= 'z'))

#define EQUALS_IGNORE_CASE(a, b) \
('0' <= (a) && (a) <= '9' && '0' <= (b) && (b) <= '9' ? \
(a) == (b) : \
((a) & 0xdf) == ((b) & 0xdf))

bool isPalindrome_125(char *s) {
    if (s == NULL) return false;

    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (!IS_ALPHANUMERIC(s[i]))
            ++i;
        else if (!IS_ALPHANUMERIC(s[j]))
            --j;
        else if (!EQUALS_IGNORE_CASE(s[i], s[j]))
            return false;
        else {
            ++i;
            --j;
        }
    }
    return true;
}
