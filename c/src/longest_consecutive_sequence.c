#include "longest_consecutive_sequence.h"
#include "uthash.h"

#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (a) >= (b) ? (a) : (b)

typedef struct {
    int key;
    UT_hash_handle hh;
} set_entry;

int longestConsecutive_128_1(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    set_entry *set = NULL;
    for (int i = 0; i < numsSize; ++i) {
        set_entry *e = (set_entry *) malloc(sizeof(set_entry));
        e->key = nums[i];
        HASH_ADD_INT(set, key, e);
    }
    int ret = 0;
    set_entry *e;
    for (int i = 0, j; i < numsSize; ++i) {
        j = nums[i] - 1;
        HASH_FIND_INT(set, &j, e);
        if (e != NULL)
            continue;
        for (j = nums[i] + 1;; ++j) {
            HASH_FIND_INT(set, &j, e);
            if (e == NULL)
                break;
        }
        ret = MAX(ret, j - nums[i]);
    }
    set_entry *tmp;
    HASH_ITER(hh, set, e, tmp) {
        HASH_DEL(set, e);
        free(e);
    }
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
    return u->parent[i] = uf_find(u, u->parent[i]);
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
    int ret = 0;
    int *size = (int *) calloc(u->n, sizeof(int));
    for (int i = 0, e = u->n, root; i < e; ++i) {
        root = uf_find(u, i);
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

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} map_entry;

int longestConsecutive_128_2(int *nums, int numsSize) {
    if (numsSize == 0) return 0;

    uf *u = uf_create(numsSize);
    map_entry *map = NULL, *e;
    for (int i = 0, j; i < numsSize; ++i) {
        HASH_FIND_INT(map, nums + i, e);
        if (e != NULL)
            continue;
        e = (map_entry *) malloc(sizeof(map_entry));
        e->key = nums[i];
        e->val = i;
        HASH_ADD_INT(map, key, e);
        j = nums[i] - 1;
        HASH_FIND_INT(map, &j, e);
        if (e != NULL)
            uf_union(u, i, e->val);
        j = nums[i] + 1;
        HASH_FIND_INT(map, &j, e);
        if (e != NULL)
            uf_union(u, i, e->val);
    }
    map_entry *tmp;
    HASH_ITER(hh, map, e, tmp) {
        HASH_DEL(map, e);
        free(e);
    }
    int ret = uf_max_set_size(u);
    uf_free(u);
    return ret;
}
