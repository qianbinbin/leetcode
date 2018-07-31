#include "two_sum.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_MAP_SIZE 256

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hash_code(int key) {
    return key;
}

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
    return map;
}

static void hashmap_put(hashmap *map, int key, int value) {
    int index = hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key) {
            e->next->value = value;
            return;
        }
        e = e->next;
    }

    entry *new = (struct Entry *) malloc(sizeof(struct Entry));
    new->key = key;
    new->value = value;
    new->next = NULL;
    e->next = new;
}

static bool hashmap_constains(hashmap *map, int key) {
    int index = hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key) {
            return true;
        }
        e = e->next;
    }
    return false;
}

static int hashmap_get(hashmap *map, int key) {
    int index = hash_code(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key) {
            return e->next->value;
        }
        e = e->next;
    }
    return INT_MIN;
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

int *twoSum_1_1(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 2) return NULL;

    int *ret = NULL;
    hashmap *map = hashmap_create();
    for (int i = 0; i < numsSize; ++i) {
        if (hashmap_constains(map, target - nums[i])) {
            ret = (int *) malloc(2 * sizeof(int));
            ret[0] = hashmap_get(map, target - nums[i]);
            ret[1] = i;
            break;
        }
        hashmap_put(map, nums[i], i);
    }
    hashmap_free(map);
    return ret;
}
