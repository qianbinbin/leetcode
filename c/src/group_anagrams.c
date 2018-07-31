#include "group_anagrams.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Anagram {
    const char *str;
    int count[26];
    int hash;
} anagram;

static anagram *anagram_create(const char *str) {
    anagram *a = (anagram *) malloc(sizeof(anagram));
    a->str = str;
    memset(a->count, 0, 26 * sizeof(int));
    for (; *str != '\0'; ++str)
        ++a->count[*str - 'a'];
    int hash = 0;
    for (int i = 0; i < 26; ++i)
        hash = hash * 31 + a->count[i];
    a->hash = hash;
    return a;
}

static int anagram_hash_code(const void *a) {
    return ((anagram *) a)->hash;
}

static bool anagram_equals(const void *a, const void *b) {
    if (a == b) return true;
    for (int i = 0; i < 26; ++i) {
        if (((anagram *) a)->count[i] != ((anagram *) b)->count[i])
            return false;
    }
    return true;
}

#define ARRAY_INIT_SIZE 16

typedef struct Array {
    void **data;
    int size;
    int capacity;
} array;

static array *array_create() {
    array *arr = (array *) malloc(sizeof(array));
    arr->data = (void **) calloc(ARRAY_INIT_SIZE, sizeof(void *));
    arr->size = 0;
    arr->capacity = ARRAY_INIT_SIZE;
    return arr;
}

static void array_add(array *arr, void *e) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (void **) realloc(arr->data, arr->capacity * sizeof(void *));
    }
    arr->data[arr->size++] = e;
}

static void array_free(array *arr) {
    free(arr->data);
    free(arr);
}

#define HASH_MAP_SIZE 256

typedef struct Entry {
    void *key;
    void *value;
    struct Entry *next;
} entry;

typedef struct HashMap {
    entry entries[HASH_MAP_SIZE];

    int (*hash_code)(const void *);

    bool (*equals)(const void *, const void *);
} hash_map;

static hash_map *hash_map_create(int (*hash_code)(const void *),
                                 bool (*equals)(const void *, const void *)) {
    hash_map *map = (hash_map *) malloc(sizeof(hash_map));
    entry *entries = map->entries;
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (entries + i)->next = NULL;
    map->hash_code = hash_code;
    map->equals = equals;
    return map;
}

static void *hash_map_get(hash_map *map, void *key) {
    int index = map->hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (map->equals(e->next->key, key))
            return e->next->value;
        e = e->next;
    }
    return NULL;
}

static void hash_map_put(hash_map *map, void *key, void *value) {
    int index = map->hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (map->equals(e->next->key, key)) {
            e->next->value = value;
            return;
        }
        e = e->next;
    }
    e->next = (entry *) malloc(sizeof(entry));
    e = e->next;
    e->key = key;
    e->value = value;
    e->next = NULL;
}

static void **hash_map_values(hash_map *map, int *size) {
    int capacity = 16;
    *size = 0;
    void **ret = (void **) malloc(capacity * sizeof(void *));
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        entry *e = (map->entries + i)->next;
        while (e != NULL) {
            if (*size >= capacity) {
                capacity *= 2;
                ret = (void **) realloc(ret, capacity * sizeof(void *));
            }
            ret[(*size)++] = e->value;
            e = e->next;
        }
    }
    ret = (void **) realloc(ret, *size * sizeof(void *));
    return ret;
}

static void hash_map_free(hash_map *map, void (*iterate)(void *, void *)) {
    entry *pre, *p, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        pre = map->entries + i;
        p = pre->next;
        while (p != NULL) {
            tmp = p;
            pre->next = p->next;
            p = pre->next;
            iterate(tmp->key, tmp->value);
            free(tmp);
        }
    }
    free(map);
}

static void iterate(void *k, void *v) {
    free(k);
}

char ***groupAnagrams_49_1(char **strs, int strsSize, int **columnSizes, int *returnSize) {
    if (strs == NULL || strsSize < 0 || columnSizes == NULL || returnSize == NULL) return NULL;

    hash_map *map = hash_map_create(anagram_hash_code, anagram_equals);

    for (int i = 0; i < strsSize; ++i) {
        anagram *key = anagram_create(strs[i]);
        array *arr = hash_map_get(map, key);
        if (arr == NULL) {
            arr = array_create();
            hash_map_put(map, key, arr);
        } else {
            free(key);
        }
        array_add(arr, strs[i]);
    }

    array **arrays = (array **) hash_map_values(map, returnSize);
    char ***ret = (char ***) malloc(*returnSize * sizeof(char **));
    *columnSizes = (int *) malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = (char **) malloc(arrays[i]->size * sizeof(char *));
        memcpy(ret[i], arrays[i]->data, arrays[i]->size * sizeof(void *));
        (*columnSizes)[i] = arrays[i]->size;
        array_free(arrays[i]);
    }
    free(arrays);
    hash_map_free(map, iterate);
    return ret;
}
