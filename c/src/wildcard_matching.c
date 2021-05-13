#include "wildcard_matching.h"

#include <stdlib.h>
#include <string.h>

bool isMatch_44_1(char *s, char *p) {
    size_t const m = strlen(s), n = strlen(p);
    bool **match = (bool **) malloc((m + 1) * sizeof(bool *));
    for (size_t i = 0; i <= m; ++i)
        match[i] = (bool *) calloc(n + 1, sizeof(bool));
    match[0][0] = true;
    for (size_t j = 1; j <= n && p[j - 1] == '*'; ++j)
        match[0][j] = true;
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                match[i][j] = match[i - 1][j - 1];
            else if (p[j - 1] == '*')
                match[i][j] = match[i][j - 1] || match[i - 1][j];
        }
    }
    bool ret = match[m][n];
    for (size_t i = 0; i <= m; ++i) free(match[i]);
    free(match);
    return ret;
}

bool isMatch_44_2(char *s, char *p) {
    char *star = NULL, *last_s = NULL;
    while (*s != '\0') {
        if (*p == '?' || *p == *s) {
            ++s;
            ++p;
        } else if (*p == '*') {
            last_s = s;
            star = p;
            ++p;
        } else if (star != NULL) {
            s = ++last_s;
            p = star + 1;
        } else {
            return false;
        }
    }
    while (*p == '*') ++p;
    return *p == '\0';
}
