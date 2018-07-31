#include "word_ladder_ii.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} deque;

static void deque_init(deque *q) {
    q->head = (node *) malloc(sizeof(node));
    q->tail = (node *) malloc(sizeof(node));
    q->head->prev = NULL;
    q->head->next = q->tail;
    q->tail->prev = q->head;
    q->tail->next = NULL;
    q->size = 0;
}

static deque *deque_create() {
    deque *q = (deque *) malloc(sizeof(deque));
    deque_init(q);
    return q;
}

static void deque_add_first(deque *q, char *data) {
    node *next = q->head->next;
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->prev = q->head;
    new->next = next;
    next->prev = new;
    q->head->next = new;
    ++q->size;
}

static char *deque_remove_first(deque *q) {
    node *n = q->head->next;
    if (n != q->tail) {
        char *ret = n->data;
        q->head->next = n->next;
        n->next->prev = q->head;
        free(n);
        --q->size;
        return ret;
    }
    return NULL;
}

static void deque_add_last(deque *q, char *data) {
    node *pre = q->tail->prev;
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->next = q->tail;
    new->prev = pre;
    pre->next = new;
    q->tail->prev = new;
    ++q->size;
}

static char *deque_remove_last(deque *q) {
    node *n = q->tail->prev;
    if (n != q->head) {
        char *ret = n->data;
        q->tail->prev = n->prev;
        n->prev->next = q->tail;
        free(n);
        --q->size;
        return ret;
    }
    return NULL;
}

static char **deque_to_array(deque *q, int *size) {
    char **ret = (char **) malloc(q->size * sizeof(char *));
    node *n = q->head->next;
    for (*size = 0; *size < q->size; ++*size) {
        ret[*size] = n->data;
        n = n->next;
    }
    return ret;
}

static void deque_uninit(deque *q) {
    node *n = q->head->next;
    while (n != NULL) {
        q->head->next = n->next;
        free(n);
        n = q->head->next;
    }
    free(q->head);
    q->size = 0;
}

static void deque_free(deque *q) {
    if (q == NULL) return;
    deque_uninit(q);
    free(q);
}

#define HASH_MAP_SIZE 256

typedef struct Entry {
    char *key;
    void *value;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hashcode(char *key) {
    int hash = 0;
    const size_t len = strlen(key);
    for (size_t i = 0; i < len; ++i)
        hash = hash * 31 + key[i];
    return hash;
}

static void hashmap_init(hashmap *map) {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
}

static hashmap *hashmap_create() {
    hashmap *m = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(m);
    return m;
}

static void hashmap_put(hashmap *map, char *key, void *val) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            e->next->value = val;
            return;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->value = val;
    new->next = NULL;
    e->next = new;
}

static void hashmap_put_key(hashmap *map, char *key) {
    hashmap_put(map, key, NULL);
}

static deque *hashmap_get(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->value;
        e = e->next;
    }
    return NULL;
}

static char *hashmap_get_key(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->key;
        e = e->next;
    }
    return NULL;
}

static bool hashmap_contains(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return true;
        e = e->next;
    }
    return false;
}

static char *hashmap_remove(hashmap *map, char *key) {
    int index = hashcode(key) & (HASH_MAP_SIZE - 1);
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            entry *n = e->next->next;
            char *ret = e->next->key;
            free(e->next);
            e->next = n;
            return ret;
        }
        e = e->next;
    }
    return NULL;
}

static void hashmap_remove_all(hashmap *map, deque *q) {
    node *n = q->head->next;
    while (n != q->tail) {
        hashmap_remove(map, n->data);
        n = n->next;
    }
}

static void hashmap_uninit(hashmap *map, void func(void *)) {
    entry *head, *e;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        head = map->entries + i;
        e = head->next;
        while (e != NULL) {
            e = e->next;
            if (func != NULL) {
                func(head->next->value);
            }
            free(head->next);
            head->next = e;
        }
    }
}

static void hashmap_free(hashmap *map, void func(void *)) {
    hashmap_uninit(map, func);
    free(map);
}

