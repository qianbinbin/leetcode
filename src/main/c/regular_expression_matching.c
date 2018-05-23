#include "regular_expression_matching.h"

#define MATCH(s, p) ((p) == '.' || (s) == (p))

bool isMatch_10_1(char *s, char *p) {
    if (*p == '\0') return *s == '\0';

    if (*(p + 1) != '*') {
        if (*s != '\0' && MATCH(*s, *p))
            return isMatch_10_1(s + 1, p + 1);
        else
            return false;
    } else {
        if (*s != '\0' && MATCH(*s, *p))
            return isMatch_10_1(s, p + 2) || isMatch_10_1(s + 1, p);
        else
            return isMatch_10_1(s, p + 2);
    }
}
