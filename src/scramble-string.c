#include <scramble-string.h>
#include <stdlib.h>
#include <string.h>

static bool is_scramble(char *s1, char *s2, size_t len) {
    if (len == 1) return *s1 == *s2;

    int map[26];
    memset(map, 0, 26 * sizeof(int));
    for (size_t i = 0; i < len; ++i) {
        ++map[s1[i] - 'a'];
        --map[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) if (map[i] != 0) return false;

    for (size_t i = 1; i < len; ++i) {
        if ((is_scramble(s1, s2, i) && is_scramble(s1 + i, s2 + i, len - i)) ||
            (is_scramble(s1, s2 + len - i, i) && is_scramble(s1 + i, s2, len - i))) {
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
    for (int l = 0; l <= len; ++l) {
        dp[l] = (bool **) malloc(len * sizeof(bool *));
        for (int i = 0; i < len; ++i)
            dp[l][i] = (bool *) calloc(len, sizeof(bool));
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }

    for (size_t l = 2; l <= len; ++l) {
        for (size_t i = 0; i <= len - l; ++i) {
            for (size_t j = 0; j <= len - l; ++j) {
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
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j < len; ++j) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    return ret;
}
