#include "group_anagrams.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 1024

static int hash_code(char const *k) {
    int ret = 0;
    while (*k++) {
        // ret = ret * 31 + *k;
        // play with dumb compiler
        ret = (int) ((int64_t) ret * 31 + *k);
    }
    return ret;
}

static bool equals(char const *a, char const *b) {
    if (a == b)
        return true;
    while (*a && *b) {
        if (*a++ != *b++)
            return false;
    }
    return *a == '\0' && *b == '\0';
}

typedef struct Entry {
    char *key;
    int val;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hash_map;

static hash_map *hash_map_create() {
    return (hash_map *) calloc(1, sizeof(hash_map));
}

static int hash_map_get(hash_map *map, char *k) {
    int index = hash_code(k) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries[index].next;
    while (e != NULL) {
        if (equals(e->key, k))
            return e->val;
        e = e->next;
    }
    return -1;
}

static int hash_map_put(hash_map *map, char *k, int v) {
    int index = hash_code(k) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index, *n;
    while ((n = e->next) != NULL) {
        if (equals(n->key, k)) {
            int ret = n->val;
            n->val = v;
            return ret;
        }
        e = n;
    }
    n = (entry *) malloc(sizeof(entry));
    n->key = k;
    n->val = v;
    n->next = NULL;
    e->next = n;
    return -1;
}

static void hash_map_free(hash_map *map, void (*delegate)(entry *)) {
    entry *pre, *p;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        pre = map->entries + i;
        while ((p = pre->next) != NULL) {
            pre->next = p->next;
            delegate(p);
            free(p);
        }
    }
    free(map);
}

static void free_key(entry *e) {
    free(e->key);
}

static int comp(void const *a, void const *b) {
    return *(char *) a - *(char *) b;
}

static char *sort(char const *s) {
    char *ret = strdup(s);
    qsort(ret, strlen(ret), sizeof(char), comp);
    return ret;
}

#define DEFAULT_ROW_CAP 16
#define DEFAULT_COL_CAP 16


char ***groupAnagrams_49_1(char **strs, int strsSize, int *returnSize,
                           int **returnColumnSizes) {
    hash_map *map = hash_map_create();

    int capacity = DEFAULT_ROW_CAP;
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char *));
    *returnColumnSizes = (int *) calloc(capacity, sizeof(int));
    int *col_capacities = (int *) malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; ++i) {
        col_capacities[i] = DEFAULT_COL_CAP;
        ret[i] = (char **) malloc(DEFAULT_COL_CAP * sizeof(char *));
    }

    for (int i = 0, j; i < strsSize; ++i) {
        char *s = sort(strs[i]);
        j = hash_map_get(map, s);
        if (j == -1) {
            if (*returnSize >= capacity) {
                capacity *= 2;
                ret = (char ***) realloc(ret, capacity * sizeof(char **));
                *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                                     capacity * sizeof(int *));
                col_capacities = (int *) realloc(col_capacities,
                                                 capacity * sizeof(int));
                for (int k = capacity / 2; k < capacity; ++k) {
                    (*returnColumnSizes)[k] = 0;
                    col_capacities[k] = DEFAULT_COL_CAP;
                    ret[k] = (char **) malloc(DEFAULT_COL_CAP * sizeof(char *));
                }
            }
            hash_map_put(map, s, *returnSize);
            ret[*returnSize][(*returnColumnSizes)[*returnSize]++] = strdup(
                    strs[i]);
            ++(*returnSize);
        } else {
            free(s);
            if ((*returnColumnSizes)[j] >= col_capacities[j]) {
                col_capacities[j] *= 2;
                ret[j] = (char **) realloc(ret[j],
                                           col_capacities[j] * sizeof(char *));
            }
            ret[j][(*returnColumnSizes)[j]++] = strdup(strs[i]);
        }
    }

    hash_map_free(map, free_key);
    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         (*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i)
        ret[i] = (char **) realloc(ret[i],
                                   (*returnColumnSizes)[i] * sizeof(char *));
    free(col_capacities);
    return ret;
}
