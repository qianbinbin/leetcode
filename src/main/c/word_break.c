#include "word_break.h"

#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 256

typedef struct Entry {
    char *key;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    entry *entries = map->entries;
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (entries + i)->next = NULL;
    return map;
}

static int hashcode(char *key) {
    int hash = 0;
    for (; *key != '\0'; ++key)
        hash = hash * 31 + *key;
    return hash;
}

static void hashmap_put(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return;
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->next = NULL;
    e->next = new;
}

static bool hashmap_contains(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return true;
        e = e->next;
    }
    return false;
}

static void hashmap_free(hashmap *map) {
    entry *e, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = map->entries + i;
        while (e->next != NULL) {
            tmp = e->next;
            e->next = tmp->next;
            free(tmp);
        }
    }
    free(map);
}

static char *str_new(char *s, size_t start, size_t end) {
    const size_t len = end - start;
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    memcpy(ret, s + start, len);
    return ret;
}

bool wordBreak_139_1(char *s, char **wordDict, int wordDictSize) {
    if (s == NULL || wordDict == NULL || wordDictSize < 0) return false;
    const size_t len = strlen(s);
    if (len < 1) return false;

    hashmap *map = hashmap_create();
    for (size_t i = 0; i < wordDictSize; ++i)
        hashmap_put(map, wordDict[i]);

    bool *dp = (bool *) calloc(len + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 1; i <= len; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (dp[j]) {
                char *tmp = str_new(s, j, i);
                if (hashmap_contains(map, tmp)) {
                    dp[i] = true;
                    free(tmp);
                    break;
                }
                free(tmp);
            }
        }
    }

    hashmap_free(map);
    bool ret = dp[len];
    free(dp);
    return ret;
}
