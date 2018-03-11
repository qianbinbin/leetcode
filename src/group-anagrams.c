#include <group-anagrams.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 1024

struct Index {
    int index;
    struct Index *next;
};

struct Entry {
    char *key;
    struct Index *value;
    struct Entry *next;
};

int hashcode(char *key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash += (key[i] - 'a') * (i + 1);
    }
    return hash % HASH_MAP_SIZE;
}

struct Entry *hashmap_init() {
    struct Entry *entries = (struct Entry *) malloc(HASH_MAP_SIZE * sizeof(struct Entry));
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        entries[i].key = NULL;
        entries[i].value = NULL;
        entries[i].next = NULL;
    }
    return entries;
}

struct Entry *hashmap_pop(struct Entry *entries, char *key) {
    int hash = hashcode(key);
    struct Entry *pre = entries + hash;
    struct Entry *p = pre->next;
    while (p != NULL) {
        if (strcmp(p->key, key) == 0) {
            pre->next = p->next;
            return p;
        }
        pre = p;
        p = pre->next;
    }
    return NULL;
}

void hashmap_push(struct Entry *entries, char *key, int index) {
    int hash = hashcode(key);
    struct Entry *pre = entries + hash;
    while (pre->next != NULL) {
        if (strcmp(pre->next->key, key) == 0) {
            struct Index *idx_p = pre->next->value;
            while (idx_p->next != NULL) idx_p = idx_p->next;
            idx_p->next = (struct Index *) malloc(sizeof(struct Index));
            idx_p = idx_p->next;
            idx_p->index = index;
            idx_p->next = NULL;
            return;
        }
        pre = pre->next;
    }
    pre->next = (struct Entry *) malloc(sizeof(struct Entry));
    pre = pre->next;
    pre->key = key;
    pre->value = (struct Index *) malloc(sizeof(struct Index));
    pre->value->index = index;
    pre->value->next = NULL;
    pre->next = NULL;
}

void hashmap_free_entry(struct Entry *entry) {
    struct Index *idx_pre, *idx_p;
    idx_pre = entry->value;
    idx_p = idx_pre->next;
    while (idx_p != NULL) {
        idx_pre->next = idx_p->next;
        free(idx_p);
        idx_p = idx_pre->next;
    }
    free(idx_pre);
    free(entry);
}

void hashmap_uninit(struct Entry *entries) {
    struct Entry *pre, *p;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        pre = entries + i;
        p = pre->next;
        while (p != NULL) {
            pre->next = p->next;
            hashmap_free_entry(p);
            p = pre->next;
        }
    }
    free(entries);
}

int compare(const void *a, const void *b) {
    return (*(char *) a - *(char *) b);
}

char ***groupAnagrams_49(char **strs, int strsSize, int **columnSizes, int *returnSize) {
    if (strs == NULL || strsSize < 0 || columnSizes == NULL || returnSize == NULL) return NULL;

    struct Entry *entries = hashmap_init();

    char **copy = (char **) malloc(strsSize * sizeof(char *));
    char *tmp;
    for (int i = 0; i < strsSize; ++i) {
        tmp = (char *) malloc(strlen(strs[i] + 1));
        strcpy(tmp, strs[i]);
        qsort(tmp, strlen(tmp), sizeof(char), compare);
        copy[i] = tmp;
        hashmap_push(entries, tmp, i);
    }

    char ***ret = (char ***) malloc(strsSize * sizeof(char **));
    *columnSizes = (int *) malloc(strsSize * sizeof(int));
    int group = 0, count;
    struct Entry *entry;
    struct Index *index;
    for (int i = 0; i < strsSize; ++i) {
        entry = hashmap_pop(entries, copy[i]);
        if (entry != NULL) {
            index = entry->value;
            count = 0;
            while (index != NULL) {
                ++count;
                index = index->next;
            }
            (*columnSizes)[group] = count;
            ret[group] = (char **) malloc(count * sizeof(char *));
            index = entry->value;
            for (int column = 0; column < count; ++column) {
                ret[group][column] = (char *) malloc(strlen(entry->key) + 1);
                strcpy(ret[group][column], strs[index->index]);
                index = index->next;
            }
            ++group;
            hashmap_free_entry(entry);
        }
    }
    ret = (char ***) realloc(ret, group * sizeof(char **));
    *columnSizes = (int *) realloc(*columnSizes, group * sizeof(int));
    *returnSize = group;

    for (int i = 0; i < strsSize; ++i) {
        free(copy[i]);
    }
    free(copy);
    hashmap_uninit(entries);
    return ret;
}
