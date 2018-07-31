#include "regular_expression_matching.h"

#include <stdlib.h>
#include <string.h>

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

bool isMatch_10_2(char *s, char *p) {
    if (s == NULL || p == NULL) return false;

    const size_t row = strlen(s) + 1, col = strlen(p) + 1;
    bool **match = (bool **) malloc(row * sizeof(bool *));
    for (size_t i = 0; i < row; ++i) match[i] = (bool *) malloc(col * sizeof(col));

    match[0][0] = true;
    if (col > 1) match[0][1] = false;
    for (size_t j = 2; j < col; ++j) match[0][j] = match[0][j - 2] && p[j - 1] == '*';
    for (size_t i = 1; i < row; ++i) match[i][0] = false;
    if (col > 1) {
        if (row > 1) match[1][1] = MATCH(s[0], p[0]);
        for (size_t i = 2; i < row; ++i) match[i][1] = false;
    }

    for (size_t i = 1; i < row; ++i) {
        for (size_t j = 2; j < col; ++j) {
            if (p[j - 1] == '*') {
                if (MATCH(s[i - 1], p[j - 2]))
                    match[i][j] = match[i][j - 2] || match[i - 1][j];
                else
                    match[i][j] = match[i][j - 2];
            } else {
                match[i][j] = match[i - 1][j - 1] && MATCH(s[i - 1], p[j - 1]);
            }
        }
    }

    bool ret = match[row - 1][col - 1];
    for (size_t i = 0; i < row; ++i) free(match[i]);
    free(match);
    return ret;
}
