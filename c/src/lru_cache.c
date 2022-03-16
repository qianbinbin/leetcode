#include "lru_cache.h"

#include <stdlib.h>

static int table_size(int cap) {
    int n = cap - 1;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

static node *node_create(int key) {
    node *n = (node *) malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

static void node_reorder(LRUCache *cache, node *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->next = cache->head->next;
    n->prev = cache->head;
    cache->head->next->prev = n;
    cache->head->next = n;
}

static entry *entry_create(int key, int value) {
    entry *e = (entry *) malloc(sizeof(entry));
    e->key = key;
    e->value = value;
    e->next = NULL;
    e->node = NULL;
    return e;
}

static void lru_pop(LRUCache *cache) {
    node *n = cache->tail->prev;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    int i = n->key & (cache->table_size - 1);
    entry *e = cache->table + i;
    while (e->next->key != n->key)
        e = e->next;
    e->next = e->next->next;
    --cache->size;
}

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *) malloc(sizeof(LRUCache));
    cache->size = 0;
    cache->capacity = capacity;
    int t_size = table_size(capacity);
    cache->table_size = t_size;

    node *head = node_create(0);
    node *tail = node_create(0);
    head->next = tail;
    tail->prev = head;
    cache->head = head;
    cache->tail = tail;
    cache->table = (entry *) calloc(t_size, sizeof(entry));
    return cache;
}

int lRUCacheGet(LRUCache *obj, int key) {
    int i = key & (obj->table_size - 1);
    entry *e = (obj->table + i)->next;
    while (e != NULL) {
        if (e->key == key) {
            node_reorder(obj, e->node);
            return e->value;
        }
        e = e->next;
    }
    return -1;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    int i = key & (obj->table_size - 1);
    entry *h = obj->table + i, *e = h->next;
    while (e != NULL) {
        if (e->key == key) {
            e->value = value;
            node_reorder(obj, e->node);
            return;
        }
        e = e->next;
    }

    e = entry_create(key, value);
    node *n = node_create(key), *head = obj->head;
    n->next = head->next;
    n->prev = head;
    head->next->prev = n;
    head->next = n;
    e->node = n;
    e->next = h->next;
    h->next = e;
    if (++obj->size > obj->capacity)
        lru_pop(obj);
}

void lRUCacheFree(LRUCache *obj) {
    entry *table = obj->table;
    const int size = obj->table_size;
    entry *h, *e;
    for (int i = 0; i < size; ++i) {
        h = table + i;
        while ((e = h->next) != NULL) {
            h->next = e->next;
            free(e);
        }
    }
    free(table);

    node *pre = obj->head, *p;
    while ((p = pre->next) != NULL) {
        pre->next = p->next;
        free(p);
    }
    free(pre);
    free(obj);
}
