#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <longest_consecutive_sequence.h>

// Approach 1: sorting, O(nlog(n)) but accepted

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int longestConsecutive_128_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 2) return numsSize;

    int *tmp = (int *) malloc(numsSize * sizeof(int));
    assert(tmp != NULL);
    memcpy(tmp, nums, numsSize * sizeof(int));
    qsort(tmp, numsSize, sizeof(int), compare);
    int length = 1, longest = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (tmp[i] == tmp[i - 1]) {
            continue;
        } else if (tmp[i] == tmp[i - 1] + 1) {
            ++length;
        } else {
            longest = longest > length ? longest : length;
            length = 1;
        }
    }
    longest = longest > length ? longest : length;
    free(tmp);
    return longest;
}

// Approach 2: hashmap, O(n)

#define HASH_MAP_SIZE 1024

struct Entry {
    int key;
    int value;
    struct Entry *next;
} entries[HASH_MAP_SIZE];

int hashcode(int key) {
    return abs(key) % HASH_MAP_SIZE;
}

void hashmap_init() {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        entries[i].next = NULL;
}

int hashmap_put(int key, int value) {
    struct Entry *p = entries + hashcode(key);
    while (p->next != NULL) {
        if (p->next->key == key) {
            p->next->value = value;
            return 0;
        }
        p = p->next;
    }

    p->next = (struct Entry *) malloc(sizeof(struct Entry));
    if (p->next != NULL) {
        p->next->key = key;
        p->next->value = value;
        p->next->next = NULL;
        return 0;
    }
    return -1;
}

int hashmap_get(int key, int *value) {
    if (value == NULL) return -2;

    struct Entry *p = entries + hashcode(key);
    while (p->next != NULL) {
        if (p->next->key == key) {
            *value = p->next->value;
            return 0;
        }
        p = p->next;
    }
    return -1;
}

int hashmap_remove(int key) {
    struct Entry *p = entries + hashcode(key);
    while (p->next != NULL) {
        if (p->next->key == key) {
            struct Entry *q = p->next;
            p->next = q->next;
            free(q);
            return 0;
        }
        p = p->next;
    }
    return -1;
}

void hashmap_uninit() {
    struct Entry *p;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        while (entries[i].next != NULL) {
            p = entries[i].next;
            entries[i].next = p->next;
            free(p);
        }
    }
}

int longestConsecutive_128_2(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 2) return numsSize;

    hashmap_init();
    for (int i = 0; i < numsSize; ++i) {
        hashmap_put(nums[i], 0);
    }

    int longest = 1, length;
    int visited = 0;
    int offset;
    for (int i = 0; i < numsSize; ++i) {
        hashmap_get(nums[i], &visited);
        if (visited == 1) continue;
        length = 1;
        for (offset = 1; hashmap_get(nums[i] + offset, &visited) == 0; ++offset) {
            hashmap_put(nums[i] + offset, 1);
            ++length;
        }
        for (offset = -1; hashmap_get(nums[i] + offset, &visited) == 0; --offset) {
            hashmap_put(nums[i] + offset, 1);
            ++length;
        }
        longest = longest > length ? longest : length;
    }
    hashmap_uninit();
    return longest;
}
