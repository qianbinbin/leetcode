#include <regular-expression-matching.h>
#include <string.h>

bool isMatch_10(char *s, char *p) {
    if (s == NULL || p == NULL) return false;
    if (*p == '\0') return *s == '\0';

    if (*(p + 1) != '*') {
        if (*s != '\0' && (*p == '.' || *s == *p)) return isMatch_10(s + 1, p + 1);
        else return false;
    } else {
        if (*s != '\0' && (*p == '.' || *s == *p)) return isMatch_10(s, p + 2) || isMatch_10(s + 1, p);
        else return isMatch_10(s, p + 2);
    }
}
