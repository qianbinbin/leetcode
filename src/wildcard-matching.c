#include <wildcard-matching.h>
#include <string.h>

bool isMatch_44(char *s, char *p) {
    if (s == NULL || p == NULL) return false;
    char *star = NULL, *last_str = NULL;
    while (*s != '\0') {
        if (*p == '?' || *s == *p) {
            ++s;
            ++p;
        } else if (*p == '*') {
            last_str = s;
            star = p;
            ++p;
        } else if (star) {
            s = last_str + 1;
            ++last_str;
            p = star + 1;
        } else {
            return false;
        }
    }
    while (*p == '*') ++p;
    return *p == '\0';
}
