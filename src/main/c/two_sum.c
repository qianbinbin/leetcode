#include <stdlib.h>
#include <two_sum.h>

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

int *twoSum_1(int *nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 2) return NULL;

    hashmap_init();
    for (int i = 0; i < numsSize; ++i) {
        hashmap_put(nums[i], i);
    }
    int index = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (hashmap_get(target - nums[i], &index) == 0 && i != index) {
            int *result = (int *) malloc(2 * sizeof(int));
            if (result == NULL) return NULL;
            result[0] = i;
            result[1] = index;
            return result;
        }
    }
    hashmap_uninit();
    return NULL;
}
