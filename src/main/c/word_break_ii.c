#include <word_break_ii.h>
#include <stdbool.h>
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

static void word_break_dfs(char *s, const size_t len, size_t index, bool **valid,
                           char ***result, int *size, size_t *capacity,
                           char **path, size_t *path_size, size_t *path_capacity) {
    if (index == len) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *result = (char **) realloc(*result, (*capacity) * sizeof(char *));
        }
        (*result)[*size] = (char *) malloc((*path_size) * sizeof(char));
        memcpy((*result)[*size], *path, *path_size - 1);
        (*result)[*size][*path_size - 1] = '\0';
        ++(*size);
        return;
    }
    for (size_t j = index; j < len; ++j) {
        if (valid[index][j]) {
            const size_t l = j - index + 1;
            while (*path_size + l + 1 >= *path_capacity) {
                *path_capacity *= 2;
                *path = (char *) realloc(*path, (*path_capacity) * sizeof(char));
            }
            memcpy(*path + *path_size, s + index, l);
            *path_size += l;
            (*path)[(*path_size)++] = ' ';
            word_break_dfs(s, len, j + 1, valid, result, size, capacity, path, path_size, path_capacity);
            *path_size -= l + 1;
        }
    }
}

char **wordBreak_140(char *s, char **wordDict, int wordDictSize, int *returnSize) {
    if (s == NULL || wordDict == NULL || wordDictSize < 0 || returnSize == NULL) return NULL;
    const size_t len = strlen(s);
    if (len < 1) return NULL;

    hashmap *map = hashmap_create();
    for (int i = 0; i < wordDictSize; ++i) hashmap_put(map, wordDict[i]);
    bool *dp = (bool *) calloc(len + 1, sizeof(bool));
    dp[0] = true;
    bool **valid = (bool **) malloc(len * sizeof(bool *));
    for (int i = 0; i < len; ++i) valid[i] = (bool *) calloc(len, sizeof(bool));

    for (size_t i = 1; i <= len; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (dp[j]) {
                char *tmp = str_create(s, j, i - 1);
                if (hashmap_contains(map, tmp)) {
                    dp[i] = true;
                    valid[j][i - 1] = true;
                }
                free(tmp);
            }
        }
    }
    if (!dp[len]) {
        free(dp);
        hashmap_free(map);
        for (int i = 0; i < len; ++i) free(valid[i]);
        free(valid);

        char **ret = (char **) malloc(0);
        *returnSize = 0;
        return ret;
    }

    free(dp);
    hashmap_free(map);

    size_t capacity = 16;
    *returnSize = 0;
    char **ret = (char **) malloc(capacity * sizeof(char *));

    size_t path_capacity = 64;
    size_t path_size = 0;
    char *path = (char *) malloc(path_capacity * sizeof(char));

    word_break_dfs(s, len, 0, valid, &ret, returnSize, &capacity, &path, &path_size, &path_capacity);

    free(path);
    ret = (char **) realloc(ret, (*returnSize) * sizeof(char *));
    for (int i = 0; i < len; ++i) free(valid[i]);
    free(valid);

    return ret;
}