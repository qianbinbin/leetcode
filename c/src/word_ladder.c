#include "word_ladder.h"

#include "uthash.h"

#include <stddef.h>
#include <string.h>

typedef struct {
    char *key;
    UT_hash_handle hh;
} entry;

static void hash_set_add(entry **set, char *key, size_t len) {
    entry *e = (entry *) malloc(sizeof *e);
    e->key = key;
    HASH_ADD_KEYPTR(hh, *set, e->key, len, e);
}

static int hash_set_del(entry **set, char *key) {
    entry *e;
    HASH_FIND_STR(*set, key, e);
    if (e != NULL) {
        HASH_DEL(*set, e);
        free(e);
        return 1;
    }
    return 0;
}

static void hash_set_free(entry **set) {
    entry *e, *tmp;
    HASH_ITER(hh, *set, e, tmp) {
        HASH_DEL(*set, e);
        free(e);
    }
}

int ladderLength_127_1(char *beginWord, char *endWord, char **wordList,
                       int wordListSize) {
    entry *dict = NULL;
    size_t const width = strlen(beginWord);
    for (int i = 0; i < wordListSize; ++i)
        hash_set_add(&dict, wordList[i], width);
    if (!hash_set_del(&dict, endWord)) {
        hash_set_free(&dict);
        return 0;
    }
    hash_set_del(&dict, beginWord);

    entry *set1 = NULL, *set2 = NULL, *next = NULL;
    hash_set_add(&set1, beginWord, width);
    hash_set_add(&set2, endWord, width);

    int depth = 1;
    while (HASH_COUNT(set1) && HASH_COUNT(set2)) {
        if (HASH_COUNT(set1) > HASH_COUNT(set2)) {
            entry *t = set1;
            set1 = set2;
            set2 = t;
        }
        ++depth;
        for (entry *e1 = set1; e1 != NULL; e1 = e1->hh.next) {
            char *str = strdup(e1->key);
            for (int i = 0; i < width; ++i) {
                char origin = str[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == origin) continue;
                    str[i] = c;
                    entry *e;
                    HASH_FIND_STR(set2, str, e);
                    if (e != NULL) {
                        hash_set_free(&set1);
                        hash_set_free(&set2);
                        hash_set_free(&next);
                        hash_set_free(&dict);
                        return depth;
                    }
                    HASH_FIND_STR(dict, str, e);
                    if (e != NULL) {
                        hash_set_add(&next, e->key, width);
                        HASH_DEL(dict, e);
                        free(e);
                    }
                }
                str[i] = origin;
            }
            free(str);
        }
        HASH_CLEAR(hh, set1);
        entry *t = set1;
        set1 = next;
        next = t;
    }

    hash_set_free(&dict);
    return 0;
}
