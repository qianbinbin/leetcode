#include "substring_with_concatenation_of_all_words.h"

#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    char *str;
    int count;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hash_code(char *str) {
    int ret = 0;
    for (; *str; ++str)
        ret = ret * 31 + *str;
    // to play with dumb compiler
    // ret = (int64_t) ret * 31 + *str;
    return ret;
}

static hashmap *hashmap_create() {
    return (hashmap *) calloc(1, sizeof(hashmap));
}

static int hashmap_increase_and_get(hashmap *map, char *key) {
    entry *e = map->entries + (hash_code(key) & (HASH_MAP_SIZE - 1));
    while (e->next != NULL) {
        e = e->next;
        if (strcmp(e->str, key) == 0)
            return ++e->count;
    }
    e = (e->next = (entry *) calloc(1, sizeof(entry)));
    e->str = strdup(key);
    return ++e->count;
}

static int hashmap_get(hashmap *map, char *key) {
    entry *e = map->entries + ((hash_code(key) & (HASH_MAP_SIZE - 1)));
    while (e->next != NULL) {
        e = e->next;
        if (strcmp(e->str, key) == 0)
            return e->count;
    }
    return 0;
}

static void hashmap_clear(hashmap *map) {
    entry *entries = map->entries, *e, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = entries + i;
        while ((tmp = e->next) != NULL) {
            e->next = tmp->next;
            free(tmp->str);
            free(tmp);
        }
    }
}

static void hashmap_free(hashmap *map) {
    hashmap_clear(map);
    free(map);
}

int *findSubstring_30_1(char *s, char **words, int wordsSize, int *returnSize) {
    int capacity = 16;
    int *result = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    int const sl = (int) strlen(s), width = (int) strlen(words[0]),
            len = wordsSize * width;
    if (sl < len)
        goto ret;

    hashmap *expected = hashmap_create(), *actual = hashmap_create();
    for (int i = 0; i < wordsSize; ++i)
        hashmap_increase_and_get(expected, words[i]);
    int i = 0, end = sl - width + 1, count = 0;
    while (i < end) {
        char *word = strndup(s + i, width);
        if (hashmap_get(expected, word) >=
            hashmap_increase_and_get(actual, word)) {
            if (++count == wordsSize) {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int *) realloc(result, capacity * sizeof(int));
                }
                i -= (wordsSize - 1) * width;
                result[(*returnSize)++] = i;
                count = 0;
                hashmap_clear(actual);
                ++i;
            } else {
                i += width;
            }
        } else {
            hashmap_clear(actual);
            i -= count * width - 1;
            count = 0;
        }
        free(word);
    }
    hashmap_free(expected);
    hashmap_free(actual);

    ret:
    result = (int *) realloc(result, (*returnSize) * sizeof(int));
    return result;
}
