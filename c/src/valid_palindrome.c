#include "valid_palindrome.h"

#include <ctype.h>
#include <string.h>

bool isPalindrome_125_1(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (!isalnum(s[i]))
            ++i;
        else if (!isalnum(s[j]))
            --j;
        else if (tolower(s[i]) != tolower(s[j]))
            return false;
        else {
            ++i;
            --j;
        }
    }
    return true;
}
