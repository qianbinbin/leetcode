#include "longest_consecutive_sequence.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define HASH_MAP_SIZE 256

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} entry;

typedef struct HashMap {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hashcode(int key) {
    return key;
}

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    entry *entry = map->entries;
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        entry++->next = NULL;
    return map;
}

static void hashmap_put(hashmap *map, int key, int value) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key) {
            e->next->value = value;
            return;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->value = value;
    new->next = NULL;
    e->next = new;
}

static void hashmap_get(hashmap *map, int key, int *value) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key) {
            *value = e->next->value;
            return;
        }
        e = e->next;
    }
}

static bool hashmap_contains(hashmap *map, int key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (e->next->key == key)
            return true;
        e = e->next;
    }
    return false;
}

static void hashmap_free(hashmap *map) {
    entry *e, *n, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = map->entries + i;
        n = e->next;
        while (n != NULL) {
            e->next = n->next;
            tmp = n;
            n = e->next;
            free(tmp);
        }
    }
    free(map);
}

int longestConsecutive_128_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 2) return numsSize;

    int ret = 1;
    hashmap *map = hashmap_create();
    for (int i = 0; i < numsSize; ++i) hashmap_put(map, nums[i], i);

    for (int i = 0; i < numsSize; ++i) {
        if (!hashmap_contains(map, nums[i] - 1)) {
            int num = nums[i] + 1;
            while (hashmap_contains(map, num)) ++num;
            ret = MAX(ret, num - nums[i]);
        }
    }
    hashmap_free(map);
    return ret;
}

typedef struct UnionFind {
    int n;
    int *parent;
    int *rank;
} uf;

static uf *uf_create(int n) {
    uf *ret = (uf *) malloc(sizeof(uf));
    ret->n = n;
    int *parent = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) parent[i] = i;
    ret->parent = parent;
    ret->rank = (int *) calloc(n, sizeof(int));
    return ret;
}

static int uf_find(uf *u, int i) {
    if (i == u->parent[i])
        return i;
    u->parent[i] = uf_find(u, u->parent[i]);
    return u->parent[i];
}

static void uf_union(uf *u, int a, int b) {
    int root1 = uf_find(u, a), root2 = uf_find(u, b);
    if (root1 == root2) return;
    if (u->rank[root1] > u->rank[root2]) {
        u->parent[root2] = root1;
    } else {
        u->parent[root1] = root2;
        if (u->rank[root1] == u->rank[root2])
            ++(u->rank[root2]);
    }
}

static int uf_max_set_size(uf *u) {
    if (u->n == 0) return 0;
    int ret = 1;
    int *size = (int *) calloc(u->n, sizeof(int));
    for (int i = 0; i < u->n; ++i) {
        int root = uf_find(u, i);
        ++size[root];
        ret = MAX(ret, size[root]);
    }
    return ret;
}

static void uf_free(uf *u) {
    free(u->parent);
    free(u->rank);
    free(u);
}

int longestConsecutive_128_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 2) return numsSize;

    hashmap *map = hashmap_create();
    uf *u = uf_create(numsSize);
    for (int i = 0; i < numsSize; ++i) {
        if (hashmap_contains(map, nums[i])) continue;
        hashmap_put(map, nums[i], i);
        int index = -1;
        hashmap_get(map, nums[i] - 1, &index);
        if (index != -1) {
            uf_union(u, i, index);
            index = -1;
        }
        hashmap_get(map, nums[i] + 1, &index);
        if (index != -1) {
            uf_union(u, i, index);
            index = -1;
        }
    }
    hashmap_free(map);
    int ret = uf_max_set_size(u);
    uf_free(u);
    return ret;
}