static void graph_dfs(hashmap *graph, char *root, char *end,
                      char ****ladders, int *ladder_size, int *ladder_capacity, int **col_sizes, deque *path) {
    if (strcmp(root, end) == 0) {
        if (*ladder_size >= *ladder_capacity) {
            *ladder_capacity *= 2;
            *ladders = (char ***) realloc(*ladders, *ladder_capacity * sizeof(char **));
            *col_sizes = (int *) realloc(*col_sizes, *ladder_capacity * sizeof(int));
        }
        (*ladders)[*ladder_size] = deque_to_array(path, *col_sizes + *ladder_size);
        ++*ladder_size;
        return;
    }
    deque *q = hashmap_get(graph, root);
    if (q != NULL) {
        int size = 0;
        char **children = deque_to_array(q, &size);
        for (int i = 0; i < size; ++i) {
            deque_add_last(path, children[i]);
            graph_dfs(graph, children[i], end, ladders, ladder_size, ladder_capacity, col_sizes, path);
            deque_remove_last(path);
        }
        free(children);
    }
}

static void graph_push(hashmap *graph, char *parent, char *child, bool flip) {
    if (flip) {
        char *tmp = parent;
        parent = child;
        child = tmp;
    }
    deque *children = hashmap_get(graph, parent);
    if (children == NULL) {
        children = deque_create();
        hashmap_put(graph, parent, children);
    }
    deque_add_last(children, child);
}

static void swap(void **a, void **b) {
    void *tmp = *a;
    *a = *b;
    *b = tmp;
}

char ***findLadders_126_1(char *beginWord, char *endWord, char **wordList, int wordListSize,
                          int **columnSizes, int *returnSize) {
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 0 || columnSizes == NULL ||
        returnSize == NULL)
        return 0;

    hashmap *dict = hashmap_create();
    for (int i = 0; i < wordListSize; ++i) {
        hashmap_put_key(dict, wordList[i]);
    }
    if (!hashmap_contains(dict, endWord)) {
        hashmap_free(dict, NULL);
        return NULL;
    }

    deque *queue1 = deque_create();
    deque_add_last(queue1, beginWord);
    hashmap *visited1 = hashmap_create();
    hashmap_put_key(visited1, beginWord);

    deque *queue2 = deque_create();
    deque_add_last(queue2, endWord);
    hashmap *visited2 = hashmap_create();
    hashmap_put_key(visited2, endWord);

    hashmap *graph = hashmap_create();

    const size_t len = strlen(beginWord);
    char *word = (char *) malloc(len + 1);
    char *parent, *child;

    bool flip = false, found = false;

    while (queue1->size > 0 && queue2->size > 0 && !found) {
        if (queue1->size > queue2->size) {
            swap((void **) &queue1, (void **) &queue2);
            swap((void **) &visited1, (void **) &visited2);
            flip = !flip;
        }
        hashmap_remove_all(dict, queue1);
        hashmap_remove_all(dict, queue2);

        for (int size = queue1->size; size > 0; --size) {
            strcpy(word, deque_remove_first(queue1));
            parent = hashmap_remove(visited1, word);
            for (int i = 0; i < len; ++i) {
                const char origin = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == origin) continue;
                    word[i] = ch;
                    if (hashmap_contains(visited2, word)) {
                        if (!found) found = true;
                        child = hashmap_get_key(visited2, word);
                        graph_push(graph, parent, child, flip);
                    } else if (!found) {
                        child = hashmap_get_key(dict, word);
                        if (child != NULL) {
                            if (!hashmap_contains(visited1, child)) {
                                deque_add_last(queue1, child);
                                hashmap_put_key(visited1, child);
                            }
                            graph_push(graph, parent, child, flip);
                        }
                    }
                }
                word[i] = origin;
            }
        }
    }

    int capacity = 16;
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));
    *columnSizes = (int *) calloc(capacity, sizeof(int));

    deque *path = deque_create();
    deque_add_last(path, beginWord);
    graph_dfs(graph, beginWord, endWord, &ret, returnSize, &capacity, columnSizes, path);
    deque_free(path);

    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));
    *columnSizes = (int *) realloc(*columnSizes, (*returnSize) * sizeof(int));

    free(word);
    hashmap_free(graph, (void (*)(void *)) deque_free);
    hashmap_free(visited2, NULL);
    deque_free(queue2);
    hashmap_free(visited1, NULL);
    deque_free(queue1);
    hashmap_free(dict, NULL);

    return ret;
}
