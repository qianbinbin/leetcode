#include "scramble_string.h"

#include "uthash.h"

#include <stdlib.h>
#include <string.h>

typedef struct scramble_entry {
    char *key;
    bool value;
    UT_hash_handle hh;
} entry;

static bool is_scramble(char *s1, char *s2, size_t len, entry **map) {
    char *k = (char *) malloc(2 * len + 1);
    memcpy(k, s1, len);
    memcpy(k + len, s2, len);
    k[2 * len] = '\0';
    entry *e = NULL;
    HASH_FIND_STR(*map, k, e);
    if (e != NULL) {
        free(k);
        return e->value;
    }
    e = (entry *) malloc(sizeof(entry));
    e->key = k;
    if (len == 1) {
        e->value = *s1 == *s2;
        HASH_ADD_KEYPTR(hh, *map, e->key, 2 * len, e);
        return e->value;
    }

    int count[26];
    memset(count, 0, 26 * sizeof(int));
    for (size_t i = 0; i < len; ++i) {
        ++count[s1[i] - 'a'];
        --count[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) {
            e->value = false;
            HASH_ADD_KEYPTR(hh, *map, e->key, 2 * len, e);
            return false;
        }
    }

    for (size_t l = 1; l < len; ++l) {
        if ((is_scramble(s1, s2, l, map) &&
             is_scramble(s1 + l, s2 + l, len - l, map)) ||
            (is_scramble(s1, s2 + len - l, l, map) &&
             is_scramble(s1 + l, s2, len - l, map))) {
            e->value = true;
            HASH_ADD_KEYPTR(hh, *map, e->key, 2 * len, e);
            return true;
        }
    }
    e->value = false;
    HASH_ADD_KEYPTR(hh, *map, e->key, 2 * len, e);
    return false;
}

bool isScramble_87_1(char *s1, char *s2) {
    entry *map = NULL;
    bool ret = is_scramble(s1, s2, strlen(s1), &map);
    entry *e, *tmp;
    HASH_ITER(hh, map, e, tmp) {
        HASH_DEL(map, e);
        free(e->key);
        free(e);
    }
    return ret;
}

bool isScramble_87_2(char *s1, char *s2) {
    const size_t len = strlen(s1);

    bool ***dp = (bool ***) malloc((len + 1) * sizeof(bool **));
    size_t i, j, k, l;
    for (i = 0; i <= len; ++i) {
        dp[i] = (bool **) malloc(len * sizeof(bool *));
        for (j = 0; j < len; ++j)
            dp[i][j] = (bool *) calloc(len, sizeof(bool));
    }
    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }

    for (l = 2; l <= len; ++l) {
        for (i = 0; i + l <= len; ++i) {
            for (j = 0; j + l <= len; ++j) {
                for (k = 1; k < l; ++k) {
                    if ((dp[k][i][j] && dp[l - k][i + k][j + k]) ||
                        (dp[k][i][j + l - k] && dp[l - k][i + k][j])) {
                        dp[l][i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    bool ret = dp[len][0][0];
    for (i = 0; i <= len; ++i) {
        for (j = 0; j < len; ++j)
            free(dp[i][j]);
        free(dp[i]);
    }
    free(dp);
    return ret;
}
