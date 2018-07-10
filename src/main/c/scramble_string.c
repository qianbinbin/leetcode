#include "scramble_string.h"

#include <stdlib.h>
#include <string.h>

static bool is_scramble(char *s1, char *s2, size_t len) {
    if (len == 1) return *s1 == *s2;

    int count[26];
    memset(count, 0, 26 * sizeof(int));
    for (size_t i = 0; i < len; ++i) {
        ++count[s1[i] - 'a'];
        --count[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) if (count[i] != 0) return false;

    for (size_t l = 1; l < len; ++l) {
        if ((is_scramble(s1, s2, l) && is_scramble(s1 + l, s2 + l, len - l)) ||
            (is_scramble(s1, s2 + len - l, l) && is_scramble(s1 + l, s2, len - l))) {
            return true;
        }
    }
    return false;
}

bool isScramble_87_1(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL) return false;

    const size_t len = strlen(s1);
    if (strlen(s2) != len) return false;
    return is_scramble(s1, s2, len);
}

bool isScramble_87_2(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL) return false;

    const size_t len = strlen(s1);
    if (len == 0 || strlen(s2) != len) return false;

    bool ***dp = (bool ***) malloc((len + 1) * sizeof(bool **));
    for (size_t i = 0; i <= len; ++i) {
        dp[i] = (bool **) malloc(len * sizeof(bool *));
        for (size_t j = 0; j < len; ++j)
            dp[i][j] = (bool *) calloc(len, sizeof(bool));
    }
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < len; ++j) {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }

    for (size_t l = 2; l <= len; ++l) {
        for (size_t i = 0; i + l <= len; ++i) {
            for (size_t j = 0; j + l <= len; ++j) {
                for (size_t k = 1; k < l; ++k) {
                    if ((dp[k][i][j] && dp[l - k][i + k][j + k]) || (dp[k][i][j + l - k] && dp[l - k][i + k][j])) {
                        dp[l][i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    bool ret = dp[len][0][0];
    for (size_t i = 0; i <= len; ++i) {
        for (size_t j = 0; j < len; ++j) free(dp[i][j]);
        free(dp[i]);
    }
    free(dp);
    return ret;
}
