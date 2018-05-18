#include <word_break.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    char *key;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static hashmap *hashmap_create() {
    hashmap *new = (hashmap *) malloc(sizeof(hashmap));
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        (new->entries + i)->next = NULL;
    }
    return new;
}

static int hashcode(char *key) {
    int code = 0;
    const size_t len = strlen(key);
    for (int i = 0; i < len; ++i) {
        code = code * 31 + key[i];
    }
    return abs(code);
}

static void hashmap_put(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
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
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            return true;
        }
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

static char *str_create(char *s, size_t start, size_t end) {
    const size_t len = end - start + 1;
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    memcpy(ret, s + start, len);
    return ret;
}

bool wordBreak_139(char *s, char **wordDict, int wordDictSize) {
    if (s == NULL || wordDict == NULL || wordDictSize < 0) return false;
    const size_t len = strlen(s);
    if (len < 1) return false;

    hashmap *map = hashmap_create();
    for (size_t i = 0; i < wordDictSize; ++i) {
        hashmap_put(map, wordDict[i]);
    }

    bool *dp = (bool *) calloc(len + 1, sizeof(bool));
    dp[0] = true;
    for (size_t i = 1; i <= len; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (dp[j]) {
                char *tmp = str_create(s, j, i - 1);
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
