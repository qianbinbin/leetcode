#include <word-ladder.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    char *key;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hashcode(char *key) {
    int code = 0;
    const size_t len = strlen(key);
    for (size_t i = 0; i < len; ++i)
        code = code * 31 + key[i];
    return abs(code);
}

static void hashmap_init(hashmap *map) {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
}

static bool hashmap_put(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return false;
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->next = NULL;
    e->next = new;
    return true;
}

static char *hashmap_get(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->key;
        e = e->next;
    }
    return NULL;
}

static bool hashmap_remove(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            entry *n = e->next->next;
            free(e->next);
            e->next = n;
            return true;
        }
        e = e->next;
    }
    return false;
}

static void hashmap_uninit(hashmap *map) {
    entry *head, *e;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        head = map->entries + i;
        e = head->next;
        while (e != NULL) {
            e = e->next;
            free(head->next);
            head->next = e;
        }
    }
}

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} queue;

static void queue_init(queue *q) {
    q->head = (node *) malloc(sizeof(node));
    q->tail = (node *) malloc(sizeof(node));
    q->head->prev = NULL;
    q->head->next = q->tail;
    q->tail->prev = q->head;
    q->tail->next = NULL;
    q->size = 0;
}

static void queue_enq(queue *q, char *data) {
    node *pre = q->tail->prev;
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->next = q->tail;
    new->prev = pre;
    pre->next = new;
    q->tail->prev = new;
    ++q->size;
}

static char *queue_deq(queue *q) {
    node *n = q->head->next;
    char *ret = NULL;
    if (n != q->tail) {
        ret = n->data;
        q->head->next = n->next;
        n->next->prev = q->head;
        free(n);
        --q->size;
    }
    return ret;
}

static bool queue_empty(queue *q) {
    return q->size == 0;
}

static void queue_uninit(queue *q) {
    node *n = q->head->next;
    while (n != NULL) {
        q->head->next = n->next;
        free(n);
        n = q->head->next;
    }
    free(q->head);
    q->size = 0;
}

int ladderLength_127_1(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 0) return 0;

    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(map);
    for (int i = 0; i < wordListSize; ++i)
        hashmap_put(map, wordList[i]);
    if (hashmap_get(map, endWord) == NULL) {
        hashmap_uninit(map);
        free(map);
        return 0;
    }
    hashmap_remove(map, beginWord);

    queue *q = (queue *) malloc(sizeof(queue));
    queue_init(q);
    queue_enq(q, beginWord);

    const size_t len = strlen(beginWord);
    char *word = (char *) malloc(len + 1);

    int depth = 0;
    while (!queue_empty(q)) {
        ++depth;
        for (int size = q->size; size > 0; --size) {
            strcpy(word, queue_deq(q));
            for (int i = 0; i < len; ++i) {
                const char c = word[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j == c) continue;
                    word[i] = j;
                    char *find = hashmap_get(map, word);
                    if (find != NULL) {
                        if (strcmp(word, endWord) == 0) {
                            free(word);
                            hashmap_uninit(map);
                            free(map);
                            queue_uninit(q);
                            free(q);
                            return depth + 1;
                        }
                        queue_enq(q, find);
                        hashmap_remove(map, find);
                    }
                }
                word[i] = c;
            }
        }
    }
    free(word);
    hashmap_uninit(map);
    free(map);
    queue_uninit(q);
    free(q);

    return 0;
}

int ladderLength_127_2(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 0) return 0;

    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(map);
    for (int i = 0; i < wordListSize; ++i)
        hashmap_put(map, wordList[i]);
    if (hashmap_get(map, endWord) == NULL) {
        hashmap_uninit(map);
        free(map);
        return 0;
    }
    hashmap_remove(map, beginWord);
    hashmap_remove(map, endWord);

    queue *q1 = (queue *) malloc(sizeof(queue));
    queue_init(q1);
    queue_enq(q1, beginWord);
    hashmap *m1 = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(m1);
    hashmap_put(m1, beginWord);

    queue *q2 = (queue *) malloc(sizeof(queue));
    queue_init(q2);
    queue_enq(q2, endWord);
    hashmap *m2 = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(m2);
    hashmap_put(m2, endWord);

    const size_t len = strlen(beginWord);
    char *word = (char *) malloc(len + 1);

    int depth = 0;
    while (!queue_empty(q1) && !queue_empty(q2)) {
        ++depth;
        if (q1->size > q2->size) {
            queue *q = q1;
            q1 = q2;
            q2 = q;
            hashmap *m = m1;
            m1 = m2;
            m2 = m;
        }

        for (int size = q1->size; size > 0; --size) {
            strcpy(word, queue_deq(q1));
            hashmap_remove(m1, word);
            for (int i = 0; i < len; ++i) {
                const char c = word[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j == c) continue;
                    word[i] = j;
                    if (hashmap_get(m2, word) != NULL) {
                        free(word);
                        hashmap_uninit(m2);
                        free(m2);
                        queue_uninit(q2);
                        free(q2);
                        hashmap_uninit(m1);
                        free(m1);
                        queue_uninit(q1);
                        free(q1);
                        hashmap_uninit(map);
                        free(map);
                        return depth + 1;
                    }
                    char *find = hashmap_get(map, word);
                    if (find != NULL) {
                        queue_enq(q1, find);
                        hashmap_put(m1, find);
                        hashmap_remove(map, find);
                    }
                }
                word[i] = c;
            }
        }
    }

    free(word);
    hashmap_uninit(m2);
    free(m2);
    queue_uninit(q2);
    free(q2);
    hashmap_uninit(m1);
    free(m1);
    queue_uninit(q1);
    free(q1);
    hashmap_uninit(map);
    free(map);

    return 0;
}
