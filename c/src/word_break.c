#include "word_break.h"

#include "uthash.h"

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    UT_hash_handle hh;
} set_entry;

bool wordBreak_139_1(char *s, char **wordDict, int wordDictSize) {
    const size_t len = strlen(s);

    set_entry *set = NULL, *e;
    for (size_t i = 0; i < wordDictSize; ++i) {
        e = (set_entry *) malloc(sizeof(set_entry));
        e->key = wordDict[i];
        HASH_ADD_KEYPTR(hh, set, e->key, strlen(e->key), e);
    }

    bool *dp = (bool *) calloc(len + 1, sizeof(bool));
    dp[0] = true;
    for (int i, j = 1; j <= len; ++j) {
        for (i = j - 1; i >= 0; --i) {
            if (dp[i]) {
                char *tmp = strndup(s + i, j - i);
                HASH_FIND_STR(set, tmp, e);
                if (e != NULL) {
                    dp[j] = true;
                    free(tmp);
                    break;
                }
                free(tmp);
            }
        }
    }
    set_entry *t;
    HASH_ITER(hh, set, e, t) {
        HASH_DEL(set, e);
        free(e);
    }
    bool ret = dp[len];
    free(dp);
    return ret;
}
