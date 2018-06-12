#include "wildcard_matching.h"

#include <stdlib.h>
#include <string.h>

bool isMatch_44_1(char *s, char *p) {
    if (s == NULL || p == NULL) return false;

    const size_t len_s = strlen(s), len_p = strlen(p);
    bool **match = (bool **) malloc((len_s + 1) * sizeof(bool *));
    for (size_t i = 0; i <= len_s; ++i) match[i] = (bool *) calloc(len_p + 1, sizeof(bool));
    match[0][0] = true;
    for (size_t j = 1; j <= len_p; ++j) {
        if (p[j - 1] == '*' && match[0][j - 1])
            match[0][j] = true;
        else break;
    }
    for (size_t i = 1; i <= len_s; ++i) {
        for (size_t j = 1; j <= len_p; ++j) {
            if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                match[i][j] = match[i - 1][j - 1];
            else if (p[j - 1] == '*')
                match[i][j] = match[i][j - 1] || match[i - 1][j];
        }
    }
    bool ret = match[len_s][len_p];
    for (size_t i = 0; i <= len_s; ++i) free(match[i]);
    free(match);
    return ret;
}

bool isMatch_44_2(char *s, char *p) {
    if (s == NULL || p == NULL) return false;

    char *star = NULL, *last_str = NULL;
    while (*s != '\0') {
        if (*p == '?' || *p == *s) {
            ++s;
            ++p;
        } else if (*p == '*') {
            last_str = s;
            star = p;
            ++p;
        } else if (star != NULL) {
            s = ++last_str;
            p = star + 1;
        } else {
            return false;
        }
    }
    while (*p == '*') ++p;
    return *p == '\0';
}
