#include "two_sum.h"

#include <stdlib.h>

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} entry;

typedef entry *hashmap;

static int hash_code(int key) {
    return key;
}

static hashmap hashmap_create() {
    return (entry *) calloc(1024, sizeof(entry));
}

static void hashmap_put(hashmap map, int key, int value) {
    entry *p = map + (hash_code(key) & (HASH_MAP_SIZE - 1)), *q;
    while ((q = p->next) != NULL) {
        if (q->key == key) {
            q->value = value;
            return;
        }
        p = q;
    }
    entry *pn = (entry *) malloc(sizeof(entry));
    pn->key = key;
    pn->value = value;
    pn->next = NULL;
    p->next = pn;
}

static entry *hashmap_get_entry(hashmap map, int key) {
    entry *p = map[hash_code(key) & (HASH_MAP_SIZE - 1)].next;
    while (p != NULL && p->key != key)
        p = p->next;
    return p;
}

static void hashmap_free(hashmap map) {
    entry *h, *p;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        h = map + i;
        while ((p = h->next) != NULL) {
            h->next = p->next;
            free(p);
        }
    }
    free(map);
}

int *twoSum_1_1(int *nums, int numsSize, int target, int *returnSize) {
    int *ret = NULL;
    hashmap map = hashmap_create();
    entry *p;
    for (int i = 0; i < numsSize; ++i) {
        if ((p = hashmap_get_entry(map, target - nums[i])) != NULL) {
            ret = (int *) malloc(2 * sizeof(int));
            ret[0] = p->value;
            ret[1] = i;
            *returnSize = 2;
            break;
        }
        hashmap_put(map, nums[i], i);
    }
    hashmap_free(map);
    return ret;
}
