#ifndef LEETCODE_LRU_CACHE_H
#define LEETCODE_LRU_CACHE_H

/**
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache(2); // capacity
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */

/**
 * Doubly linked list to store key and value.
 */
struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
};

/**
 * Hashmap to store key and Node address.
 */
struct Entry {
    int key;
    struct Node *node;
    struct Entry *next;
};

typedef struct {
    int capacity;
    int size;
    struct Node *head;
    struct Node *tail;
    struct Entry *entries;
} LRUCache;

LRUCache *lRUCacheCreate(int capacity);

int lRUCacheGet(LRUCache *obj, int key);

void lRUCachePut(LRUCache *obj, int key, int value);

void lRUCacheFree(LRUCache *obj);

#endif //LEETCODE_LRU_CACHE_H
