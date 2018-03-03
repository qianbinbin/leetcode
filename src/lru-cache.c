#include <lru-cache.h>
#include <stdlib.h>

#define HASH_MAP_SIZE 1024

LRUCache *lRUCacheCreate(int capacity) {
    if (capacity < 1) return NULL;

    LRUCache *obj = (LRUCache *) malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;

    obj->head = (struct Node *) malloc(sizeof(struct Node));
    obj->tail = (struct Node *) malloc(sizeof(struct Node));
    obj->head->prev = NULL;
    obj->head->next = obj->tail;
    obj->tail->next = NULL;
    obj->tail->prev = obj->head;

    obj->entries = (struct Entry *) malloc(HASH_MAP_SIZE * sizeof(struct Entry));
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        obj->entries[i].next = NULL;
    }
    return obj;
}

struct Node *get_node(LRUCache *obj, int key) {
    int hash = key % HASH_MAP_SIZE;
    for (struct Entry *p = obj->entries[hash].next; p != NULL; p = p->next) {
        if (p->key == key) {
            return p->node;
        }
    }
    return NULL;
}

void put_node(LRUCache *obj, struct Node *node) {
    int hash = node->key % HASH_MAP_SIZE;
    struct Entry *pre;
    for (pre = obj->entries + hash; pre->next != NULL; pre = pre->next) {
        if (pre->next->key == node->key) {
            pre->next->node = node;
        }
    }
    struct Entry *entry = (struct Entry *) malloc(sizeof(struct Entry));
    entry->key = node->key;
    entry->node = node;
    entry->next = NULL;
    pre->next = entry;
}

void remove_node(LRUCache *obj, struct Node *node) {
    int hash = node->key % HASH_MAP_SIZE;
    struct Entry *pre = obj->entries + hash;
    struct Entry *p = pre->next;
    while (p != NULL) {
        if (p->key == node->key) {
            pre->next = p->next;
            free(p);
            return;
        }
        pre = p;
        p = p->next;
    }
}

void reorder_node(LRUCache *obj, struct Node *node) {
    if (node == obj->head->next) return;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = obj->head->next;
    node->prev = obj->head;
    node->next->prev = node;
    obj->head->next = node;
}

struct Node *push_node(LRUCache *obj, int key, int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next = node;
    node->next->prev = node;
    return node;
}

struct Node *pop_node(LRUCache *obj) {
    struct Node *node = obj->tail->prev;
    node->prev->next = obj->tail;
    obj->tail->prev = node->prev;
    return node;
}

int lRUCacheGet(LRUCache *obj, int key) {
    if (obj == NULL) return -1;

    struct Node *node = get_node(obj, key);
    if (node != NULL) {
        reorder_node(obj, node);
        return node->value;
    }
    return -1;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    if (obj == NULL || value < 0) return;

    struct Node *node = get_node(obj, key);
    if (node != NULL) {
        node->value = value;
        reorder_node(obj, node);
    } else {
        ++obj->size;
        if (obj->size > obj->capacity) {
            struct Node *rm = pop_node(obj);
            remove_node(obj, rm);
            free(rm);
            --obj->size;
        }
        struct Node *new = push_node(obj, key, value);
        put_node(obj, new);
    }
}

void lRUCacheFree(LRUCache *obj) {
    if (obj == NULL) return;

    obj->capacity = 0;
    obj->size = 0;

    struct Node *node = obj->head->next;
    while (node != NULL) {
        free(node->prev);
        node = node->next;
    }
    free(obj->tail);

    struct Entry *entry;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        entry = obj->entries[i].next;
        while (entry != NULL) {
            obj->entries[i].next = entry->next;
            free(entry);
            entry = obj->entries[i].next;
        }
    }
    free(obj->entries);
    free(obj);
}
